#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
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
        parameters=[{
            'device_name': LaunchConfiguration('device'),
            'deadzone': LaunchConfiguration('deadzone'),
        }]
    )

    # Xbox reader node
    xbox_reader_node = Node(
        package='arms_xbox_ctr',  # Your new package name
        executable='axe4',  # Will be defined in setup.py
        name='axe4',
        output='screen'
    )

    return LaunchDescription([
        device_arg,
        deadzone_arg,
        joy_node,
        xbox_reader_node
    ])
