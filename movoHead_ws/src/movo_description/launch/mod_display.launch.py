import os
import subprocess
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('movo_description')
    xacro_file = os.path.join(pkg_share, 'urdf', 'movo.urdf.xacro')
    urdf_file = os.path.join(pkg_share, 'urdf', 'movo.urdf')

    # Convert xacro to URDF
    result = subprocess.run(
        ['ros2', 'run', 'xacro', 'xacro', '--inorder', xacro_file, '-o', urdf_file],
        check=True
    )

    # Ensure the URDF file exists before reading
    if not os.path.exists(urdf_file):
        raise RuntimeError(f"URDF file {urdf_file} was not generated properly!")

    # Read the URDF file into a string, this string becomes our robot_description
    robot_description = open(urdf_file, 'r').read()

    # This node publishes the robot_description parameter and its associated TFs.
    # The RobotModel display in RViz uses this parameter to render the robot.
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description}],
        output='screen'
    )

    # Publish a static transform between linear_actuator_fixed_link and linear_actuator_link.
    static_transform_node = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments=['0', '0', '0.9', '0', '0', '0', 'linear_actuator_fixed_link', 'linear_actuator_link']
    )


    return LaunchDescription([
        robot_state_publisher_node,
        static_transform_node,
    ])
