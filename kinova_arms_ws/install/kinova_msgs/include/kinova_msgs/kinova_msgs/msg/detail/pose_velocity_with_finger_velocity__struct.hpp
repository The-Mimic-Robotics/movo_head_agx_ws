// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:msg/PoseVelocityWithFingerVelocity.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGER_VELOCITY__STRUCT_HPP_
#define KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGER_VELOCITY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__msg__PoseVelocityWithFingerVelocity __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__msg__PoseVelocityWithFingerVelocity __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PoseVelocityWithFingerVelocity_
{
  using Type = PoseVelocityWithFingerVelocity_<ContainerAllocator>;

  explicit PoseVelocityWithFingerVelocity_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->twist_linear_x = 0.0f;
      this->twist_linear_y = 0.0f;
      this->twist_linear_z = 0.0f;
      this->twist_angular_x = 0.0f;
      this->twist_angular_y = 0.0f;
      this->twist_angular_z = 0.0f;
      this->finger1 = 0.0f;
      this->finger2 = 0.0f;
      this->finger3 = 0.0f;
    }
  }

  explicit PoseVelocityWithFingerVelocity_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->twist_linear_x = 0.0f;
      this->twist_linear_y = 0.0f;
      this->twist_linear_z = 0.0f;
      this->twist_angular_x = 0.0f;
      this->twist_angular_y = 0.0f;
      this->twist_angular_z = 0.0f;
      this->finger1 = 0.0f;
      this->finger2 = 0.0f;
      this->finger3 = 0.0f;
    }
  }

  // field types and members
  using _twist_linear_x_type =
    float;
  _twist_linear_x_type twist_linear_x;
  using _twist_linear_y_type =
    float;
  _twist_linear_y_type twist_linear_y;
  using _twist_linear_z_type =
    float;
  _twist_linear_z_type twist_linear_z;
  using _twist_angular_x_type =
    float;
  _twist_angular_x_type twist_angular_x;
  using _twist_angular_y_type =
    float;
  _twist_angular_y_type twist_angular_y;
  using _twist_angular_z_type =
    float;
  _twist_angular_z_type twist_angular_z;
  using _finger1_type =
    float;
  _finger1_type finger1;
  using _finger2_type =
    float;
  _finger2_type finger2;
  using _finger3_type =
    float;
  _finger3_type finger3;

  // setters for named parameter idiom
  Type & set__twist_linear_x(
    const float & _arg)
  {
    this->twist_linear_x = _arg;
    return *this;
  }
  Type & set__twist_linear_y(
    const float & _arg)
  {
    this->twist_linear_y = _arg;
    return *this;
  }
  Type & set__twist_linear_z(
    const float & _arg)
  {
    this->twist_linear_z = _arg;
    return *this;
  }
  Type & set__twist_angular_x(
    const float & _arg)
  {
    this->twist_angular_x = _arg;
    return *this;
  }
  Type & set__twist_angular_y(
    const float & _arg)
  {
    this->twist_angular_y = _arg;
    return *this;
  }
  Type & set__twist_angular_z(
    const float & _arg)
  {
    this->twist_angular_z = _arg;
    return *this;
  }
  Type & set__finger1(
    const float & _arg)
  {
    this->finger1 = _arg;
    return *this;
  }
  Type & set__finger2(
    const float & _arg)
  {
    this->finger2 = _arg;
    return *this;
  }
  Type & set__finger3(
    const float & _arg)
  {
    this->finger3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__msg__PoseVelocityWithFingerVelocity
    std::shared_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__msg__PoseVelocityWithFingerVelocity
    std::shared_ptr<kinova_msgs::msg::PoseVelocityWithFingerVelocity_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PoseVelocityWithFingerVelocity_ & other) const
  {
    if (this->twist_linear_x != other.twist_linear_x) {
      return false;
    }
    if (this->twist_linear_y != other.twist_linear_y) {
      return false;
    }
    if (this->twist_linear_z != other.twist_linear_z) {
      return false;
    }
    if (this->twist_angular_x != other.twist_angular_x) {
      return false;
    }
    if (this->twist_angular_y != other.twist_angular_y) {
      return false;
    }
    if (this->twist_angular_z != other.twist_angular_z) {
      return false;
    }
    if (this->finger1 != other.finger1) {
      return false;
    }
    if (this->finger2 != other.finger2) {
      return false;
    }
    if (this->finger3 != other.finger3) {
      return false;
    }
    return true;
  }
  bool operator!=(const PoseVelocityWithFingerVelocity_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PoseVelocityWithFingerVelocity_

// alias to use template instance with default allocator
using PoseVelocityWithFingerVelocity =
  kinova_msgs::msg::PoseVelocityWithFingerVelocity_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGER_VELOCITY__STRUCT_HPP_
