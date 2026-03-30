#!/usr/bin/env python3
"""Standalone UDP → ROS 2 bridge only. Launch once (e.g. background); do not nest in other launches.

Binds UDP and publishes /bi_axe_left/*, /bi_axe_right/*, and optionally legacy /axe_leader/*.
Other launches only subscribe to those topics.
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("udp_ip", default_value="0.0.0.0"),
        DeclareLaunchArgument("udp_port", default_value="5005"),
        DeclareLaunchArgument("left_namespace", default_value="bi_axe_left"),
        DeclareLaunchArgument("right_namespace", default_value="bi_axe_right"),
        DeclareLaunchArgument("legacy_namespace", default_value="axe_leader"),
        DeclareLaunchArgument("publish_legacy_untagged", default_value="false"),
        DeclareLaunchArgument("frame_id_eef", default_value="base_link"),
        DeclareLaunchArgument("frame_id_imu", default_value="imu_link"),
        DeclareLaunchArgument("drain_period_sec", default_value="0.001"),
        Node(
            package="axe_leader_teleop",
            executable="bi_axe_udp_ros2_bridge",
            name="bi_axe_udp_ros2_bridge",
            output="screen",
            parameters=[{
                "udp_ip": LaunchConfiguration("udp_ip"),
                "udp_port": LaunchConfiguration("udp_port"),
                "left_namespace": LaunchConfiguration("left_namespace"),
                "right_namespace": LaunchConfiguration("right_namespace"),
                "legacy_namespace": LaunchConfiguration("legacy_namespace"),
                "publish_legacy_untagged": LaunchConfiguration("publish_legacy_untagged"),
                "frame_id_eef": LaunchConfiguration("frame_id_eef"),
                "frame_id_imu": LaunchConfiguration("frame_id_imu"),
                "drain_period_sec": LaunchConfiguration("drain_period_sec"),
            }],
        ),
    ])
