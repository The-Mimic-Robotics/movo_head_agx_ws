# teleop_drift_bridge

Separate from `arms_xbox_ctr` / `kinova_teleop`: hybrid **twist** + **pose-feedback** Cartesian correction, then optional Jacobian **joint velocity** (same imports as the main teleop stack).

## Behavior

- Subscribes to leader **twist** and **pose** (e.g. `/axe4/eef_twist`, `/axe4/eef_position`).
- Subscribes to Kinova **tool_pose** and **joint_angles**.
- Computes a **target TCP** from pose the same way as position teleop:  
  `p_target = robot_home + speed * map(leader_delta)`.
- **Drift correction**: `v_corr = drift_kp * deadband(p_target - p_current)` (clamped).
- **Output**: `v = clamp(v_twist + v_corr)` → `PoseVelocity` or `JointVelocity` (if `lock_joint1`).

Axis mapping uses `home_joints.yaml` via `arms_xbox_ctr.home_joint_config` (same as MOVO controllers).

## Important

Do **not** run `kinova_teleop` and `drift_joint_teleop` to the **same** arm at once (both would publish driver commands).

Pure twist (no drift term): set `drift_kp:=0.0`.

## Build

```bash
cd kinova_arms_ws
colcon build --packages-select teleop_drift_bridge
source install/setup.bash
ros2 run teleop_drift_bridge drift_joint_teleop --ros-args -p drift_kp:=2.0
```

Or: `ros2 launch teleop_drift_bridge drift_joint_teleop.launch.py`
