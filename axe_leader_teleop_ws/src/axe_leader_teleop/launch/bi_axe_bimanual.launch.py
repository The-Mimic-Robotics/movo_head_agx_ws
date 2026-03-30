#!/usr/bin/env python3
"""Dual-arm Kinova teleop + Xbox safety + MOVO home (no UDP bridge — run that separately).

Expects leader data on ROS topics, e.g. from ``bi_axe_udp_ros2_bridge`` (another terminal):
  /bi_axe_left/eef_twist, /bi_axe_right/eef_twist, /bi_axe_*/joy, etc.

Override home joints (optional): export MOVO_HOME_JOINTS_YAML=/path/to/home_joints.yaml before launch.
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    device_arg = DeclareLaunchArgument(
        "device", default_value="/dev/input/js0", description="Xbox controller for arm safety (/joy)")
    deadzone_arg = DeclareLaunchArgument("deadzone", default_value="0.05")

    input_mode_arg = DeclareLaunchArgument("input_mode", default_value="ros2")
    udp_eef_control_arg = DeclareLaunchArgument("udp_eef_control", default_value="auto")
    axe_leader_input_left_arg = DeclareLaunchArgument(
        "axe_leader_input_topic_left", default_value="/bi_axe_left/eef_twist")
    axe_leader_input_right_arg = DeclareLaunchArgument(
        "axe_leader_input_topic_right", default_value="/bi_axe_right/eef_twist")
    locked_joints_arg = DeclareLaunchArgument(
        "locked_joints",
        default_value="1",
        description="Comma-separated 1-indexed joint numbers to lock (e.g. 1 or 1,5). Empty string => Cartesian velocity mode.",
    )
    auto_arm_udp_arg = DeclareLaunchArgument("auto_arm_udp", default_value="true")
    auto_start_arm_arg = DeclareLaunchArgument("auto_start_arm", default_value="true")
    require_joy_keepalive_arg = DeclareLaunchArgument("require_joy_keepalive", default_value="false")
    joy_timeout_sec_arg = DeclareLaunchArgument("joy_timeout_sec", default_value="1.0")
    speed_arg = DeclareLaunchArgument("speed", default_value="1.0")
    max_joint_vel_deg_arg = DeclareLaunchArgument("max_joint_vel_deg", default_value="45.0")
    respawn_joy_arg = DeclareLaunchArgument(
        "respawn_joy", default_value="false",
        description="Respawn joy node on crash (disable to avoid participant storm while debugging).")

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

    kinova_left = Node(
        package="axe_leader_teleop",
        executable="kinova_teleop",
        name="kinova_teleop_left",
        output="screen",
        parameters=[{
            "arm_namespace": "left_arm",
            "input_mode": LaunchConfiguration("input_mode"),
            "udp_eef_control": LaunchConfiguration("udp_eef_control"),
            "axe_leader_input_topic": LaunchConfiguration("axe_leader_input_topic_left"),
            "locked_joints": ParameterValue(LaunchConfiguration("locked_joints"), value_type=str),
            "auto_arm_udp": LaunchConfiguration("auto_arm_udp"),
            "auto_start_arm": LaunchConfiguration("auto_start_arm"),
            "require_joy_keepalive": LaunchConfiguration("require_joy_keepalive"),
            "joy_timeout_sec": LaunchConfiguration("joy_timeout_sec"),
            "speed": LaunchConfiguration("speed"),
            "max_joint_vel_deg": LaunchConfiguration("max_joint_vel_deg"),
        }],
    )

    kinova_right = Node(
        package="axe_leader_teleop",
        executable="kinova_teleop",
        name="kinova_teleop_right",
        output="screen",
        parameters=[{
            "arm_namespace": "right_arm",
            "input_mode": LaunchConfiguration("input_mode"),
            "udp_eef_control": LaunchConfiguration("udp_eef_control"),
            "axe_leader_input_topic": LaunchConfiguration("axe_leader_input_topic_right"),
            "locked_joints": ParameterValue(LaunchConfiguration("locked_joints"), value_type=str),
            "auto_arm_udp": LaunchConfiguration("auto_arm_udp"),
            "auto_start_arm": LaunchConfiguration("auto_start_arm"),
            "require_joy_keepalive": LaunchConfiguration("require_joy_keepalive"),
            "joy_timeout_sec": LaunchConfiguration("joy_timeout_sec"),
            "speed": LaunchConfiguration("speed"),
            "max_joint_vel_deg": LaunchConfiguration("max_joint_vel_deg"),
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
        input_mode_arg,
        udp_eef_control_arg,
        axe_leader_input_left_arg,
        axe_leader_input_right_arg,
        locked_joints_arg,
        auto_arm_udp_arg,
        auto_start_arm_arg,
        require_joy_keepalive_arg,
        joy_timeout_sec_arg,
        speed_arg,
        max_joint_vel_deg_arg,
        respawn_joy_arg,
        joy_node,
        kinova_left,
        kinova_right,
        home_service_node,
    ])
