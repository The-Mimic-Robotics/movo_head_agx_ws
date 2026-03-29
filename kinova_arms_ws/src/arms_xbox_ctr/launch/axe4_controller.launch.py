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
    udp_ip_arg = DeclareLaunchArgument(
        "udp_ip", default_value="0.0.0.0",
        description="UDP bind IP for input_mode=udp|hybrid (use 0.0.0.0 for all interfaces)"
    )
    udp_port_arg = DeclareLaunchArgument(
        "udp_port", default_value="5005", description="UDP bind port for input_mode=udp|hybrid"
    )
    udp_eef_control_arg = DeclareLaunchArgument(
        "udp_eef_control", default_value="auto",
        description="UDP EEF control mode: auto | velocity | pose | position"
    )
    axe4_input_topic_arg = DeclareLaunchArgument(
        "axe4_input_topic", default_value="/axe4/eef_twist",
        description=(
            "Pose/position: /axe4/eef_position, eef_pose, eef_position_absolute, eef_pose_absolute; "
            "velocity: /axe4/eef_twist"
        )
    )
    axe4_position_frame_arg = DeclareLaunchArgument(
        "axe4_position_frame", default_value="auto",
        description="relative | absolute | auto (auto: absolute if topic name contains 'absolute')"
    )
    position_error_deadband_arg = DeclareLaunchArgument(
        "position_error_deadband", default_value="0.002",
        description="meters; zero Cartesian velocity when |error| is below this (reduces wobble)"
    )
    position_gain_arg = DeclareLaunchArgument(
        "position_gain", default_value="4.0",
        description="ROS2 position mode P-gain (1/s); lower than old implicit ~rate for stability"
    )
    position_vel_filter_alpha_arg = DeclareLaunchArgument(
        "position_vel_filter_alpha", default_value="0.35",
        description="EMA on commanded linear vel; 0 = off"
    )
    speed_arg = DeclareLaunchArgument(
        "speed", default_value="1.0",
        description="Workspace + speed: 1=normal, 2–4 = use more of robot workspace (small teleop → big arm). Reduce to slow."
    )
    teleop_axis_arg = DeclareLaunchArgument(
        "teleop_axis", default_value="",
        description="Override home_joints.yaml teleop_axis for this arm; empty = use YAML",
    )
    lock_joint1_arg = DeclareLaunchArgument(
        "lock_joint1", default_value="true", description="Lock joint 1 (Jacobian-based joint velocity)"
    )
    auto_arm_udp_arg = DeclareLaunchArgument(
        "auto_arm_udp", default_value="true", description="Start teleop armed in UDP mode"
    )
    auto_start_arm_arg = DeclareLaunchArgument(
        "auto_start_arm", default_value="true", description="Auto-call Kinova start service when teleop is active"
    )
    require_joy_keepalive_arg = DeclareLaunchArgument(
        "require_joy_keepalive", default_value="false",
        description="If true, disarm teleop when /joy times out"
    )
    joy_timeout_sec_arg = DeclareLaunchArgument(
        "joy_timeout_sec", default_value="1.0", description="Joy timeout seconds"
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
        executable="kinova_teleop",
        name="kinova_teleop",
        output="screen",
        parameters=[{
            "arm_namespace": LaunchConfiguration("arm_namespace"),
            "input_mode": LaunchConfiguration("input_mode"),
            "udp_ip": LaunchConfiguration("udp_ip"),
            "udp_port": LaunchConfiguration("udp_port"),
            "udp_eef_control": LaunchConfiguration("udp_eef_control"),
            "axe4_input_topic": LaunchConfiguration("axe4_input_topic"),
            "axe4_position_frame": LaunchConfiguration("axe4_position_frame"),
            "position_error_deadband": LaunchConfiguration("position_error_deadband"),
            "position_gain": LaunchConfiguration("position_gain"),
            "position_vel_filter_alpha": LaunchConfiguration("position_vel_filter_alpha"),
            "speed": LaunchConfiguration("speed"),
            "teleop_axis": LaunchConfiguration("teleop_axis"),
            "lock_joint1": LaunchConfiguration("lock_joint1"),
            "auto_arm_udp": LaunchConfiguration("auto_arm_udp"),
            "auto_start_arm": LaunchConfiguration("auto_start_arm"),
            "require_joy_keepalive": LaunchConfiguration("require_joy_keepalive"),
            "joy_timeout_sec": LaunchConfiguration("joy_timeout_sec"),
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
        udp_ip_arg,
        udp_port_arg,
        udp_eef_control_arg,
        axe4_input_topic_arg,
        axe4_position_frame_arg,
        position_error_deadband_arg,
        position_gain_arg,
        position_vel_filter_alpha_arg,
        speed_arg,
        teleop_axis_arg,
        lock_joint1_arg,
        auto_arm_udp_arg,
        auto_start_arm_arg,
        require_joy_keepalive_arg,
        joy_timeout_sec_arg,
        joy_node,
        axe4_node,
        home_service_node,
    ])
