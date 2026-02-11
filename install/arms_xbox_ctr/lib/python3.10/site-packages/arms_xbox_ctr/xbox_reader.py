#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
from rclpy.time import Time

import kinova_msgs.msg
from sensor_msgs.msg import Joy
from kinova_msgs.msg import PoseVelocity
from kinova_msgs.action import SetFingersPosition
from kinova_msgs.srv import HomeArm, Stop,Start



""" Xbox controller with the following code.

Index i      Button array msg.buttons[i] Values: 0 or 1       
0            A                               
1            B  ---> emergnecy stop button!                            
2            X  --> swap arm control                                
3            Y                                  
4            left top trigger
5            Right top trigger --> Home
6            Select (Pause)
7           Start (Menu)
8            
9            
10           
11           
12           
13           
14           

* Empty bindings

remapping not down under 
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
        super().__init__('xbox_velocity_controller')

        self.arm_namespace = 'left_arm'
        
        # --- CONFIGURATION ---
        self.MAX_LIN_VEL = 0.08  # 8 cm/s max speed
        self.MAX_ANG_VEL = 0.20  # ~11 degrees/s rotation speed (adjust as needed)
        
        # STATE TRACKING
        self.prev_buttons = [0] * 15
        self.last_gripper_cmd = None
        self.last_joy_msg_time = self.get_clock().now()

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

        # Joy subscriber
        self.joy_subscription = self.create_subscription(
            Joy, '/joy', self.joy_callback, qos_profile)

        # Velocities
        self.linear_x = 0.0
        self.linear_y = 0.0
        self.linear_z = 0.0
        self.angular_x = 0.0
        self.angular_y = 0.0
        self.angular_z = 0.0

        # Timer
        self.timer_period = 1.0 / ros_rate
        self.timer = self.create_timer(self.timer_period, self.publish_velocity)

        self.get_logger().info('=== Xbox Velocity Controller STARTED ===')
        self.get_logger().info(f'Max Linear Speed: {self.MAX_LIN_VEL} m/s')

    def joy_callback(self, msg: Joy):
        self.last_joy_msg_time = self.get_clock().now()
        
        # Padding safety
        if len(msg.buttons) > len(self.prev_buttons):
             self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        # --- HELPER: Apply Deadzone & Scale ---
        def get_axis(index, max_val):
            val = msg.axes[index]
            # Deadzone of 0.1 to prevent drift
            if abs(val) < 0.1:
                return 0.0
            return val * max_val

        # ---------------------------------------------------------
        # NEW AXIS MAPPING
        # ---------------------------------------------------------
        
        # Left Stick (Axis 0 & 1) -> Linear X/Y
        # Axis 1 is usually inverted (-1 is up/forward)
        self.linear_x = get_axis(1, self.MAX_LIN_VEL)   # Forward/Back
        self.linear_y = get_axis(0, self.MAX_LIN_VEL)   # Left/Right

        # Right Stick (Axis 3 & 4) -> Linear Z & Angular Z
        # Axis 4 (Vertical) -> Linear Z (Height)
        self.linear_z = get_axis(4, self.MAX_LIN_VEL)   
        
        # Axis 3 (Horizontal) -> Angular Z (Rotation)
        # I added this so you can still rotate the wrist!
        self.angular_z = -get_axis(3, self.MAX_ANG_VEL) 

        # Zero out other angulars for now (unless you want pitch/roll on triggers?)
        self.angular_x = 0.0
        self.angular_y = 0.0

        # ---------------------------------------------------------
        # BUTTON LOGIC
        # ---------------------------------------------------------
        def is_pressed(index):
            if index >= len(msg.buttons): return False
            return msg.buttons[index] == 1 and self.prev_buttons[index] == 0

        # A Button (Index 0) -> START
        if is_pressed(0):
            self.call_service(self.start_clients, "Start")

        # B Button (Index 1) -> STOP (Emergency)
        if is_pressed(1):
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
    # I combined the service callers to make the code cleaner
    def call_service(self, client_dict, service_name):
        self.get_logger().info(f"--- Initiating {service_name} request for {self.arm_namespace} ---")
        client = client_dict[self.arm_namespace]
        
        if not client.service_is_ready():
            self.get_logger().error(f"[FAIL] {service_name} service not ready!")
            return
            
        # Dynamically create the correct request type
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
        # Watchdog: Stop if no msg for 0.5s
        time_diff = (self.get_clock().now() - self.last_joy_msg_time).nanoseconds / 1e9
        if time_diff > 0.5:
            self.linear_x = 0.0; self.linear_y = 0.0; self.linear_z = 0.0
            self.angular_x = 0.0; self.angular_y = 0.0; self.angular_z = 0.0

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
    xbox_controller = XboxVelocityController()
    try:
        rclpy.spin(xbox_controller)
    except KeyboardInterrupt:
        pass
    finally:
        xbox_controller.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()