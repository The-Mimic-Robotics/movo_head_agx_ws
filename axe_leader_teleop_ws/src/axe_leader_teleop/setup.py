from setuptools import find_packages, setup
import os
from glob import glob

package_name = "axe_leader_teleop"

setup(
    name=package_name,
    version="0.1.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.launch.py")),
        (os.path.join("share", package_name, "config"), glob("config/*")),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="useradmin",
    maintainer_email="useradmin@todo.todo",
    description="AXE leader teleop for MOVO / Kinova (UDP bridge + Xbox safety + home)",
    license="Apache-2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "bi_axe_udp_ros2_bridge = axe_leader_teleop.bi_axe_udp_ros2_bridge:main",
            "axe_leader_base_teleop = axe_leader_teleop.axe_leader_base_teleop:main",
            "kinova_teleop = axe_leader_teleop.kinova_teleop:main",
            "movo_dual_arm_base_controller = axe_leader_teleop.movo_dual_arm_base_controller:main",
            "movo_custom_home_service = axe_leader_teleop.movo_custom_home_service:main",
        ],
    },
)
