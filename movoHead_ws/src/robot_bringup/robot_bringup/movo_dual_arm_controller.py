#!/usr/bin/env python3
"""
Dual-arm Xbox controller for MOVO — both arms move simultaneously.

You command the LEFT arm; the RIGHT arm follows in mimic or mirror mode.
X toggles between mimic (same velocities) and mirror (X/roll/yaw flipped).

  Left stick vertical    forward / back  (Kinova +Z)
  Left stick horizontal  left / right    (Kinova +X)
  Right stick vertical   up / down       (Kinova +Y)
  Right stick horizontal Yaw
  D-pad up / down        Pitch
  D-pad left / right     Roll
  RT / LT                Close / Open grippers (both arms)
  A                      Start both arms
  B                      Emergency stop both arms
  RB                     Home both arms
  X                      Toggle mimic / mirror

Joint locking (optional):
  Pass locked_joints:="1" (or "1,5" etc.) to lock specific joints.
  Uses Jacobian-based cart→joint velocity conversion, same as single-arm controller.
"""

import numpy as np
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy

from kinova_msgs.action import SetFingersPosition
from kinova_msgs.msg import JointAngles, JointVelocity, PoseVelocity
from kinova_msgs.srv import HomeArm, Start, Stop
from sensor_msgs.msg import Joy

from arms_xbox_ctr.jaco_jacobian import cart_to_joint_vel

ARMS = ("left_arm", "right_arm")
MIRROR_SIGN = [-1.0, 1.0, 1.0, 1.0, -1.0, -1.0]  # x, y, z, roll, pitch, yaw


class MovoDualArmController(Node):
    def __init__(self):
        super().__init__("movo_dual_arm_controller")

        self._print_banner()

        self.declare_parameter("locked_joints", "")
        self.declare_parameter("max_joint_vel_deg", 45.0)
        self.max_joint_vel_deg = float(self.get_parameter("max_joint_vel_deg").value)
        raw = self.get_parameter("locked_joints").value.strip()
        self._locked_joints: list[int] = (
            [int(s) - 1 for s in raw.split(",") if s.strip()]
            if raw else []
        )

        self.mirror = False
        self.MAX_LIN = 0.20
        self.MAX_ANG = 0.20
        self.FINGERS_CLOSED = 5000.0

        self.prev_buttons = [0] * 15
        self.gripper_open = True
        self.last_joy_time = self.get_clock().now()
        self._homing = False
        self._jvel_stop_count = {arm: 0 for arm in ARMS}
        self.current_joint_deg: dict[str, list[float] | None] = {
            arm: None for arm in ARMS
        }
        self.vel = [0.0] * 6

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE, depth=1,
        )

        self.vel_pubs = {
            arm: self.create_publisher(
                PoseVelocity, f"/{arm}/{arm}_driver/in/cartesian_velocity", qos,
            ) for arm in ARMS
        }
        self.jvel_pubs = {
            arm: self.create_publisher(
                JointVelocity, f"/{arm}/{arm}_driver/in/joint_velocity", qos,
            ) for arm in ARMS
        }
        self.stop_clients = {
            arm: self.create_client(Stop, f"/{arm}/{arm}_driver/in/stop")
            for arm in ARMS
        }
        self.start_clients = {
            arm: self.create_client(Start, f"/{arm}/{arm}_driver/in/start")
            for arm in ARMS
        }
        self.home_client = self.create_client(HomeArm, "/movo/home_both_arms")
        self.finger_clients = {
            arm: ActionClient(
                self, SetFingersPosition,
                f"/{arm}/{arm}_driver/fingers_action/finger_positions",
            ) for arm in ARMS
        }

        self.create_subscription(Joy, "/joy", self._joy_cb, qos)
        for arm in ARMS:
            self.create_subscription(
                JointAngles,
                f"/{arm}/{arm}_driver/out/joint_angles",
                lambda msg, a=arm: self._on_joint_angles(a, msg),
                qos,
            )
        self.create_timer(0.01, self._publish)
        self._log_ctr = 0

    def _print_banner(self):
        banner = (
            "\n"
            "╔═════════════════════════════════════════════════════════╗\n"
            "║                                                         ║\n"
            "║   ⚠⚠⚠   DUAL-ARM SIMULTANEOUS CONTROL ACTIVE   ⚠⚠⚠      ║\n"
            "║                                                         ║\n"
            "║   BOTH ARMS WILL MOVE AT THE SAME TIME.                 ║\n"
            "║   RISK OF COLLISION — USE WITH EXTREME CAUTION!         ║\n"
            "║   KEEP HANDS ON E-STOP AT ALL TIMES.                    ║\n"
            "║                                                         ║\n"
            "║   X = toggle mimic / mirror    B = emergency stop       ║\n"
            "║                                                         ║\n"
            "╚═════════════════════════════════════════════════════════╝\n"
        )
        self.get_logger().warn(banner)

    # ── Joint-angle feedback ──

    def _on_joint_angles(self, arm: str, msg: JointAngles):
        self.current_joint_deg[arm] = [
            msg.joint1, msg.joint2, msg.joint3, msg.joint4,
            msg.joint5, msg.joint6, msg.joint7,
        ]

    # ── Joystick ──

    def _joy_cb(self, msg: Joy):
        self.last_joy_time = self.get_clock().now()
        if len(msg.buttons) > len(self.prev_buttons):
            self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        def axis(i, scale):
            v = msg.axes[i] if i < len(msg.axes) else 0.0
            return 0.0 if abs(v) < 0.1 else v * scale

        def dpad(i):
            return msg.axes[i] if i < len(msg.axes) else 0.0

        def trigger(i):
            return i < len(msg.axes) and msg.axes[i] < 0.0

        def pressed(i):
            return i < len(msg.buttons) and msg.buttons[i] == 1 and self.prev_buttons[i] == 0

        if pressed(2):  # X → toggle mimic/mirror
            self.mirror = not self.mirror
            label = "MIRROR" if self.mirror else "MIMIC"
            self.get_logger().warn(f"*** MODE: {label} ***")

        if pressed(0):  # A → start both
            for arm in ARMS:
                c = self.start_clients[arm]
                if c.service_is_ready():
                    c.call_async(Start.Request())
            self.get_logger().info("Both arms STARTED")

        if pressed(1):  # B → e-stop both
            for arm in ARMS:
                c = self.stop_clients[arm]
                if c.service_is_ready():
                    c.call_async(Stop.Request())
            self.vel = [0.0] * 6
            self.get_logger().warn("Both arms STOPPED")

        if pressed(5):  # RB → home both
            self._homing = True
            self.vel = [0.0] * 6
            if self.home_client.wait_for_service(timeout_sec=0.5):
                fut = self.home_client.call_async(HomeArm.Request())
                fut.add_done_callback(lambda f: setattr(self, '_homing', False))
            else:
                self.get_logger().error("Home service not ready")
                self._homing = False

        self.vel[0] = axis(0, self.MAX_LIN)   # X
        self.vel[1] = axis(4, self.MAX_LIN)   # Y
        self.vel[2] = axis(1, self.MAX_LIN)   # Z
        self.vel[3] = dpad(7) * self.MAX_ANG  # Roll
        self.vel[4] = dpad(6) * self.MAX_ANG  # Pitch
        self.vel[5] = -axis(3, self.MAX_ANG)  # Yaw

        if trigger(5) and self.gripper_open:
            self._send_grippers([self.FINGERS_CLOSED] * 3)
            self.gripper_open = False
            self.get_logger().info("Grippers CLOSED")
        elif trigger(2) and not self.gripper_open:
            self._send_grippers([0.0, 0.0, 0.0])
            self.gripper_open = True
            self.get_logger().info("Grippers OPEN")

        self.prev_buttons = list(msg.buttons)

    # ── Publishing ──

    def _publish(self):
        dt = (self.get_clock().now() - self.last_joy_time).nanoseconds / 1e9
        if dt > 0.5:
            self.vel = [0.0] * 6

        if self._homing:
            return

        right_vel = (
            [v * s for v, s in zip(self.vel, MIRROR_SIGN)]
            if self.mirror else list(self.vel)
        )

        if self._locked_joints:
            self._publish_joint_velocity("left_arm", self.vel)
            self._publish_joint_velocity("right_arm", right_vel)
        else:
            self.vel_pubs["left_arm"].publish(self._make_vel(self.vel))
            self.vel_pubs["right_arm"].publish(self._make_vel(right_vel))

        self._log_ctr += 1
        if self._log_ctr >= 500:
            self._log_ctr = 0
            mode = "MIRROR" if self.mirror else "MIMIC"
            self.get_logger().info(
                f"[{mode}] vel=({self.vel[0]:.3f},{self.vel[1]:.3f},{self.vel[2]:.3f},"
                f"{self.vel[3]:.3f},{self.vel[4]:.3f},{self.vel[5]:.3f})"
            )

    def _publish_joint_velocity(self, arm: str, vel: list[float]):
        q = self.current_joint_deg.get(arm)
        has_motion = False
        if q is not None:
            v_cart = np.array(vel)
            if np.any(np.abs(v_cart) > 1e-6):
                has_motion = True
                dq = cart_to_joint_vel(
                    q, v_cart,
                    locked_joints=self._locked_joints,
                    max_joint_vel_deg=self.max_joint_vel_deg,
                )
                jmsg = JointVelocity()
                jmsg.joint1 = float(dq[0])
                jmsg.joint2 = float(dq[1])
                jmsg.joint3 = float(dq[2])
                jmsg.joint4 = float(dq[3])
                jmsg.joint5 = float(dq[4])
                jmsg.joint6 = float(dq[5])
                jmsg.joint7 = float(dq[6])
                self.jvel_pubs[arm].publish(jmsg)
                self._jvel_stop_count[arm] = 10

        if not has_motion and self._jvel_stop_count[arm] > 0:
            self.jvel_pubs[arm].publish(JointVelocity())
            self._jvel_stop_count[arm] -= 1

    @staticmethod
    def _make_vel(v):
        msg = PoseVelocity()
        msg.twist_linear_x = v[0]
        msg.twist_linear_y = v[1]
        msg.twist_linear_z = v[2]
        msg.twist_angular_x = v[3]
        msg.twist_angular_y = v[4]
        msg.twist_angular_z = v[5]
        return msg

    def _send_grippers(self, target):
        for arm in ARMS:
            c = self.finger_clients[arm]
            if not c.server_is_ready():
                continue
            goal = SetFingersPosition.Goal()
            goal.fingers.finger1, goal.fingers.finger2, goal.fingers.finger3 = map(float, target)
            c.send_goal_async(goal)


def main(args=None):
    rclpy.init(args=args)
    node = MovoDualArmController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
