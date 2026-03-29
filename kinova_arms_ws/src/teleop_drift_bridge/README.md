# teleop_drift_bridge

Separate from `kinova_teleop`: **velocity-first** AXE teleop with a **small pose drift bump** only when the leader twist is idle.

## Control (simple)

- **Primary**: `v_twist = twist_rate * map(leader_twist)` (same idea as velocity teleop).
- **Drift bump** (optional): `v_drift = drift_kp * deadband(p_target − p_tcp)` **only when** mapped twist magnitude &lt; `drift_twist_idle_thresh` (so pose never fights your motion or drives singularities).
- Output: `clamp(v_twist + v_drift)` → `PoseVelocity` or Jacobian `JointVelocity` if `lock_joint1`.

## Safety / Xbox (same roles as kinova_teleop)

- `/joy`: B = stop, RB = home, A = start, X = toggle teleop; D-pad vertical = gripper.
- `/axe4/joy`: gripper open/close.
- Services: `HomeArm`, `Start`, `Stop` on the arm namespace.

## Params (defaults tuned mild)

- `drift_kp` (default **0.35**), `max_correction_vel` (default **0.025** m/s), `drift_twist_idle_thresh` (default **0.015** m/s in Cartesian after map).
- `drift_kp:=0.0` → pure twist.

## Important

Do **not** run `kinova_teleop` and `drift_joint_teleop` on the **same** arm at once.

## Build

```bash
cd kinova_arms_ws
colcon build --packages-select teleop_drift_bridge
source install/setup.bash
ros2 launch teleop_drift_bridge drift_joint_teleop.launch.py
```
