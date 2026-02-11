#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
import socket
import struct
import threading
import time

import kinova_msgs.msg
from sensor_msgs.msg import Joy
from kinova_msgs.msg import PoseVelocity
from kinova_msgs.action import SetFingersPosition
from kinova_msgs.srv import HomeArm, Stop, Start

class XboxAndUDPController(Node):
    def __init__(self, fingers_closed_pos: int = 5000, ros_rate: int = 100):
        super().__init__('xbox_udp_controller')

        self.arm_namespace = 'left_arm'
        
        # --- CONFIGURATION ---
        self.MAX_LIN_VEL = 0.08  # 8 cm/s max speed
        self.MAX_ANG_VEL = 0.20  # ~11 degrees/s rotation speed
        
        # UDP CONFIG
        self.UDP_IP = "0.0.0.0" # Listen on all interfaces
        self.UDP_PORT = 5005
        # CRITICAL: Scaling factor. 
        # If your device sends "1.0" for x, we probably don't want 1.0 m/s velocity.
        # Adjust this so that your device's range maps comfortably to speed.
        self.UDP_SCALE = 1.0 
        
        # STATE TRACKING
        self.prev_buttons = [0] * 15
        self.last_gripper_cmd = None
        self.last_cmd_time = time.time() # Shared watchdog for both Joy and UDP

        # QoS profile
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1
        )

        # Publishers
        self.velocity_pubs = {
            "left_arm": self.create_publisher(
                PoseVelocity, "/left_arm/left_arm_driver/in/cartesian_velocity", qos_profile),
            "right_arm": self.create_publisher(
                PoseVelocity, "/right_arm/right_arm_driver/in/cartesian_velocity", qos_profile),
        }

        # Service clients
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

        # Action clients
        self.finger_clients = {
            "left_arm": ActionClient(self, SetFingersPosition, "/left_arm/left_arm_driver/fingers_action/finger_positions"),
            "right_arm": ActionClient(self, SetFingersPosition, "/right_arm/right_arm_driver/fingers_action/finger_positions"),
        }

        self.fingers_closed_pos = fingers_closed_pos

        # Joy subscriber (ONLY for Buttons now)
        self.joy_subscription = self.create_subscription(
            Joy, '/joy', self.joy_callback, qos_profile)

        # Velocities
        self.linear_x = 0.0
        self.linear_y = 0.0
        self.linear_z = 0.0
        self.angular_x = 0.0
        self.angular_y = 0.0
        self.angular_z = 0.0

        # Start UDP Thread
        self.udp_thread = threading.Thread(target=self.receive_udp_data, daemon=True)
        self.udp_thread.start()

        # Timer
        self.timer_period = 1.0 / ros_rate
        self.timer = self.create_timer(self.timer_period, self.publish_velocity)

        self.get_logger().info('=== Xbox + UDP Controller STARTED ===')
        self.get_logger().info(f'UDP Listening on port: {self.UDP_PORT}')
        self.get_logger().info(f'Max Linear Speed: {self.MAX_LIN_VEL} m/s')

    def receive_udp_data(self):
        """
        Runs in background thread. Listens for 7 floats:
        x, y, z, qw, qx, qy, qz
        """
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.bind((self.UDP_IP, self.UDP_PORT))
        # Non-blocking so we can exit cleanly if needed, or use a select loop
        # For simplicity, we stick to blocking with a timeout or just standard blocking in daemon
        
        # Expected struct format: 7 floats (Little Endian)
        fmt = '<fffffff'
        struct_len = struct.calcsize(fmt)

        self.get_logger().info("UDP Thread waiting for data...")

        while rclpy.ok():
            try:
                data, addr = sock.recvfrom(1024)
                if len(data) == struct_len:
                    # Unpack
                    x, y, z, qw, qx, qy, qz = struct.unpack(fmt, data)
                    
                    # --- MAPPING STRATEGY ---
                    # We interpret the incoming X, Y, Z as velocity inputs.
                    # We clamp them to MAX_LIN_VEL for safety.
                    
                    def clamp(val, limit):
                        return max(min(val, limit), -limit)

                    self.linear_x = clamp(x * self.UDP_SCALE, self.MAX_LIN_VEL)
                    self.linear_y = clamp(y * self.UDP_SCALE, self.MAX_LIN_VEL)
                    self.linear_z = clamp(z * self.UDP_SCALE, self.MAX_LIN_VEL)
                    
                    # TODO: Map Quaternions (qw, qx, qy, qz) to Angular Velocity if desired later.
                    # For now, user requested only X, Y, Z.
                    
                    self.last_cmd_time = time.time()
                else:
                    self.get_logger().warn(f"Received UDP packet of wrong size: {len(data)} bytes")
            except Exception as e:
                self.get_logger().error(f"UDP Error: {e}")
                time.sleep(1)

    def joy_callback(self, msg: Joy):
        # NOTE: We do NOT update self.last_cmd_time here merely for button presses
        # because we want the watchdog to stop the robot if the UDP stream dies,
        # even if buttons are being pressed. 
        # However, if you want buttons to keep the connection "alive", uncomment below:
        # self.last_cmd_time = time.time()
        
        # Padding safety
        if len(msg.buttons) > len(self.prev_buttons):
             self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        # ---------------------------------------------------------
        # BUTTON LOGIC (Copied from previous script)
        # ---------------------------------------------------------
        def is_pressed(index):
            if index >= len(msg.buttons): return False
            return msg.buttons[index] == 1 and self.prev_buttons[index] == 0

        # A Button (Index 0) -> START
        if is_pressed(0):
            self.call_service(self.start_clients, "Start")

        # B Button (Index 1) -> STOP (Emergency)
        if is_pressed(1):
            # Force velocity to zero immediately
            self.linear_x = 0.0; self.linear_y = 0.0; self.linear_z = 0.0
            self.call_service(self.stop_clients, "Stop")

        # X Button (Index 2) -> SWAP ARM
        if is_pressed(2): 
            self.arm_namespace = "left_arm" if self.arm_namespace == "right_arm" else "right_arm"
            self.get_logger().info(f"*** SWITCHED ARM to: {self.arm_namespace} ***")

        # RB Button (Index 5) -> HOME
        if is_pressed(5):
            self.call_service(self.home_clients, "Home")

        # Gripper (D-Pad Vertical - Axis 7)
        current_gripper_cmd = None
        if len(msg.axes) > 7:
            if msg.axes[7] > 0.5:
                current_gripper_cmd = "OPEN"
            elif msg.axes[7] < -0.5:
                current_gripper_cmd = "CLOSE"
        
        if current_gripper_cmd and current_gripper_cmd != self.last_gripper_cmd:
            if current_gripper_cmd == "OPEN":
                self.gripper_client([0, 0, 0])
            else:
                self.gripper_client([self.fingers_closed_pos]*3)
            self.last_gripper_cmd = current_gripper_cmd
        elif current_gripper_cmd is None:
             self.last_gripper_cmd = None

        self.prev_buttons = list(msg.buttons)

    # --- GENERIC SERVICE CALLER ---
    def call_service(self, client_dict, service_name):
        self.get_logger().info(f"--- Initiating {service_name} request for {self.arm_namespace} ---")
        client = client_dict[self.arm_namespace]
        
        if not client.service_is_ready():
            self.get_logger().error(f"[FAIL] {service_name} service not ready!")
            return
            
        if service_name == "Home":
            request = HomeArm.Request()
        elif service_name == "Stop":
            request = Stop.Request()
        elif service_name == "Start":
            request = Start.Request()
            
        future = client.call_async(request)
        future.add_done_callback(lambda f: self.service_response_callback(f, service_name))

    def service_response_callback(self, future, service_name):
        try:
            response = future.result()
            self.get_logger().info(f"[SUCCESS] {service_name} responded: {response}")
        except Exception as e:
            self.get_logger().error(f"[CRITICAL] {service_name} call failed: {e}")

    def gripper_client(self, target):
        client = self.finger_clients[self.arm_namespace]
        if not client.server_is_ready():
            return
        goal_msg = SetFingersPosition.Goal()
        goal_msg.fingers.finger1, goal_msg.fingers.finger2, goal_msg.fingers.finger3 = map(float, target)
        client.send_goal_async(goal_msg)

    def publish_velocity(self):
        # Watchdog: Stop if no data received for 0.5s (Joystick OR UDP)
        current_time = time.time()
        time_diff = current_time - self.last_cmd_time
        
        if time_diff > 0.5:
            # Safety stop
            self.linear_x = 0.0; self.linear_y = 0.0; self.linear_z = 0.0
            self.angular_x = 0.0; self.angular_y = 0.0; self.angular_z = 0.0

        velocity_msg = PoseVelocity()
        velocity_msg.twist_linear_x = float(self.linear_x)
        velocity_msg.twist_linear_y = float(self.linear_y)
        velocity_msg.twist_linear_z = float(self.linear_z)
        velocity_msg.twist_angular_x = float(self.angular_x)
        velocity_msg.twist_angular_y = float(self.angular_y)
        velocity_msg.twist_angular_z = float(self.angular_z)

        self.velocity_pubs[self.arm_namespace].publish(velocity_msg)

def main(args=None):
    rclpy.init(args=args)
    controller = XboxAndUDPController()
    try:
        rclpy.spin(controller)
    except KeyboardInterrupt:
        pass
    finally:
        controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()