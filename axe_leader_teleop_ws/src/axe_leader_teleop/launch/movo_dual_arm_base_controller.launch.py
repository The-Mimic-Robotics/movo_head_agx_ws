#!/usr/bin/env python3
"""Dual-arm + base toggle Xbox controller."""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    device_arg = DeclareLaunchArgument(
        "device", default_value="/dev/input/js0",
        description="Joystick device path")

    deadzone_arg = DeclareLaunchArgument(
        "deadzone", default_value="0.05",
        description="Joystick deadzone")

    locked_joints_arg = DeclareLaunchArgument(
        "locked_joints", default_value="1",
        description="Comma-separated 1-indexed joint numbers to lock (e.g. 1 or 1,5). "
                    "Default 1 = lock joint 1. Empty string = Cartesian velocity mode (no locking).")

    max_joint_vel_deg_arg = DeclareLaunchArgument(
        "max_joint_vel_deg", default_value="45.0",
        description="Per-joint velocity safety clamp (deg/s)")
    respawn_joy_arg = DeclareLaunchArgument(
        "respawn_joy", default_value="false",
        description="Respawn joy node on crash (disable to avoid participant storm while debugging).")
    enable_home_pose_cycle_arg = DeclareLaunchArgument(
        "enable_home_pose_cycle",
        default_value="true",
        description="Run double-tap-A home pose cycler node",
    )
    home_cycle_joy_topic_arg = DeclareLaunchArgument(
        "home_cycle_joy_topic",
        default_value="/joy",
        description="Joy topic for home pose cycler",
    )
    home_cycle_double_tap_sec_arg = DeclareLaunchArgument(
        "home_cycle_double_tap_sec",
        default_value="0.4",
        description="Max gap (s) between A presses to count as double tap",
    )
    home_cycle_start_pose_arg = DeclareLaunchArgument(
        "home_cycle_start_pose",
        default_value="",
        description="Optional starting pose name for cycler (empty = first in YAML)",
    )

    joy_node = Node(
        package="joy_linux",
        executable="joy_linux_node",
        name="joy_node",
        output="screen",
        parameters=[{
            "device_name": LaunchConfiguration("device"),
            "deadzone": LaunchConfiguration("deadzone"),
            "autorepeat_rate": 0.0,
        }],
        respawn=LaunchConfiguration("respawn_joy"),
        respawn_delay=2.0,
    )

    controller_node = Node(
        package="axe_leader_teleop",
        executable="movo_dual_arm_base_controller",
        name="movo_dual_arm_base_controller",
        output="screen",
        parameters=[{
            "locked_joints": ParameterValue(LaunchConfiguration("locked_joints"), value_type=str),
            "max_joint_vel_deg": LaunchConfiguration("max_joint_vel_deg"),
        }],
    )

    home_pose_cycle_node = Node(
        package="axe_leader_teleop",
        executable="home_pose_cycle_teleop",
        name="home_pose_cycle_teleop",
        output="screen",
        condition=IfCondition(LaunchConfiguration("enable_home_pose_cycle")),
        parameters=[{
            "joy_topic": LaunchConfiguration("home_cycle_joy_topic"),
            "double_tap_sec": LaunchConfiguration("home_cycle_double_tap_sec"),
            "start_pose_name": LaunchConfiguration("home_cycle_start_pose"),
        }],
    )

    home_service_node = Node(
        package="axe_leader_teleop",
        executable="movo_custom_home_service",
        name="movo_custom_home_service",
        output="screen",
    )

    return LaunchDescription([
        device_arg,
        deadzone_arg,
        locked_joints_arg,
        max_joint_vel_deg_arg,
        respawn_joy_arg,
        enable_home_pose_cycle_arg,
        home_cycle_joy_topic_arg,
        home_cycle_double_tap_sec_arg,
        home_cycle_start_pose_arg,
        joy_node,
        controller_node,
        home_pose_cycle_node,
        home_service_node,
    ])
