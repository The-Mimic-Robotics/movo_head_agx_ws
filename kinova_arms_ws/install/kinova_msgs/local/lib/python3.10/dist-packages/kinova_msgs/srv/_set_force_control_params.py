# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kinova_msgs:srv/SetForceControlParams.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetForceControlParams_Request(type):
    """Metaclass of message 'SetForceControlParams_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kinova_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kinova_msgs.srv.SetForceControlParams_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_force_control_params__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_force_control_params__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_force_control_params__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_force_control_params__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_force_control_params__request

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetForceControlParams_Request(metaclass=Metaclass_SetForceControlParams_Request):
    """Message class 'SetForceControlParams_Request'."""

    __slots__ = [
        '_inertia_linear',
        '_inertia_angular',
        '_damping_linear',
        '_damping_angular',
        '_force_min_linear',
        '_force_min_angular',
        '_force_max_linear',
        '_force_max_angular',
    ]

    _fields_and_field_types = {
        'inertia_linear': 'geometry_msgs/Vector3',
        'inertia_angular': 'geometry_msgs/Vector3',
        'damping_linear': 'geometry_msgs/Vector3',
        'damping_angular': 'geometry_msgs/Vector3',
        'force_min_linear': 'geometry_msgs/Vector3',
        'force_min_angular': 'geometry_msgs/Vector3',
        'force_max_linear': 'geometry_msgs/Vector3',
        'force_max_angular': 'geometry_msgs/Vector3',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Vector3
        self.inertia_linear = kwargs.get('inertia_linear', Vector3())
        from geometry_msgs.msg import Vector3
        self.inertia_angular = kwargs.get('inertia_angular', Vector3())
        from geometry_msgs.msg import Vector3
        self.damping_linear = kwargs.get('damping_linear', Vector3())
        from geometry_msgs.msg import Vector3
        self.damping_angular = kwargs.get('damping_angular', Vector3())
        from geometry_msgs.msg import Vector3
        self.force_min_linear = kwargs.get('force_min_linear', Vector3())
        from geometry_msgs.msg import Vector3
        self.force_min_angular = kwargs.get('force_min_angular', Vector3())
        from geometry_msgs.msg import Vector3
        self.force_max_linear = kwargs.get('force_max_linear', Vector3())
        from geometry_msgs.msg import Vector3
        self.force_max_angular = kwargs.get('force_max_angular', Vector3())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.inertia_linear != other.inertia_linear:
            return False
        if self.inertia_angular != other.inertia_angular:
            return False
        if self.damping_linear != other.damping_linear:
            return False
        if self.damping_angular != other.damping_angular:
            return False
        if self.force_min_linear != other.force_min_linear:
            return False
        if self.force_min_angular != other.force_min_angular:
            return False
        if self.force_max_linear != other.force_max_linear:
            return False
        if self.force_max_angular != other.force_max_angular:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def inertia_linear(self):
        """Message field 'inertia_linear'."""
        return self._inertia_linear

    @inertia_linear.setter
    def inertia_linear(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'inertia_linear' field must be a sub message of type 'Vector3'"
        self._inertia_linear = value

    @builtins.property
    def inertia_angular(self):
        """Message field 'inertia_angular'."""
        return self._inertia_angular

    @inertia_angular.setter
    def inertia_angular(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'inertia_angular' field must be a sub message of type 'Vector3'"
        self._inertia_angular = value

    @builtins.property
    def damping_linear(self):
        """Message field 'damping_linear'."""
        return self._damping_linear

    @damping_linear.setter
    def damping_linear(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'damping_linear' field must be a sub message of type 'Vector3'"
        self._damping_linear = value

    @builtins.property
    def damping_angular(self):
        """Message field 'damping_angular'."""
        return self._damping_angular

    @damping_angular.setter
    def damping_angular(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'damping_angular' field must be a sub message of type 'Vector3'"
        self._damping_angular = value

    @builtins.property
    def force_min_linear(self):
        """Message field 'force_min_linear'."""
        return self._force_min_linear

    @force_min_linear.setter
    def force_min_linear(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'force_min_linear' field must be a sub message of type 'Vector3'"
        self._force_min_linear = value

    @builtins.property
    def force_min_angular(self):
        """Message field 'force_min_angular'."""
        return self._force_min_angular

    @force_min_angular.setter
    def force_min_angular(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'force_min_angular' field must be a sub message of type 'Vector3'"
        self._force_min_angular = value

    @builtins.property
    def force_max_linear(self):
        """Message field 'force_max_linear'."""
        return self._force_max_linear

    @force_max_linear.setter
    def force_max_linear(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'force_max_linear' field must be a sub message of type 'Vector3'"
        self._force_max_linear = value

    @builtins.property
    def force_max_angular(self):
        """Message field 'force_max_angular'."""
        return self._force_max_angular

    @force_max_angular.setter
    def force_max_angular(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'force_max_angular' field must be a sub message of type 'Vector3'"
        self._force_max_angular = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_SetForceControlParams_Response(type):
    """Metaclass of message 'SetForceControlParams_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kinova_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kinova_msgs.srv.SetForceControlParams_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__set_force_control_params__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__set_force_control_params__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__set_force_control_params__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__set_force_control_params__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__set_force_control_params__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetForceControlParams_Response(metaclass=Metaclass_SetForceControlParams_Response):
    """Message class 'SetForceControlParams_Response'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


class Metaclass_SetForceControlParams(type):
    """Metaclass of service 'SetForceControlParams'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kinova_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kinova_msgs.srv.SetForceControlParams')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__set_force_control_params

            from kinova_msgs.srv import _set_force_control_params
            if _set_force_control_params.Metaclass_SetForceControlParams_Request._TYPE_SUPPORT is None:
                _set_force_control_params.Metaclass_SetForceControlParams_Request.__import_type_support__()
            if _set_force_control_params.Metaclass_SetForceControlParams_Response._TYPE_SUPPORT is None:
                _set_force_control_params.Metaclass_SetForceControlParams_Response.__import_type_support__()


class SetForceControlParams(metaclass=Metaclass_SetForceControlParams):
    from kinova_msgs.srv._set_force_control_params import SetForceControlParams_Request as Request
    from kinova_msgs.srv._set_force_control_params import SetForceControlParams_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
