from setuptools import find_packages, setup
from glob import glob
import os

package_name = 'robot_bringup'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='useradmin',
    maintainer_email='useradmin@todo.todo',
    description='Unified Xbox controller for MOVO: dual Kinova arms + mecanum base',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'movo_xbox_controller = robot_bringup.movo_xbox_controller:main',
            'movo_dual_arm_controller = robot_bringup.movo_dual_arm_controller:main',
            'movo_dual_arm_base_controller = robot_bringup.movo_dual_arm_base_controller:main',
            'movo_custom_home_service = robot_bringup.movo_custom_home_service:main',
        ],
    },
)
