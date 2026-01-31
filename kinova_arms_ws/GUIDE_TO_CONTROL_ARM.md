




1. set up the arms computer .  

Note, they are set in up vscode, connect to host at the bottom left

ssh movo@192.168.131.10
-> movo420

roscore & roslaunch kinova_bringup dual_arms.launch 


2. 
ssh movo_base@192.168.131.100
-> movo420
./ros-humble-ros1-bridge-builder/kinova_ros1_bridge_v2.sh



on agx
test arms : 

ros2 service call /left_arm/left_arm_driver/in/home_arm kinova_msgs/srv/HomeArm "{}"
ros2 service call /right_arm/right_arm_driver/in/home_arm kinova_msgs/srv/HomeArm "{}"


then launch main : 
ros2 launch arms_xbox_ctr xbox_controller.launch.py


##debug

# calling the service with right type
ros2 service call /left_arm/left_arm_driver/in/home_arm kinova_msgs/srv/HomeArm "{}"


if issue with xbox "
issue with the xbox controller so in another terminal lauch it :
 ros2 run joy_linux joy_linux_node --ros-args -p device_name:="/dev/input/js0"
"


# Rebuild just this package and create a symlink so you don't have to rebuild next time
colcon build --packages-select arms_xbox_ctr --symlink-install

# Source the changes
source install/setup.bash