// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from kinova_msgs:action/ArmPose.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "kinova_msgs/action/detail/arm_pose__struct.h"
#include "kinova_msgs/action/detail/arm_pose__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_Goal_type_support_ids_t;

static const _ArmPose_Goal_type_support_ids_t _ArmPose_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_Goal_type_support_symbol_names_t _ArmPose_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_Goal)),
  }
};

typedef struct _ArmPose_Goal_type_support_data_t
{
  void * data[2];
} _ArmPose_Goal_type_support_data_t;

static _ArmPose_Goal_type_support_data_t _ArmPose_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_Goal_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_Goal)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_Result_type_support_ids_t;

static const _ArmPose_Result_type_support_ids_t _ArmPose_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_Result_type_support_symbol_names_t _ArmPose_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_Result)),
  }
};

typedef struct _ArmPose_Result_type_support_data_t
{
  void * data[2];
} _ArmPose_Result_type_support_data_t;

static _ArmPose_Result_type_support_data_t _ArmPose_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_Result_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_Result_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_Result_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_Result)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_Feedback_type_support_ids_t;

static const _ArmPose_Feedback_type_support_ids_t _ArmPose_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_Feedback_type_support_symbol_names_t _ArmPose_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_Feedback)),
  }
};

typedef struct _ArmPose_Feedback_type_support_data_t
{
  void * data[2];
} _ArmPose_Feedback_type_support_data_t;

static _ArmPose_Feedback_type_support_data_t _ArmPose_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_Feedback_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_Feedback)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_SendGoal_Request_type_support_ids_t;

static const _ArmPose_SendGoal_Request_type_support_ids_t _ArmPose_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_SendGoal_Request_type_support_symbol_names_t _ArmPose_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_SendGoal_Request)),
  }
};

typedef struct _ArmPose_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _ArmPose_SendGoal_Request_type_support_data_t;

static _ArmPose_SendGoal_Request_type_support_data_t _ArmPose_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_SendGoal_Request_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_SendGoal_Request)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_SendGoal_Response_type_support_ids_t;

static const _ArmPose_SendGoal_Response_type_support_ids_t _ArmPose_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_SendGoal_Response_type_support_symbol_names_t _ArmPose_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_SendGoal_Response)),
  }
};

typedef struct _ArmPose_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _ArmPose_SendGoal_Response_type_support_data_t;

static _ArmPose_SendGoal_Response_type_support_data_t _ArmPose_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_SendGoal_Response_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_SendGoal_Response)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_SendGoal_type_support_ids_t;

static const _ArmPose_SendGoal_type_support_ids_t _ArmPose_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_SendGoal_type_support_symbol_names_t _ArmPose_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_SendGoal)),
  }
};

typedef struct _ArmPose_SendGoal_type_support_data_t
{
  void * data[2];
} _ArmPose_SendGoal_type_support_data_t;

static _ArmPose_SendGoal_type_support_data_t _ArmPose_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_SendGoal_service_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ArmPose_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_SendGoal)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_GetResult_Request_type_support_ids_t;

static const _ArmPose_GetResult_Request_type_support_ids_t _ArmPose_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_GetResult_Request_type_support_symbol_names_t _ArmPose_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_GetResult_Request)),
  }
};

typedef struct _ArmPose_GetResult_Request_type_support_data_t
{
  void * data[2];
} _ArmPose_GetResult_Request_type_support_data_t;

static _ArmPose_GetResult_Request_type_support_data_t _ArmPose_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_GetResult_Request_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_GetResult_Request)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_GetResult_Response_type_support_ids_t;

static const _ArmPose_GetResult_Response_type_support_ids_t _ArmPose_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_GetResult_Response_type_support_symbol_names_t _ArmPose_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_GetResult_Response)),
  }
};

typedef struct _ArmPose_GetResult_Response_type_support_data_t
{
  void * data[2];
} _ArmPose_GetResult_Response_type_support_data_t;

static _ArmPose_GetResult_Response_type_support_data_t _ArmPose_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_GetResult_Response_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_GetResult_Response)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_GetResult_type_support_ids_t;

static const _ArmPose_GetResult_type_support_ids_t _ArmPose_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_GetResult_type_support_symbol_names_t _ArmPose_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_GetResult)),
  }
};

typedef struct _ArmPose_GetResult_type_support_data_t
{
  void * data[2];
} _ArmPose_GetResult_type_support_data_t;

static _ArmPose_GetResult_type_support_data_t _ArmPose_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_GetResult_service_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ArmPose_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_GetResult)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__struct.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace kinova_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _ArmPose_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ArmPose_FeedbackMessage_type_support_ids_t;

static const _ArmPose_FeedbackMessage_type_support_ids_t _ArmPose_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ArmPose_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ArmPose_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ArmPose_FeedbackMessage_type_support_symbol_names_t _ArmPose_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, action, ArmPose_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmPose_FeedbackMessage)),
  }
};

typedef struct _ArmPose_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _ArmPose_FeedbackMessage_type_support_data_t;

static _ArmPose_FeedbackMessage_type_support_data_t _ArmPose_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ArmPose_FeedbackMessage_message_typesupport_map = {
  2,
  "kinova_msgs",
  &_ArmPose_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_ArmPose_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_ArmPose_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ArmPose_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ArmPose_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace kinova_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, kinova_msgs, action, ArmPose_FeedbackMessage)() {
  return &::kinova_msgs::action::rosidl_typesupport_c::ArmPose_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "kinova_msgs/action/arm_pose.h"
// already included above
// #include "kinova_msgs/action/detail/arm_pose__type_support.h"

static rosidl_action_type_support_t _kinova_msgs__action__ArmPose__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, kinova_msgs, action, ArmPose)()
{
  // Thread-safe by always writing the same values to the static struct
  _kinova_msgs__action__ArmPose__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, kinova_msgs, action, ArmPose_SendGoal)();
  _kinova_msgs__action__ArmPose__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, kinova_msgs, action, ArmPose_GetResult)();
  _kinova_msgs__action__ArmPose__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _kinova_msgs__action__ArmPose__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, kinova_msgs, action, ArmPose_FeedbackMessage)();
  _kinova_msgs__action__ArmPose__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_kinova_msgs__action__ArmPose__typesupport_c;
}

#ifdef __cplusplus
}
#endif
