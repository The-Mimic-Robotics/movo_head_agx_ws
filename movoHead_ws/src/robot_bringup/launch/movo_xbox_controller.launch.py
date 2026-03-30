#!/usr/bin/env python3
"""
Launch file for unified MOVO Xbox controller.
Starts joy_linux_node + movo_xbox_controller node.
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, SetEnvironmentVariable
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

_HOME_JOINTS_YAML = os.path.join(
    get_package_share_directory('robot_bringup'), 'config', 'home_joints.yaml')


def generate_launch_description():
    device_arg = DeclareLaunchArgument(
        'device', default_value='/dev/input/js0',
        description='Joystick device path')

    deadzone_arg = DeclareLaunchArgument(
        'deadzone', default_value='0.05',
        description='Joystick deadzone')

    locked_joints_arg = DeclareLaunchArgument(
        'locked_joints', default_value='1',
        description='Comma-separated 1-indexed joint numbers to lock (e.g. 1 or 1,5). '
                    'Default 1 = lock joint 1. Empty string = Cartesian velocity mode (no locking).')

    max_joint_vel_deg_arg = DeclareLaunchArgument(
        'max_joint_vel_deg', default_value='45.0',
        description='Per-joint velocity safety clamp (deg/s)')

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
        parameters=[{
            'locked_joints': ParameterValue(LaunchConfiguration('locked_joints'), value_type=str),
            'max_joint_vel_deg': LaunchConfiguration('max_joint_vel_deg'),
        }],
    )

    home_service_node = Node(
        package='robot_bringup',
        executable='movo_custom_home_service',
        name='movo_custom_home_service',
        output='screen',
    )

    return LaunchDescription([
        SetEnvironmentVariable('MOVO_HOME_JOINTS_YAML', _HOME_JOINTS_YAML),
        device_arg,
        deadzone_arg,
        locked_joints_arg,
        max_joint_vel_deg_arg,
        joy_node,
        controller_node,
        home_service_node,
    ])
