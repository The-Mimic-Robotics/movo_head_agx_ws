#!/usr/bin/env python3
"""
AXE leader handle Joy topics → MOVO base (/cmd_vel) + gripper toggles.

Subscribes to handle ``sensor_msgs/Joy`` (from bi_axe_udp_ros2_bridge: /bi_axe_left/joy, /bi_axe_right/joy).
Optional Xbox ``/joy`` safety: B latches override (zero base, ignore handle grippers); A clears latch
(same idea as kinova_teleop arm E-stop / re-enable). Handle-side deadman and grip hysteresis remain.
"""

import time

import rclpy
from geometry_msgs.msg import Twist
from kinova_msgs.action import SetFingersPosition
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Joy


def _as_bool(v, default=False) -> bool:
    if isinstance(v, bool):
        return v
    if isinstance(v, str):
        return v.strip().lower() in ("true", "1", "yes")
    return bool(v)


class AxeLeaderBaseTeleop(Node):
    def __init__(self):
        super().__init__("axe_leader_base_teleop")

        self.declare_parameter("cmd_vel_topic", "/cmd_vel")
        self.declare_parameter("publish_rate_hz", 20.0)

        self.declare_parameter("max_linear", 0.6)
        self.declare_parameter("max_angular", 0.8)
        self.declare_parameter("velocity_scale", 0.8)
        
        self.declare_parameter("deadzone", 0.08)
        self.declare_parameter("left_joy_topic", "/bi_axe_left/joy")
        self.declare_parameter("left_axis_linear", 0)
        self.declare_parameter("left_axis_strafe", 1)
        self.declare_parameter("left_axis_grip", 2)
        self.declare_parameter("linear_x_sign", 1.0)
        self.declare_parameter("strafe_y_sign", -1.0)
        self.declare_parameter("use_right_joy", True)
        self.declare_parameter("right_joy_topic", "/bi_axe_right/joy")
        self.declare_parameter("right_axis_yaw", 1)
        self.declare_parameter("right_axis_grip", 2)
        self.declare_parameter("yaw_sign", 1.0)
        self.declare_parameter("gripper_threshold", -0.5)
        self.declare_parameter("gripper_release", -0.25)
        self.declare_parameter("fingers_closed", 5000.0)
        # Always require deadman for base motion (per handles).
        self.declare_parameter("require_deadman", True)
        self.declare_parameter("left_deadman_button", 1)
        self.declare_parameter("right_deadman_button", 1)

        self.declare_parameter("xbox_joy_topic", "/joy")
        self.declare_parameter("enable_xbox_safety_override", True)
        self.declare_parameter("xbox_estop_button", 1)
        self.declare_parameter("xbox_clear_override_button", 0)

        p = self.get_parameter
        self._cmd_topic = str(p("cmd_vel_topic").value).strip() or "/cmd_vel"
        self._rate = max(5.0, float(p("publish_rate_hz").value))
        self._max_lin = max(0.01, float(p("max_linear").value))
        self._max_ang = max(0.01, float(p("max_angular").value))
        self._vel_scale = max(0.0, float(p("velocity_scale").value))
        self._dz = max(0.0, float(p("deadzone").value))
        self._li = int(p("left_axis_linear").value)
        self._ls = int(p("left_axis_strafe").value)
        self._lg = int(p("left_axis_grip").value)
        self._sx = float(p("linear_x_sign").value)
        self._sy = float(p("strafe_y_sign").value)
        self._use_right = _as_bool(p("use_right_joy").value)
        self._ri = int(p("right_axis_yaw").value)
        self._rg = int(p("right_axis_grip").value)
        self._ys = float(p("yaw_sign").value)
        self._gth = float(p("gripper_threshold").value)
        self._grl = float(p("gripper_release").value)
        self._fclosed = float(p("fingers_closed").value)
        # Enforced: base motion only when deadman button is held.
        self._require_deadman = True
        self._ld_btn = int(p("left_deadman_button").value)
        self._rd_btn = int(p("right_deadman_button").value)

        self._xbox_topic = str(p("xbox_joy_topic").value).strip() or "/joy"
        self._xbox_override_en = _as_bool(p("enable_xbox_safety_override").value)
        self._xbox_estop_btn = int(p("xbox_estop_button").value)
        self._xbox_clear_btn = int(p("xbox_clear_override_button").value)
        self._xbox_override_active = False
        self._xbox_prev_buttons: list[int] = []

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )
        self._pub = self.create_publisher(Twist, self._cmd_topic, qos)

        lt = str(p("left_joy_topic").value).strip() or "/bi_axe_left/joy"
        self.create_subscription(Joy, lt, self._cb_left, qos)
        self._left_axes: list[float] = []
        self._left_buttons: list[int] = []
        self._right_axes: list[float] = []
        self._right_buttons: list[int] = []
        if self._use_right:
            rt = str(p("right_joy_topic").value).strip() or "/bi_axe_right/joy"
            self.create_subscription(Joy, rt, self._cb_right, qos)

        if self._xbox_override_en:
            self.create_subscription(Joy, self._xbox_topic, self._cb_xbox, qos)

        self._grip_phase = {"left_arm": "ready", "right_arm": "ready"}
        self._gripper_busy = {"left_arm": False, "right_arm": False}
        self._grip_open = {"left_arm": True, "right_arm": True}
        self._finger_clients = {
            "left_arm": ActionClient(
                self,
                SetFingersPosition,
                "/left_arm/left_arm_driver/fingers_action/finger_positions",
            ),
            "right_arm": ActionClient(
                self,
                SetFingersPosition,
                "/right_arm/right_arm_driver/fingers_action/finger_positions",
            ),
        }
        self._last_grip_warn = 0.0

        period = 1.0 / self._rate
        self.create_timer(period, self._tick)
        self._last_left_t = time.monotonic()
        self._last_right_t = time.monotonic()

        self.get_logger().info(
            f"axe_leader_base_teleop: cmd={self._cmd_topic} left_joy={lt} "
            f"use_right={self._use_right} require_deadman={self._require_deadman} "
            f"xbox_override={self._xbox_override_en} ({self._xbox_topic})"
        )

    def _axis(self, axes: list[float], i: int) -> float:
        if i < 0 or i >= len(axes):
            return 0.0
        v = float(axes[i])
        return 0.0 if abs(v) < self._dz else v

    def _btn(self, buttons: list[int], i: int) -> bool:
        return i < len(buttons) and int(buttons[i]) == 1

    def _deadman_left(self) -> bool:
        if not self._require_deadman:
            return True
        return self._btn(self._left_buttons, self._ld_btn)

    def _deadman_right(self) -> bool:
        if not self._require_deadman:
            return True
        return self._btn(self._right_buttons, self._rd_btn)

    def _cb_xbox(self, msg: Joy):
        if not self._xbox_override_en:
            return
        bt = list(msg.buttons)
        if len(bt) > len(self._xbox_prev_buttons):
            self._xbox_prev_buttons.extend([0] * (len(bt) - len(self._xbox_prev_buttons)))

        def pressed(i: int) -> bool:
            return i < len(bt) and bt[i] == 1 and (i >= len(self._xbox_prev_buttons) or self._xbox_prev_buttons[i] == 0)

        if pressed(self._xbox_estop_btn):
            self._xbox_override_active = True
            self.get_logger().warn("Xbox safety: OVERRIDE latched — base zero, handle grippers ignored (press A to clear)")

        if pressed(self._xbox_clear_btn):
            self._xbox_override_active = False
            self.get_logger().info("Xbox safety: override cleared — handle base + grippers active again")

        self._xbox_prev_buttons = bt[:]

    def _cb_left(self, msg: Joy):
        self._left_axes = list(msg.axes)
        self._left_buttons = list(msg.buttons)
        self._last_left_t = time.monotonic()
        if not self._xbox_override_active:
            self._process_grip_axis("left_arm", self._left_axes, self._lg)

    def _cb_right(self, msg: Joy):
        self._right_axes = list(msg.axes)
        self._right_buttons = list(msg.buttons)
        self._last_right_t = time.monotonic()
        if not self._xbox_override_active:
            self._process_grip_axis("right_arm", self._right_axes, self._rg)

    def _process_grip_axis(self, arm: str, axes: list[float], idx: int):
        val = float(axes[idx]) if 0 <= idx < len(axes) else 0.0
        if self._grip_phase[arm] == "waiting_release" and val > self._grl:
            self._grip_phase[arm] = "ready"
        if self._gripper_busy[arm]:
            return
        if self._grip_phase[arm] == "ready" and val < self._gth:
            self._toggle_gripper(arm)
            self._grip_phase[arm] = "waiting_release"

    def _toggle_gripper(self, arm: str):
        client = self._finger_clients.get(arm)
        if client is None:
            return
        if not client.server_is_ready():
            now = time.monotonic()
            if now - self._last_grip_warn > 2.0:
                self._last_grip_warn = now
                self.get_logger().warn(f"{arm} gripper action server not ready (throttled)")
            return

        self._gripper_busy[arm] = True
        open_g = self._grip_open[arm]
        goal = SetFingersPosition.Goal()
        if open_g:
            goal.fingers.finger1 = goal.fingers.finger2 = goal.fingers.finger3 = self._fclosed
            self.get_logger().info(f"{arm} gripper → CLOSE (sent)")
        else:
            goal.fingers.finger1 = goal.fingers.finger2 = goal.fingers.finger3 = 0.0
            self.get_logger().info(f"{arm} gripper → OPEN (sent)")

        send_future = client.send_goal_async(goal)
        send_future.add_done_callback(
            lambda f, a=arm, prev_open=open_g: self._on_grip_goal_sent(f, a, prev_open)
        )

    def _on_grip_goal_sent(self, future, arm: str, prev_open: bool):
        try:
            gh = future.result()
        except Exception as e:
            self.get_logger().error(f"{arm} gripper send failed: {e}")
            self._gripper_busy[arm] = False
            return
        if not gh.accepted:
            self.get_logger().warn(f"{arm} gripper goal rejected")
            self._gripper_busy[arm] = False
            return
        result_future = gh.get_result_async()
        result_future.add_done_callback(
            lambda f, a=arm, po=prev_open: self._on_grip_result(f, a, po)
        )

    def _on_grip_result(self, future, arm: str, prev_open: bool):
        try:
            future.result()
            self._grip_open[arm] = not prev_open
            self.get_logger().info(
                f"{arm} gripper done (now {'open' if self._grip_open[arm] else 'closed'})"
            )
        except Exception as e:
            self.get_logger().warn(f"{arm} gripper result error: {e}")
        finally:
            self._gripper_busy[arm] = False

    def _tick(self):
        if self._xbox_override_active:
            self._pub.publish(Twist())
            return

        now = time.monotonic()
        if now - self._last_left_t > 0.5:
            lx, ly = 0.0, 0.0
        elif self._deadman_left():
            lx = self._axis(self._left_axes, self._li)
            ly = self._axis(self._left_axes, self._ls)
        else:
            lx, ly = 0.0, 0.0

        if not self._use_right or now - self._last_right_t > 0.5:
            wz = 0.0
        elif self._deadman_right():
            wz = self._axis(self._right_axes, self._ri)
        else:
            wz = 0.0

        tw = Twist()
        s = self._vel_scale
        tw.linear.x = s * self._sx * lx * self._max_lin
        tw.linear.y = s * self._sy * ly * self._max_lin
        tw.angular.z = s * self._ys * wz * self._max_ang
        self._pub.publish(tw)


def main(args=None):
    rclpy.init(args=args)
    node = AxeLeaderBaseTeleop()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
