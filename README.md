# MOVO Startup

## Run

```bash
cd ~/Desktop/movo_ws
python3 start_robot.py
```

Opens 3 terminals (auto SSH, auto password, Ctrl+C reconnects):
1. Arms NUC: `roscore & roslaunch kinova_bringup dual_arms.launch`
2. Base NUC: `./ros-humble-ros1-bridge-builder/kinova_ros1_bridge_v2.sh` (skips if already running)
3. Base NUC: `ros2 launch <pkg> base_bringup.launch.py` (placeholder for now)

## Install sshpass First

```bash
sudo apt install -y sshpass
```

## If SSH Fails

- Check network: `ping 192.168.131.10` / `ping 192.168.131.100`
- Test manual SSH: `ssh movo@192.168.131.10` (password: movo420)


## AXE4 Velocity Ctrl
```bash
ros2 launch arms_xbox_ctr axe4_controller.launch.py input_mode:=ros2 control_mode:=velocity arm_namespace:=left_arm speed:=4.0
```
```bash
ros2 launch arms_xbox_ctr axe4_controller.launch.py \
  input_mode:=ros2 \
  axe4_input_topic:=/axe4/eef_twist \
  arm_namespace:=left_arm \
  speed:=4.0 \
  lock_joint1:=true
```
## AXE4 Pose Ctrl
```bash
ros2 launch arms_xbox_ctr axe4_controller.launch.py \
  input_mode:=ros2 \
  axe4_input_topic:=/axe4/eef_position \
  arm_namespace:=left_arm \
  speed:=0.6 \
  axis_map:=fwd_away_from_base \
  lock_joint1:=true
```

ros2 launch robot_bringup movo_dual_arm_base_controller.launch.py

ros2 launch arms_xbox_ctr axe4_controller.launch.py   input_mode:=ros2   axe4_input_topic:=/axe4/eef_position   arm_namespace:=left_arm   speed:=0.6   lock_joint1:=true


ros2 launch arms_xbox_ctr axe4_controller.launch.py \
  input_mode:=udp \
  udp_ip:=0.0.0.0 \
  udp_port:=5005 \
  udp_eef_control:=velocity \
  arm_namespace:=left_arm \
  speed:=4.0 \
  lock_joint1:=true \
  auto_arm_udp:=true \
  auto_start_arm:=true \
  require_joy_keepalive:=false \
  enable_joy_node:=false
  
ros2 launch arms_xbox_ctr axe4_controller.launch.py \
  input_mode:=udp \
  udp_ip:=0.0.0.0 \
  udp_port:=5005 \
  udp_eef_control:=velocity \
  arm_namespace:=left_arm \
  speed:=4.0 \
  lock_joint1:=true \
  auto_arm_udp:=true \
  auto_start_arm:=true \
  require_joy_keepalive:=false \
  enable_joy_node:=false
