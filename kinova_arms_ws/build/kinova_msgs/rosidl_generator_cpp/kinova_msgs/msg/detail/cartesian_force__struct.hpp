// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:msg/CartesianForce.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__STRUCT_HPP_
#define KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__msg__CartesianForce __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__msg__CartesianForce __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CartesianForce_
{
  using Type = CartesianForce_<ContainerAllocator>;

  explicit CartesianForce_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_x = 0.0f;
      this->force_y = 0.0f;
      this->force_z = 0.0f;
      this->torque_x = 0.0f;
      this->torque_y = 0.0f;
      this->torque_z = 0.0f;
    }
  }

  explicit CartesianForce_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_x = 0.0f;
      this->force_y = 0.0f;
      this->force_z = 0.0f;
      this->torque_x = 0.0f;
      this->torque_y = 0.0f;
      this->torque_z = 0.0f;
    }
  }

  // field types and members
  using _force_x_type =
    float;
  _force_x_type force_x;
  using _force_y_type =
    float;
  _force_y_type force_y;
  using _force_z_type =
    float;
  _force_z_type force_z;
  using _torque_x_type =
    float;
  _torque_x_type torque_x;
  using _torque_y_type =
    float;
  _torque_y_type torque_y;
  using _torque_z_type =
    float;
  _torque_z_type torque_z;

  // setters for named parameter idiom
  Type & set__force_x(
    const float & _arg)
  {
    this->force_x = _arg;
    return *this;
  }
  Type & set__force_y(
    const float & _arg)
  {
    this->force_y = _arg;
    return *this;
  }
  Type & set__force_z(
    const float & _arg)
  {
    this->force_z = _arg;
    return *this;
  }
  Type & set__torque_x(
    const float & _arg)
  {
    this->torque_x = _arg;
    return *this;
  }
  Type & set__torque_y(
    const float & _arg)
  {
    this->torque_y = _arg;
    return *this;
  }
  Type & set__torque_z(
    const float & _arg)
  {
    this->torque_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::msg::CartesianForce_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::msg::CartesianForce_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::msg::CartesianForce_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::msg::CartesianForce_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__msg__CartesianForce
    std::shared_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__msg__CartesianForce
    std::shared_ptr<kinova_msgs::msg::CartesianForce_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianForce_ & other) const
  {
    if (this->force_x != other.force_x) {
      return false;
    }
    if (this->force_y != other.force_y) {
      return false;
    }
    if (this->force_z != other.force_z) {
      return false;
    }
    if (this->torque_x != other.torque_x) {
      return false;
    }
    if (this->torque_y != other.torque_y) {
      return false;
    }
    if (this->torque_z != other.torque_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianForce_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianForce_

// alias to use template instance with default allocator
using CartesianForce =
  kinova_msgs::msg::CartesianForce_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__STRUCT_HPP_
