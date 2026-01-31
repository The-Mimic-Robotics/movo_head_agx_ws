// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:srv/SetForceControlParams.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__STRUCT_HPP_
#define KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'inertia_linear'
// Member 'inertia_angular'
// Member 'damping_linear'
// Member 'damping_angular'
// Member 'force_min_linear'
// Member 'force_min_angular'
// Member 'force_max_linear'
// Member 'force_max_angular'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__SetForceControlParams_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__SetForceControlParams_Request __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetForceControlParams_Request_
{
  using Type = SetForceControlParams_Request_<ContainerAllocator>;

  explicit SetForceControlParams_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : inertia_linear(_init),
    inertia_angular(_init),
    damping_linear(_init),
    damping_angular(_init),
    force_min_linear(_init),
    force_min_angular(_init),
    force_max_linear(_init),
    force_max_angular(_init)
  {
    (void)_init;
  }

  explicit SetForceControlParams_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : inertia_linear(_alloc, _init),
    inertia_angular(_alloc, _init),
    damping_linear(_alloc, _init),
    damping_angular(_alloc, _init),
    force_min_linear(_alloc, _init),
    force_min_angular(_alloc, _init),
    force_max_linear(_alloc, _init),
    force_max_angular(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _inertia_linear_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _inertia_linear_type inertia_linear;
  using _inertia_angular_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _inertia_angular_type inertia_angular;
  using _damping_linear_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _damping_linear_type damping_linear;
  using _damping_angular_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _damping_angular_type damping_angular;
  using _force_min_linear_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _force_min_linear_type force_min_linear;
  using _force_min_angular_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _force_min_angular_type force_min_angular;
  using _force_max_linear_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _force_max_linear_type force_max_linear;
  using _force_max_angular_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _force_max_angular_type force_max_angular;

  // setters for named parameter idiom
  Type & set__inertia_linear(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->inertia_linear = _arg;
    return *this;
  }
  Type & set__inertia_angular(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->inertia_angular = _arg;
    return *this;
  }
  Type & set__damping_linear(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->damping_linear = _arg;
    return *this;
  }
  Type & set__damping_angular(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->damping_angular = _arg;
    return *this;
  }
  Type & set__force_min_linear(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->force_min_linear = _arg;
    return *this;
  }
  Type & set__force_min_angular(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->force_min_angular = _arg;
    return *this;
  }
  Type & set__force_max_linear(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->force_max_linear = _arg;
    return *this;
  }
  Type & set__force_max_angular(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->force_max_angular = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__SetForceControlParams_Request
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__SetForceControlParams_Request
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetForceControlParams_Request_ & other) const
  {
    if (this->inertia_linear != other.inertia_linear) {
      return false;
    }
    if (this->inertia_angular != other.inertia_angular) {
      return false;
    }
    if (this->damping_linear != other.damping_linear) {
      return false;
    }
    if (this->damping_angular != other.damping_angular) {
      return false;
    }
    if (this->force_min_linear != other.force_min_linear) {
      return false;
    }
    if (this->force_min_angular != other.force_min_angular) {
      return false;
    }
    if (this->force_max_linear != other.force_max_linear) {
      return false;
    }
    if (this->force_max_angular != other.force_max_angular) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetForceControlParams_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetForceControlParams_Request_

// alias to use template instance with default allocator
using SetForceControlParams_Request =
  kinova_msgs::srv::SetForceControlParams_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__SetForceControlParams_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__SetForceControlParams_Response __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetForceControlParams_Response_
{
  using Type = SetForceControlParams_Response_<ContainerAllocator>;

  explicit SetForceControlParams_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SetForceControlParams_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__SetForceControlParams_Response
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__SetForceControlParams_Response
    std::shared_ptr<kinova_msgs::srv::SetForceControlParams_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetForceControlParams_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetForceControlParams_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetForceControlParams_Response_

// alias to use template instance with default allocator
using SetForceControlParams_Response =
  kinova_msgs::srv::SetForceControlParams_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs

namespace kinova_msgs
{

namespace srv
{

struct SetForceControlParams
{
  using Request = kinova_msgs::srv::SetForceControlParams_Request;
  using Response = kinova_msgs::srv::SetForceControlParams_Response;
};

}  // namespace srv

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__STRUCT_HPP_
