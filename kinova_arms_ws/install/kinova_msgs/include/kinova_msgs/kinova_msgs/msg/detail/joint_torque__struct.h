// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:msg/JointTorque.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__JOINT_TORQUE__STRUCT_H_
#define KINOVA_MSGS__MSG__DETAIL__JOINT_TORQUE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/JointTorque in the package kinova_msgs.
typedef struct kinova_msgs__msg__JointTorque
{
  float joint1;
  float joint2;
  float joint3;
  float joint4;
  float joint5;
  float joint6;
  float joint7;
} kinova_msgs__msg__JointTorque;

// Struct for a sequence of kinova_msgs__msg__JointTorque.
typedef struct kinova_msgs__msg__JointTorque__Sequence
{
  kinova_msgs__msg__JointTorque * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__msg__JointTorque__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__MSG__DETAIL__JOINT_TORQUE__STRUCT_H_
