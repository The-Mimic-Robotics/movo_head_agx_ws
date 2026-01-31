import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import TimerAction
from launch.actions import IncludeLaunchDescription
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    # Get the share directories for the packages
    movo_description_share = get_package_share_directory('movo_description')
    movobase_ctr_share = get_package_share_directory('movobase_ctr')

    # Include the robot display launch file
    display_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(movo_description_share, 'launch', 'mod_display.launch.py')
        )
    )
    # odom_tf = Node(
    #     package='tf2_ros',
    #     executable='static_transform_publisher',
    #     name='odom_tf',
    #     arguments=['0', '0', '0', '0', '0', '0', 'odom', 'base_link']
    # )
    # SLAM parameters file
    slam_params_file = os.path.join(movobase_ctr_share, 'config', 'movo_slam.yaml')

    # SLAM node with delay to ensure topic availability
    slam_node = TimerAction(
        period=2.0,  # 2 seconds delay
        actions=[
            Node(
                package='slam_toolbox',
                executable='sync_slam_toolbox_node',
                name='slam_toolbox',
                output='screen',
                parameters=[slam_params_file]
            )
        ]
    )


         # Launch joy_node
    joy_node =     Node(
            package='joy_linux',
            executable='joy_linux_node',
            name='joy_node',
            output='log'
        )

        # Launch joy_to_twist_node
    joy_to_twist_node =   Node(
            package='joy_to_twist',
            executable='joy_to_twist_node',
            name='joy_to_twist_node',
            output='log'
        )


    return LaunchDescription([
        display_launch,
        # odom_tf,
        slam_node,
        joy_node,
        joy_to_twist_node
    ])