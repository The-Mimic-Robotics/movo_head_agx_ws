#!/usr/bin/env python3

import socket
import struct
import threading
import time

import rclpy
from geometry_msgs.msg import PoseStamped
from kinova_msgs.action import ArmPose, SetFingersPosition
from kinova_msgs.msg import PoseVelocity
from kinova_msgs.srv import HomeArm, Start, Stop
from rclpy.action import ActionClient
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Joy


class Axe4BridgeController(Node):
    def __init__(self):
        super().__init__("axe4_bridge_controller")

        self.declare_parameter("arm_namespace", "left_arm")
        self.declare_parameter("input_mode", "udp")          # udp|xbox|hybrid
        self.declare_parameter("control_mode", "velocity")   # velocity|pose_action
        self.declare_parameter("udp_ip", "127.0.0.1")
        self.declare_parameter("udp_port", 5005)
        self.declare_parameter("udp_gain", 2.0)
        self.declare_parameter("deadzone", 0.005)
        # Match movo_xbox_controller defaults for comparable arm response.
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

        self.arm_namespace = self.get_parameter("arm_namespace").value
        self.input_mode = self.get_parameter("input_mode").value
        self.control_mode = self.get_parameter("control_mode").value
        self.udp_ip = self.get_parameter("udp_ip").value
        self.udp_port = int(self.get_parameter("udp_port").value)
        self.udp_gain = float(self.get_parameter("udp_gain").value)
        self.deadzone = float(self.get_parameter("deadzone").value)
        self.max_lin_vel = float(self.get_parameter("max_lin_vel").value)
        self.max_ang_vel = float(self.get_parameter("max_ang_vel").value)
        self.pose_goal_period = 1.0 / max(1.0, float(self.get_parameter("pose_goal_rate_hz").value))
        self.pose_frame_id = self.get_parameter("pose_frame_id").value
        self.x_sign = float(self.get_parameter("x_sign").value)
        self.y_sign = float(self.get_parameter("y_sign").value)
        self.z_sign = float(self.get_parameter("z_sign").value)
        self.x_offset = float(self.get_parameter("x_offset").value)
        self.y_offset = float(self.get_parameter("y_offset").value)
        self.z_offset = float(self.get_parameter("z_offset").value)
        self.button_debounce_sec = float(self.get_parameter("button_debounce_sec").value)
        self.udp_bind_retry_sec = float(self.get_parameter("udp_bind_retry_sec").value)
        self.require_joy_keepalive = bool(self.get_parameter("require_joy_keepalive").value)
        self.joy_timeout_sec = float(self.get_parameter("joy_timeout_sec").value)
        self.auto_arm_udp = bool(self.get_parameter("auto_arm_udp").value)
        self.auto_start_arm = bool(self.get_parameter("auto_start_arm").value)
        self.require_command_path_ready = bool(self.get_parameter("require_command_path_ready").value)

        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )

        arm = self.arm_namespace
        self.velocity_pub = self.create_publisher(
            PoseVelocity, f"/{arm}/{arm}_driver/in/cartesian_velocity", qos_profile
        )
        self.udp_pose_pub = self.create_publisher(PoseStamped, f"/{arm}/udp_position", qos_profile)

        self.home_client = self.create_client(HomeArm, f"/{arm}/{arm}_driver/in/home_arm")
        self.stop_client = self.create_client(Stop, f"/{arm}/{arm}_driver/in/stop")
        self.start_client = self.create_client(Start, f"/{arm}/{arm}_driver/in/start")

        self.pose_action_client = ActionClient(self, ArmPose, f"/{arm}/{arm}_driver/pose_action/tool_pose")
        self.finger_client = ActionClient(
            self, SetFingersPosition, f"/{arm}/{arm}_driver/fingers_action/finger_positions"
        )

        self.create_subscription(Joy, "/joy", self.joy_callback, qos_profile)
        self.create_timer(0.01, self.publish_control)

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
        self._last_debug_log_t = 0.0
        self._last_gate_log_t = 0.0
        self._last_gate_state = None
        self._stop_event = threading.Event()
        self._udp_sock = None

        self.vel_cmd = [0.0] * 6  # x, y, z, ax, ay, az
        self.udp_offset = [0.0, 0.0, 0.0]
        self.latest_udp_pose = [0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0]
        self.state_lock = threading.Lock()

        self.udp_thread = threading.Thread(target=self.udp_loop, daemon=True)
        self.udp_thread.start()

        self.get_logger().info(
            f"AXE4 bridge started arm={arm} input_mode={self.input_mode} control_mode={self.control_mode}"
        )
        self.get_logger().info(
            f"teleop_active={self.teleop_active} require_joy_keepalive={self.require_joy_keepalive}"
        )

    @staticmethod
    def _clamp(value, max_abs):
        return max(min(value, max_abs), -max_abs)

    def _axis_with_deadzone(self, val, scale):
        if abs(val) < 0.1:
            return 0.0
        return self._clamp(val * scale, scale)

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

        # Match movo_xbox_controller safety mapping: A start, B stop, X toggle, RB home.
        if pressed_debounced(1, "stop"):  # B -> stop
            self.teleop_active = False
            self.calibrated = False
            self.vel_cmd = [0.0] * 6
            self.call_service(self.stop_client, Stop.Request())
            self._arm_started = False
            self.get_logger().warn("EMERGENCY STOP + teleop disarmed")

        if pressed_debounced(5, "home"):  # RB -> home
            self.teleop_active = False
            self.calibrated = False
            self.vel_cmd = [0.0] * 6
            self.call_service(self.home_client, HomeArm.Request())
            self._arm_started = False
            self.get_logger().info("Home requested + teleop disarmed")

        if pressed_debounced(0, "start"):  # A -> start
            self.call_service(self.start_client, Start.Request())
            self._arm_started = True

        if pressed_debounced(2, "toggle"):  # X toggle teleop
            self.teleop_active = not self.teleop_active
            self.calibrated = False
            if not self.teleop_active:
                self.vel_cmd = [0.0] * 6
            self.get_logger().info(f"teleop_active={self.teleop_active}")

        # Wrist rotation from right stick horizontal for xbox/hybrid velocity mode
        if self.control_mode == "velocity" and self.input_mode in ("xbox", "hybrid"):
            self.vel_cmd[5] = -self._axis_with_deadzone(msg.axes[3], self.max_ang_vel)

        if self.input_mode == "xbox" and self.control_mode == "velocity":
            self.vel_cmd[0] = self._axis_with_deadzone(msg.axes[1], self.max_lin_vel)
            self.vel_cmd[1] = self._axis_with_deadzone(msg.axes[0], self.max_lin_vel)
            self.vel_cmd[2] = self._axis_with_deadzone(msg.axes[4], self.max_lin_vel)

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

    def udp_loop(self):
        fmt = "<fffffff"
        pkt_size = struct.calcsize(fmt)
        sock = None

        while rclpy.ok() and not self._stop_event.is_set():
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
                            f"UDP bind failed on {self.udp_ip}:{self.udp_port}: {exc}. "
                            f"Retrying every {self.udp_bind_retry_sec:.1f}s. "
                            "Close other process using this port."
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

            latest = None
            while True:
                try:
                    data, _ = sock.recvfrom(1024)
                    if len(data) == pkt_size:
                        latest = struct.unpack(fmt, data)
                except BlockingIOError:
                    break
                except OSError:
                    # Socket became invalid, rebinding loop will recover.
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
                return self._clamp(delta * self.udp_gain, self.max_lin_vel)

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

    def publish_control(self):
        if self.require_joy_keepalive and (time.time() - self.last_joy_msg_time) > self.joy_timeout_sec:
            self.teleop_active = False
            self.calibrated = False
            self.vel_cmd = [0.0] * 6

        if self.control_mode == "pose_action":
            self.publish_pose_goal()
            return

        command_path_ready, gate_reason = self._command_path_ready()
        wants_motion = any(abs(v) > 1e-6 for v in self.vel_cmd[:3] + [self.vel_cmd[5]])

        msg = PoseVelocity()
        if self.teleop_active and (not self.require_command_path_ready or command_path_ready):
            if self.auto_start_arm and not self._arm_started and self.start_client.service_is_ready():
                self.call_service(self.start_client, Start.Request())
                self._arm_started = True
                self.get_logger().info("Auto-started arm driver for UDP teleop.")
            msg.twist_linear_x = float(self.vel_cmd[0])
            msg.twist_linear_y = float(self.vel_cmd[1])
            msg.twist_linear_z = float(self.vel_cmd[2])
            msg.twist_angular_x = 0.0
            msg.twist_angular_y = 0.0
            msg.twist_angular_z = float(self._clamp(self.vel_cmd[5], self.max_ang_vel))
        elif self.teleop_active and wants_motion and self.require_command_path_ready:
            now = time.time()
            if now - self._last_gate_log_t > 1.0:
                self._last_gate_log_t = now
                self.get_logger().error(f"Motion gated: {gate_reason}")

        self.velocity_pub.publish(msg)

        now = time.time()
        if now - self._last_debug_log_t > 2.0:
            self._last_debug_log_t = now
            start_ready = self.start_client.service_is_ready()
            stop_ready = self.stop_client.service_is_ready()
            home_ready = self.home_client.service_is_ready()
            sub_count = self.velocity_pub.get_subscription_count()
            self.get_logger().info(
                f"state teleop={self.teleop_active} arm_started={self._arm_started} "
                f"svc(start={start_ready},stop={stop_ready},home={home_ready}) "
                f"path(subscribers={sub_count},udp_bound={self._udp_bound}) "
                f"cmd=({msg.twist_linear_x:.3f},{msg.twist_linear_y:.3f},{msg.twist_linear_z:.3f},{msg.twist_angular_z:.3f})"
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

        with self.state_lock:
            pose = self.latest_udp_pose[:]

        goal = ArmPose.Goal()
        goal.pose.header.stamp = self.get_clock().now().to_msg()
        goal.pose.header.frame_id = self.pose_frame_id
        goal.pose.pose.position.x = pose[0]
        goal.pose.pose.position.y = pose[1]
        goal.pose.pose.position.z = pose[2]
        goal.pose.pose.orientation.w = pose[3]
        goal.pose.pose.orientation.x = pose[4]
        goal.pose.pose.orientation.y = pose[5]
        goal.pose.pose.orientation.z = pose[6]
        self.pose_action_client.send_goal_async(goal)

    def send_gripper(self, target):
        if not self.finger_client.server_is_ready():
            return
        goal_msg = SetFingersPosition.Goal()
        goal_msg.fingers.finger1, goal_msg.fingers.finger2, goal_msg.fingers.finger3 = target
        self.finger_client.send_goal_async(goal_msg)

    def call_service(self, client, request):
        if client.service_is_ready():
            client.call_async(request)

    def _services_ready(self):
        return (
            self.start_client.service_is_ready()
            and self.stop_client.service_is_ready()
            and self.home_client.service_is_ready()
        )

    def _command_path_ready(self):
        if not self._services_ready():
            return False, "kinova services not ready (start/stop/home)"
        if self.input_mode in ("udp", "hybrid") and not self._udp_bound:
            return False, "udp listener not bound"
        sub_count = self.velocity_pub.get_subscription_count()
        if sub_count < 1:
            return False, "no subscriber on cartesian_velocity (bridge/driver path missing)"
        return True, "ok"

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
            zero = PoseVelocity()
            self.velocity_pub.publish(zero)
        except Exception:
            pass
        try:
            self.udp_thread.join(timeout=0.5)
        except Exception:
            pass


def main(args=None):
    rclpy.init(args=args)
    node = Axe4BridgeController()
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
