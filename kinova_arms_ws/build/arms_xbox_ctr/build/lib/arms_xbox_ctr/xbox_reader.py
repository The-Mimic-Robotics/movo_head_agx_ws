#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy

#import kinova_msgs_ros2.msg
import kinova_msgs.msg
from sensor_msgs.msg import Joy
from kinova_msgs.msg import PoseVelocity
from kinova_msgs.action import SetFingersPosition
from kinova_msgs.srv import HomeArm, Stop

""" Xbox controller with the following code.

Index i      Button array msg.buttons[i] Values: 0 or 1       
0            A                                 
1            B                              
2            C*                                  
3            X                                  
4            Y
5            Z*
6            BL (Button Left)
7            BR (Button Right)
8            BL2*
9            BR2*
10           Select (Pause)
11           Start (Menu)
12           Mode (Xbox logo)
13           ThumbL (L3)
14           ThumbR (R3)

* Empty bindings

Intex i     Axis array msg.axes[i]          Values 
0           -X/X (Right/Left) Left Stick    Norm(-32767, 32767) = [-1,1]
1           -Y/Y (Up/Down) Left Stick       Norm(32767, -32767) = [-1,1]
2           -X/X (Right/Left) Right Stick   Norm(32767, -32767) = [-1,1]
3           -Y/Y (Up/Down) Right Stick      Norm(32767, -32767) = [-1,1]
4           RT                              [1.0, -1.0], No press= 1.0
5           LT                              [1.0, -1.0], No press= 1.0
6           Right/Left Pad Key              (-1, 1), No press= 0.0
7           Up/Down Pad Key                 (-1, 1), No press= 0.0

"""

class XboxVelocityController(Node):
    def __init__(self, fingers_closed_pos: int = 5000, ros_rate: int = 100):
        """Initialize a xbox controller class. 
        Movo will by default start with left arm controlled.
        Assumes open fingers.

        Args:
            fingers_closed_pos (int, optional): Close command send to the gripper.
                Increase for harder grasp. Min 0, max 6500. Defaults to 5000.
            ros_rate (int, optional): ROS update rate. Defaults to 100.
        """
        super().__init__('xbox_velocity_controller')

        self.arm_namespace = 'left_arm'
        self.prev_x_pressed = True  

        # QoS profile for reliable communication
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1
        )

        # Publishers
        self.velocity_pubs = {
            "left_arm": self.create_publisher(
                PoseVelocity,
                "/left_arm/left_arm_driver/in/cartesian_velocity",
                qos_profile),
            "right_arm": self.create_publisher(
                PoseVelocity,
                "/right_arm/right_arm_driver/in/cartesian_velocity",
                qos_profile),
        }

        # Service clients
        self.home_clients = {
            "left_arm": self.create_client(
                HomeArm, "/left_arm/left_arm_driver/in/home_arm"),
            "right_arm": self.create_client(
                HomeArm, "/right_arm/right_arm_driver/in/home_arm"),
        }
        self.stop_clients = {
            "left_arm": self.create_client(
                Stop, "/left_arm/left_arm_driver/in/stop"),
            "right_arm": self.create_client(
                Stop, "/right_arm/right_arm_driver/in/stop"),
        }

        # Action clients
        left_fingers = "/left_arm/left_arm_driver/fingers_action/finger_positions"
        right_fingers = "/right_arm/right_arm_driver/fingers_action/finger_positions"

        self.finger_clients = {
            "left_arm": ActionClient(
                self, SetFingersPosition, left_fingers),
            "right_arm": ActionClient(
                self, SetFingersPosition, right_fingers),
        }

        # Wait for services and action servers
        self.wait_for_services_and_actions()
       
        self.last_finger_pos = {
            "left_arm": [0, 0, 0],
            "right_arm": [0, 0, 0],
        }
        self.fingers_closed_pos = fingers_closed_pos

        # Joy subscriber
        self.joy_subscription = self.create_subscription(
            Joy,
            '/joy',
            self.joy_callback,
            qos_profile)

        # Initial twist values
        self.linear_x = 0.0
        self.linear_y = 0.0
        self.linear_z = 0.0
        self.angular_x = 0.0
        self.angular_y = 0.0
        self.angular_z = 0.0

        # Timer for publishing velocity commands
        self.timer_period = 1.0 / ros_rate  # seconds
        self.timer = self.create_timer(self.timer_period, self.publish_velocity)

        self.get_logger().info('Xbox Velocity Controller initialized')

    def wait_for_services_and_actions(self):
        """Wait for all services and action servers to be available."""
        
        # Wait for services
        services_to_wait = [
            (self.home_clients["left_arm"], "/left_arm/left_arm_driver/in/home_arm"),
            (self.home_clients["right_arm"], "/right_arm/right_arm_driver/in/home_arm"),
            (self.stop_clients["left_arm"], "/left_arm/left_arm_driver/in/stop"),
            (self.stop_clients["right_arm"], "/right_arm/right_arm_driver/in/stop"),
        ]

        for client, service_name in services_to_wait:
            self.get_logger().info(f"Waiting for service {service_name}")
            while not client.wait_for_service(timeout_sec=1.0):
                self.get_logger().info(f"Service {service_name} not available, waiting...")

        # Wait for action servers
        actions_to_wait = [
            (self.finger_clients["left_arm"], "left_arm fingers"),
            (self.finger_clients["right_arm"], "right_arm fingers"),
        ]

        for client, name in actions_to_wait:
            self.get_logger().info(f"Waiting for action server {name}")
            while not client.wait_for_server(timeout_sec=1.0):
                self.get_logger().info(f"Action server {name} not available, waiting...")

        self.get_logger().info("All services and action servers are available")

    def joy_callback(self, msg: Joy):
        """Translate ``/joy`` message into velocity & service calls."""

        # ─ Linear XY (left‑stick)
        self.linear_x = msg.axes[0]  # Up ↑ / Down ↓  (stick Y)
        self.linear_y = msg.axes[1]  # Left ↔ Right   (stick X)

        # ─ Linear Z (triggers)
        rt = (1.0 - msg.axes[4]) * 0.5  # RT  1→0  −1→1  (forward)
        lt = (1.0 - msg.axes[5]) * 0.5  # LT  1→0  −1→1  (backward)
        self.linear_z = rt - lt
        if abs(self.linear_z) < 0.05:   # dead‑band ≈ 5 %
            self.linear_z = 0.0

        # ─ Angular XY (R‑stick)
        self.angular_x = msg.axes[3]   # Roll  (stick X)
        self.angular_y = -msg.axes[2]  # Pitch (stick Y)

        # ─ Gripper (D‑pad U/D)
        if msg.axes[7] > 0.5:                      # D-pad UP  → open
            self.gripper_client([0, 0, 0])
        elif msg.axes[7] < -0.5:                   # D-pad DOWN → close
            self.gripper_client([self.fingers_closed_pos]*3)
        elif msg.axes[6] > 0.5:                    # D-pad RIGHT → rotate CW
            self.angular_z = 1.0
        elif msg.axes[6] < -0.5:                   # D-pad LEFT  → rotate CCW
            self.angular_z = -1.0
        else:
            self.angular_z = 0.0

        # ─ Arm toggle (X)
        x_pressed = msg.buttons[3]
        if x_pressed and not self.prev_x_pressed:
            self.arm_namespace = (
                "left_arm" if self.arm_namespace == "right_arm" else "right_arm"
            )
            self.get_logger().info(f"[Xbox] Switched control to **{self.arm_namespace}**")
        self.prev_x_pressed = x_pressed

        # ─ Emergency stop (Start)
        if msg.buttons[7]:
            self.call_stop_service()
            self.get_logger().warn("[Xbox] EMERGENCY STOP sent to current arm!")

        # ─ Home (Back)
        if msg.buttons[6]:
            self.get_logger().info("[Xbox] Homing current arm…")
            self.call_home_service()

    def call_home_service(self):
        """Call home service for the current arm."""
        client = self.home_clients[self.arm_namespace]
        if client.service_is_ready():
            request = HomeArm.Request()
            future = client.call_async(request)
            # Note: In ROS2, we typically don't block on service calls in callbacks
            # The future will complete asynchronously
        else:
            self.get_logger().warn(f"Home service for {self.arm_namespace} not ready")

    def call_stop_service(self):
        """Call stop service for the current arm."""
        client = self.stop_clients[self.arm_namespace]
        if client.service_is_ready():
            request = Stop.Request()
            future = client.call_async(request)
            # Note: In ROS2, we typically don't block on service calls in callbacks
            # The future will complete asynchronously
        else:
            self.get_logger().warn(f"Stop service for {self.arm_namespace} not ready")

    def gripper_client(self, target):
        """Send a *SetFingersPosition* action goal to the active arm.

        Args:
            target: list[int]
                Desired position for fingers 1-3 (0 = open … 6500 ≈ closed).
        """
        # Pick the pre-created client for the selected arm
        client = self.finger_clients[self.arm_namespace]
        
        if not client.server_is_ready():
            self.get_logger().warn(f"Action server for {self.arm_namespace} fingers not ready")
            return

        # Build & send the goal
        goal_msg = SetFingersPosition.Goal()
        goal_msg.fingers.finger1 = float(target[0])
        goal_msg.fingers.finger2 = float(target[1])
        goal_msg.fingers.finger3 = float(target[2])

        # Send goal asynchronously
        future = client.send_goal_async(goal_msg)
        # Note: In ROS2, we typically don't block on action calls in callbacks
        # The future will complete asynchronously

    def publish_velocity(self):
        """Timer callback to send twist commands based on xbox controller readings."""
        velocity_msg = PoseVelocity()
        velocity_msg.twist_linear_x = self.linear_x
        velocity_msg.twist_linear_y = self.linear_y
        velocity_msg.twist_linear_z = self.linear_z
        velocity_msg.twist_angular_x = self.angular_x
        velocity_msg.twist_angular_y = self.angular_y
        velocity_msg.twist_angular_z = self.angular_z

        self.velocity_pubs[self.arm_namespace].publish(velocity_msg)


def main(args=None):
    rclpy.init(args=args)
    
    try:
        xbox_controller = XboxVelocityController()
        rclpy.spin(xbox_controller)
    except KeyboardInterrupt:
        pass
    finally:
        # Clean shutdown
        if 'xbox_controller' in locals():
            xbox_controller.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
