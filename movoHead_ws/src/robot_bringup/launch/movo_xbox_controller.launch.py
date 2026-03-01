#!/usr/bin/env python3
"""
Launch file for unified MOVO Xbox controller.
Starts joy_linux_node + movo_xbox_controller node.
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    device_arg = DeclareLaunchArgument(
        'device', default_value='/dev/input/js0',
        description='Joystick device path')

    deadzone_arg = DeclareLaunchArgument(
        'deadzone', default_value='0.05',
        description='Joystick deadzone')

    joy_node = Node(
        package='joy_linux',
        executable='joy_linux_node',
        name='joy_node',
        output='screen',
        parameters=[{
            'device_name': LaunchConfiguration('device'),
            'deadzone': LaunchConfiguration('deadzone'),
            'autorepeat_rate': 0.0,  # Don't spam when no device
        }],
        # Respawn if joy_linux_node crashes (e.g., device unplugged)
        respawn=True,
        respawn_delay=2.0,
    )

    controller_node = Node(
        package='robot_bringup',
        executable='movo_xbox_controller',
        name='movo_xbox_controller',
        output='screen',
    )

    home_service_node = Node(
        package='robot_bringup',
        executable='movo_custom_home_service',
        name='movo_custom_home_service',
        output='screen',
    )

    return LaunchDescription([
        device_arg,
        deadzone_arg,
        joy_node,
        controller_node,
        home_service_node,
    ])
