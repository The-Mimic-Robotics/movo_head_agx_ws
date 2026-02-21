# SYSTEM MAP

## 1) Mission Tonight
- Replace Xbox arm teleop path with AXE4 teleoperator path.
- Keep MOVO base + ROS bridge + Kinova SDK control operational.
- Deliver safe one-arm control first (left arm), no MoveIt.

## 2) Computers and Responsibilities
- Jetson AGX (`/home/agx/Desktop/movo_ws`)
  - Orchestrator: `start_robot.py`
  - ROS2 control nodes:
    - `movoHead_ws/src/robot_bringup`
    - `kinova_arms_ws/src/arms_xbox_ctr`
  - AXE teleoperator repo: `/home/agx/axe3_teleoperator`
- Arms NUC (`movo@192.168.131.10`)
  - ROS1 dual-arm stack: `/home/movo/bimanual_ws/src`
  - Key launch: `kinova_bringup/launch/dual_arms.launch`
  - Key SDK driver: `kinova_driver`
- Base NUC (`movo_base@192.168.131.100`)
  - Base activation: `movobase_activation/launch/movobase_activation.launch.py`
  - ROS1<->ROS2 bridge script:
    - `/home/movo_base/ros-humble-ros1-bridge-builder/kinova_ros1_bridge_v2.sh`

## 3) What Runs Where
- Jetson `start_robot.py` opens 3 terminals:
  1. Arms NUC: `roscore && roslaunch kinova_bringup dual_arms.launch`
  2. Base NUC: starts docker `ros_bridge` dynamic bridge
  3. Base NUC: `ros2 launch movobase_activation movobase_activation.launch.py`
- Jetson teleop node for arms:
  - `kinova_arms_ws/src/arms_xbox_ctr/arms_xbox_ctr/axe4_bridge.py`
- Jetson base/arm Xbox node:
  - `movoHead_ws/src/robot_bringup/robot_bringup/movo_xbox_controller.py`

## 4) Real Dataflow
1. AXE leader reads motors + IMU:
   - `axe3_teleoperator/src/lerobot/teleoperators/axe4_leader/axe4_leader.py`
2. AXE follower sends UDP packet `<fffffff>`:
   - `x y z qw qx qy qz` to `127.0.0.1:5005`
3. Jetson `axe4.py` receives UDP, publishes:
   - `PoseStamped` on `/<arm>/udp_position`
   - `PoseVelocity` on `/<arm>/<arm>_driver/in/cartesian_velocity`
4. ROS1 bridge forwards kinova messages to ROS1 driver.
5. Arms NUC `kinova_driver` executes commands on left/right JACO arm.

## 5) Kinova SDK Capabilities Found (No MoveIt Needed)
- Cartesian velocity command path exists and is active:
  - Topic: `/<arm>/<arm>_driver/in/cartesian_velocity`
  - Driver path: `cartesianVelocityCallback -> setCartesianVelocities(...)`
- Cartesian pose command path exists:
  - Action: `/<arm>/<arm>_driver/pose_action/tool_pose` (`ArmPose`)
  - Service: `/<arm>/<arm>_driver/in/add_pose_to_Cartesian_trajectory`
  - Driver path calls `setCartesianPosition(...)`
- Joint position action exists:
  - `/<arm>/<arm>_driver/joints_action/joint_angles`
- Gripper action exists:
  - `/<arm>/<arm>_driver/fingers_action/finger_positions`

## 6) Position vs Velocity in This Stack
- Velocity mode:
  - Input: twist linear/angular.
  - Behavior: continuous stream, best for live teleop stability.
  - Use tonight: yes (primary).
- Position/pose mode:
  - Input: absolute pose goals.
  - Behavior: driver solves and executes trajectory.
  - Use tonight: optional secondary mode, rate-limited.
- Joint position mode:
  - Input: joint angle goals.
  - Not ideal for generalized Cartesian teleoperator objective.

## 7) Frame/Baselink Notes
- Kinova driver publishes tool pose in `<arm>_link_base`.
- Pose action expects transformable target frame.
- Current UDP bridge uses `frame_id="base_link"` in Jetson node.
- Required calibration layer for reliable transfer:
  - axis sign mapping
  - scale mapping
  - translation offsets
  - quaternion normalization

## 8) Critical Blockers (Fix First)
1. `robot_bringup` entrypoint mismatch:
   - `setup.py` points to `robot_bringup.movo_xbox_controller:main`
   - source file currently named `movo_xbox_controller.launch.py` inside package dir
2. Missing import hygiene in moved controller module (`time` watchdog usage).
3. `arms_xbox_ctr/package.xml` missing runtime dependencies actually used.
4. Potential `/cmd_vel` conflicts if multiple base command publishers run simultaneously.
5. Orientation path not yet wired from UDP quaternion to arm control output.

## 9) Safety Envelope Tonight
- Start with low bounds:
  - linear <= 0.02 m/s
  - angular <= 0.10 rad/s
- Keep `Start`, `Stop`, `Home` always reachable.
- Zero command watchdog on input timeout.
- One-arm only (left arm) until stable.

## 10) Validation Ladder
- Mandatory:
  - `python /home/agx/axe3_teleoperator/simple_udp_receiver.py`
  - `ros2 topic echo /left_arm/udp_position`
  - `ros2 topic echo /left_arm/left_arm_driver/in/cartesian_velocity`
- Optional:
  - `python /home/agx/axe3_teleoperator/tester_eef/eef_tester.py` (MuJoCo)
- Robot safe test:
  - tiny motions, estop ready, verify axis direction one by one.

## 11) Key Files Index
- Jetson orchestration:
  - `/home/agx/Desktop/movo_ws/start_robot.py`
- Jetson arm teleop bridge:
  - `/home/agx/Desktop/movo_ws/kinova_arms_ws/src/arms_xbox_ctr/arms_xbox_ctr/axe4_bridge.py`
  - `/home/agx/Desktop/movo_ws/kinova_arms_ws/src/arms_xbox_ctr/launch/axe4_controller.launch.py`
- Jetson unified Xbox package:
  - `/home/agx/Desktop/movo_ws/movoHead_ws/src/robot_bringup/setup.py`
  - `/home/agx/Desktop/movo_ws/movoHead_ws/src/robot_bringup/robot_bringup/movo_xbox_controller.py`
  - `/home/agx/Desktop/movo_ws/movoHead_ws/src/robot_bringup/launch/movo_xbox_controller.launch.py`
- AXE teleop:
  - `/home/agx/axe3_teleoperator/src/lerobot/teleoperators/axe4_leader/axe4_leader.py`
  - `/home/agx/axe3_teleoperator/src/lerobot/robots/axe4_follower/axe4_follower.py`
- Arms NUC ROS1:
  - `/home/movo/bimanual_ws/src/kinova_bringup/launch/dual_arms.launch`
  - `/home/movo/bimanual_ws/src/kinova_driver/src/kinova_arm.cpp`
  - `/home/movo/bimanual_ws/src/kinova_driver/src/kinova_comm.cpp`
  - `/home/movo/bimanual_ws/src/kinova_driver/src/kinova_tool_pose_action.cpp`
