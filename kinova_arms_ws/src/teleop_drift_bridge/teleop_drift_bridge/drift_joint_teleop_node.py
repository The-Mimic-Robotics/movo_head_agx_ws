#!/usr/bin/env python3
"""Velocity-first AXE teleop with a small pose drift nudge (separate from kinova_teleop).

Leader: +x fwd, +y left, +z up. Axes from home_joints.yaml via arms_xbox_ctr.home_joint_config.

Control (simple):
  v_twist = rate * map(twist)   ← primary command
  v_drift = Kp * deadband(p_target - p_tcp)  ← only when leader twist is ~idle (idle-only bump)
  v_cart  = clamp(v_twist + v_drift)

So drift never fights velocity: when you move, you get pure twist; when idle, a tiny correction
slows TCP drift. No position-dominated joint motion.

Also: /joy Xbox safety (B stop, RB home, A start, X toggle teleop, gripper), /axe4/joy gripper,
HomeArm / Start / Stop services.
"""

from __future__ import annotations

import math
import time

import numpy as np
import rclpy
from geometry_msgs.msg import PoseStamped, TwistStamped
from kinova_msgs.action import SetFingersPosition
from kinova_msgs.msg import JointAngles, JointVelocity, PoseVelocity
from kinova_msgs.srv import HomeArm, Start, Stop
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Joy

from arms_xbox_ctr.home_joint_config import apply_linear, axis_map_for_arm, parse_axis_map
from arms_xbox_ctr.jaco_jacobian import cart_to_joint_vel


def _deadband_vec(err: list[float], d: float) -> list[float]:
    out = []
    for e in err:
        if abs(e) <= d:
            out.append(0.0)
        else:
            out.append(e - math.copysign(d, e))
    return out


class DriftJointTeleopNode(Node):
    def __init__(self) -> None:
        super().__init__("drift_joint_teleop")

        self.declare_parameter("arm_namespace", "left_arm")
        self.declare_parameter("leader_twist_topic", "/axe4/eef_twist")
        self.declare_parameter("leader_pose_topic", "/axe4/eef_position")
        self.declare_parameter("teleop_axis", "")
        self.declare_parameter("speed", 1.0)
        self.declare_parameter("twist_rate", 12.0)
        self.declare_parameter("drift_kp", 0.35)
        self.declare_parameter("drift_deadband_m", 0.004)
        self.declare_parameter("max_lin_vel", 0.5)
        self.declare_parameter("max_correction_vel", 0.025)
        self.declare_parameter("max_ang_vel", 0.2)
        self.declare_parameter("lock_joint1", True)
        self.declare_parameter("max_joint_vel_deg", 120.0)
        self.declare_parameter("pose_timeout_sec", 0.25)
        self.declare_parameter("twist_timeout_sec", 0.15)
        self.declare_parameter("use_pose_absolute", False)
        self.declare_parameter("drift_twist_idle_thresh", 0.015)
        self.declare_parameter("button_debounce_sec", 0.3)
        self.declare_parameter("require_joy_keepalive", False)
        self.declare_parameter("joy_timeout_sec", 1.0)
        self.declare_parameter("auto_arm", True)
        self.declare_parameter("auto_start_arm", True)
        self.declare_parameter("require_command_path_ready", True)
        self.declare_parameter("fingers_closed_pos", 6000.0)

        p = self.get_parameter
        self._arm = str(p("arm_namespace").value).strip()
        self._lt = str(p("leader_twist_topic").value).strip()
        self._lp = str(p("leader_pose_topic").value).strip()
        ta = (p("teleop_axis").value or "").strip()
        self._axis = parse_axis_map(ta if ta else axis_map_for_arm(self._arm))
        self._speed = max(0.0, float(p("speed").value))
        self._rate = max(0.0, float(p("twist_rate").value))
        self._kp = max(0.0, float(p("drift_kp").value))
        self._dbd = max(0.0, float(p("drift_deadband_m").value))
        self._max_lin = max(0.0, float(p("max_lin_vel").value))
        self._max_corr = max(0.0, float(p("max_correction_vel").value))
        self._max_ang = max(0.0, float(p("max_ang_vel").value))
        self._lock_j1 = bool(p("lock_joint1").value)
        self._max_jd = max(0.0, float(p("max_joint_vel_deg").value))
        self._pose_t = float(p("pose_timeout_sec").value)
        self._twist_t = float(p("twist_timeout_sec").value)
        self._use_abs = bool(p("use_pose_absolute").value)
        if not self._use_abs and "absolute" in self._lp.lower():
            self._use_abs = True
        self._idle_thresh = max(0.0, float(p("drift_twist_idle_thresh").value))
        self.button_debounce_sec = float(p("button_debounce_sec").value)
        self.require_joy_keepalive = bool(p("require_joy_keepalive").value)
        self.joy_timeout_sec = float(p("joy_timeout_sec").value)
        self.auto_arm = bool(p("auto_arm").value)
        self.auto_start_arm = bool(p("auto_start_arm").value)
        self.require_command_path_ready = bool(p("require_command_path_ready").value)
        self.fingers_closed_pos = float(p("fingers_closed_pos").value)

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )

        self.create_subscription(TwistStamped, self._lt, self._on_twist, qos)
        self.create_subscription(PoseStamped, self._lp, self._on_pose, qos)
        self.create_subscription(
            PoseStamped, f"/{self._arm}/{self._arm}_driver/out/tool_pose", self._on_tool, qos
        )
        self.create_subscription(
            JointAngles, f"/{self._arm}/{self._arm}_driver/out/joint_angles", self._on_joints, qos
        )
        self.create_subscription(Joy, "/joy", self._joy_cb, qos)
        self.create_subscription(Joy, "/axe4/joy", self._axe4_joy_cb, qos)

        self._vel_pub = self.create_publisher(
            PoseVelocity, f"/{self._arm}/{self._arm}_driver/in/cartesian_velocity", qos
        )
        self._jvel_pub = self.create_publisher(
            JointVelocity, f"/{self._arm}/{self._arm}_driver/in/joint_velocity", qos
        )

        self.home_client = self.create_client(HomeArm, f"/movo/home_{self._arm}")
        self.stop_client = self.create_client(Stop, f"/{self._arm}/{self._arm}_driver/in/stop")
        self.start_client = self.create_client(Start, f"/{self._arm}/{self._arm}_driver/in/start")
        self.finger_client = ActionClient(
            self, SetFingersPosition,
            f"/{self._arm}/{self._arm}_driver/fingers_action/finger_positions",
        )

        self.prev_buttons: list[int] = [0] * 15
        self.last_joy_msg_time = time.time()
        self._last_button_event_time: dict[str, float] = {}
        self.last_gripper_cmd: str | None = None
        self._last_axe4_gripper: str | None = None
        self.teleop_active = self.auto_arm
        self._arm_started = False
        self._homing = False

        self._last_twist = time.time()
        self._last_pose = time.time()
        self._leader_abs_ref: list[float] | None = None
        self._leader_rel = [0.0, 0.0, 0.0]
        self._twist_lin = [0.0, 0.0, 0.0]
        self._twist_ang_z = 0.0
        self._robot_home: list[float] | None = None
        self._tool_xyz = [0.0, 0.0, 0.0]
        self._have_tool = False
        self._joint_deg: list[float] | None = None
        self._jvel_stop = 0

        self.create_timer(0.01, self._tick)
        self.get_logger().info(
            f"drift_joint_teleop arm={self._arm} twist={self._lt} pose={self._lp} "
            f"drift idle-only (thresh={self._idle_thresh}) kp={self._kp} max_corr={self._max_corr}"
        )

    def _on_twist(self, msg: TwistStamped) -> None:
        self._last_twist = time.time()
        self._twist_lin = [msg.twist.linear.x, msg.twist.linear.y, msg.twist.linear.z]
        self._twist_ang_z = msg.twist.angular.z

    def _on_pose(self, msg: PoseStamped) -> None:
        self._last_pose = time.time()
        px = float(msg.pose.position.x)
        py = float(msg.pose.position.y)
        pz = float(msg.pose.position.z)
        if self._use_abs:
            if self._leader_abs_ref is None:
                self._leader_abs_ref = [px, py, pz]
            self._leader_rel = [
                px - self._leader_abs_ref[0],
                py - self._leader_abs_ref[1],
                pz - self._leader_abs_ref[2],
            ]
        else:
            self._leader_rel = [px, py, pz]

    def _on_tool(self, msg: PoseStamped) -> None:
        self._tool_xyz = [
            float(msg.pose.position.x),
            float(msg.pose.position.y),
            float(msg.pose.position.z),
        ]
        self._have_tool = True
        if self._robot_home is None:
            self._robot_home = self._tool_xyz[:]

    def _on_joints(self, msg: JointAngles) -> None:
        self._joint_deg = [
            msg.joint1, msg.joint2, msg.joint3, msg.joint4,
            msg.joint5, msg.joint6, msg.joint7,
        ]

    def _pressed(self, msg: Joy, i: int) -> bool:
        return i < len(msg.buttons) and msg.buttons[i] == 1 and self.prev_buttons[i] == 0

    def _debounced(self, msg: Joy, i: int, key: str) -> bool:
        if not self._pressed(msg, i):
            return False
        now = time.time()
        last = self._last_button_event_time.get(key, 0.0)
        if now - last < self.button_debounce_sec:
            return False
        self._last_button_event_time[key] = now
        return True

    def _joy_cb(self, msg: Joy) -> None:
        self.last_joy_msg_time = time.time()
        if len(msg.buttons) > len(self.prev_buttons):
            self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        if self._debounced(msg, 1, "stop"):
            self.teleop_active = False
            self._robot_home = None
            self._leader_abs_ref = None
            self._call(self.stop_client, Stop.Request())
            self._arm_started = False
            self.get_logger().warn("EMERGENCY STOP + teleop disarmed")

        if self._debounced(msg, 5, "home"):
            self.teleop_active = False
            self._homing = True
            self._robot_home = None
            self._leader_abs_ref = None
            self._arm_started = False
            self._call_home()

        if self._debounced(msg, 0, "start"):
            self._call(self.start_client, Start.Request())
            self._arm_started = True

        if self._debounced(msg, 2, "toggle"):
            self.teleop_active = not self.teleop_active
            self.get_logger().info(f"teleop_active={self.teleop_active}")

        cur = None
        if len(msg.axes) > 7 and msg.axes[7] > 0.5:
            cur = "OPEN"
        elif len(msg.axes) > 7 and msg.axes[7] < -0.5:
            cur = "CLOSE"
        if cur and cur != self.last_gripper_cmd:
            if cur == "OPEN":
                self._gripper([0.0, 0.0, 0.0])
            else:
                c = self.fingers_closed_pos
                self._gripper([c, c, c])
            self.last_gripper_cmd = cur
        elif cur is None:
            self.last_gripper_cmd = None

        self.prev_buttons = list(msg.buttons)

    def _axe4_joy_cb(self, msg: Joy) -> None:
        cmd = None
        if len(msg.buttons) > 0 and msg.buttons[0] == 1:
            cmd = "OPEN"
        elif len(msg.buttons) > 0 and msg.buttons[0] == 0:
            cmd = "CLOSE"
        if cmd and cmd != self._last_axe4_gripper:
            if cmd == "OPEN":
                self._gripper([0.0, 0.0, 0.0])
            else:
                c = self.fingers_closed_pos
                self._gripper([c, c, c])
            self._last_axe4_gripper = cmd

    def _call(self, client, req) -> None:
        if client.service_is_ready():
            client.call_async(req)

    def _call_home(self) -> None:
        if not self.home_client.service_is_ready():
            self.get_logger().error("Home service not ready")
            self._homing = False
            return
        fut = self.home_client.call_async(HomeArm.Request())
        fut.add_done_callback(self._on_home_done)

    def _on_home_done(self, fut) -> None:
        self._homing = False
        try:
            r = fut.result()
            self.get_logger().info(f"Home result: {r.homearm_result}")
        except Exception as e:
            self.get_logger().error(f"Home failed: {e}")
        self._call(self.start_client, Start.Request())
        self._arm_started = True

    def _gripper(self, t: list[float]) -> None:
        if not self.finger_client.server_is_ready():
            return
        g = SetFingersPosition.Goal()
        g.fingers.finger1, g.fingers.finger2, g.fingers.finger3 = t[0], t[1], t[2]
        self.finger_client.send_goal_async(g)

    @staticmethod
    def _clamp(v: float, m: float) -> float:
        return max(min(v, m), -m)

    def _path_ready(self) -> bool:
        if not (
            self.start_client.service_is_ready()
            and self.stop_client.service_is_ready()
            and self.home_client.service_is_ready()
        ):
            return False
        if self._lock_j1:
            if self._joint_deg is None:
                return False
            if self._jvel_pub.get_subscription_count() < 1:
                return False
        else:
            if self._vel_pub.get_subscription_count() < 1:
                return False
        return True

    def _tick(self) -> None:
        if self._homing:
            return

        if self.require_joy_keepalive and (time.time() - self.last_joy_msg_time) > self.joy_timeout_sec:
            self.teleop_active = False

        now = time.time()
        if now - self._last_twist > self._twist_t:
            self._twist_lin = [0.0, 0.0, 0.0]
            self._twist_ang_z = 0.0

        pose_ok = now - self._last_pose <= self._pose_t

        if self._robot_home is None or not self._have_tool:
            self._publish_stop()
            return

        if not self.teleop_active:
            self._publish_stop()
            return

        active = not self.require_command_path_ready or self._path_ready()
        if not active:
            self._publish_stop()
            return

        if self.auto_start_arm and not self._arm_started and self.start_client.service_is_ready():
            self._call(self.start_client, Start.Request())
            self._arm_started = True

        vL = [
            self._clamp(self._rate * self._twist_lin[0], self._max_lin),
            self._clamp(self._rate * self._twist_lin[1], self._max_lin),
            self._clamp(self._rate * self._twist_lin[2], self._max_lin),
        ]
        v_twist = apply_linear(vL, self._axis)

        twist_mag = math.sqrt(v_twist[0] ** 2 + v_twist[1] ** 2 + v_twist[2] ** 2)
        idle = twist_mag < self._idle_thresh

        v_corr = [0.0, 0.0, 0.0]
        if self._kp > 0.0 and idle and pose_ok and self._robot_home is not None:
            delta_f = apply_linear(self._leader_rel, self._axis)
            p_tgt = [
                self._robot_home[i] + self._speed * delta_f[i]
                for i in range(3)
            ]
            err = [p_tgt[i] - self._tool_xyz[i] for i in range(3)]
            err_db = _deadband_vec(err, self._dbd)
            v_corr = [self._kp * e for e in err_db]
            v_corr = [self._clamp(v_corr[i], self._max_corr) for i in range(3)]

        vx = self._clamp(v_twist[0] + v_corr[0], self._max_lin)
        vy = self._clamp(v_twist[1] + v_corr[1], self._max_lin)
        vz = self._clamp(v_twist[2] + v_corr[2], self._max_lin)
        wz = self._clamp(self._rate * self._twist_ang_z, self._max_ang)

        out6 = [vx, vy, vz, 0.0, 0.0, wz]

        if self._lock_j1:
            self._publish_joint(out6)
        else:
            self._publish_cart(out6)

    def _publish_cart(self, out6: list[float]) -> None:
        m = PoseVelocity()
        m.twist_linear_x = float(out6[0])
        m.twist_linear_y = float(out6[1])
        m.twist_linear_z = float(out6[2])
        m.twist_angular_z = float(out6[5])
        self._vel_pub.publish(m)

    def _publish_joint(self, out6: list[float]) -> None:
        q = self._joint_deg
        if q is None:
            return
        v_cart = np.array([
            out6[0], out6[1], out6[2], 0.0, 0.0, out6[5],
        ], dtype=float)
        if np.max(np.abs(v_cart)) < 1e-9:
            if self._jvel_stop > 0:
                self._jvel_pub.publish(JointVelocity())
                self._jvel_stop -= 1
            return
        dq = cart_to_joint_vel(
            q, v_cart,
            locked_joints=[0],
            max_joint_vel_deg=self._max_jd,
        )
        jm = JointVelocity()
        jm.joint1 = 0.0
        jm.joint2 = float(dq[1])
        jm.joint3 = float(dq[2])
        jm.joint4 = float(dq[3])
        jm.joint5 = float(dq[4])
        jm.joint6 = float(dq[5])
        jm.joint7 = float(dq[6])
        self._jvel_pub.publish(jm)
        self._jvel_stop = 10

    def _publish_stop(self) -> None:
        self._vel_pub.publish(PoseVelocity())
        self._jvel_pub.publish(JointVelocity())


def main(args=None) -> None:
    rclpy.init(args=args)
    node = DriftJointTeleopNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
