#!/usr/bin/env python3
"""AXE4 teleop handles → MOVO base /cmd_vel + gripper toggles (Kinova MOVO)."""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            DeclareLaunchArgument(
                "cmd_vel_topic", default_value="/cmd_vel", description="Twist for mecanum base"
            ),
            DeclareLaunchArgument(
                "left_joy_topic",
                default_value="/axe4/joy",
                description="sensor_msgs/Joy for left handle (linear + strafe + grip)",
            ),
            DeclareLaunchArgument(
                "use_right_joy",
                default_value="false",
                description="Subscribe to right handle for yaw + right gripper",
            ),
            DeclareLaunchArgument(
                "right_joy_topic",
                default_value="/axe4/joy_right",
                description="Joy for right handle when use_right_joy:=true",
            ),
            DeclareLaunchArgument("max_linear", default_value="0.6"),
            DeclareLaunchArgument("max_angular", default_value="0.8"),
            DeclareLaunchArgument("deadzone", default_value="0.08"),
            DeclareLaunchArgument(
                "require_deadman",
                default_value="false",
                description="If true: base motion only while button 1 (or *_deadman_button) held per handle",
            ),
            DeclareLaunchArgument("left_deadman_button", default_value="1"),
            DeclareLaunchArgument("right_deadman_button", default_value="1"),
            DeclareLaunchArgument(
                "gripper_release",
                default_value="-0.25",
                description="Axis must go above this after a toggle before the next can arm (hysteresis)",
            ),
            Node(
                package="arms_xbox_ctr",
                executable="axe4_base_teleop",
                name="axe4_base_teleop",
                output="screen",
                parameters=[
                    {
                        "cmd_vel_topic": LaunchConfiguration("cmd_vel_topic"),
                        "left_joy_topic": LaunchConfiguration("left_joy_topic"),
                        "use_right_joy": LaunchConfiguration("use_right_joy"),
                        "right_joy_topic": LaunchConfiguration("right_joy_topic"),
                        "max_linear": LaunchConfiguration("max_linear"),
                        "max_angular": LaunchConfiguration("max_angular"),
                        "deadzone": LaunchConfiguration("deadzone"),
                        "require_deadman": LaunchConfiguration("require_deadman"),
                        "left_deadman_button": LaunchConfiguration("left_deadman_button"),
                        "right_deadman_button": LaunchConfiguration("right_deadman_button"),
                        "gripper_release": LaunchConfiguration("gripper_release"),
                    }
                ],
            ),
        ]
    )
