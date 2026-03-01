# kinova_msgs_ros2 quick reference

This package defines Kinova ROS2 message, service, and action interfaces.

## Use this for custom homing

- Use `HomeArm` service first (`/<arm>/<arm>_driver/in/home_arm`)
- Then use `ArmJointAngles` action (`/<arm>/<arm>_driver/joints_action/joint_angles`)
- This is **angular/joint control only** (not Cartesian)

For safest behavior, command joint targets in the equivalent revolution branch closest to current joints (same final pose, less unexpected spinning).

## Actions

- `ArmJointAngles.action`
  - Goal: `JointAngles angles`
  - Joint-space target (degrees). Best for deterministic custom home poses.
- `ArmPose.action`
  - Goal: `geometry_msgs/PoseStamped pose`
  - Cartesian pose target with IK in driver/robot.
- `ArmKinovaPose.action`
  - Goal: `KinovaPose kinova_pose`
  - Cartesian pose using Kinova pose fields (`x,y,z,theta_x,theta_y,theta_z`).
- `SetFingersPosition.action`
  - Goal: `FingerPosition fingers`
  - Finger open/close or absolute finger targets.

## Services

- `HomeArm.srv`
  - No request fields, response `homearm_result`.
  - Sends arm to Kinova home position.
- `Start.srv` / `Stop.srv`
  - Enable/disable API motion commands.
- `AddPoseToCartesianTrajectory.srv`
  - Queue Cartesian waypoint (`x,y,z,theta_x,theta_y,theta_z`) in trajectory buffer.
- `ClearTrajectories.srv`
  - Clear buffered trajectories in robot base.
- `SetForceControlParams.srv`
  - Configure admittance/force control parameters.
- `SetTorqueControlMode.srv`
  - Switch torque mode state.
- `SetTorqueControlParameters.srv`
  - Apply torque controller parameters from driver config.
- `SetNullSpaceModeState.srv`
  - Enable/disable null-space mode on supported arms.
- `ZeroTorques.srv`
  - Zero/recalibrate torque offsets.
- `RunCOMParametersEstimation.srv`
  - Run center-of-mass parameter estimation.
- `SetEndEffectorOffset.srv`
  - Configure end-effector offset.

## Messages

- `JointAngles.msg`
  - 7 joint position values (`joint1..joint7`) in degrees.
- `JointVelocity.msg`
  - 7 joint velocity values (`joint1..joint7`) in deg/s.
- `JointTorque.msg`
  - 7 joint torque commands/values.
- `PoseVelocity.msg`
  - Cartesian twist (`linear xyz`, `angular xyz`).
- `PoseVelocityWithFingers.msg`
  - Cartesian twist + finger closure percentage.
- `PoseVelocityWithFingerVelocity.msg`
  - Cartesian twist + per-finger velocity commands.
- `KinovaPose.msg`
  - Kinova pose (`x,y,z,theta_x,theta_y,theta_z`).
- `FingerPosition.msg`
  - Finger positions (`finger1..finger3`).
- `CartesianForce.msg`
  - Cartesian wrench (`force xyz`, `torque xyz`).

## Practical selection guide

- Need known joint posture (like custom home): **`ArmJointAngles`**
- Need end-effector target pose: `ArmPose` or `ArmKinovaPose`
- Need continuous teleop in joint space: publish `JointVelocity`
- Need continuous teleop in Cartesian space: publish `PoseVelocity`
- Need gripper goal: `SetFingersPosition`

