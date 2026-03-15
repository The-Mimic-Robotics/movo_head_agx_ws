#!/usr/bin/env python3
"""
Minimal ROS 2 position sweep test for the AXE4 ros2 input mode.

Publishes smooth sinusoidal sweeps on /axe4/eef_position:
  X back-and-forth → Y back-and-forth → Z back-and-forth → repeat

Usage:
  python3 sim_eef_position_ros2.py
  python3 sim_eef_position_ros2.py --distance 0.08 --period 3.0
"""

import argparse
import math
import time

import rclpy
from geometry_msgs.msg import PoseStamped
from rclpy.node import Node


class EefSweep(Node):
    def __init__(self, distance: float, period: float, rate_hz: float):
        super().__init__("sim_eef_sweep")
        self.pub = self.create_publisher(PoseStamped, "/axe4/eef_position", 1)
        self.distance = distance
        self.period = period
        self.t0 = time.monotonic()
        self.create_timer(1.0 / rate_hz, self.tick)
        self.get_logger().info(
            f"Sweeping ±{distance*100:.1f} cm per axis, period={period:.1f}s"
        )

    def tick(self):
        elapsed = time.monotonic() - self.t0
        cycle = self.period * 3  # full X+Y+Z cycle
        phase = (elapsed % cycle) / self.period  # 0..3
        axis = int(phase)  # 0=X 1=Y 2=Z
        t = (phase - axis) * 2 * math.pi  # 0..2π within this axis
        offset = self.distance * math.sin(t)

        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "base_link"
        xyz = [0.0, 0.0, 0.0]
        xyz[axis] = offset
        msg.pose.position.x = xyz[0]
        msg.pose.position.y = xyz[1]
        msg.pose.position.z = xyz[2]
        self.pub.publish(msg)


def main():
    parser = argparse.ArgumentParser(description="ROS 2 EEF position sweep test")
    parser.add_argument("--distance", type=float, default=0.05, help="Sweep amplitude in meters (default 5 cm)")
    parser.add_argument("--period", type=float, default=4.0, help="Seconds per axis sweep (default 4)")
    parser.add_argument("--rate", type=float, default=50.0, help="Publish rate Hz (default 50)")
    args = parser.parse_args()

    rclpy.init()
    node = EefSweep(args.distance, args.period, args.rate)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == "__main__":
    main()
