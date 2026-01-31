// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:msg/FingerPosition.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__STRUCT_H_
#define KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FingerPosition in the package kinova_msgs.
typedef struct kinova_msgs__msg__FingerPosition
{
  float finger1;
  float finger2;
  float finger3;
} kinova_msgs__msg__FingerPosition;

// Struct for a sequence of kinova_msgs__msg__FingerPosition.
typedef struct kinova_msgs__msg__FingerPosition__Sequence
{
  kinova_msgs__msg__FingerPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__msg__FingerPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__STRUCT_H_
