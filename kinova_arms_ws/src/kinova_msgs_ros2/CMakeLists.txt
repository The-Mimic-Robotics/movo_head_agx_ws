cmake_minimum_required(VERSION 3.8)
project(kinova_msgs)

# rosidl_adapter runs Python during configure; it needs the `em` module (Debian: python3-empy).
# If conda/miniforge is first on PATH, CMake picks that python and the build fails with:
#   ModuleNotFoundError: No module named 'em'
if(EXISTS "/usr/bin/python3")
  set(Python3_EXECUTABLE "/usr/bin/python3" CACHE FILEPATH "Python for ament/rosidl" FORCE)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# Generate messages, services, and actions
rosidl_generate_interfaces(${PROJECT_NAME}
  # Message files
  "msg/CartesianForce.msg"
  "msg/FingerPosition.msg"
  "msg/JointAngles.msg"
  "msg/JointTorque.msg"
  "msg/JointVelocity.msg"
  "msg/KinovaPose.msg"
  "msg/PoseVelocity.msg"
  "msg/PoseVelocityWithFingers.msg"
  "msg/PoseVelocityWithFingerVelocity.msg"
  
  # Service files
  "srv/AddPoseToCartesianTrajectory.srv"
  "srv/ClearTrajectories.srv"
  "srv/HomeArm.srv"
  "srv/RunCOMParametersEstimation.srv"
  "srv/SetEndEffectorOffset.srv"
  "srv/SetForceControlParams.srv"
  "srv/SetNullSpaceModeState.srv"
  "srv/SetTorqueControlMode.srv"
  "srv/SetTorqueControlParameters.srv"
  "srv/Start.srv"
  "srv/Stop.srv"
  "srv/ZeroTorques.srv"
  
  # Action files
  "action/ArmJointAngles.action"
  "action/ArmKinovaPose.action"
  "action/ArmPose.action"
  "action/SetFingersPosition.action"
  
  DEPENDENCIES geometry_msgs std_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()