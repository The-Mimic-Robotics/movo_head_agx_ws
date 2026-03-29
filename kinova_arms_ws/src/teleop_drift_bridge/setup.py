from setuptools import find_packages, setup
import os
from glob import glob

package_name = "teleop_drift_bridge"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(exclude=["test"]),
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob(os.path.join("launch", "*.launch.py"))),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="useradmin",
    maintainer_email="useradmin@todo.todo",
    description="Pose-feedback drift bridge on top of twist teleop for Kinova.",
    license="Apache License 2.0",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "drift_joint_teleop = teleop_drift_bridge.drift_joint_teleop_node:main",
        ],
    },
)
