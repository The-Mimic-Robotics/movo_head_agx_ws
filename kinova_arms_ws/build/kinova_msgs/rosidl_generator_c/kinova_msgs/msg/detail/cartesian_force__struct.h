// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:msg/CartesianForce.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__STRUCT_H_
#define KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CartesianForce in the package kinova_msgs.
typedef struct kinova_msgs__msg__CartesianForce
{
  float force_x;
  float force_y;
  float force_z;
  float torque_x;
  float torque_y;
  float torque_z;
} kinova_msgs__msg__CartesianForce;

// Struct for a sequence of kinova_msgs__msg__CartesianForce.
typedef struct kinova_msgs__msg__CartesianForce__Sequence
{
  kinova_msgs__msg__CartesianForce * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__msg__CartesianForce__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__STRUCT_H_
