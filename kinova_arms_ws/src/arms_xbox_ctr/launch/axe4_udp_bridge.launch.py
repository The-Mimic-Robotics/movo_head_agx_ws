#!/usr/bin/env python3
"""Bind UDP (AXE4 lerobot wire format) and republish on /axe4/* ROS 2 topics.

If `ros2 launch arms_xbox_ctr axe4_udp_bridge.launch.py` fails (wrong share path),
prepend the Kinova install *before* other workspaces, or launch by file path after build:
  ros2 launch /path/to/kinova_arms_ws/install/share/arms_xbox_ctr/launch/axe4_udp_bridge.launch.py
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("udp_ip", default_value="0.0.0.0"),
        DeclareLaunchArgument("udp_port", default_value="5005"),
        DeclareLaunchArgument("topic_namespace", default_value="axe4"),
        DeclareLaunchArgument("frame_id_eef", default_value="base_link"),
        DeclareLaunchArgument("frame_id_imu", default_value="imu_link"),
        DeclareLaunchArgument("drain_period_sec", default_value="0.001"),
        Node(
            package="arms_xbox_ctr",
            executable="axe4_udp_bridge",
            name="axe4_udp_bridge",
            output="screen",
            parameters=[{
                "udp_ip": LaunchConfiguration("udp_ip"),
                "udp_port": LaunchConfiguration("udp_port"),
                "topic_namespace": LaunchConfiguration("topic_namespace"),
                "frame_id_eef": LaunchConfiguration("frame_id_eef"),
                "frame_id_imu": LaunchConfiguration("frame_id_imu"),
                "drain_period_sec": LaunchConfiguration("drain_period_sec"),
            }],
        ),
    ])
