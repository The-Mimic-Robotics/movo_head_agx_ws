#!/usr/bin/env python3
"""Optional launch for drift_joint_teleop (does not start kinova_teleop)."""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("arm_namespace", default_value="left_arm"),
        DeclareLaunchArgument("leader_twist_topic", default_value="/axe4/eef_twist"),
        DeclareLaunchArgument("leader_pose_topic", default_value="/axe4/eef_position"),
        DeclareLaunchArgument("drift_kp", default_value="2.0"),
        DeclareLaunchArgument("twist_rate", default_value="12.0"),
        DeclareLaunchArgument("speed", default_value="1.0"),
        DeclareLaunchArgument("lock_joint1", default_value="true"),
        Node(
            package="teleop_drift_bridge",
            executable="drift_joint_teleop",
            name="drift_joint_teleop",
            output="screen",
            parameters=[{
                "arm_namespace": LaunchConfiguration("arm_namespace"),
                "leader_twist_topic": LaunchConfiguration("leader_twist_topic"),
                "leader_pose_topic": LaunchConfiguration("leader_pose_topic"),
                "drift_kp": LaunchConfiguration("drift_kp"),
                "twist_rate": LaunchConfiguration("twist_rate"),
                "speed": LaunchConfiguration("speed"),
                "lock_joint1": LaunchConfiguration("lock_joint1"),
            }],
        ),
    ])
