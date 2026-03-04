#!/usr/bin/env python3
"""
Kinova arm teleop controller.

Accepts commands from UDP and/or Xbox, outputs Cartesian velocity or
pose-action goals to one Kinova Jaco arm.

Input modes (set via 'input_mode' param):
  udp     - Position data from a UDP socket → velocity or pose commands
  xbox    - Joystick via sensor_msgs/Joy → velocity commands
  hybrid  - UDP position + Xbox wrist/gripper

Control modes (set via 'control_mode' param):
  velocity     - Publishes PoseVelocity at 100Hz (or JointVelocity when lock_joint1=True)
  pose_action  - Sends ArmPose action goals

Safety features:
  - Auto-start arm driver when teleop is active
  - Command path gating (won't move unless services + UDP + subscribers ready)
  - Custom home via /movo/home_{arm} (pauses velocity during trajectory)
  - Status log every 2s

Xbox buttons (when connected):
  A  (0) Start arm      B  (1) Emergency stop
  X  (2) Toggle teleop  RB (5) Home arm
"""

import socket
import struct
import threading
import time

import rclpy
import numpy as np
from geometry_msgs.msg import PoseStamped
from kinova_msgs.action import ArmPose, SetFingersPosition
from kinova_msgs.msg import JointAngles, JointVelocity, PoseVelocity
from kinova_msgs.srv import HomeArm, Start, Stop

from arms_xbox_ctr.jaco_jacobian import cart_to_joint_vel
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Joy


class KinovaTeleop(Node):
    def __init__(self):
        super().__init__("kinova_teleop")

        # ── Parameters ──
        self.declare_parameter("arm_namespace", "left_arm")
        self.declare_parameter("input_mode", "udp")
        self.declare_parameter("control_mode", "velocity")
        self.declare_parameter("udp_ip", "127.0.0.1")
        self.declare_parameter("udp_port", 5005)
        self.declare_parameter("udp_gain", 2.0)
        self.declare_parameter("deadzone", 0.005)
        self.declare_parameter("max_lin_vel", 0.08)
        self.declare_parameter("max_ang_vel", 0.20)
        self.declare_parameter("pose_goal_rate_hz", 10.0)
        self.declare_parameter("pose_frame_id", "base_link")
        self.declare_parameter("x_sign", 1.0)
        self.declare_parameter("y_sign", 1.0)
        self.declare_parameter("z_sign", 1.0)
        self.declare_parameter("x_offset", 0.0)
        self.declare_parameter("y_offset", 0.0)
        self.declare_parameter("z_offset", 0.0)
        self.declare_parameter("button_debounce_sec", 0.30)
        self.declare_parameter("udp_bind_retry_sec", 2.0)
        self.declare_parameter("require_joy_keepalive", False)
        self.declare_parameter("joy_timeout_sec", 1.0)
        self.declare_parameter("auto_arm_udp", True)
        self.declare_parameter("auto_start_arm", True)
        self.declare_parameter("require_command_path_ready", True)
        self.declare_parameter("pose_safety_enable", True)
        self.declare_parameter("pose_x_min", 0.20)
        self.declare_parameter("pose_x_max", 0.40)
        self.declare_parameter("pose_y_min", -0.15)
        self.declare_parameter("pose_y_max", 0.15)
        self.declare_parameter("pose_z_min", 0.20)
        self.declare_parameter("pose_z_max", 0.50)
        self.declare_parameter("pose_require_udp_fresh", True)
        self.declare_parameter("pose_udp_timeout_sec", 0.5)
        self.declare_parameter("pose_hold_current_orientation", True)
        self.declare_parameter("lock_joint1", True)
        self.declare_parameter("max_joint_vel_deg", 45.0)

        p = self.get_parameter
        self.arm_namespace = p("arm_namespace").value
        self.input_mode = p("input_mode").value
        self.control_mode = p("control_mode").value
        self.udp_ip = p("udp_ip").value
        self.udp_port = int(p("udp_port").value)
        self.udp_gain = float(p("udp_gain").value)
        self.deadzone = float(p("deadzone").value)
        self.max_lin_vel = float(p("max_lin_vel").value)
        self.max_ang_vel = float(p("max_ang_vel").value)
        self.pose_goal_period = 1.0 / max(1.0, float(p("pose_goal_rate_hz").value))
        self.pose_frame_id = p("pose_frame_id").value
        self.x_sign = float(p("x_sign").value)
        self.y_sign = float(p("y_sign").value)
        self.z_sign = float(p("z_sign").value)
        self.x_offset = float(p("x_offset").value)
        self.y_offset = float(p("y_offset").value)
        self.z_offset = float(p("z_offset").value)
        self.button_debounce_sec = float(p("button_debounce_sec").value)
        self.udp_bind_retry_sec = float(p("udp_bind_retry_sec").value)
        self.require_joy_keepalive = bool(p("require_joy_keepalive").value)
        self.joy_timeout_sec = float(p("joy_timeout_sec").value)
        self.auto_arm_udp = bool(p("auto_arm_udp").value)
        self.auto_start_arm = bool(p("auto_start_arm").value)
        self.require_command_path_ready = bool(p("require_command_path_ready").value)
        self.pose_safety_enable = bool(p("pose_safety_enable").value)
        self.pose_x_min = float(p("pose_x_min").value)
        self.pose_x_max = float(p("pose_x_max").value)
        self.pose_y_min = float(p("pose_y_min").value)
        self.pose_y_max = float(p("pose_y_max").value)
        self.pose_z_min = float(p("pose_z_min").value)
        self.pose_z_max = float(p("pose_z_max").value)
        self.pose_require_udp_fresh = bool(p("pose_require_udp_fresh").value)
        self.pose_udp_timeout_sec = float(p("pose_udp_timeout_sec").value)
        self.pose_hold_current_orientation = bool(p("pose_hold_current_orientation").value)
        self.lock_joint1 = bool(p("lock_joint1").value)
        self.max_joint_vel_deg = float(p("max_joint_vel_deg").value)

        # ── ROS interfaces ──
        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )

        arm = self.arm_namespace
        self.velocity_pub = self.create_publisher(
            PoseVelocity, f"/{arm}/{arm}_driver/in/cartesian_velocity", qos
        )
        self.joint_velocity_pub = self.create_publisher(
            JointVelocity, f"/{arm}/{arm}_driver/in/joint_velocity", qos
        )
        self.udp_pose_pub = self.create_publisher(PoseStamped, f"/{arm}/udp_position", qos)

        self.home_client = self.create_client(HomeArm, f"/movo/home_{arm}")
        self.stop_client = self.create_client(Stop, f"/{arm}/{arm}_driver/in/stop")
        self.start_client = self.create_client(Start, f"/{arm}/{arm}_driver/in/start")

        self.pose_action_client = ActionClient(
            self, ArmPose, f"/{arm}/{arm}_driver/pose_action/tool_pose"
        )
        self.finger_client = ActionClient(
            self, SetFingersPosition, f"/{arm}/{arm}_driver/fingers_action/finger_positions"
        )

        self.create_subscription(Joy, "/joy", self.joy_callback, qos)
        self.create_subscription(
            PoseStamped, f"/{arm}/{arm}_driver/out/tool_pose", self.tool_pose_callback, qos
        )
        self.create_subscription(
            JointAngles, f"/{arm}/{arm}_driver/out/joint_angles", self.joint_angles_callback, qos
        )
        self.create_timer(0.01, self.publish_control)

        # ── State ──
        self.prev_buttons = [0] * 15
        self.last_joy_msg_time = time.time()
        self.last_pose_goal_time = 0.0
        self.last_gripper_cmd = None
        self.teleop_active = self.auto_arm_udp and self.input_mode in ("udp", "hybrid")
        self.calibrated = False
        self.fingers_closed_pos = 6000
        self._last_button_event_time = {}
        self._udp_bound = False
        self._udp_last_error = None
        self._arm_started = False
        self._homing = False
        self._last_debug_log_t = 0.0
        self._last_gate_log_t = 0.0
        self._last_udp_pose_time = 0.0
        self._stop_event = threading.Event()
        self._udp_sock = None

        self.vel_cmd = [0.0] * 6  # x, y, z, ax, ay, az
        self.udp_offset = [0.0, 0.0, 0.0]
        self.latest_udp_pose = [0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0]
        self.latest_tool_quat = [1.0, 0.0, 0.0, 0.0]
        self.have_tool_pose = False
        self.current_joint_deg = None  # set by joint_angles_callback
        self._jvel_stop_count = 0  # zero-burst counter for joint velocity stop
        self.state_lock = threading.Lock()

        # Start UDP listener thread
        self.udp_thread = threading.Thread(target=self.udp_loop, daemon=True)
        self.udp_thread.start()

        self.get_logger().info(
            f"KinovaTeleop started arm={arm} input={self.input_mode} control={self.control_mode}"
        )
        self.get_logger().info(
            f"teleop_active={self.teleop_active} require_joy_keepalive={self.require_joy_keepalive}"
        )

    # ── Helpers ──

    @staticmethod
    def clamp(value, max_abs):
        return max(min(value, max_abs), -max_abs)

    def axis_with_deadzone(self, val, scale):
        if abs(val) < 0.1:
            return 0.0
        return self.clamp(val * scale, scale)

    # ── Joy callback ──

    def joy_callback(self, msg: Joy):
        self.last_joy_msg_time = time.time()

        if len(msg.buttons) > len(self.prev_buttons):
            self.prev_buttons.extend([0] * (len(msg.buttons) - len(self.prev_buttons)))

        def is_pressed(i):
            return i < len(msg.buttons) and msg.buttons[i] == 1 and self.prev_buttons[i] == 0

        def pressed_debounced(i, key):
            if not is_pressed(i):
                return False
            now = time.time()
            last = self._last_button_event_time.get(key, 0.0)
            if now - last < self.button_debounce_sec:
                return False
            self._last_button_event_time[key] = now
            return True

        # B (1) → Emergency stop
        if pressed_debounced(1, "stop"):
            self.teleop_active = False
            self.calibrated = False
            self.vel_cmd = [0.0] * 6
            self.call_service(self.stop_client, Stop.Request())
            self._arm_started = False
            self.get_logger().warn("EMERGENCY STOP + teleop disarmed")

        # RB (5) → Home arm
        if pressed_debounced(5, "home"):
            self.teleop_active = False
            self._homing = True
            self.calibrated = False
            self.vel_cmd = [0.0] * 6
            self._arm_started = False
            self.call_home()
            self.get_logger().info("Home requested + teleop disarmed")

        # A (0) → Start arm
        if pressed_debounced(0, "start"):
            self.call_service(self.start_client, Start.Request())
            self._arm_started = True

        # X (2) → Toggle teleop
        if pressed_debounced(2, "toggle"):
            self.teleop_active = not self.teleop_active
            self.calibrated = False
            if not self.teleop_active:
                self.vel_cmd = [0.0] * 6
            self.get_logger().info(f"teleop_active={self.teleop_active}")

        # Wrist rotation from right stick horizontal (xbox/hybrid velocity mode)
        if self.control_mode == "velocity" and self.input_mode in ("xbox", "hybrid"):
            self.vel_cmd[5] = -self.axis_with_deadzone(msg.axes[3], self.max_ang_vel)

        # Full Xbox velocity control
        if self.input_mode == "xbox" and self.control_mode == "velocity":
            self.vel_cmd[0] = self.axis_with_deadzone(msg.axes[1], self.max_lin_vel)
            self.vel_cmd[1] = self.axis_with_deadzone(msg.axes[0], self.max_lin_vel)
            self.vel_cmd[2] = self.axis_with_deadzone(msg.axes[4], self.max_lin_vel)

        # Gripper on D-pad vertical
        current_gripper_cmd = None
        if len(msg.axes) > 7 and msg.axes[7] > 0.5:
            current_gripper_cmd = "OPEN"
        elif len(msg.axes) > 7 and msg.axes[7] < -0.5:
            current_gripper_cmd = "CLOSE"
        if current_gripper_cmd and current_gripper_cmd != self.last_gripper_cmd:
            if current_gripper_cmd == "OPEN":
                self.send_gripper([0.0, 0.0, 0.0])
            else:
                c = float(self.fingers_closed_pos)
                self.send_gripper([c, c, c])
            self.last_gripper_cmd = current_gripper_cmd
        elif current_gripper_cmd is None:
            self.last_gripper_cmd = None

        self.prev_buttons = list(msg.buttons)

    # ── UDP ──

    def udp_loop(self):
        fmt = "<fffffff"
        pkt_size = struct.calcsize(fmt)
        sock = None

        while rclpy.ok() and not self._stop_event.is_set():
            # Bind socket (with retry on failure)
            if sock is None:
                try:
                    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                    sock.bind((self.udp_ip, self.udp_port))
                    sock.setblocking(False)
                    self._udp_sock = sock
                    self._udp_bound = True
                    self._udp_last_error = None
                    self.get_logger().info(f"UDP bound on {self.udp_ip}:{self.udp_port}")
                except OSError as exc:
                    self._udp_bound = False
                    err = str(exc)
                    if err != self._udp_last_error:
                        self._udp_last_error = err
                        self.get_logger().error(
                            f"UDP bind failed {self.udp_ip}:{self.udp_port}: {exc}. "
                            f"Retrying every {self.udp_bind_retry_sec:.1f}s."
                        )
                    if sock is not None:
                        try:
                            sock.close()
                        except Exception:
                            pass
                    self._udp_sock = None
                    sock = None
                    time.sleep(self.udp_bind_retry_sec)
                    continue

            # Drain buffer, keep latest packet
            latest = None
            while True:
                try:
                    data, _ = sock.recvfrom(1024)
                    if len(data) == pkt_size:
                        latest = struct.unpack(fmt, data)
                except BlockingIOError:
                    break
                except OSError:
                    try:
                        sock.close()
                    except Exception:
                        pass
                    self._udp_sock = None
                    sock = None
                    self._udp_bound = False
                    break
                except Exception:
                    break

            if latest is not None:
                x = self.x_sign * latest[0] + self.x_offset
                y = self.y_sign * latest[1] + self.y_offset
                z = self.z_sign * latest[2] + self.z_offset
                qw, qx, qy, qz = latest[3], latest[4], latest[5], latest[6]
                n = max((qw * qw + qx * qx + qy * qy + qz * qz) ** 0.5, 1e-9)
                pose = [x, y, z, qw / n, qx / n, qy / n, qz / n]

                with self.state_lock:
                    self.latest_udp_pose = pose
                    self._last_udp_pose_time = time.time()

                self.publish_udp_pose(pose)

                if self.control_mode == "velocity" and self.input_mode in ("udp", "hybrid"):
                    self.compute_udp_velocity(pose)

            time.sleep(0.005)

        if sock is not None:
            try:
                sock.close()
            except Exception:
                pass
        self._udp_sock = None
        self._udp_bound = False

    def compute_udp_velocity(self, pose):
        curr = pose[:3]
        if self.teleop_active and not self.calibrated:
            self.udp_offset = curr[:]
            self.calibrated = True
            self.get_logger().info(f"UDP zero captured: {self.udp_offset}")

        if self.teleop_active and self.calibrated:
            dx = curr[0] - self.udp_offset[0]
            dy = curr[1] - self.udp_offset[1]
            dz = curr[2] - self.udp_offset[2]

            def v(delta):
                if abs(delta) < self.deadzone:
                    return 0.0
                return self.clamp(delta * self.udp_gain, self.max_lin_vel)

            self.vel_cmd[0] = v(dx)
            self.vel_cmd[1] = v(dy)
            self.vel_cmd[2] = v(dz)
        else:
            if self.input_mode == "udp":
                self.vel_cmd[0] = 0.0
                self.vel_cmd[1] = 0.0
                self.vel_cmd[2] = 0.0
            self.calibrated = False

    def publish_udp_pose(self, pose):
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = self.pose_frame_id
        msg.pose.position.x = pose[0]
        msg.pose.position.y = pose[1]
        msg.pose.position.z = pose[2]
        msg.pose.orientation.w = pose[3]
        msg.pose.orientation.x = pose[4]
        msg.pose.orientation.y = pose[5]
        msg.pose.orientation.z = pose[6]
        self.udp_pose_pub.publish(msg)

    def tool_pose_callback(self, msg: PoseStamped):
        with self.state_lock:
            self.latest_tool_quat = [
                msg.pose.orientation.w,
                msg.pose.orientation.x,
                msg.pose.orientation.y,
                msg.pose.orientation.z,
            ]
            self.have_tool_pose = True

    def joint_angles_callback(self, msg: JointAngles):
        self.current_joint_deg = [
            msg.joint1, msg.joint2, msg.joint3, msg.joint4,
            msg.joint5, msg.joint6, msg.joint7,
        ]

    # ── Control output ──

    def publish_control(self):
        # Pause velocity during homing — even zeros conflict with the joint action
        if self._homing:
            return

        if self.require_joy_keepalive and (time.time() - self.last_joy_msg_time) > self.joy_timeout_sec:
            self.teleop_active = False
            self.calibrated = False
            self.vel_cmd = [0.0] * 6

        if self.control_mode == "pose_action":
            self.publish_pose_goal()
            return

        command_path_ready, gate_reason = self.command_path_ready()
        wants_motion = any(abs(v) > 1e-6 for v in self.vel_cmd[:3] + [self.vel_cmd[5]])

        active = self.teleop_active and (not self.require_command_path_ready or command_path_ready)

        if active:
            if self.auto_start_arm and not self._arm_started and self.start_client.service_is_ready():
                self.call_service(self.start_client, Start.Request())
                self._arm_started = True
                self.get_logger().info("Auto-started arm driver.")

        if self.lock_joint1:
            self._publish_joint_velocity(active)
        else:
            self._publish_cartesian_velocity(active)

        if self.teleop_active and wants_motion and not active:
            now = time.time()
            if now - self._last_gate_log_t > 1.0:
                self._last_gate_log_t = now
                self.get_logger().error(f"Motion gated: {gate_reason}")

        self._periodic_status_log()

    def _publish_cartesian_velocity(self, active: bool):
        msg = PoseVelocity()
        if active:
            msg.twist_linear_x = float(self.vel_cmd[0])
            msg.twist_linear_y = float(self.vel_cmd[1])
            msg.twist_linear_z = float(self.vel_cmd[2])
            msg.twist_angular_z = float(self.clamp(self.vel_cmd[5], self.max_ang_vel))
        self.velocity_pub.publish(msg)

    def _publish_joint_velocity(self, active: bool):
        has_motion = False
        if active and self.current_joint_deg is not None:
            v_cart = np.array([
                self.vel_cmd[0], self.vel_cmd[1], self.vel_cmd[2],
                0.0, 0.0, self.clamp(self.vel_cmd[5], self.max_ang_vel),
            ])
            if np.any(np.abs(v_cart) > 1e-6):
                has_motion = True
                dq = cart_to_joint_vel(
                    self.current_joint_deg, v_cart,
                    locked_joints=[0], max_joint_vel_deg=self.max_joint_vel_deg,
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
                self._jvel_stop_count = 10  # queue 10 zero-frames on next idle

        if not has_motion and self._jvel_stop_count > 0:
            self.joint_velocity_pub.publish(JointVelocity())
            self._jvel_stop_count -= 1

    def _periodic_status_log(self):
        now = time.time()
        if now - self._last_debug_log_t > 2.0:
            self._last_debug_log_t = now
            mode = "joint_vel(J1 locked)" if self.lock_joint1 else "cartesian_vel"
            pub = self.joint_velocity_pub if self.lock_joint1 else self.velocity_pub
            sub_count = pub.get_subscription_count()
            j1_str = f" j1={self.current_joint_deg[0]:.1f}" if self.current_joint_deg else ""
            self.get_logger().info(
                f"mode={mode} teleop={self.teleop_active} arm={self._arm_started} "
                f"svc(start={self.start_client.service_is_ready()},"
                f"stop={self.stop_client.service_is_ready()},"
                f"home={self.home_client.service_is_ready()}) "
                f"path(subs={sub_count},udp={self._udp_bound}){j1_str}"
            )

    def publish_pose_goal(self):
        if not self.teleop_active:
            return
        now = time.time()
        if now - self.last_pose_goal_time < self.pose_goal_period:
            return
        self.last_pose_goal_time = now

        if not self.pose_action_client.server_is_ready():
            return
        if self.pose_require_udp_fresh and self.input_mode in ("udp", "hybrid"):
            if (time.time() - self._last_udp_pose_time) > self.pose_udp_timeout_sec:
                return
        command_path_ready, _ = self.command_path_ready()
        if self.require_command_path_ready and not command_path_ready:
            return

        with self.state_lock:
            pose = self.latest_udp_pose[:]
            tool_quat = self.latest_tool_quat[:]
            have_tool_pose = self.have_tool_pose
        pose = self.apply_pose_safety(pose)

        goal = ArmPose.Goal()
        goal.pose.header.stamp = self.get_clock().now().to_msg()
        goal.pose.header.frame_id = self.pose_frame_id
        goal.pose.pose.position.x = pose[0]
        goal.pose.pose.position.y = pose[1]
        goal.pose.pose.position.z = pose[2]
        if self.pose_hold_current_orientation and have_tool_pose:
            goal.pose.pose.orientation.w = tool_quat[0]
            goal.pose.pose.orientation.x = tool_quat[1]
            goal.pose.pose.orientation.y = tool_quat[2]
            goal.pose.pose.orientation.z = tool_quat[3]
        else:
            goal.pose.pose.orientation.w = pose[3]
            goal.pose.pose.orientation.x = pose[4]
            goal.pose.pose.orientation.y = pose[5]
            goal.pose.pose.orientation.z = pose[6]

        self.pose_action_client.send_goal_async(goal)

    def apply_pose_safety(self, pose):
        p = pose[:]
        if self.pose_safety_enable:
            p[0] = max(self.pose_x_min, min(p[0], self.pose_x_max))
            p[1] = max(self.pose_y_min, min(p[1], self.pose_y_max))
            p[2] = max(self.pose_z_min, min(p[2], self.pose_z_max))
        return p

    # ── Services ──

    def send_gripper(self, target):
        if not self.finger_client.server_is_ready():
            return
        goal = SetFingersPosition.Goal()
        goal.fingers.finger1, goal.fingers.finger2, goal.fingers.finger3 = target
        self.finger_client.send_goal_async(goal)

    def call_service(self, client, request):
        if client.service_is_ready():
            client.call_async(request)

    def call_home(self):
        if not self.home_client.service_is_ready():
            self.get_logger().error("Home service not ready!")
            self._homing = False
            return
        future = self.home_client.call_async(HomeArm.Request())
        future.add_done_callback(self.on_home_done)

    def on_home_done(self, future):
        self._homing = False
        try:
            result = future.result()
            self.get_logger().info(f"Home result: {result.homearm_result}")
        except Exception as e:
            self.get_logger().error(f"Home call failed: {e}")
        self.call_service(self.start_client, Start.Request())
        self._arm_started = True
        self.get_logger().info("Arm re-started after homing.")

    def services_ready(self):
        return (
            self.start_client.service_is_ready()
            and self.stop_client.service_is_ready()
            and self.home_client.service_is_ready()
        )

    def command_path_ready(self):
        if not self.services_ready():
            return False, "kinova services not ready (start/stop/home)"
        if self.input_mode in ("udp", "hybrid") and not self._udp_bound:
            return False, "udp listener not bound"
        if self.control_mode == "pose_action":
            if not self.pose_action_client.server_is_ready():
                return False, "pose action server not ready"
            return True, "ok"
        if self.lock_joint1:
            if self.current_joint_deg is None:
                return False, "waiting for joint_angles feedback"
            if self.joint_velocity_pub.get_subscription_count() < 1:
                return False, "no subscriber on joint_velocity"
        else:
            if self.velocity_pub.get_subscription_count() < 1:
                return False, "no subscriber on cartesian_velocity"
        return True, "ok"

    # ── Shutdown ──

    def shutdown_safely(self):
        self._stop_event.set()
        if self._udp_sock is not None:
            try:
                self._udp_sock.close()
            except Exception:
                pass
            self._udp_sock = None
        self._udp_bound = False
        try:
            self.velocity_pub.publish(PoseVelocity())
            self.joint_velocity_pub.publish(JointVelocity())
        except Exception:
            pass
        try:
            self.udp_thread.join(timeout=0.5)
        except Exception:
            pass


def main(args=None):
    rclpy.init(args=args)
    node = KinovaTeleop()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.shutdown_safely()
        node.destroy_node()
        try:
            rclpy.shutdown()
        except Exception:
            pass


if __name__ == "__main__":
    main()
