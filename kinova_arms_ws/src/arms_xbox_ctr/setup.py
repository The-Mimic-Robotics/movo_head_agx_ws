from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'arms_xbox_ctr'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # Include launch files
        (os.path.join('share', package_name, 'launch'), 
         glob(os.path.join('launch', '*.launch.py'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='useradmin',
    maintainer_email='useradmin@todo.todo',
    description='Xbox controller interface for Kinova arms',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'xbox_reader = arms_xbox_ctr.xbox_reader:main',
            'axe4 = arms_xbox_ctr.axe4:main',
            'kinova_teleop = arms_xbox_ctr.kinova_teleop:main',
            'axe4_udp_bridge = arms_xbox_ctr.axe4_udp_bridge:main',
        ],
    },
)
