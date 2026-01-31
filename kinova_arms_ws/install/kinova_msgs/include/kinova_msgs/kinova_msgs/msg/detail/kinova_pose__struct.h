// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:msg/KinovaPose.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__STRUCT_H_
#define KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/KinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__msg__KinovaPose
{
  float x;
  float y;
  float z;
  float theta_x;
  float theta_y;
  float theta_z;
} kinova_msgs__msg__KinovaPose;

// Struct for a sequence of kinova_msgs__msg__KinovaPose.
typedef struct kinova_msgs__msg__KinovaPose__Sequence
{
  kinova_msgs__msg__KinovaPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__msg__KinovaPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__STRUCT_H_
