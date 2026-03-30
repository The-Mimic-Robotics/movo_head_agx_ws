#!/usr/bin/env python3
"""All-in-one Bi-AXE teleop stack.

Includes:
  1) UDP -> ROS 2 bridge (bi_axe_udp_ros2_bridge)
  2) Dual-arm Kinova teleop + Xbox safety + home service (bi_axe_bimanual)
  3) Base + handle gripper teleop (axe_leader_base_teleop)

Defaults avoid duplicate joy nodes by letting bi_axe_bimanual own /joy.
"""

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    launch_dir = PathJoinSubstitution([FindPackageShare("axe_leader_teleop"), "launch"])

    # Bridge args
    udp_ip_arg = DeclareLaunchArgument("udp_ip", default_value="0.0.0.0")
    udp_port_arg = DeclareLaunchArgument("udp_port", default_value="5005")
    left_namespace_arg = DeclareLaunchArgument("left_namespace", default_value="bi_axe_left")
    right_namespace_arg = DeclareLaunchArgument("right_namespace", default_value="bi_axe_right")
    publish_legacy_untagged_arg = DeclareLaunchArgument("publish_legacy_untagged", default_value="false")

    # Bimanual args
    device_arg = DeclareLaunchArgument("device", default_value="/dev/input/js0")
    deadzone_arg = DeclareLaunchArgument("deadzone", default_value="0.05")
    input_mode_arg = DeclareLaunchArgument("input_mode", default_value="ros2")
    udp_eef_control_arg = DeclareLaunchArgument("udp_eef_control", default_value="auto")
    axe_left_topic_arg = DeclareLaunchArgument(
        "axe_leader_input_topic_left", default_value="/bi_axe_left/eef_twist"
    )
    axe_right_topic_arg = DeclareLaunchArgument(
        "axe_leader_input_topic_right", default_value="/bi_axe_right/eef_twist"
    )
    locked_joints_arg = DeclareLaunchArgument(
        "locked_joints",
        default_value="1",
        description="Comma-separated 1-indexed joints to lock. Empty string for Cartesian velocity mode.",
    )
    auto_arm_udp_arg = DeclareLaunchArgument("auto_arm_udp", default_value="true")
    auto_start_arm_arg = DeclareLaunchArgument("auto_start_arm", default_value="true")
    require_joy_keepalive_arg = DeclareLaunchArgument("require_joy_keepalive", default_value="false")
    joy_timeout_sec_arg = DeclareLaunchArgument("joy_timeout_sec", default_value="1.0")
    speed_arg = DeclareLaunchArgument("speed", default_value="1.0")
    max_joint_vel_deg_arg = DeclareLaunchArgument("max_joint_vel_deg", default_value="45.0")
    respawn_joy_arg = DeclareLaunchArgument("respawn_joy", default_value="false")

    # Base teleop args
    cmd_vel_topic_arg = DeclareLaunchArgument("cmd_vel_topic", default_value="/cmd_vel")
    left_joy_topic_arg = DeclareLaunchArgument("left_joy_topic", default_value="/bi_axe_left/joy")
    right_joy_topic_arg = DeclareLaunchArgument("right_joy_topic", default_value="/bi_axe_right/joy")
    use_right_joy_arg = DeclareLaunchArgument("use_right_joy", default_value="true")
    max_linear_arg = DeclareLaunchArgument("max_linear", default_value="0.6")
    max_angular_arg = DeclareLaunchArgument("max_angular", default_value="0.8")
    velocity_scale_arg = DeclareLaunchArgument("velocity_scale", default_value="0.6")
    base_deadzone_arg = DeclareLaunchArgument("base_deadzone", default_value="0.08")
    left_deadman_button_arg = DeclareLaunchArgument("left_deadman_button", default_value="0")
    right_deadman_button_arg = DeclareLaunchArgument("right_deadman_button", default_value="0")
    gripper_release_arg = DeclareLaunchArgument("gripper_release", default_value="-0.25")
    enable_xbox_safety_override_arg = DeclareLaunchArgument("enable_xbox_safety_override", default_value="true")
    xbox_joy_topic_arg = DeclareLaunchArgument("xbox_joy_topic", default_value="/joy")
    include_joy_for_base_arg = DeclareLaunchArgument(
        "include_joy_for_base",
        default_value="false",
        description="Set true only if bimanual joy node is disabled and you still want base safety override from /joy.",
    )

    bridge = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(PathJoinSubstitution([launch_dir, "bi_axe_udp_ros2_bridge.launch.py"])),
        launch_arguments={
            "udp_ip": LaunchConfiguration("udp_ip"),
            "udp_port": LaunchConfiguration("udp_port"),
            "left_namespace": LaunchConfiguration("left_namespace"),
            "right_namespace": LaunchConfiguration("right_namespace"),
            "publish_legacy_untagged": LaunchConfiguration("publish_legacy_untagged"),
        }.items(),
    )

    bimanual = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(PathJoinSubstitution([launch_dir, "bi_axe_bimanual.launch.py"])),
        launch_arguments={
            "device": LaunchConfiguration("device"),
            "deadzone": LaunchConfiguration("deadzone"),
            "input_mode": LaunchConfiguration("input_mode"),
            "udp_eef_control": LaunchConfiguration("udp_eef_control"),
            "axe_leader_input_topic_left": LaunchConfiguration("axe_leader_input_topic_left"),
            "axe_leader_input_topic_right": LaunchConfiguration("axe_leader_input_topic_right"),
            "locked_joints": LaunchConfiguration("locked_joints"),
            "auto_arm_udp": LaunchConfiguration("auto_arm_udp"),
            "auto_start_arm": LaunchConfiguration("auto_start_arm"),
            "require_joy_keepalive": LaunchConfiguration("require_joy_keepalive"),
            "joy_timeout_sec": LaunchConfiguration("joy_timeout_sec"),
            "speed": LaunchConfiguration("speed"),
            "max_joint_vel_deg": LaunchConfiguration("max_joint_vel_deg"),
            "respawn_joy": LaunchConfiguration("respawn_joy"),
        }.items(),
    )

    base_teleop = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(PathJoinSubstitution([launch_dir, "axe_leader_base_teleop.launch.py"])),
        launch_arguments={
            "cmd_vel_topic": LaunchConfiguration("cmd_vel_topic"),
            "left_joy_topic": LaunchConfiguration("left_joy_topic"),
            "right_joy_topic": LaunchConfiguration("right_joy_topic"),
            "use_right_joy": LaunchConfiguration("use_right_joy"),
            "max_linear": LaunchConfiguration("max_linear"),
            "max_angular": LaunchConfiguration("max_angular"),
            "velocity_scale": LaunchConfiguration("velocity_scale"),
            "deadzone": LaunchConfiguration("base_deadzone"),
            "left_deadman_button": LaunchConfiguration("left_deadman_button"),
            "right_deadman_button": LaunchConfiguration("right_deadman_button"),
            "gripper_release": LaunchConfiguration("gripper_release"),
            "enable_xbox_safety_override": LaunchConfiguration("enable_xbox_safety_override"),
            "xbox_joy_topic": LaunchConfiguration("xbox_joy_topic"),
            "include_joy": LaunchConfiguration("include_joy_for_base"),
            "joy_device": LaunchConfiguration("device"),
        }.items(),
    )

    return LaunchDescription(
        [
            udp_ip_arg,
            udp_port_arg,
            left_namespace_arg,
            right_namespace_arg,
            publish_legacy_untagged_arg,
            device_arg,
            deadzone_arg,
            input_mode_arg,
            udp_eef_control_arg,
            axe_left_topic_arg,
            axe_right_topic_arg,
            locked_joints_arg,
            auto_arm_udp_arg,
            auto_start_arm_arg,
            require_joy_keepalive_arg,
            joy_timeout_sec_arg,
            speed_arg,
            max_joint_vel_deg_arg,
            respawn_joy_arg,
            cmd_vel_topic_arg,
            left_joy_topic_arg,
            right_joy_topic_arg,
            use_right_joy_arg,
            max_linear_arg,
            max_angular_arg,
            velocity_scale_arg,
            base_deadzone_arg,
            left_deadman_button_arg,
            right_deadman_button_arg,
            gripper_release_arg,
            enable_xbox_safety_override_arg,
            xbox_joy_topic_arg,
            include_joy_for_base_arg,
            bridge,
            bimanual,
            base_teleop,
        ]
    )
