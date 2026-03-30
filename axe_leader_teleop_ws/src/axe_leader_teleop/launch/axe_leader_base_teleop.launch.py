#!/usr/bin/env python3
"""Handle Joy → /cmd_vel + grippers. Default topics match bi_axe_udp_ros2_bridge (/bi_axe_left|right/joy).

Xbox /joy (optional): B latches safety override (zero base, ignore handle grippers); A clears.
Run ``joy_linux`` elsewhere if needed (e.g. bi_axe_bimanual already publishes /joy — set include_joy:=false).
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument("cmd_vel_topic", default_value="/cmd_vel"),
        DeclareLaunchArgument("left_joy_topic", default_value="/bi_axe_left/joy"),
        DeclareLaunchArgument("right_joy_topic", default_value="/bi_axe_right/joy"),
        DeclareLaunchArgument("use_right_joy", default_value="true"),
        DeclareLaunchArgument("max_linear", default_value="0.6"),
        DeclareLaunchArgument("max_angular", default_value="0.8"),
        DeclareLaunchArgument("velocity_scale", default_value="0.6"),
        DeclareLaunchArgument("deadzone", default_value="0.08"),
        # Deadman is always required for base motion; default to first handle button (sw).
        DeclareLaunchArgument("left_deadman_button", default_value="0"),
        DeclareLaunchArgument("right_deadman_button", default_value="0"),
        DeclareLaunchArgument("gripper_release", default_value="-0.25"),
        DeclareLaunchArgument("enable_xbox_safety_override", default_value="true"),
        DeclareLaunchArgument("xbox_joy_topic", default_value="/joy"),
        DeclareLaunchArgument(
            "include_joy",
            default_value="false",
            description="If true, start joy_linux for /joy (avoid duplicate if another launch owns Xbox)",
        ),
        DeclareLaunchArgument("joy_device", default_value="/dev/input/js0"),

        Node(
            package="joy_linux",
            executable="joy_linux_node",
            name="joy_node_base_stack",
            output="screen",
            condition=IfCondition(LaunchConfiguration("include_joy")),
            parameters=[{
                "device_name": LaunchConfiguration("joy_device"),
                "deadzone": LaunchConfiguration("deadzone"),
                "autorepeat_rate": 0.0,
            }],
        ),
        Node(
            package="axe_leader_teleop",
            executable="axe_leader_base_teleop",
            name="axe_leader_base_teleop",
            output="screen",
            parameters=[{
                "cmd_vel_topic": LaunchConfiguration("cmd_vel_topic"),
                "left_joy_topic": LaunchConfiguration("left_joy_topic"),
                "right_joy_topic": LaunchConfiguration("right_joy_topic"),
                "use_right_joy": LaunchConfiguration("use_right_joy"),
                "max_linear": LaunchConfiguration("max_linear"),
                "max_angular": LaunchConfiguration("max_angular"),
                "velocity_scale": LaunchConfiguration("velocity_scale"),
                "deadzone": LaunchConfiguration("deadzone"),
                "require_deadman": True,
                "left_deadman_button": LaunchConfiguration("left_deadman_button"),
                "right_deadman_button": LaunchConfiguration("right_deadman_button"),
                "gripper_release": LaunchConfiguration("gripper_release"),
                "enable_xbox_safety_override": LaunchConfiguration("enable_xbox_safety_override"),
                "xbox_joy_topic": LaunchConfiguration("xbox_joy_topic"),
            }],
        ),
    ])
