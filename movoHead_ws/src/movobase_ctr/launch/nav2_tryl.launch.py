import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import TimerAction

def generate_launch_description():
    # Get the share directories for the packages
    movo_description_share = get_package_share_directory('movo_description')
    movobase_ctr_share = get_package_share_directory('movobase_ctr')

    # Include the robot display launch file (RViz)
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

    # Nav2 parameters file
    nav2_params_file = os.path.join(movobase_ctr_share, 'config', 'movo_nav2_config.yaml')

    # Map file
    map_file = os.path.join(movobase_ctr_share, 'my_maps', 'map_t4.yaml')

    # Nav2 bringup launch
    nav2_bringup = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('nav2_bringup'), 'launch', 'bringup_launch.py')
        ),
        launch_arguments={
            'map': map_file,
            'params_file': nav2_params_file,
            'use_sim_time': 'false',
            'autostart': 'true'
        }.items()
    )

    return LaunchDescription([
        display_launch,
        # odom_tf,
        TimerAction(
        period=3.0,  # 10 second delay
        actions=[nav2_bringup]
        ),
       
    ])