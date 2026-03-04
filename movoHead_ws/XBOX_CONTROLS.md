# MOVO Xbox Controller Mapping

Press **X** to cycle control target: `left_arm` → `right_arm` → `base`

## Arm Mode (left_arm / right_arm)

| Input | Action |
|---|---|
| Left stick vertical | X — forward / back |
| Left stick horizontal | Y — left / right |
| Right stick vertical | Z — up / down |
| Right stick horizontal | Yaw rotation |
| D-pad up / down | Pitch |
| D-pad left / right | Roll |
| RT (right trigger) | Close gripper |
| LT (left trigger) | Open gripper |
| A | Start arm driver |
| B | Emergency stop |
| RB | Home current arm |
| LB (double-tap) | Home both arms |

## Base Mode

Hold **RB** as deadman switch, then:

| Input | Action |
|---|---|
| Left stick vertical | Drive forward / back |
| Left stick horizontal | Strafe left / right |
| Right stick horizontal | Rotate |

## Launch

```bash
# Both arms + base (movo_xbox_controller + custom home service)
ros2 launch robot_bringup movo_xbox_controller.launch.py

# Single arm with UDP teleop (kinova_teleop + custom home service)
ros2 launch arms_xbox_ctr axe4_controller.launch.py arm_namespace:=left_arm
```
