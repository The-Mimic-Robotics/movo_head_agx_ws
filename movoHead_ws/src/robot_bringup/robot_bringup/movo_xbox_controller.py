#!/usr/bin/env python3
"""
Xbox controller for MOVO robot (two Jaco arms + mobile base).

X cycles control target: left_arm → right_arm → base → ...

ARM MODE — full 6DOF Cartesian velocity:
  Left stick vertical    forward / back  (Kinova +Z)
  Left stick horizontal  left / right    (Kinova +X)
  Right stick vertical   up / down       (Kinova +Y)
  Right stick horizontal Yaw
  D-pad up / down        Pitch
  D-pad left / right     Roll
  RT (right trigger)     Close gripper
  LT (left trigger)      Open gripper
  A                      Start arm
  B                      Emergency stop
  RB                     Home current arm
  LB double-tap          Home both arms

BASE MODE — hold RB as deadman:
  Left stick vertical    Drive forward / back
  Left stick horizontal  Strafe left / right
  Right stick horizontal Rotate
"""

import time

import numpy as np
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy

from geometry_msgs.msg import Twist
from kinova_msgs.action import SetFingersPosition
from kinova_msgs.msg import JointAngles, JointVelocity, PoseVelocity
from kinova_msgs.srv import HomeArm, Start, Stop
from sensor_msgs.msg import Joy

from arms_xbox_ctr.home_joint_config import apply_linear, movo_linear_axis_map_for_arm
from arms_xbox_ctr.jaco_jacobian import cart_to_joint_vel

MODES = ["left_arm", "right_arm", "base"]


class MovoXboxController(Node):
    def __init__(self):
        super().__init__("movo_xbox_controller")

        self.declare_parameter("locked_joints", "")
        self.declare_parameter("max_joint_vel_deg", 45.0)
        self.declare_parameter("use_home_yaml_teleop_frame", True)
        self.max_joint_vel_deg = float(self.get_parameter("max_joint_vel_deg").value)
        self._use_yaml_teleop = bool(self.get_parameter("use_home_yaml_teleop_frame").value)
        # Parse "1,3,5" → [0, 2, 4]  (1-indexed input → 0-indexed for Jacobian)
        raw = self.get_parameter("locked_joints").value.strip()
        self._locked_joints: list[int] = (
            [int(s) - 1 for s in raw.split(",") if s.strip()]
            if raw else []
        )

        self.mode_index = 0
        self.mode = MODES[0]

        self.MAX_LIN_VEL = 0.20
        self.MAX_ANG_VEL = 0.20
        self.BASE_MAX_LIN = 1.0
        self.BASE_MAX_ANG = 1.0
        self.FINGERS_CLOSED = 5000.0

        self.prev_buttons = [0] * 15
        self.gripper_open = True
        self.last_joy_time = self.get_clock().now()
        self._btn4_last_press = 0.0
        self._homing = False
        self._jvel_stop_count = 0
        self.current_joint_deg: dict[str, list[float] | None] = {
            "left_arm": None, "right_arm": None,
        }

        # 6DOF velocity: [x, y, z, roll, pitch, yaw]
        self.vel = [0.0] * 6

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )

        # Arm velocity publishers (Cartesian)
        self.vel_pubs = {
            "left_arm": self.create_publisher(
                PoseVelocity, "/left_arm/left_arm_driver/in/cartesian_velocity", qos
            ),
            "right_arm": self.create_publisher(
                PoseVelocity, "/right_arm/right_arm_driver/in/cartesian_velocity", qos
            ),
        }
        # Arm velocity publishers (joint-space, used when lock_joint1=True)
        self.jvel_pubs = {
            "left_arm": self.create_publisher(
                JointVelocity, "/left_arm/left_arm_driver/in/joint_velocity", qos
            ),
            "right_arm": self.create_publisher(
                JointVelocity, "/right_arm/right_arm_driver/in/joint_velocity", qos
            ),
        }
        self.base_pub = self.create_publisher(Twist, "/cmd_vel", 100)

        # Arm services
        self.home_clients = {
            "left_arm": self.create_client(HomeArm, "/movo/home_left_arm"),
            "right_arm": self.create_client(HomeArm, "/movo/home_right_arm"),
        }
        self.home_both_client = self.create_client(HomeArm, "/movo/home_both_arms")
        self.stop_clients = {
            "left_arm": self.create_client(Stop, "/left_arm/left_arm_driver/in/stop"),
            "right_arm": self.create_client(Stop, "/right_arm/right_arm_driver/in/stop"),
        }
        self.start_clients = {
            "left_arm": self.create_client(Start, "/left_arm/left_arm_driver/in/start"),
            "right_arm": self.create_client(Start, "/right_arm/right_arm_driver/in/start"),
        }

        # Gripper action clients
        self.finger_clients = {
            "left_arm": ActionClient(
                self, SetFingersPosition, "/left_arm/left_arm_driver/fingers_action/finger_positions"
            ),
            "right_arm": ActionClient(
                self, SetFingersPosition, "/right_arm/right_arm_driver/fingers_action/finger_positions"
            ),
        }

        self.create_subscription(Joy, "/joy", self.joy_callback, qos)
        for arm in ("left_arm", "right_arm"):
            self.create_subscription(
                JointAngles,
                f"/{arm}/{arm}_driver/out/joint_angles",
                lambda msg, a=arm: self._on_joint_angles(a, msg),
                qos,
            )
        self.create_timer(0.01, self.publish_velocity)

        self._axis_spec = {
            "left_arm": (
                movo_linear_axis_map_for_arm("left_arm")
                if self._use_yaml_teleop
                else "x,y,z"
            ),
            "right_arm": (
                movo_linear_axis_map_for_arm("right_arm")
                if self._use_yaml_teleop
                else "x,y,z"
            ),
        }
        self.get_logger().info(
            f"MOVO movo_linear_axis_map (home_joints.yaml): left={self._axis_spec['left_arm']} "
            f"right={self._axis_spec['right_arm']}"
        )

        self._log_counter = 0
        self.get_logger().info("=== MoVo Xbox Controller STARTED ===")

    # ── Joy input ──

    def joy_callback(self, msg: Joy):
        self.last_joy_time = self.get_clock().now()

        if len(msg.buttons) > len(self.prev_buttons):
            self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        def axis(i, scale):
            val = msg.axes[i] if i < len(msg.axes) else 0.0
            return 0.0 if abs(val) < 0.1 else val * scale

        def dpad(i):
            """D-pad axes are digital: -1, 0, or 1."""
            return msg.axes[i] if i < len(msg.axes) else 0.0

        def trigger_pressed(i):
            """Trigger axes: 1.0 = released, -1.0 = fully pressed."""
            return i < len(msg.axes) and msg.axes[i] < 0.0

        def pressed(i):
            return i < len(msg.buttons) and msg.buttons[i] == 1 and self.prev_buttons[i] == 0

        # X (2) → cycle mode
        if pressed(2):
            self.mode_index = (self.mode_index + 1) % len(MODES)
            self.mode = MODES[self.mode_index]
            self.vel = [0.0] * 6
            self.get_logger().info(f"*** MODE: {self.mode} ***")

        if self.mode == "base":
            # RB held as deadman switch for base movement
            rb_held = len(msg.buttons) > 5 and msg.buttons[5] == 1
            if rb_held:
                self.vel[0] = axis(1, self.BASE_MAX_LIN)   # Left stick vert → drive
                self.vel[1] = axis(0, self.BASE_MAX_LIN)   # Left stick horiz → strafe
                self.vel[5] = axis(3, self.BASE_MAX_ANG)   # Right stick horiz → rotate
            else:
                self.vel = [0.0] * 6
        else:
            # ── Arm buttons ──
            if pressed(0):                                  # A → Start
                self.call_arm_service(self.start_clients, Start.Request(), "Start")
            if pressed(1):                                  # B → Emergency stop
                self.call_arm_service(self.stop_clients, Stop.Request(), "Stop")
            if pressed(5):                                  # RB → Home current arm
                self.start_homing()
                self.call_home()
            if pressed(4):                                  # LB double-tap → Home both
                now = time.monotonic()
                if now - self._btn4_last_press < 0.5:
                    self.get_logger().info("*** DOUBLE-TAP LB: Homing BOTH arms ***")
                    self.start_homing()
                    self.call_home_both()
                    self._btn4_last_press = 0.0
                else:
                    self._btn4_last_press = now

            # ── Sticks → leader linear (+x fwd,+y left,+z up); YAML movo_linear_axis_map → Kinova ──
            self.vel[0] = axis(1, self.MAX_LIN_VEL)        # leader x ← left stick vert
            self.vel[1] = axis(0, self.MAX_LIN_VEL)        # leader y ← left stick horiz
            self.vel[2] = axis(4, self.MAX_LIN_VEL)        # leader z ← right stick vert
            self.vel[5] = -axis(3, self.MAX_ANG_VEL)       # Right stick horiz → Yaw

            # ── D-pad → Roll / Pitch ──
            self.vel[3] = dpad(7) * self.MAX_ANG_VEL       # D-pad up/down → Roll
            self.vel[4] = dpad(6) * self.MAX_ANG_VEL       # D-pad left/right → Pitch

            # ── Triggers → Gripper (boolean: open / close) ──
            if trigger_pressed(5) and self.gripper_open:    # RT → Close
                self.send_gripper([self.FINGERS_CLOSED] * 3)
                self.gripper_open = False
                self.get_logger().info("Gripper CLOSED")
            elif trigger_pressed(2) and not self.gripper_open:  # LT → Open
                self.send_gripper([0.0, 0.0, 0.0])
                self.gripper_open = True
                self.get_logger().info("Gripper OPEN")

        self.prev_buttons = list(msg.buttons)

    # ── Homing ──

    def start_homing(self):
        self._homing = True
        self.vel = [0.0] * 6

    def call_home(self):
        client = self.home_clients[self.mode]
        if not client.wait_for_service(timeout_sec=0.8):
            self.get_logger().error("Home service not ready!")
            self._homing = False
            return
        future = client.call_async(HomeArm.Request())
        future.add_done_callback(self.on_service_done)

    def call_home_both(self):
        if not self.home_both_client.wait_for_service(timeout_sec=0.8):
            self.get_logger().error("home_both_arms service not ready!")
            self._homing = False
            return
        future = self.home_both_client.call_async(HomeArm.Request())
        future.add_done_callback(self.on_service_done)

    def on_service_done(self, future):
        self._homing = False
        try:
            resp = future.result()
            self.get_logger().info(f"Home response: {resp}")
        except Exception as e:
            self.get_logger().error(f"Home call failed: {e}")

    # ── Services ──

    def call_arm_service(self, client_dict, request, name):
        client = client_dict[self.mode]
        if client.service_is_ready():
            client.call_async(request)
            self.get_logger().info(f"[{self.mode}] {name} called")
        else:
            self.get_logger().error(f"[{self.mode}] {name} service not ready!")

    def send_gripper(self, target):
        if self.mode not in self.finger_clients:
            return
        client = self.finger_clients[self.mode]
        if not client.server_is_ready():
            return
        goal = SetFingersPosition.Goal()
        goal.fingers.finger1, goal.fingers.finger2, goal.fingers.finger3 = map(float, target)
        client.send_goal_async(goal)

    def _linear_kinova(self, arm: str) -> tuple[float, float, float]:
        """MOVO stick → Kinova linear; home_joints.yaml movo_linear_axis_map per arm."""
        vk = apply_linear(self.vel[:3], self._axis_spec[arm])
        return (vk[0], vk[1], vk[2])

    # ── Joint-angle feedback ──

    def _on_joint_angles(self, arm: str, msg: JointAngles):
        self.current_joint_deg[arm] = [
            msg.joint1, msg.joint2, msg.joint3, msg.joint4,
            msg.joint5, msg.joint6, msg.joint7,
        ]

    # ── Velocity publishing ──

    def publish_velocity(self):
        # Watchdog: zero if joy drops out
        dt = (self.get_clock().now() - self.last_joy_time).nanoseconds / 1e9
        if dt > 0.5:
            self.vel = [0.0] * 6

        if self.mode == "base":
            msg = Twist()
            msg.linear.x = self.vel[0]
            msg.linear.y = self.vel[1]
            msg.angular.z = self.vel[5]
            self.base_pub.publish(msg)
        elif not self._homing:
            if self._locked_joints:
                self._publish_joint_velocity()
            else:
                self._publish_cartesian_velocity()

        # Status log every 5 seconds
        self._log_counter += 1
        if self._log_counter >= 500:
            self._log_counter = 0
            self.get_logger().info(
                f"[{self.mode}] "
                f"lin=({self.vel[0]:.3f},{self.vel[1]:.3f},{self.vel[2]:.3f}) "
                f"ang=({self.vel[3]:.3f},{self.vel[4]:.3f},{self.vel[5]:.3f})"
            )

    def _publish_cartesian_velocity(self):
        lx, ly, lz = self._linear_kinova(self.mode)
        msg = PoseVelocity()
        msg.twist_linear_x = lx
        msg.twist_linear_y = ly
        msg.twist_linear_z = lz
        msg.twist_angular_x = self.vel[3]   # Roll
        msg.twist_angular_y = self.vel[4]   # Pitch
        msg.twist_angular_z = self.vel[5]   # Yaw
        self.vel_pubs[self.mode].publish(msg)

    def _publish_joint_velocity(self):
        q = self.current_joint_deg.get(self.mode)
        has_motion = False
        if q is not None:
            lx, ly, lz = self._linear_kinova(self.mode)
            v_cart = np.array([
                lx, ly, lz,
                self.vel[3], self.vel[4], self.vel[5],
            ])
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
                self.jvel_pubs[self.mode].publish(jmsg)
                self._jvel_stop_count = 10

        if not has_motion and self._jvel_stop_count > 0:
            self.jvel_pubs[self.mode].publish(JointVelocity())
            self._jvel_stop_count -= 1


def main(args=None):
    rclpy.init(args=args)
    node = MovoXboxController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
