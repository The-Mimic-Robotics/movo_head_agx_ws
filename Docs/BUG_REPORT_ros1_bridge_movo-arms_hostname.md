# Bug report: Homing fails — ros1_bridge cannot resolve `movo-arms`

**Date:** 2026-03-14  
**Status:** Resolved (workarounds on Base NUC; can recur if bridge starts before arms)  
**Affected:** Custom home service (`/movo/home_left_arm`, `/movo/home_right_arm`) — returns "FAIL: goal rejected" or "action server unavailable"

---

## Symptoms

- Homing from Xbox controller or `ros2 service call /movo/home_left_arm ...` fails with **"FAIL: goal rejected"** or **"Action server not available after waiting"**.
- Arm control (e.g. velocity) still works.
- Kinova driver’s native home service (`/left_arm/left_arm_driver/in/home_arm`) works when called directly.
- Sending the same `ArmJointAngles` goal from **ROS 1 on the Arms NUC** succeeds; failure only when going through the bridge from ROS 2.

---

## Root cause

The **ros1_bridge** runs in Docker on the **Base NUC** (192.168.131.100) and connects to the ROS 1 master on the **Arms NUC** (192.168.131.10). The Arms NUC’s hostname is **`movo-arms`**. ROS 1 advertises node addresses using that hostname.

The Base NUC (and thus the bridge container when using `--network host`) **could not resolve the hostname `movo-arms`**. The bridge then logged:

```text
[ERROR]: couldn't resolve publisher host [movo-arms]
```

and **removed** the left/right arm bridges (topics, services, and **actions** including `joint_angles`). So the homing action was no longer bridged and homing failed.

---

## Fix (on Base NUC only)

1. **Add hostname resolution** on the Base NUC (e.g. in `/etc/hosts`):
   ```text
   192.168.131.10  movo-arms
   ```
   (Use `sudo` to edit `/etc/hosts` if needed.)

2. **Make the bridge script pass the host into the container** (on Base NUC, in `~/ros-humble-ros1-bridge-builder/kinova_ros1_bridge_v2.sh`): add to the `docker run` line:
   ```text
   --add-host=movo-arms:192.168.131.10 \
   ```
   so the container always resolves `movo-arms` even if host `/etc/hosts` is wrong or missing.

3. **Start order matters.** The bridge must see the ROS 1 action servers (from the Kinova drivers) when it starts. If the bridge starts **before** the arms are up, it logs "Action server not available after waiting" and **never creates the 2-to-1 action bridge** for `joint_angles`, so homing stays broken until the bridge is restarted.

   **If homing fails again:**
   - Ensure the arms launch is running on the Arms NUC (e.g. `dual_arms.launch`).
   - Then **restart the bridge** so it discovers the action servers and creates the bridges:
     ```bash
     docker stop ros_bridge; docker rm ros_bridge
     # Then run the bridge script again (or start the container with the same docker run as in the script).
     cd ~ && ./ros-humble-ros1-bridge-builder/kinova_ros1_bridge_v2.sh
     ```
   - Or start the bridge **after** the arms in your normal workflow (e.g. start Terminal 1 arms first, wait ~30 s, then start Terminal 2 bridge).

After this, homing via `/movo/home_left_arm` and `/movo/home_right_arm` works again.

---

## Prevention

- Keep the `movo-arms` entry in `/etc/hosts` on the Base NUC across reinstalls or reimages.
- Use `--add-host=movo-arms:192.168.131.10` in the bridge `docker run` (already added in the script on Base NUC).
- **Start the arms (Arms NUC) before starting the bridge (Base NUC)** so the bridge can create the left/right arm action bridges; if you start the bridge first and homing fails, restart the bridge once the arms are up.

---

## References

- `start_robot.py`: ARMS_HOST = 192.168.131.10, BASE_HOST = 192.168.131.100; bridge runs on Base NUC via `kinova_ros1_bridge_v2.sh`.
- Homing implemented in `movoHead_ws/src/robot_bringup/robot_bringup/movo_custom_home_service.py` (sends `ArmJointAngles` goals to bridged action).
