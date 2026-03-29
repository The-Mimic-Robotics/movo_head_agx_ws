#!/usr/bin/env python3
"""UDP → ROS 2 bridge for AXE4 leader packets (lerobot udp_transport.py wire format).

Mirrors topics from axe_leader/transport/ros2_transport.py and udp_transport.py:
  /{namespace}/eef_pose                 geometry_msgs/PoseStamped   28-byte <7f> legacy pose
  /{namespace}/eef_pose_absolute       geometry_msgs/PoseStamped   29-byte b'A' + <7f> absolute pose
  /{namespace}/eef_position             geometry_msgs/PoseStamped   13-byte b'P' + xyz (identity quat)
  /{namespace}/eef_position_absolute    geometry_msgs/PoseStamped   13-byte b'Q' + xyz (identity quat)
  /{namespace}/eef_twist                geometry_msgs/TwistStamped 25-byte b'T' + 6 floats
  /{namespace}/imu                      sensor_msgs/Imu             29-byte b'I' + quat + rpy
  /{namespace}/imu_rpy                  geometry_msgs/Vector3Stamped  (roll, pitch, yaw from I packet)
  /{namespace}/joy                      sensor_msgs/Joy             15-byte b'J' + 3 floats + 2 buttons

Floats are passed through as Python float (double in ROS msg fields) — no loss vs UDP float32
beyond the wire format itself.
"""

from __future__ import annotations

import socket
import struct
import time

import rclpy
from geometry_msgs.msg import PoseStamped, TwistStamped, Vector3Stamped
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from sensor_msgs.msg import Imu, Joy


class Axe4UdpBridge(Node):
    FMT_POSE = "<7f"
    FMT_POSE_ABS = "<c7f"  # b'A' + x,y,z,qw,qx,qy,qz
    FMT_TWIST = "<c6f"
    FMT_POS = "<c3f"  # b'P' or b'Q' + xyz
    FMT_IMU = "<c7f"
    FMT_JOY = "<c3f2B"

    LEN_POSE = struct.calcsize(FMT_POSE)
    LEN_POSE_ABS = struct.calcsize(FMT_POSE_ABS)
    LEN_TWIST = struct.calcsize(FMT_TWIST)
    LEN_POS = struct.calcsize(FMT_POS)
    LEN_IMU = struct.calcsize(FMT_IMU)
    LEN_JOY = struct.calcsize(FMT_JOY)

    def __init__(self) -> None:
        super().__init__("axe4_udp_bridge")

        self.declare_parameter("udp_ip", "0.0.0.0")
        self.declare_parameter("udp_port", 5005)
        self.declare_parameter("topic_namespace", "axe4")
        self.declare_parameter("frame_id_eef", "base_link")
        self.declare_parameter("frame_id_imu", "imu_link")
        self.declare_parameter("drain_period_sec", 0.001)

        udp_ip = str(self.get_parameter("udp_ip").value)
        udp_port = int(self.get_parameter("udp_port").value)
        ns = str(self.get_parameter("topic_namespace").value).strip().strip("/")
        if not ns:
            ns = "axe4"
        self._frame_eef = str(self.get_parameter("frame_id_eef").value)
        self._frame_imu = str(self.get_parameter("frame_id_imu").value)
        period = float(self.get_parameter("drain_period_sec").value)
        period = max(period, 0.0005)

        qos = QoSProfile(
            depth=10,
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
        )

        def tp(name: str) -> str:
            return f"/{ns}/{name}"

        self._pub_pose = self.create_publisher(PoseStamped, tp("eef_pose"), qos)
        self._pub_pose_abs = self.create_publisher(PoseStamped, tp("eef_pose_absolute"), qos)
        self._pub_position = self.create_publisher(PoseStamped, tp("eef_position"), qos)
        self._pub_position_abs = self.create_publisher(PoseStamped, tp("eef_position_absolute"), qos)
        self._pub_twist = self.create_publisher(TwistStamped, tp("eef_twist"), qos)
        self._pub_imu = self.create_publisher(Imu, tp("imu"), qos)
        self._pub_imu_rpy = self.create_publisher(Vector3Stamped, tp("imu_rpy"), qos)
        self._pub_joy = self.create_publisher(Joy, tp("joy"), qos)

        self._sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self._sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._sock.bind((udp_ip, udp_port))
        self._sock.setblocking(False)

        self._rx_counts = {"pose": 0, "A": 0, "P": 0, "Q": 0, "T": 0, "I": 0, "J": 0, "bad": 0}
        self._last_stat = time.monotonic()

        self.create_timer(period, self._drain_udp)
        self.get_logger().info(
            f"AXE4 UDP bridge bind {udp_ip}:{udp_port} → "
            f"/{ns}/eef_pose|eef_pose_absolute|eef_position|eef_position_absolute|"
            f"eef_twist|imu|imu_rpy|joy"
        )

    def _stamp(self):
        return self.get_clock().now().to_msg()

    def _drain_udp(self) -> None:
        while rclpy.ok():
            try:
                chunk, _ = self._sock.recvfrom(2048)
            except BlockingIOError:
                break
            n = len(chunk)
            st = self._stamp()

            try:
                if n == self.LEN_POSE:
                    x, y, z, qw, qx, qy, qz = struct.unpack(self.FMT_POSE, chunk)
                    msg = PoseStamped()
                    msg.header.stamp = st
                    msg.header.frame_id = self._frame_eef
                    msg.pose.position.x = float(x)
                    msg.pose.position.y = float(y)
                    msg.pose.position.z = float(z)
                    msg.pose.orientation.w = float(qw)
                    msg.pose.orientation.x = float(qx)
                    msg.pose.orientation.y = float(qy)
                    msg.pose.orientation.z = float(qz)
                    self._pub_pose.publish(msg)
                    self._rx_counts["pose"] += 1

                elif n == self.LEN_POSE_ABS and chunk[:1] == b"A":
                    _, x, y, z, qw, qx, qy, qz = struct.unpack(self.FMT_POSE_ABS, chunk)
                    msg = PoseStamped()
                    msg.header.stamp = st
                    msg.header.frame_id = self._frame_eef
                    msg.pose.position.x = float(x)
                    msg.pose.position.y = float(y)
                    msg.pose.position.z = float(z)
                    msg.pose.orientation.w = float(qw)
                    msg.pose.orientation.x = float(qx)
                    msg.pose.orientation.y = float(qy)
                    msg.pose.orientation.z = float(qz)
                    self._pub_pose_abs.publish(msg)
                    self._rx_counts["A"] += 1

                elif n == self.LEN_TWIST and chunk[:1] == b"T":
                    _, vx, vy, vz, wx, wy, wz = struct.unpack(self.FMT_TWIST, chunk)
                    msg = TwistStamped()
                    msg.header.stamp = st
                    msg.header.frame_id = self._frame_eef
                    msg.twist.linear.x = float(vx)
                    msg.twist.linear.y = float(vy)
                    msg.twist.linear.z = float(vz)
                    msg.twist.angular.x = float(wx)
                    msg.twist.angular.y = float(wy)
                    msg.twist.angular.z = float(wz)
                    self._pub_twist.publish(msg)
                    self._rx_counts["T"] += 1

                elif n == self.LEN_POS and chunk[:1] == b"P":
                    _, x, y, z = struct.unpack(self.FMT_POS, chunk)
                    msg = PoseStamped()
                    msg.header.stamp = st
                    msg.header.frame_id = self._frame_eef
                    msg.pose.position.x = float(x)
                    msg.pose.position.y = float(y)
                    msg.pose.position.z = float(z)
                    msg.pose.orientation.w = 1.0
                    msg.pose.orientation.x = 0.0
                    msg.pose.orientation.y = 0.0
                    msg.pose.orientation.z = 0.0
                    self._pub_position.publish(msg)
                    self._rx_counts["P"] += 1

                elif n == self.LEN_POS and chunk[:1] == b"Q":
                    _, x, y, z = struct.unpack(self.FMT_POS, chunk)
                    msg = PoseStamped()
                    msg.header.stamp = st
                    msg.header.frame_id = self._frame_eef
                    msg.pose.position.x = float(x)
                    msg.pose.position.y = float(y)
                    msg.pose.position.z = float(z)
                    msg.pose.orientation.w = 1.0
                    msg.pose.orientation.x = 0.0
                    msg.pose.orientation.y = 0.0
                    msg.pose.orientation.z = 0.0
                    self._pub_position_abs.publish(msg)
                    self._rx_counts["Q"] += 1

                elif n == self.LEN_IMU and chunk[:1] == b"I":
                    _, qw, qx, qy, qz, roll, pitch, yaw = struct.unpack(self.FMT_IMU, chunk)
                    imu = Imu()
                    imu.header.stamp = st
                    imu.header.frame_id = self._frame_imu
                    imu.orientation.w = float(qw)
                    imu.orientation.x = float(qx)
                    imu.orientation.y = float(qy)
                    imu.orientation.z = float(qz)
                    imu.orientation_covariance[0] = -1.0
                    imu.angular_velocity_covariance[0] = -1.0
                    imu.linear_acceleration_covariance[0] = -1.0
                    self._pub_imu.publish(imu)

                    rpy = Vector3Stamped()
                    rpy.header.stamp = st
                    rpy.header.frame_id = self._frame_imu
                    rpy.vector.x = float(roll)
                    rpy.vector.y = float(pitch)
                    rpy.vector.z = float(yaw)
                    self._pub_imu_rpy.publish(rpy)
                    self._rx_counts["I"] += 1

                elif n == self.LEN_JOY and chunk[:1] == b"J":
                    _, jx, jy, jz, sw, sw2 = struct.unpack(self.FMT_JOY, chunk)
                    msg = Joy()
                    msg.header.stamp = st
                    msg.header.frame_id = self._frame_eef
                    msg.axes = [float(jx), float(jy), float(jz)]
                    msg.buttons = [int(sw), int(sw2)]
                    self._pub_joy.publish(msg)
                    self._rx_counts["J"] += 1

                else:
                    self._rx_counts["bad"] += 1

            except struct.error as e:
                self._rx_counts["bad"] += 1
                self.get_logger().warning(f"struct error len={n}: {e}")

        now = time.monotonic()
        if now - self._last_stat >= 5.0:
            self._last_stat = now
            c = self._rx_counts
            self.get_logger().info(
                f"rx/5s pose={c['pose']} A={c['A']} P={c['P']} Q={c['Q']} "
                f"T={c['T']} I={c['I']} J={c['J']} bad={c['bad']}"
            )
            for k in c:
                c[k] = 0

    def destroy_node(self) -> bool:
        try:
            self._sock.close()
        except Exception:
            pass
        return super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = Axe4UdpBridge()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
