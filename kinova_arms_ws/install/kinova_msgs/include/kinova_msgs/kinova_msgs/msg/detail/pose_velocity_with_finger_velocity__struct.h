// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:msg/PoseVelocityWithFingerVelocity.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGER_VELOCITY__STRUCT_H_
#define KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGER_VELOCITY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PoseVelocityWithFingerVelocity in the package kinova_msgs.
typedef struct kinova_msgs__msg__PoseVelocityWithFingerVelocity
{
  float twist_linear_x;
  float twist_linear_y;
  float twist_linear_z;
  float twist_angular_x;
  float twist_angular_y;
  float twist_angular_z;
  float finger1;
  float finger2;
  float finger3;
} kinova_msgs__msg__PoseVelocityWithFingerVelocity;

// Struct for a sequence of kinova_msgs__msg__PoseVelocityWithFingerVelocity.
typedef struct kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence
{
  kinova_msgs__msg__PoseVelocityWithFingerVelocity * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGER_VELOCITY__STRUCT_H_
