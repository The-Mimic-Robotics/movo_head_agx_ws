// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:srv/RunCOMParametersEstimation.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__RUN_COM_PARAMETERS_ESTIMATION__STRUCT_HPP_
#define KINOVA_MSGS__SRV__DETAIL__RUN_COM_PARAMETERS_ESTIMATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Request __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RunCOMParametersEstimation_Request_
{
  using Type = RunCOMParametersEstimation_Request_<ContainerAllocator>;

  explicit RunCOMParametersEstimation_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit RunCOMParametersEstimation_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Request
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Request
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RunCOMParametersEstimation_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const RunCOMParametersEstimation_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RunCOMParametersEstimation_Request_

// alias to use template instance with default allocator
using RunCOMParametersEstimation_Request =
  kinova_msgs::srv::RunCOMParametersEstimation_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Response __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RunCOMParametersEstimation_Response_
{
  using Type = RunCOMParametersEstimation_Response_<ContainerAllocator>;

  explicit RunCOMParametersEstimation_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  explicit RunCOMParametersEstimation_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Response
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__RunCOMParametersEstimation_Response
    std::shared_ptr<kinova_msgs::srv::RunCOMParametersEstimation_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RunCOMParametersEstimation_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const RunCOMParametersEstimation_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RunCOMParametersEstimation_Response_

// alias to use template instance with default allocator
using RunCOMParametersEstimation_Response =
  kinova_msgs::srv::RunCOMParametersEstimation_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs

namespace kinova_msgs
{

namespace srv
{

struct RunCOMParametersEstimation
{
  using Request = kinova_msgs::srv::RunCOMParametersEstimation_Request;
  using Response = kinova_msgs::srv::RunCOMParametersEstimation_Response;
};

}  // namespace srv

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__RUN_COM_PARAMETERS_ESTIMATION__STRUCT_HPP_
