from setuptools import setup

package_name = 'joy_to_twist'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='movo_base',
    maintainer_email='movo_base@todo.todo',
    description='A package to convert joystick inputs to Twist messages for controlling a robot',
    license='Apache License 2.0',
    entry_points={
        'console_scripts': [
            'joy_to_twist_node = joy_to_twist.joy_to_twist_node:main',
        ],
    },
)

