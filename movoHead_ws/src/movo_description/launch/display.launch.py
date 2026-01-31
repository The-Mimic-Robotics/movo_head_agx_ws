import os
import subprocess
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_share = get_package_share_directory('movo_description')
    xacro_file = os.path.join(pkg_share, 'urdf', 'movo.urdf.xacro')

    # Convert xacro to URDF
    urdf_file = os.path.join(pkg_share, 'urdf', 'movo.urdf')
    # subprocess.run(['xacro', xacro_file, '-o', urdf_file])
    subprocess.run(['ros2', 'run', 'xacro', 'xacro', '--inorder', xacro_file, '-o', urdf_file], check=True)

    # Start robot_state_publisher
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': open(urdf_file).read()}],
        output='screen'
    )

    return LaunchDescription([robot_state_publisher_node])
# import os
# import subprocess
# from launch import LaunchDescription
# from launch_ros.actions import Node
# from ament_index_python.packages import get_package_share_directory

# def generate_launch_description():
#     pkg_share = get_package_share_directory('movo_description')
#     xacro_file = os.path.join(pkg_share, 'urdf', 'movo.urdf.xacro')
#     urdf_file = os.path.join(pkg_share, 'urdf', 'movo.urdf')

#     # Convert xacro to URDF
#     result = subprocess.run(
#         ['ros2', 'run', 'xacro', 'xacro', '--inorder', xacro_file, '-o', urdf_file],
#         check=True
#     )

#     # Ensure the URDF file exists before reading
#     if not os.path.exists(urdf_file):
#         raise RuntimeError(f"URDF file {urdf_file} was not generated properly!")

#     # Start robot_state_publisher
#     robot_state_publisher_node = Node(
#         package='robot_state_publisher',
#         executable='robot_state_publisher',
#         parameters=[{'robot_description': open(urdf_file, 'r').read()}],
#         output='screen'
#     )

#     return LaunchDescription([robot_state_publisher_node])
