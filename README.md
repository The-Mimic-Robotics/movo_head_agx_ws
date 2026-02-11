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
