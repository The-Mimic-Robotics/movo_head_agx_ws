# axe_leader_teleop_ws

ROS 2 package **`axe_leader_teleop`**: UDP → ROS (`bi_axe_udp_ros2_bridge`), dual-arm Kinova teleop, base + grippers from handles, MOVO home, optional Xbox-only dual-arm + base.

## Why `/axe_leader/*` and `/bi_axe_*/*` both exist

**`bi_axe_udp_ros2_bridge`** listens on **one UDP port** and supports **two wire formats**:

| Format | ROS topics |
|--------|------------|
| **L/R tagged** (lerobot bimanual `BiAxeUDPTransport`) | `/bi_axe_left/*`, `/bi_axe_right/*` |
| **Untagged legacy** (single-stream pose/twist/joy, no `L`/`R` byte) | `/axe_leader/*` (default `legacy_namespace`) |

If you **only** use bimanual tagged packets, you do not need `/axe_leader/*`. Launch the bridge with:

```bash
ros2 launch axe_leader_teleop bi_axe_udp_ros2_bridge.launch.py publish_legacy_untagged:=false
```

Then only `/bi_axe_left/*` and `/bi_axe_right/*` are published (no duplicate legacy tree).

---

## Build (once)

```bash
cd ~/Desktop/movo_ws/axe_leader_teleop_ws
source /opt/ros/humble/setup.bash
colcon build --packages-select axe_leader_teleop
source install/setup.bash
```

---

## Minimal launch sequence

Use **separate terminals**. Source `install/setup.bash` in each after build.

### 1) UDP → ROS (run once; keep running)

```bash
ros2 launch axe_leader_teleop bi_axe_udp_ros2_bridge.launch.py
```

Bare minimum overrides:

```bash
ros2 launch axe_leader_teleop bi_axe_udp_ros2_bridge.launch.py udp_port:=5005 publish_legacy_untagged:=false
```

### 2) Kinova / MOVO drivers

Start your existing arm/base driver stack (not part of this package).

### 3) Dual-arm teleop + Xbox safety + home service

```bash
ros2 launch axe_leader_teleop bi_axe_bimanual.launch.py
```

Optional:

```bash
ros2 launch axe_leader_teleop bi_axe_bimanual.launch.py device:=/dev/input/js0
```

### 4) Base + grippers from handles (uses `/bi_axe_left/joy`, `/bi_axe_right/joy`)

If **`bi_axe_bimanual`** already publishes `/joy`, do **not** start a second joystick node:

```bash
ros2 launch axe_leader_teleop axe_leader_base_teleop.launch.py include_joy:=false
```

Standalone test (no other `/joy`):

```bash
ros2 launch axe_leader_teleop axe_leader_base_teleop.launch.py include_joy:=true joy_device:=/dev/input/js0
```

### Single-arm teleop only (no bimanual launch)

```bash
ros2 launch axe_leader_teleop axe_leader_controller.launch.py
```

### Xbox-only dual-arm + base (no leader UDP)

```bash
ros2 launch axe_leader_teleop movo_dual_arm_base_controller.launch.py
```

---

## Quick checks

```bash
ros2 topic echo /bi_axe_left/eef_twist --once
ros2 topic echo /joy --once
ros2 topic echo /cmd_vel --once
```

More detail: `src/axe_leader_teleop/config/run_sequence.txt`.
