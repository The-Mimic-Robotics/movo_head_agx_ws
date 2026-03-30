#!/usr/bin/env python3
"""UDP → ROS 2: lerobot BiAxeUDPTransport (L/R tagged) + optional legacy single-arm packets.

Matches ``lerobot/.../bi_axe_leader/udp_transport.py`` for tagged streams.

Wire format (tagged):
  Relative pose:      <cc7f>  arm('L'|'R'), 'O', x,y,z,qw,qx,qy,qz
  Absolute pose:      <cc7f>  arm, 'A', x,y,z,qw,qx,qy,qz
  Relative position:  <cc3f>  arm, 'P', x,y,z
  Absolute position:  <cc3f>  arm, 'Q', x,y,z
  Twist:              <cc6f>  arm, 'T', vx,vy,vz,wx,wy,wz
  IMU:                <cc7f>  arm, 'I', qw,qx,qy,qz,roll,pitch,yaw
  Buttons:            <cc3f2B> arm, 'J', joy_x,joy_y,joy_z,sw,sw2

Legacy (untagged) single-arm packets (same lengths as single-namespace AXE leader bridge):
  publish to ``legacy_namespace`` (default ``axe_leader``) when ``publish_legacy_untagged`` is true.
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


def _qos() -> QoSProfile:
    return QoSProfile(
        depth=10,
        reliability=ReliabilityPolicy.RELIABLE,
        durability=DurabilityPolicy.VOLATILE,
    )


class _NsPublishers:
    """Publishers for one topic namespace (e.g. bi_axe_left)."""

    def __init__(self, node: Node, ns: str, frame_eef: str, frame_imu: str) -> None:
        ns = ns.strip().strip("/")
        p = node.create_publisher

        def tp(name: str) -> str:
            return f"/{ns}/{name}"

        self._frame_eef = frame_eef
        self._frame_imu = frame_imu
        self._pub_pose = p(PoseStamped, tp("eef_pose"), _qos())
        self._pub_pose_abs = p(PoseStamped, tp("eef_pose_absolute"), _qos())
        self._pub_position = p(PoseStamped, tp("eef_position"), _qos())
        self._pub_position_abs = p(PoseStamped, tp("eef_position_absolute"), _qos())
        self._pub_twist = p(TwistStamped, tp("eef_twist"), _qos())
        self._pub_imu = p(Imu, tp("imu"), _qos())
        self._pub_imu_rpy = p(Vector3Stamped, tp("imu_rpy"), _qos())
        self._pub_joy = p(Joy, tp("joy"), _qos())
        self._node = node

    def stamp(self):
        return self._node.get_clock().now().to_msg()

    def pub_pose(self, st, x, y, z, qw, qx, qy, qz):
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

    def pub_pose_abs(self, st, x, y, z, qw, qx, qy, qz):
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

    def pub_pos(self, st, x, y, z, abs_: bool):
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
        if abs_:
            self._pub_position_abs.publish(msg)
        else:
            self._pub_position.publish(msg)

    def pub_twist(self, st, vx, vy, vz, wx, wy, wz):
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

    def pub_imu(self, st, qw, qx, qy, qz, roll, pitch, yaw):
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

    def pub_joy(self, st, jx, jy, jz, sw, sw2):
        msg = Joy()
        msg.header.stamp = st
        msg.header.frame_id = self._frame_eef
        msg.axes = [float(jx), float(jy), float(jz)]
        msg.buttons = [int(sw), int(sw2)]
        self._pub_joy.publish(msg)


class BiAxeUdpRos2Bridge(Node):
    FMT_POSE = "<7f"
    FMT_POSE_ABS = "<c7f"
    FMT_TWIST = "<c6f"
    FMT_POS = "<c3f"
    FMT_IMU = "<c7f"
    FMT_JOY = "<c3f2B"

    FMT_TAG_POSE = "<cc7f"
    FMT_TAG_TWIST = "<cc6f"
    FMT_TAG_POS = "<cc3f"
    FMT_TAG_IMU = "<cc7f"
    FMT_TAG_JOY = "<cc3f2B"

    LEN_POSE = struct.calcsize(FMT_POSE)
    LEN_POSE_ABS = struct.calcsize(FMT_POSE_ABS)
    LEN_TWIST = struct.calcsize(FMT_TWIST)
    LEN_POS = struct.calcsize(FMT_POS)
    LEN_IMU = struct.calcsize(FMT_IMU)
    LEN_JOY = struct.calcsize(FMT_JOY)

    LEN_TAG_30 = struct.calcsize(FMT_TAG_POSE)
    LEN_TAG_26 = struct.calcsize(FMT_TAG_TWIST)
    LEN_TAG_14 = struct.calcsize(FMT_TAG_POS)
    LEN_TAG_16 = struct.calcsize(FMT_TAG_JOY)

    def __init__(self) -> None:
        super().__init__("bi_axe_udp_ros2_bridge")

        self.declare_parameter("udp_ip", "0.0.0.0")
        self.declare_parameter("udp_port", 5005)
        self.declare_parameter("left_namespace", "bi_axe_left")
        self.declare_parameter("right_namespace", "bi_axe_right")
        self.declare_parameter("legacy_namespace", "axe_leader")
        self.declare_parameter("publish_legacy_untagged", True)
        self.declare_parameter("frame_id_eef", "base_link")
        self.declare_parameter("frame_id_imu", "imu_link")
        self.declare_parameter("drain_period_sec", 0.001)

        udp_ip = str(self.get_parameter("udp_ip").value)
        udp_port = int(self.get_parameter("udp_port").value)
        left_ns = str(self.get_parameter("left_namespace").value).strip().strip("/") or "bi_axe_left"
        right_ns = str(self.get_parameter("right_namespace").value).strip().strip("/") or "bi_axe_right"
        legacy_ns = str(self.get_parameter("legacy_namespace").value).strip().strip("/") or "axe_leader"
        self._legacy_on = bool(self.get_parameter("publish_legacy_untagged").value)
        fe = str(self.get_parameter("frame_id_eef").value)
        fi = str(self.get_parameter("frame_id_imu").value)
        period = max(float(self.get_parameter("drain_period_sec").value), 0.0005)

        self._pub_left = _NsPublishers(self, left_ns, fe, fi)
        self._pub_right = _NsPublishers(self, right_ns, fe, fi)
        self._pub_legacy = _NsPublishers(self, legacy_ns, fe, fi) if self._legacy_on else None

        self._sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self._sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self._sock.bind((udp_ip, udp_port))
        self._sock.setblocking(False)

        self._rx_counts: dict[str, int] = {}
        self._last_stat = time.monotonic()

        self.create_timer(period, self._drain_udp)
        self.get_logger().info(
            f"Bi-AXE UDP → ROS 2 bind {udp_ip}:{udp_port} → "
            f"/{left_ns}/* /{right_ns}/*"
            + (f" legacy /{legacy_ns}/*" if self._legacy_on else "")
        )

    def _arm_pub(self, tag: bytes) -> _NsPublishers | None:
        if tag == b"L":
            return self._pub_left
        if tag == b"R":
            return self._pub_right
        return None

    def _bump(self, key: str) -> None:
        self._rx_counts[key] = self._rx_counts.get(key, 0) + 1

    def _drain_udp(self) -> None:
        while rclpy.ok():
            try:
                chunk, _ = self._sock.recvfrom(2048)
            except BlockingIOError:
                break
            n = len(chunk)
            st = self.get_clock().now().to_msg()

            try:
                if n >= 2 and chunk[0:1] in (b"L", b"R"):
                    pub = self._arm_pub(chunk[0:1])
                    if pub is None:
                        self._bump("bad")
                        continue
                    kind = chunk[1:2]

                    if n == self.LEN_TAG_30 and kind == b"O":
                        _, _, x, y, z, qw, qx, qy, qz = struct.unpack(self.FMT_TAG_POSE, chunk)
                        pub.pub_pose(st, x, y, z, qw, qx, qy, qz)
                        self._bump("L_O" if chunk[0:1] == b"L" else "R_O")
                    elif n == self.LEN_TAG_30 and kind == b"A":
                        _, _, x, y, z, qw, qx, qy, qz = struct.unpack(self.FMT_TAG_POSE, chunk)
                        pub.pub_pose_abs(st, x, y, z, qw, qx, qy, qz)
                        self._bump("L_A" if chunk[0:1] == b"L" else "R_A")
                    elif n == self.LEN_TAG_14 and kind == b"P":
                        _, _, x, y, z = struct.unpack(self.FMT_TAG_POS, chunk)
                        pub.pub_pos(st, x, y, z, False)
                        self._bump("L_P" if chunk[0:1] == b"L" else "R_P")
                    elif n == self.LEN_TAG_14 and kind == b"Q":
                        _, _, x, y, z = struct.unpack(self.FMT_TAG_POS, chunk)
                        pub.pub_pos(st, x, y, z, True)
                        self._bump("L_Q" if chunk[0:1] == b"L" else "R_Q")
                    elif n == self.LEN_TAG_26 and kind == b"T":
                        _, _, vx, vy, vz, wx, wy, wz = struct.unpack(self.FMT_TAG_TWIST, chunk)
                        pub.pub_twist(st, vx, vy, vz, wx, wy, wz)
                        self._bump("L_T" if chunk[0:1] == b"L" else "R_T")
                    elif n == self.LEN_TAG_30 and kind == b"I":
                        _, _, qw, qx, qy, qz, roll, pitch, yaw = struct.unpack(self.FMT_TAG_IMU, chunk)
                        pub.pub_imu(st, qw, qx, qy, qz, roll, pitch, yaw)
                        self._bump("L_I" if chunk[0:1] == b"L" else "R_I")
                    elif n == self.LEN_TAG_16 and kind == b"J":
                        _, _, jx, jy, jz, sw, sw2 = struct.unpack(self.FMT_TAG_JOY, chunk)
                        pub.pub_joy(st, jx, jy, jz, sw, sw2)
                        self._bump("L_J" if chunk[0:1] == b"L" else "R_J")
                    else:
                        self._bump("bad")
                    continue

                if not self._legacy_on or self._pub_legacy is None:
                    self._bump("bad")
                    continue

                lp = self._pub_legacy
                if n == self.LEN_POSE:
                    x, y, z, qw, qx, qy, qz = struct.unpack(self.FMT_POSE, chunk)
                    lp.pub_pose(st, x, y, z, qw, qx, qy, qz)
                    self._bump("pose")
                elif n == self.LEN_POSE_ABS and chunk[:1] == b"A":
                    _, x, y, z, qw, qx, qy, qz = struct.unpack(self.FMT_POSE_ABS, chunk)
                    lp.pub_pose_abs(st, x, y, z, qw, qx, qy, qz)
                    self._bump("A")
                elif n == self.LEN_TWIST and chunk[:1] == b"T":
                    _, vx, vy, vz, wx, wy, wz = struct.unpack(self.FMT_TWIST, chunk)
                    lp.pub_twist(st, vx, vy, vz, wx, wy, wz)
                    self._bump("T")
                elif n == self.LEN_POS and chunk[:1] == b"P":
                    _, x, y, z = struct.unpack(self.FMT_POS, chunk)
                    lp.pub_pos(st, x, y, z, False)
                    self._bump("P")
                elif n == self.LEN_POS and chunk[:1] == b"Q":
                    _, x, y, z = struct.unpack(self.FMT_POS, chunk)
                    lp.pub_pos(st, x, y, z, True)
                    self._bump("Q")
                elif n == self.LEN_IMU and chunk[:1] == b"I":
                    _, qw, qx, qy, qz, roll, pitch, yaw = struct.unpack(self.FMT_IMU, chunk)
                    lp.pub_imu(st, qw, qx, qy, qz, roll, pitch, yaw)
                    self._bump("I")
                elif n == self.LEN_JOY and chunk[:1] == b"J":
                    _, jx, jy, jz, sw, sw2 = struct.unpack(self.FMT_JOY, chunk)
                    lp.pub_joy(st, jx, jy, jz, sw, sw2)
                    self._bump("J")
                else:
                    self._bump("bad")

            except struct.error as e:
                self._bump("bad")
                self.get_logger().warning(f"struct error len={n}: {e}")

        now = time.monotonic()
        if now - self._last_stat >= 5.0:
            self._last_stat = now
            c = self._rx_counts
            self.get_logger().info("rx/5s " + " ".join(f"{k}={v}" for k, v in sorted(c.items())))
            self._rx_counts.clear()

    def destroy_node(self) -> bool:
        try:
            self._sock.close()
        except Exception:
            pass
        return super().destroy_node()


def main(args=None) -> None:
    rclpy.init(args=args)
    node = BiAxeUdpRos2Bridge()
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
