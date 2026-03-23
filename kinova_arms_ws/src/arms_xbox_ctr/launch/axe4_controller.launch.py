#!/usr/bin/env python3
"""Minimal launch for AXE4 leader → one Kinova arm. Realtime velocity on topics (no action server)."""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    device_arg = DeclareLaunchArgument(
        "device", default_value="/dev/input/js0", description="Joystick device"
    )
    deadzone_arg = DeclareLaunchArgument(
        "deadzone", default_value="0.05", description="Joystick deadzone"
    )
    enable_joy_arg = DeclareLaunchArgument(
        "enable_joy_node", default_value="true", description="Run joy_linux_node for safety buttons"
    )

    arm_namespace_arg = DeclareLaunchArgument(
        "arm_namespace", default_value="left_arm", description="Arm: left_arm or right_arm"
    )
    input_mode_arg = DeclareLaunchArgument(
        "input_mode", default_value="ros2", description="udp | xbox | hybrid | ros2"
    )
    axe4_input_topic_arg = DeclareLaunchArgument(
        "axe4_input_topic", default_value="/axe4/eef_twist",
        description="Topic: /axe4/eef_position, /axe4/eef_pose (position), or /axe4/eef_twist (velocity)"
    )
    speed_arg = DeclareLaunchArgument(
        "speed", default_value="1.0",
        description="Workspace + speed: 1=normal, 2–4 = use more of robot workspace (small teleop → big arm). Reduce to slow."
    )
    axis_map_arg = DeclareLaunchArgument(
        "axis_map", default_value="fwd_towards_base",
        description=(
            "Direction mode: fwd_towards_base (current behavior) or "
            "fwd_away_from_base (flip left/right and fwd/bwd, keep up/down)"
        )
    )
    lock_joint1_arg = DeclareLaunchArgument(
        "lock_joint1", default_value="true", description="Lock joint 1 (Jacobian-based joint velocity)"
    )

    joy_node = Node(
        package="joy_linux",
        executable="joy_linux_node",
        name="joy_node",
        output="screen",
        condition=IfCondition(LaunchConfiguration("enable_joy_node")),
        parameters=[{
            "device_name": LaunchConfiguration("device"),
            "deadzone": LaunchConfiguration("deadzone"),
        }],
    )

    axe4_node = Node(
        package="arms_xbox_ctr",
        executable="axe4",
        name="axe4",
        output="screen",
        parameters=[{
            "arm_namespace": LaunchConfiguration("arm_namespace"),
            "input_mode": LaunchConfiguration("input_mode"),
            "axe4_input_topic": LaunchConfiguration("axe4_input_topic"),
            "speed": LaunchConfiguration("speed"),
            "axis_map": LaunchConfiguration("axis_map"),
            "lock_joint1": LaunchConfiguration("lock_joint1"),
        }],
    )

    home_service_node = Node(
        package="robot_bringup",
        executable="movo_custom_home_service",
        name="movo_custom_home_service",
        output="screen",
    )

    return LaunchDescription([
        device_arg,
        deadzone_arg,
        enable_joy_arg,
        arm_namespace_arg,
        input_mode_arg,
        axe4_input_topic_arg,
        speed_arg,
        axis_map_arg,
        lock_joint1_arg,
        joy_node,
        axe4_node,
        home_service_node,
    ])
