#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy
import socket
import struct
import threading
import time
import numpy as np

import kinova_msgs.msg
from sensor_msgs.msg import Joy
from kinova_msgs.msg import PoseVelocity, JointVelocity, JointAngles
from kinova_msgs.action import SetFingersPosition
from kinova_msgs.srv import HomeArm, Stop, Start
from geometry_msgs.msg import PoseStamped
from arms_xbox_ctr.jaco_jacobian import cart_to_joint_vel

class XboxAndUDPController(Node):
    def __init__(self, fingers_closed_pos: int = 6000, ros_rate: int = 100):
        super().__init__('xbox_udp_controller')

        # Params (kept compatible with axe4_controller.launch.py)
        self.declare_parameter('arm_namespace', 'left_arm')
        self.declare_parameter('udp_ip', '127.0.0.1')
        self.declare_parameter('udp_port', 5005)
        self.declare_parameter('udp_eef_control', 'auto')   # auto | velocity | pose | position
        self.declare_parameter('speed', 1.0)
        self.declare_parameter('lock_joint1', True)
        self.declare_parameter('auto_arm_udp', True)
        self.declare_parameter('auto_start_arm', True)
        self.declare_parameter('require_joy_keepalive', False)
        self.declare_parameter('joy_timeout_sec', 1.0)

        # --- 1. CONFIGURATION ---
        self.arm_namespace = str(self.get_parameter('arm_namespace').value)
        self.MAX_LIN_VEL = 0.08  # Max speed 8 cm/s
        self.MAX_ANG_VEL = 0.20  # Max rotation speed
        self.lock_joint1 = bool(self.get_parameter('lock_joint1').value)
        self._max_joint_vel_deg = 120.0
        self.auto_arm_udp = bool(self.get_parameter('auto_arm_udp').value)
        self.auto_start_arm = bool(self.get_parameter('auto_start_arm').value)
        self.require_joy_keepalive = bool(self.get_parameter('require_joy_keepalive').value)
        self.joy_timeout_sec = float(self.get_parameter('joy_timeout_sec').value)
        
        # UDP Settings
        self.UDP_IP = str(self.get_parameter('udp_ip').value)
        self.UDP_PORT = int(self.get_parameter('udp_port').value)
        self.udp_eef_control = str(self.get_parameter('udp_eef_control').value).strip().lower()
        if self.udp_eef_control not in ('auto', 'velocity', 'pose', 'position'):
            self.udp_eef_control = 'auto'
        speed_scale = max(0.1, float(self.get_parameter('speed').value))
        self.UDP_GAIN = 2.0      # Sensitivity (2.0 = 5cm move -> 10cm/s command)
        self.DEADZONE = 0.005    # 5mm deadzone
        self.TWIST_GAIN = 12.0 * min(speed_scale, 5.0)
        
        # --- 2. STATE FLAGS ---
        self.teleop_active = bool(self.auto_arm_udp)  # default ON for UDP remote teleop
        self.homing = False         # True while arm is running a home trajectory
        self.udp_offset = None      # Calibration point
        self.prev_buttons = [0] * 15
        self.last_gripper_cmd = None
        
        # Watchdog
        self.last_joy_msg_time = time.time()
        self.current_joint_deg = None
        self._last_joint_feedback_time = 0.0
        self._last_joint_missing_warn_t = 0.0
        self._jvel_stop_count = 0
        self._last_rx_pose = None
        self._last_rx_twist = None
        self._last_out_cart = [0.0, 0.0, 0.0, 0.0]
        self._last_out_joint = [0.0] * 7
        self._udp_rx_total = 0
        self._udp_rx_pose = 0
        self._udp_rx_twist = 0
        self._udp_rx_other = 0
        self._last_udp_log_t = 0.0
        self._arm_started = False

        # --- 3. ROS SETUP ---
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1
        )

        # Publisher
        self.udp_pub = self.create_publisher(
            PoseStamped, 
            f"/{self.arm_namespace}/udp_position", 
            qos_profile)
        self.velocity_pub = self.create_publisher(
            PoseVelocity, 
            f"/{self.arm_namespace}/{self.arm_namespace}_driver/in/cartesian_velocity", 
            qos_profile
        )
        self.joint_velocity_pub = self.create_publisher(
            JointVelocity,
            f"/{self.arm_namespace}/{self.arm_namespace}_driver/in/joint_velocity",
            qos_profile,
        )

        # Services
        self.home_client = self.create_client(HomeArm, f"/movo/home_{self.arm_namespace}")
        self.stop_client = self.create_client(Stop, f"/{self.arm_namespace}/{self.arm_namespace}_driver/in/stop")
        self.start_client = self.create_client(Start, f"/{self.arm_namespace}/{self.arm_namespace}_driver/in/start")
        
        # Action Client (Gripper)
        self.finger_client_node = ActionClient(self, SetFingersPosition, f"/{self.arm_namespace}/{self.arm_namespace}_driver/fingers_action/finger_positions")

        self.fingers_closed_pos = fingers_closed_pos

        # Joy Subscriber
        self.create_subscription(Joy, '/joy', self.joy_callback, qos_profile)
        joint_qos = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
            depth=10,
        )
        self.create_subscription(
            JointAngles,
            f"/{self.arm_namespace}/{self.arm_namespace}_driver/out/joint_angles",
            self.joint_angles_callback,
            joint_qos,
        )
        # Compatibility for stacks that expose driver topics without the arm namespace prefix.
        self.create_subscription(
            JointAngles,
            f"/{self.arm_namespace}_driver/out/joint_angles",
            self.joint_angles_callback,
            joint_qos,
        )

        # Current Velocities
        self.vel_cmd = [0.0] * 6 # x, y, z, ax, ay, az

        # Start UDP Thread
        self.udp_thread = threading.Thread(target=self.receive_udp_data_and_transform_to_velocity, daemon=True)
        self.udp_thread.start()

        # Timer
        self.timer = self.create_timer(1.0 / ros_rate, self.publish_velocity)

        self.get_logger().info('=== Xbox + UDP Teleop Initialized ===')
        self.get_logger().info(
            f'UDP bind={self.UDP_IP}:{self.UDP_PORT} udp_eef_control={self.udp_eef_control} lock_joint1={self.lock_joint1}'
        )
        self.get_logger().info(
            f'teleop_active={self.teleop_active} require_joy_keepalive={self.require_joy_keepalive}'
        )
        # self.get_logger().info(f'Target: {self.arm_namespace} ONLY')
        # self.get_logger().info('*** SAFETY ON: Press "X" to ARM/DISARM Teleop ***')

    def receive_udp_data_and_transform_to_velocity(self):
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) # AF_INET = IPv4, SOCK_DGRAM = UDP
        sock.bind((self.UDP_IP, self.UDP_PORT)) # listen 
        sock.setblocking(False) # will not block ie code just moves on
        
        fmt = '<fffffff' # legacy pose packet: 7 floats, little-endian
        struct_len = struct.calcsize(fmt) # 28 bytes
        fmt_twist = '<c6f' # typed twist packet: b'T'+(vx,vy,vz,wx,wy,wz)
        twist_len = struct.calcsize(fmt_twist) # 25 bytes
        tagged_lengths = {13, 15, 25, 29} # P/T/J/I packets from typed UDP mode
        last_unexpected_warn = 0.0
        
        while rclpy.ok():
            try:
                # Loop to drain buffer (prevent backlog) and get latest packet
                data = None
                twist = None
                while True:
                    try:
                        chunk, _ = sock.recvfrom(1024)
                        self._udp_rx_total += 1
                        if len(chunk) == struct_len:
                            data = chunk
                            self._udp_rx_pose += 1
                        elif len(chunk) == twist_len and chunk[:1] == b'T':
                            _, vx, vy, vz, wx, wy, wz = struct.unpack(fmt_twist, chunk)
                            twist = (vx, vy, vz, wx, wy, wz)
                            self._last_rx_twist = twist
                            self._udp_rx_twist += 1
                        elif len(chunk) in tagged_lengths and chunk[:1] in (b"P", b"T", b"I", b"J"):
                            self._udp_rx_other += 1
                        else:
                            self._udp_rx_other += 1
                            now = time.time()
                            if now - last_unexpected_warn > 2.0:
                                last_unexpected_warn = now
                                self.get_logger().warn(
                                    f"DEBUG: Received packet of unexpected size {len(chunk)} bytes"
                                )
                    except BlockingIOError:
                        break
                
                # Velocity mode: prefer typed twist packets
                twist_mag = 0.0
                if twist is not None:
                    twist_mag = max(abs(twist[0]), abs(twist[1]), abs(twist[2]), abs(twist[5]))

                use_twist = (
                    self.teleop_active
                    and twist is not None
                    and (
                        self.udp_eef_control == 'velocity'
                        or (self.udp_eef_control == 'auto' and twist_mag > 1e-5)
                    )
                )

                if use_twist:
                    vx, vy, vz, wx, wy, wz = twist
                    self.vel_cmd[0] = max(min(vx * self.TWIST_GAIN, self.MAX_LIN_VEL), -self.MAX_LIN_VEL)
                    self.vel_cmd[1] = max(min(vy * self.TWIST_GAIN, self.MAX_LIN_VEL), -self.MAX_LIN_VEL)
                    self.vel_cmd[2] = max(min(vz * self.TWIST_GAIN, self.MAX_LIN_VEL), -self.MAX_LIN_VEL)
                    self.vel_cmd[5] = max(min(wz * self.TWIST_GAIN, self.MAX_ANG_VEL), -self.MAX_ANG_VEL)

                if data is None:
                    if self.udp_eef_control == 'velocity' and twist is None:
                        self.vel_cmd[0] = 0.0
                        self.vel_cmd[1] = 0.0
                        self.vel_cmd[2] = 0.0
                    time.sleep(0.01)
                    continue

                # Unpack: x, y, z, qw, qx, qy, qz
                vals = struct.unpack(fmt, data)
                self._last_rx_pose = vals
                
                # Publish PoseStamped end effector 
                msg = PoseStamped()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.header.frame_id = "base_link"
                msg.pose.position.x = vals[0]       # x
                msg.pose.position.y = vals[1]       # y
                msg.pose.position.z = vals[2]       # z
                msg.pose.orientation.w = vals[3]    # qw
                msg.pose.orientation.x = vals[4]    # qx
                msg.pose.orientation.y = vals[5]    # qy
                msg.pose.orientation.z = vals[6]    # qz
                self.udp_pub.publish(msg)
                
                curr_pos = vals[0:3]
                curr_angle = vals[3:]

                # LOGIC:
                # If Teleop is OFF, we just track the position but do NOT update velocity
                # If Teleop is ON, we calculate velocity based on offset
                
                if self.teleop_active and self.udp_offset and (self.udp_eef_control in ('pose', 'position') or (self.udp_eef_control == 'auto' and not use_twist)):
                    dx = curr_pos[0] - self.udp_offset[0]
                    dy = curr_pos[1] - self.udp_offset[1]
                    dz = curr_pos[2] - self.udp_offset[2]

                    def calc_vel(delta):
                        if abs(delta) < self.DEADZONE: return 0.0
                        v = delta * self.UDP_GAIN
                        return max(min(v, self.MAX_LIN_VEL), -self.MAX_LIN_VEL)

                    # Update LINEAR velocities (Indices 0, 1, 2)
                    self.vel_cmd[0] = calc_vel(dx) # X
                    self.vel_cmd[1] = calc_vel(dy) # Y
                    self.vel_cmd[2] = calc_vel(dz) # Z
                elif self.udp_eef_control in ('auto', 'pose', 'position'):
                    # If not active, zero out linear velocity
                    self.vel_cmd[0] = 0.0
                    self.vel_cmd[1] = 0.0
                    self.vel_cmd[2] = 0.0
                    
                    # Update offset constantly while inactive so we are ready to start
                    # OR we can update it only when button is pressed. 
                    # Let's update it ONLY when button is pressed (in joy_callback) for safety.

            except Exception as e:
                pass
            time.sleep(0.005)

    def joy_callback(self, msg: Joy):
        self.last_joy_msg_time = time.time()
        
        # Pad buttons
        if len(msg.buttons) > len(self.prev_buttons):
             self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        def is_pressed(i):
            return msg.buttons[i] == 1 and self.prev_buttons[i] == 0

        # --- 1. CRITICAL BUTTONS (Start, Stop, Home) ---
        
        # B Button (1) -> STOP (Disable Teleop)
        if is_pressed(1): 
            self.teleop_active = False
            self.vel_cmd = [0.0] * 6
            self.call_service(self.stop_client, "Stop")
            self.get_logger().warn("!!! EMERGENCY STOP - TELEOP DISABLED !!!")

        # RB Button (5) -> HOME (Disable Teleop)
        if is_pressed(5):
            self.teleop_active = False
            self.homing = True
            self.vel_cmd = [0.0] * 6
            self.call_home_service()
            self.get_logger().info("Homing... Teleop Disabled.")

        # A Button (0) -> START (Does not enable teleop, just starts robot)
        if is_pressed(0):
            self.call_service(self.start_client, "Start")

        # --- 2. TELEOP TOGGLE ---
        
        # X Button (2) -> TOGGLE TELEOP + CALIBRATE
        if is_pressed(2):
            if self.teleop_active:
                # Turn OFF
                self.teleop_active = False
                self.vel_cmd = [0.0] * 6
                self.get_logger().info("--- Teleop PAUSED ---")
            else:
                # Turn ON
                # We need to grab the CURRENT UDP position to set as offset
                # Since we don't have direct access to the UDP variable in this thread easily
                # without a lock, we will rely on the UDP thread to grab the 'next' packet as zero
                # BUT, simpler way: Let's read the latest offset in UDP thread.
                
                # Force a recalibration in the next UDP loop:
                # Actually, simplest is to temporarily flag "need_calibration"
                # but for now, let's assume the user holds steady.
                
                # NOTE: To make this robust, we need the UDP thread to expose current raw pos.
                # However, for this script, we will just set the flag and let the user flow work.
                
                # WAIT! better approach:
                # Just set a flag "reset_offset_now"
                self.udp_offset = None # This triggers the "First time setup" logic in many scripts
                # But my UDP thread above relies on self.udp_offset being set. 
                
                # Let's change UDP thread logic slightly:
                # It needs to grab the *current* raw packet as the new zero.
                # See update in UDP thread logic below.
                
                # For now, we enable it. The UDP thread needs to handle the "Tare".
                self.teleop_active = True
                self.calibrated = False # Signal to UDP thread to reset zero
                self.get_logger().info(">>> Teleop ARMED (Calibrating Zero...) <<<")

        # --- 3. WRIST & GRIPPER ---
        
        # Right Stick Horizontal (Axis 3) -> Wrist Rotation
        # We allow this even if Teleop is off? No, safer to only allow if Active.
        if self.teleop_active:
            val = msg.axes[3]
            if abs(val) > 0.1:
                self.vel_cmd[5] = -val * self.MAX_ANG_VEL
            else:
                self.vel_cmd[5] = 0.0
        else:
             self.vel_cmd[5] = 0.0

        # Gripper (D-Pad Vertical - Axis 7)
        # Always allow gripper control
        current_gripper_cmd = None
        if len(msg.axes) > 7:
            if msg.axes[7] > 0.5: current_gripper_cmd = "OPEN"
            elif msg.axes[7] < -0.5: current_gripper_cmd = "CLOSE"
        
        if current_gripper_cmd and current_gripper_cmd != self.last_gripper_cmd:
            pos = [0,0,0] if current_gripper_cmd == "OPEN" else [self.fingers_closed_pos]*3
            self.send_gripper(pos)
            self.last_gripper_cmd = current_gripper_cmd
        elif current_gripper_cmd is None:
             self.last_gripper_cmd = None

        self.prev_buttons = list(msg.buttons)

    def send_gripper(self, target):
        if not self.finger_client_node.server_is_ready(): return
        goal = SetFingersPosition.Goal()
        goal.fingers.finger1, goal.fingers.finger2, goal.fingers.finger3 = map(float, target)
        self.finger_client_node.send_goal_async(goal)

    def call_service(self, client, name):
        if client.service_is_ready():
            if name == "Stop": req = Stop.Request()
            elif name == "Home": req = HomeArm.Request()
            elif name == "Start": req = Start.Request()
            client.call_async(req)
            if name == "Start":
                self._arm_started = True
            elif name == "Stop":
                self._arm_started = False

    def call_home_service(self):
        if not self.home_client.service_is_ready():
            self.get_logger().error("Home service not ready!")
            self.homing = False
            return
        future = self.home_client.call_async(HomeArm.Request())
        future.add_done_callback(self.on_home_done)

    def on_home_done(self, future):
        self.homing = False
        try:
            result = future.result()
            self.get_logger().info(f"Home result: {result.homearm_result}")
        except Exception as e:
            self.get_logger().error(f"Home call failed: {e}")
        # Re-start the arm so it accepts velocity commands again
        self.call_service(self.start_client, "Start")
        self.get_logger().info("Arm re-started after homing.")

    def joint_angles_callback(self, msg: JointAngles):
        self.current_joint_deg = [
            msg.joint1, msg.joint2, msg.joint3, msg.joint4,
            msg.joint5, msg.joint6, msg.joint7,
        ]
        self._last_joint_feedback_time = time.time()

    def _publish_joint_velocity(self):
        has_motion = False
        if self.teleop_active and self.current_joint_deg is not None:
            v_cart = np.array([
                self.vel_cmd[0], self.vel_cmd[1], self.vel_cmd[2],
                0.0, 0.0, max(min(self.vel_cmd[5], self.MAX_ANG_VEL), -self.MAX_ANG_VEL),
            ])
            if np.any(np.abs(v_cart) > 1e-6):
                has_motion = True
                dq = cart_to_joint_vel(
                    self.current_joint_deg,
                    v_cart,
                    locked_joints=[0],
                    max_joint_vel_deg=self._max_joint_vel_deg,
                )
                msg = JointVelocity()
                msg.joint1 = 0.0
                msg.joint2 = float(dq[1])
                msg.joint3 = float(dq[2])
                msg.joint4 = float(dq[3])
                msg.joint5 = float(dq[4])
                msg.joint6 = float(dq[5])
                msg.joint7 = float(dq[6])
                self.joint_velocity_pub.publish(msg)
                self._last_out_joint = [
                    msg.joint1, msg.joint2, msg.joint3, msg.joint4,
                    msg.joint5, msg.joint6, msg.joint7,
                ]
                self._jvel_stop_count = 10

        if not has_motion and self._jvel_stop_count > 0:
            self.joint_velocity_pub.publish(JointVelocity())
            self._jvel_stop_count -= 1

    def publish_velocity(self):
        # Don't send ANY velocity commands while the arm is running a home trajectory.
        # Velocity commands conflict with the joint-angles action and cause it to abort.
        if self.homing:
            return

        # Optional joystick keepalive watchdog (default disabled for UDP-only control)
        if self.require_joy_keepalive and (time.time() - self.last_joy_msg_time) > self.joy_timeout_sec:
            self.teleop_active = False

        if self.auto_start_arm and self.teleop_active and (not self._arm_started) and self.start_client.service_is_ready():
            self.call_service(self.start_client, "Start")
            self.get_logger().info("Auto-started arm driver.")

        if self.lock_joint1:
            if self.current_joint_deg is None:
                # Strict mode: no joint feedback means no joint command.
                now = time.time()
                if now - self._last_joint_missing_warn_t > 2.0:
                    self._last_joint_missing_warn_t = now
                    self.get_logger().warn(
                        "lock_joint1 requested but no joint feedback received yet; holding zero commands."
                    )
                if self._jvel_stop_count > 0:
                    self.joint_velocity_pub.publish(JointVelocity())
                    self._jvel_stop_count -= 1
            else:
                self._publish_joint_velocity()
        else:
            msg = PoseVelocity()

            if self.teleop_active:
                msg.twist_linear_x = float(self.vel_cmd[0])
                msg.twist_linear_y = float(self.vel_cmd[1])
                msg.twist_linear_z = float(self.vel_cmd[2])
                msg.twist_angular_z = float(self.vel_cmd[5])
            else:
                msg.twist_linear_x = 0.0
                msg.twist_linear_y = 0.0
                msg.twist_linear_z = 0.0
                msg.twist_angular_z = 0.0

            self.velocity_pub.publish(msg)
            self._last_out_cart = [
                msg.twist_linear_x,
                msg.twist_linear_y,
                msg.twist_linear_z,
                msg.twist_angular_z,
            ]

        now = time.time()
        if now - self._last_udp_log_t > 2.0:
            self._last_udp_log_t = now
            self.get_logger().info(
                f"path(joint_subs={self.joint_velocity_pub.get_subscription_count()}, "
                f"cart_subs={self.velocity_pub.get_subscription_count()}, "
                f"start_ready={self.start_client.service_is_ready()}, teleop={self.teleop_active})"
            )
            self.get_logger().info(
                f"udp_rx(total={self._udp_rx_total}, pose={self._udp_rx_pose}, "
                f"twist={self._udp_rx_twist}, other={self._udp_rx_other})"
            )
            if self._last_rx_pose is not None:
                p = self._last_rx_pose
                self.get_logger().info(
                    f"rx_pose xyz=({p[0]:+.3f},{p[1]:+.3f},{p[2]:+.3f}) "
                    f"quat=({p[3]:+.3f},{p[4]:+.3f},{p[5]:+.3f},{p[6]:+.3f})"
                )
            if self._last_rx_twist is not None:
                t = self._last_rx_twist
                self.get_logger().info(
                    f"rx_twist v=({t[0]:+.3f},{t[1]:+.3f},{t[2]:+.3f}) "
                    f"w=({t[3]:+.3f},{t[4]:+.3f},{t[5]:+.3f})"
                )
            if self.lock_joint1:
                j = self._last_out_joint
                self.get_logger().info(
                    f"cmd_joint dq=({j[0]:+.2f},{j[1]:+.2f},{j[2]:+.2f},{j[3]:+.2f},{j[4]:+.2f},{j[5]:+.2f},{j[6]:+.2f})"
                )
                age = (now - self._last_joint_feedback_time) if self._last_joint_feedback_time > 0.0 else -1.0
                self.get_logger().info(f"joint_feedback_age_s={age:.3f}")
            else:
                c = self._last_out_cart
                self.get_logger().info(
                    f"cmd_cart v=({c[0]:+.3f},{c[1]:+.3f},{c[2]:+.3f}) wz={c[3]:+.3f}"
                )

    # --- UDP THREAD UPDATE --- 
    # EDIT01: I COMMENTED THIS DUPLICATE FUNCTION OUT BECAUSE THIS TARING FEATURE SEEMS DANGEROUS, 
    # THOUGH I ADMITTEDLY DONT UNDERSTAND ITS PURPOSE FULLY YET 
    # EDIT02: THE POINT OF THIS IS 
    # (NATHANAEL McCOOEYE 02.06.26)
    # 
    # 
    # Need to patch the UDP thread logic to support the "Tare on Arm" feature
    # overriding the method defined earlier in the class
    # def receive_udp_data_and_transform_to_velocity(self):
    #     sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    #     sock.bind((self.UDP_IP, self.UDP_PORT))
    #     sock.setblocking(False)
    #     fmt = '<fffffff'
    #     struct_len = struct.calcsize(fmt)
        
    #     self.calibrated = False # Internal flag

    #     while rclpy.ok():
    #         try:
    #             data = None
    #             while True:
    #                 try:
    #                     chunk, _ = sock.recvfrom(1024)
    #                     if len(chunk) == struct_len: data = chunk
    #                 except BlockingIOError: break
                
    #             if data is None: 
    #                 time.sleep(0.005)
    #                 continue

    #             vals = struct.unpack(fmt, data)
                
    #             # Publish PoseStamped end effector 
    #             msg = PoseStamped()
    #             msg.header.stamp = self.get_clock().now().to_msg()
    #             msg.header.frame_id = "base_link"
    #             msg.pose.position.x = vals[0]       # x
    #             msg.pose.position.y = vals[1]       # y
    #             msg.pose.position.z = vals[2]       # z
    #             msg.pose.orientation.w = vals[3]    # alpha
    #             msg.pose.orientation.x = vals[4]    # beta
    #             msg.pose.orientation.y = vals[5]    # gamma
    #             self.udp_pub.publish(msg)

    #             curr_pos = vals[0:3]

    #             # IF RE-ARMED (User pressed X):
    #             if self.teleop_active and not self.calibrated:
    #                 self.udp_offset = curr_pos
    #                 self.calibrated = True
    #                 self.get_logger().info(f"*** ZERO SET: {curr_pos} ***")

    #             # IF ACTIVE AND CALIBRATED:
    #             if self.teleop_active and self.calibrated:
    #                 dx = curr_pos[0] - self.udp_offset[0]
    #                 dy = curr_pos[1] - self.udp_offset[1]
    #                 dz = curr_pos[2] - self.udp_offset[2]

    #                 def clamp(v): return max(min(v, self.MAX_LIN_VEL), -self.MAX_LIN_VEL)
                    
    #                 self.vel_cmd[0] = clamp(dx * self.UDP_GAIN)
    #                 self.vel_cmd[1] = clamp(dy * self.UDP_GAIN)
    #                 self.vel_cmd[2] = clamp(dz * self.UDP_GAIN)
    #             elif not self.teleop_active:
    #                 self.calibrated = False # Reset calibration flag when disarmed

    #         except Exception:
    #             pass
    #         time.sleep(0.002)

def main(args=None):
    rclpy.init(args=args)
    controller = XboxAndUDPController()
    try:
        rclpy.spin(controller)
    except KeyboardInterrupt:
        pass
    finally:
        controller.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()

if __name__ == '__main__':
    main()