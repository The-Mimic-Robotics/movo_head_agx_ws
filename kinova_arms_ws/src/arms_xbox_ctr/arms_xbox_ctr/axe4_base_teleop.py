#!/usr/bin/env python3
"""
AXE4 / Kinova teleop handles → MOVO base (/cmd_vel) + gripper toggles.

Left: axes[0] fwd/back, [1] strafe, [2] grip (must release axis past gripper_release before next toggle).
Right (optional): [0] yaw, [2] grip.

Optional require_deadman: base motion from a handle only while that handle's button is held.
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


class Axe4BaseTeleop(Node):
    def __init__(self):
        super().__init__("axe4_base_teleop")

        self.declare_parameter("cmd_vel_topic", "/cmd_vel")
        self.declare_parameter("publish_rate_hz", 20.0)
        self.declare_parameter("max_linear", 0.6)
        self.declare_parameter("max_angular", 0.8)
        self.declare_parameter("deadzone", 0.08)
        self.declare_parameter("left_joy_topic", "/axe4/joy")
        self.declare_parameter("left_axis_linear", 0)
        self.declare_parameter("left_axis_strafe", 1)
        self.declare_parameter("left_axis_grip", 2)
        self.declare_parameter("linear_x_sign", 1.0)
        self.declare_parameter("strafe_y_sign", -1.0)
        self.declare_parameter("use_right_joy", False)
        self.declare_parameter("right_joy_topic", "/axe4/joy_right")
        self.declare_parameter("right_axis_yaw", 0)
        self.declare_parameter("right_axis_grip", 2)
        self.declare_parameter("yaw_sign", 1.0)
        self.declare_parameter("gripper_threshold", -0.5)
        self.declare_parameter("gripper_release", -0.25)
        self.declare_parameter("fingers_closed", 5000.0)
        self.declare_parameter("require_deadman", False)
        self.declare_parameter("left_deadman_button", 1)
        self.declare_parameter("right_deadman_button", 1)

        p = self.get_parameter
        self._cmd_topic = str(p("cmd_vel_topic").value).strip() or "/cmd_vel"
        self._rate = max(5.0, float(p("publish_rate_hz").value))
        self._max_lin = max(0.01, float(p("max_linear").value))
        self._max_ang = max(0.01, float(p("max_angular").value))
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
        self._require_deadman = _as_bool(p("require_deadman").value)
        self._ld_btn = int(p("left_deadman_button").value)
        self._rd_btn = int(p("right_deadman_button").value)

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )
        self._pub = self.create_publisher(Twist, self._cmd_topic, qos)

        lt = str(p("left_joy_topic").value).strip() or "/axe4/joy"
        self.create_subscription(Joy, lt, self._cb_left, qos)
        self._left_axes: list[float] = []
        self._left_buttons: list[int] = []
        self._right_axes: list[float] = []
        self._right_buttons: list[int] = []
        if self._use_right:
            rt = str(p("right_joy_topic").value).strip() or "/axe4/joy_right"
            self.create_subscription(Joy, rt, self._cb_right, qos)

        # ready: can arm next toggle; waiting_release: ignore until axis > gripper_release
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
            f"axe4_base_teleop: cmd={self._cmd_topic} left_joy={lt} "
            f"use_right={self._use_right} require_deadman={self._require_deadman}"
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

    def _cb_left(self, msg: Joy):
        self._left_axes = list(msg.axes)
        self._left_buttons = list(msg.buttons)
        self._last_left_t = time.monotonic()
        self._process_grip_axis("left_arm", self._left_axes, self._lg)

    def _cb_right(self, msg: Joy):
        self._right_axes = list(msg.axes)
        self._right_buttons = list(msg.buttons)
        self._last_right_t = time.monotonic()
        self._process_grip_axis("right_arm", self._right_axes, self._rg)

    def _process_grip_axis(self, arm: str, axes: list[float], idx: int):
        val = float(axes[idx]) if 0 <= idx < len(axes) else 0.0
        # Always allow release so we can arm again after the axis comes back (even while action busy)
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
        tw.linear.x = self._sx * lx * self._max_lin
        tw.linear.y = self._sy * ly * self._max_lin
        tw.angular.z = self._ys * wz * self._max_ang
        self._pub.publish(tw)


def main(args=None):
    rclpy.init(args=args)
    node = Axe4BaseTeleop()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
