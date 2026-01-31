// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:msg/KinovaPose.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__STRUCT_HPP_
#define KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__msg__KinovaPose __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__msg__KinovaPose __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct KinovaPose_
{
  using Type = KinovaPose_<ContainerAllocator>;

  explicit KinovaPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->theta_x = 0.0f;
      this->theta_y = 0.0f;
      this->theta_z = 0.0f;
    }
  }

  explicit KinovaPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->theta_x = 0.0f;
      this->theta_y = 0.0f;
      this->theta_z = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _theta_x_type =
    float;
  _theta_x_type theta_x;
  using _theta_y_type =
    float;
  _theta_y_type theta_y;
  using _theta_z_type =
    float;
  _theta_z_type theta_z;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__theta_x(
    const float & _arg)
  {
    this->theta_x = _arg;
    return *this;
  }
  Type & set__theta_y(
    const float & _arg)
  {
    this->theta_y = _arg;
    return *this;
  }
  Type & set__theta_z(
    const float & _arg)
  {
    this->theta_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::msg::KinovaPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::msg::KinovaPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::msg::KinovaPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::msg::KinovaPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__msg__KinovaPose
    std::shared_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__msg__KinovaPose
    std::shared_ptr<kinova_msgs::msg::KinovaPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const KinovaPose_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->theta_x != other.theta_x) {
      return false;
    }
    if (this->theta_y != other.theta_y) {
      return false;
    }
    if (this->theta_z != other.theta_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const KinovaPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct KinovaPose_

// alias to use template instance with default allocator
using KinovaPose =
  kinova_msgs::msg::KinovaPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__STRUCT_HPP_
