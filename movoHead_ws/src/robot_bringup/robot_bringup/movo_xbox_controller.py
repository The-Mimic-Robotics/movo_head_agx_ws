#!/usr/bin/env python3
"""
Unified Xbox controller for MOVO robot.
X button cycles control between: left_arm -> right_arm -> base -> left_arm ...
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

        self.prev_buttons = [0] * 15
        self.last_gripper_cmd = None
        self.last_joy_msg_time = self.get_clock().now()

        self.linear_x = 0.0
        self.linear_y = 0.0
        self.linear_z = 0.0
        self.angular_x = 0.0
        self.angular_y = 0.0
        self.angular_z = 0.0

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )

        self.velocity_pubs = {
            "left_arm": self.create_publisher(
                PoseVelocity, "/left_arm/left_arm_driver/in/cartesian_velocity", qos_profile
            ),
            "right_arm": self.create_publisher(
                PoseVelocity, "/right_arm/right_arm_driver/in/cartesian_velocity", qos_profile
            ),
        }

        self.base_vel_pub = self.create_publisher(Twist, "/cmd_vel", 100)

        self.home_clients = {
            "left_arm": self.create_client(HomeArm, "/left_arm/left_arm_driver/in/home_arm"),
            "right_arm": self.create_client(HomeArm, "/right_arm/right_arm_driver/in/home_arm"),
        }
        self.stop_clients = {
            "left_arm": self.create_client(Stop, "/left_arm/left_arm_driver/in/stop"),
            "right_arm": self.create_client(Stop, "/right_arm/right_arm_driver/in/stop"),
        }
        self.start_clients = {
            "left_arm": self.create_client(Start, "/left_arm/left_arm_driver/in/start"),
            "right_arm": self.create_client(Start, "/right_arm/right_arm_driver/in/start"),
        }

        self.finger_clients = {
            "left_arm": ActionClient(
                self, SetFingersPosition, "/left_arm/left_arm_driver/fingers_action/finger_positions"
            ),
            "right_arm": ActionClient(
                self, SetFingersPosition, "/right_arm/right_arm_driver/fingers_action/finger_positions"
            ),
        }
        self.fingers_closed_pos = 5000

        self.create_subscription(Joy, "/joy", self.joy_callback, qos_profile)
        self.create_timer(1.0 / 100.0, self.publish_velocity)

        self._log_counter = 0
        self.get_logger().info("=== MoVo Xbox Controller STARTED ===")

    def joy_callback(self, msg: Joy):
        self.last_joy_msg_time = self.get_clock().now()

        if len(msg.buttons) > len(self.prev_buttons):
            self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        def get_axis(index, max_val):
            val = msg.axes[index]
            if abs(val) < 0.1:
                return 0.0
            return val * max_val

        def is_pressed(index):
            if index >= len(msg.buttons):
                return False
            return msg.buttons[index] == 1 and self.prev_buttons[index] == 0

        if is_pressed(2):
            self.mode_index = (self.mode_index + 1) % len(MODES)
            self.mode = MODES[self.mode_index]
            self.linear_x = 0.0
            self.linear_y = 0.0
            self.linear_z = 0.0
            self.angular_x = 0.0
            self.angular_y = 0.0
            self.angular_z = 0.0
            self.get_logger().info(f"*** SWITCHED MODE to: {self.mode} ***")

        if self.mode == "base":
            rb_held = len(msg.buttons) > 5 and msg.buttons[5] == 1
            if rb_held:
                self.linear_x = get_axis(1, self.BASE_MAX_LIN)
                self.linear_y = get_axis(0, self.BASE_MAX_LIN)
                self.angular_z = get_axis(3, self.BASE_MAX_ANG)
            else:
                self.linear_x = 0.0
                self.linear_y = 0.0
                self.angular_z = 0.0
            self.linear_z = 0.0
            self.angular_x = 0.0
            self.angular_y = 0.0
        else:
            self.linear_x = get_axis(1, self.MAX_LIN_VEL)
            self.linear_y = get_axis(0, self.MAX_LIN_VEL)
            self.linear_z = get_axis(4, self.MAX_LIN_VEL)
            self.angular_z = -get_axis(3, self.MAX_ANG_VEL)
            self.angular_x = 0.0
            self.angular_y = 0.0

            if is_pressed(0):
                self.call_service(self.start_clients, "Start")
            if is_pressed(1):
                self.call_service(self.stop_clients, "Stop")
            if is_pressed(5):
                self.call_service(self.home_clients, "Home")

            current_gripper_cmd = None
            if len(msg.axes) > 7 and msg.axes[7] > 0.5:
                current_gripper_cmd = "OPEN"
            elif len(msg.axes) > 7 and msg.axes[7] < -0.5:
                current_gripper_cmd = "CLOSE"

            if current_gripper_cmd and current_gripper_cmd != self.last_gripper_cmd:
                if current_gripper_cmd == "OPEN":
                    self.gripper_client([0, 0, 0])
                else:
                    self.gripper_client([self.fingers_closed_pos] * 3)
                self.last_gripper_cmd = current_gripper_cmd
            elif current_gripper_cmd is None:
                self.last_gripper_cmd = None

        self.prev_buttons = list(msg.buttons)

    def call_service(self, client_dict, service_name):
        client = client_dict[self.mode]
        if not client.service_is_ready():
            self.get_logger().error(f"[FAIL] {service_name} service not ready!")
            return
        if service_name == "Home":
            request = HomeArm.Request()
        elif service_name == "Stop":
            request = Stop.Request()
        else:
            request = Start.Request()

        future = client.call_async(request)
        future.add_done_callback(lambda f: self.service_response_callback(f, service_name))

    def service_response_callback(self, future, service_name):
        try:
            response = future.result()
            self.get_logger().info(f"[SUCCESS] {service_name} responded: {response}")
        except Exception as exc:
            self.get_logger().error(f"[CRITICAL] {service_name} call failed: {exc}")

    def gripper_client(self, target):
        client = self.finger_clients[self.mode]
        if not client.server_is_ready():
            return
        goal_msg = SetFingersPosition.Goal()
        goal_msg.fingers.finger1, goal_msg.fingers.finger2, goal_msg.fingers.finger3 = map(float, target)
        client.send_goal_async(goal_msg)

    def publish_velocity(self):
        time_diff = (self.get_clock().now() - self.last_joy_msg_time).nanoseconds / 1e9
        if time_diff > 0.5:
            self.linear_x = 0.0
            self.linear_y = 0.0
            self.linear_z = 0.0
            self.angular_x = 0.0
            self.angular_y = 0.0
            self.angular_z = 0.0

        if self.mode == "base":
            msg = Twist()
            msg.linear.x = self.linear_x
            msg.linear.y = self.linear_y
            msg.angular.z = self.angular_z
            self.base_vel_pub.publish(msg)
        else:
            velocity_msg = PoseVelocity()
            velocity_msg.twist_linear_x = self.linear_x
            velocity_msg.twist_linear_y = self.linear_y
            velocity_msg.twist_linear_z = self.linear_z
            velocity_msg.twist_angular_x = self.angular_x
            velocity_msg.twist_angular_y = self.angular_y
            velocity_msg.twist_angular_z = self.angular_z
            self.velocity_pubs[self.mode].publish(velocity_msg)

        self._log_counter += 1
        if self._log_counter >= 500:
            self._log_counter = 0
            self.get_logger().info(
                f"[{self.mode}] vel: x={self.linear_x:.3f} y={self.linear_y:.3f} "
                f"z={self.linear_z:.3f} az={self.angular_z:.3f}"
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
