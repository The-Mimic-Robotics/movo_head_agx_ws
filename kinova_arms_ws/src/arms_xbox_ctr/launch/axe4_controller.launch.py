#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    # Declare launch arguments
    device_arg = DeclareLaunchArgument(
        'device',
        default_value='/dev/input/js0',
        description='Joystick device path'
    )
    
    deadzone_arg = DeclareLaunchArgument(
        'deadzone',
        default_value='0.05',
        description='Joystick deadzone value'
    )

    enable_joy_node_arg = DeclareLaunchArgument(
        'enable_joy_node',
        default_value='true',
        description='Launch local joy_linux_node for safety buttons'
    )

    arm_namespace_arg = DeclareLaunchArgument(
        'arm_namespace',
        default_value='left_arm',
        description='Target Kinova arm namespace'
    )

    input_mode_arg = DeclareLaunchArgument(
        'input_mode',
        default_value='udp',
        description='Input source: udp | xbox | hybrid'
    )

    control_mode_arg = DeclareLaunchArgument(
        'control_mode',
        default_value='velocity',
        description='Control output: velocity | pose_action'
    )

    udp_gain_arg = DeclareLaunchArgument(
        'udp_gain',
        default_value='2.0',
        description='Scale factor for UDP XYZ deltas into Cartesian velocity'
    )

    deadzone_vel_arg = DeclareLaunchArgument(
        'deadzone_vel',
        default_value='0.005',
        description='Deadzone for UDP XYZ delta before velocity output'
    )

    max_lin_vel_arg = DeclareLaunchArgument(
        'max_lin_vel',
        default_value='0.16',
        description='Maximum absolute Cartesian linear velocity (m/s)'
    )

    require_joy_keepalive_arg = DeclareLaunchArgument(
        'require_joy_keepalive',
        default_value='false',
        description='If true, disarm teleop when joy messages time out'
    )

    auto_arm_udp_arg = DeclareLaunchArgument(
        'auto_arm_udp',
        default_value='true',
        description='Auto-arm teleop in udp/hybrid mode on startup'
    )

    auto_start_arm_arg = DeclareLaunchArgument(
        'auto_start_arm',
        default_value='true',
        description='Auto-call Kinova start service when teleop is active'
    )

    require_command_path_ready_arg = DeclareLaunchArgument(
        'require_command_path_ready',
        default_value='true',
        description='Block non-zero motion unless services, bridge path, and UDP are ready'
    )

    # Joy node
    # joy_node = Node(
    #     package='joy',
   #      executable='joy_node',
   #      name='joy_node',
   #      output='screen',
   #      parameters=[{
   #          'device_name': LaunchConfiguration('device'),
   #          'deadzone': LaunchConfiguration('deadzone'),
   #      }]
    # )
    
    # Joy node (Updated for Jetson compatibility)
    joy_node = Node(
        package='joy_linux',          # <--- CHANGED
        executable='joy_linux_node',  # <--- CHANGED
        name='joy_node',
        output='screen',
        condition=IfCondition(LaunchConfiguration('enable_joy_node')),
        parameters=[{
            'device_name': LaunchConfiguration('device'),
            'deadzone': LaunchConfiguration('deadzone'),
        }]
    )

    # Xbox reader node
    axe4_reader_node = Node(
        package='arms_xbox_ctr',  # Your new package name
        executable='axe4',  # Will be defined in setup.py
        name='axe4',
        output='screen',
        parameters=[{
            'arm_namespace': LaunchConfiguration('arm_namespace'),
            'input_mode': LaunchConfiguration('input_mode'),
            'control_mode': LaunchConfiguration('control_mode'),
            'udp_gain': LaunchConfiguration('udp_gain'),
            'deadzone': LaunchConfiguration('deadzone_vel'),
            'max_lin_vel': LaunchConfiguration('max_lin_vel'),
            'require_joy_keepalive': LaunchConfiguration('require_joy_keepalive'),
            'auto_arm_udp': LaunchConfiguration('auto_arm_udp'),
            'auto_start_arm': LaunchConfiguration('auto_start_arm'),
            'require_command_path_ready': LaunchConfiguration('require_command_path_ready'),
        }]
    )

    return LaunchDescription([
        device_arg,
        deadzone_arg,
        enable_joy_node_arg,
        arm_namespace_arg,
        input_mode_arg,
        control_mode_arg,
        udp_gain_arg,
        deadzone_vel_arg,
        max_lin_vel_arg,
        require_joy_keepalive_arg,
        auto_arm_udp_arg,
        auto_start_arm_arg,
        require_command_path_ready_arg,
        joy_node,
        axe4_reader_node
    ])
