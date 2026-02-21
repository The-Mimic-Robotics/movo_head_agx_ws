# TONIGHT RUNBOOK

## 0) Scope
- One-arm AXE4 -> MOVO left arm.
- No MoveIt.
- Primary mode: velocity.
- Optional mode: pose action.

## 1) Bringup
```bash
cd /home/agx/Desktop/movo_ws
python3 start_robot.py
```

Wait until bridge + arm services are visible:
```bash
ros2 service list | rg "left_arm/left_arm_driver/in/(start|stop|home_arm)"
```

If `rg` is unavailable in shell:
```bash
ros2 service list
```

## 2) Build Updated Arm Bridge Package
```bash
cd /home/agx/Desktop/movo_ws/kinova_arms_ws
colcon build --packages-select arms_xbox_ctr --symlink-install
source /home/agx/Desktop/movo_ws/kinova_arms_ws/install/setup.bash
```

## 3) Launch AXE4 Bridge (Velocity)
```bash
ros2 launch arms_xbox_ctr axe4_controller.launch.py \
  arm_namespace:=left_arm \
  input_mode:=udp \
  control_mode:=velocity
```

## 4) Start AXE Leader Teleop
```bash
cd /home/agx/axe3_teleoperator
lerobot-teleoperate \
  --robot.type=axe4_follower \
  --robot.cameras={} \
  --robot.udp_port=5005 \
  --teleop.type=axe4_leader \
  --teleop.port=/dev/ttyACM0 \
  --teleop.imu_port=5000 \
  --teleop.id=axe \
  --display_data=false
```

## 5) Mandatory UDP Validation
Receiver:
```bash
python3 -u /home/agx/axe3_teleoperator/simple_udp_receiver.py
```
Expected packet format:
`x y z qw qx qy qz`

## 6) ROS Validation
Pose stream:
```bash
source /home/agx/Desktop/movo_ws/kinova_arms_ws/install/setup.bash
ros2 topic echo /left_arm/udp_position --once
```

Velocity command stream:
```bash
ros2 topic echo /left_arm/left_arm_driver/in/cartesian_velocity --once
```

## 7) Safety Commands
Start:
```bash
ros2 service call /left_arm/left_arm_driver/in/start kinova_msgs/srv/Start "{}"
```
Stop (E-stop software):
```bash
ros2 service call /left_arm/left_arm_driver/in/stop kinova_msgs/srv/Stop "{}"
```
Home:
```bash
ros2 service call /left_arm/left_arm_driver/in/home_arm kinova_msgs/srv/HomeArm "{}"
```

## 8) Low-Speed Policy
- Keep `max_lin_vel <= 0.02`.
- Keep `max_ang_vel <= 0.10`.
- Test one axis at a time.
- Keep stop command terminal open at all times.

## 9) Optional Pose-Action Mode
```bash
ros2 launch arms_xbox_ctr axe4_controller.launch.py \
  arm_namespace:=left_arm \
  input_mode:=udp \
  control_mode:=pose_action
```

## 10) If ROS Python Breaks (Conda mismatch)
Use system python for direct script checks:
```bash
/usr/bin/python3 --version
```

## 11) Quick Recovery
1. Stop teleop (`Ctrl+C` in AXE teleop terminal).
2. Call arm stop service.
3. Relaunch bridge node.
4. Re-arm with start service.
