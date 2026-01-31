from setuptools import find_packages
from setuptools import setup

setup(
    name='kinova_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('kinova_msgs', 'kinova_msgs.*')),
)
