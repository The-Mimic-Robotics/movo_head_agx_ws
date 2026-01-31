// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kinova_msgs:srv/SetEndEffectorOffset.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kinova_msgs/srv/detail/set_end_effector_offset__rosidl_typesupport_introspection_c.h"
#include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kinova_msgs/srv/detail/set_end_effector_offset__functions.h"
#include "kinova_msgs/srv/detail/set_end_effector_offset__struct.h"


// Include directives for member types
// Member `offset`
#include "geometry_msgs/msg/vector3.h"
// Member `offset`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__srv__SetEndEffectorOffset_Request__init(message_memory);
}

void kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_fini_function(void * message_memory)
{
  kinova_msgs__srv__SetEndEffectorOffset_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetEndEffectorOffset_Request, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "offset",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetEndEffectorOffset_Request, offset),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_members = {
  "kinova_msgs__srv",  // message namespace
  "SetEndEffectorOffset_Request",  // message name
  2,  // number of fields
  sizeof(kinova_msgs__srv__SetEndEffectorOffset_Request),
  kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_member_array,  // message members
  kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_type_support_handle = {
  0,
  &kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetEndEffectorOffset_Request)() {
  kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__srv__SetEndEffectorOffset_Request__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/srv/detail/set_end_effector_offset__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/srv/detail/set_end_effector_offset__functions.h"
// already included above
// #include "kinova_msgs/srv/detail/set_end_effector_offset__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__srv__SetEndEffectorOffset_Response__init(message_memory);
}

void kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_fini_function(void * message_memory)
{
  kinova_msgs__srv__SetEndEffectorOffset_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetEndEffectorOffset_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_members = {
  "kinova_msgs__srv",  // message namespace
  "SetEndEffectorOffset_Response",  // message name
  1,  // number of fields
  sizeof(kinova_msgs__srv__SetEndEffectorOffset_Response),
  kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_member_array,  // message members
  kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_type_support_handle = {
  0,
  &kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetEndEffectorOffset_Response)() {
  if (!kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__srv__SetEndEffectorOffset_Response__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kinova_msgs/srv/detail/set_end_effector_offset__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_service_members = {
  "kinova_msgs__srv",  // service namespace
  "SetEndEffectorOffset",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Request_message_type_support_handle,
  NULL  // response message
  // kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_Response_message_type_support_handle
};

static rosidl_service_type_support_t kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_service_type_support_handle = {
  0,
  &kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetEndEffectorOffset_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetEndEffectorOffset_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetEndEffectorOffset)() {
  if (!kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_service_type_support_handle.typesupport_identifier) {
    kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetEndEffectorOffset_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetEndEffectorOffset_Response)()->data;
  }

  return &kinova_msgs__srv__detail__set_end_effector_offset__rosidl_typesupport_introspection_c__SetEndEffectorOffset_service_type_support_handle;
}
