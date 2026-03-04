#!/usr/bin/env python3
"""
Xbox controller for MOVO robot (two Jaco arms + mobile base).

X cycles control target: left_arm → right_arm → base → ...

ARM MODE — full 6DOF Cartesian velocity:
  Left stick vertical    X  (forward / back)
  Left stick horizontal  Y  (left / right)
  Right stick vertical   Z  (up / down)
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

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy

from geometry_msgs.msg import Twist
from kinova_msgs.action import SetFingersPosition
from kinova_msgs.msg import PoseVelocity
from kinova_msgs.srv import HomeArm, Start, Stop
from sensor_msgs.msg import Joy

MODES = ["left_arm", "right_arm", "base"]


class MovoXboxController(Node):
    def __init__(self):
        super().__init__("movo_xbox_controller")

        self.mode_index = 0
        self.mode = MODES[0]

        self.MAX_LIN_VEL = 0.08
        self.MAX_ANG_VEL = 0.20
        self.BASE_MAX_LIN = 1.0
        self.BASE_MAX_ANG = 1.0
        self.FINGERS_CLOSED = 5000.0

        self.prev_buttons = [0] * 15
        self.gripper_open = True
        self.last_joy_time = self.get_clock().now()
        self._btn4_last_press = 0.0
        self._homing = False

        # 6DOF velocity: [x, y, z, roll, pitch, yaw]
        self.vel = [0.0] * 6

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )

        # Arm velocity publishers
        self.vel_pubs = {
            "left_arm": self.create_publisher(
                PoseVelocity, "/left_arm/left_arm_driver/in/cartesian_velocity", qos
            ),
            "right_arm": self.create_publisher(
                PoseVelocity, "/right_arm/right_arm_driver/in/cartesian_velocity", qos
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
        self.create_timer(0.01, self.publish_velocity)

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

            # ── Sticks → Translation + Yaw ──
            self.vel[0] = axis(1, self.MAX_LIN_VEL)        # Left stick vert → X
            self.vel[1] = axis(0, self.MAX_LIN_VEL)        # Left stick horiz → Y
            self.vel[2] = axis(4, self.MAX_LIN_VEL)        # Right stick vert → Z
            self.vel[5] = -axis(3, self.MAX_ANG_VEL)       # Right stick horiz → Yaw

            # ── D-pad → Roll / Pitch ──
            self.vel[3] = dpad(6) * self.MAX_ANG_VEL       # D-pad left/right → Roll
            self.vel[4] = dpad(7) * self.MAX_ANG_VEL       # D-pad up/down → Pitch

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
            msg = PoseVelocity()
            msg.twist_linear_x = self.vel[0]
            msg.twist_linear_y = self.vel[1]
            msg.twist_linear_z = self.vel[2]
            msg.twist_angular_x = self.vel[3]   # Roll
            msg.twist_angular_y = self.vel[4]   # Pitch
            msg.twist_angular_z = self.vel[5]   # Yaw
            self.vel_pubs[self.mode].publish(msg)

        # Status log every 5 seconds
        self._log_counter += 1
        if self._log_counter >= 500:
            self._log_counter = 0
            self.get_logger().info(
                f"[{self.mode}] "
                f"lin=({self.vel[0]:.3f},{self.vel[1]:.3f},{self.vel[2]:.3f}) "
                f"ang=({self.vel[3]:.3f},{self.vel[4]:.3f},{self.vel[5]:.3f})"
            )


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
