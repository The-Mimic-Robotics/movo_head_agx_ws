# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kinova_msgs:action/SetFingersPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SetFingersPosition_Goal(type):
    """Metaclass of message 'SetFingersPosition_Goal'."""

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
                'kinova_msgs.action.SetFingersPosition_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__goal

            from kinova_msgs.msg import FingerPosition
            if FingerPosition.__class__._TYPE_SUPPORT is None:
                FingerPosition.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_Goal(metaclass=Metaclass_SetFingersPosition_Goal):
    """Message class 'SetFingersPosition_Goal'."""

    __slots__ = [
        '_fingers',
    ]

    _fields_and_field_types = {
        'fingers': 'kinova_msgs/FingerPosition',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['kinova_msgs', 'msg'], 'FingerPosition'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from kinova_msgs.msg import FingerPosition
        self.fingers = kwargs.get('fingers', FingerPosition())

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
        if self.fingers != other.fingers:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def fingers(self):
        """Message field 'fingers'."""
        return self._fingers

    @fingers.setter
    def fingers(self, value):
        if __debug__:
            from kinova_msgs.msg import FingerPosition
            assert \
                isinstance(value, FingerPosition), \
                "The 'fingers' field must be a sub message of type 'FingerPosition'"
        self._fingers = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetFingersPosition_Result(type):
    """Metaclass of message 'SetFingersPosition_Result'."""

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
                'kinova_msgs.action.SetFingersPosition_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__result

            from kinova_msgs.msg import FingerPosition
            if FingerPosition.__class__._TYPE_SUPPORT is None:
                FingerPosition.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_Result(metaclass=Metaclass_SetFingersPosition_Result):
    """Message class 'SetFingersPosition_Result'."""

    __slots__ = [
        '_fingers',
    ]

    _fields_and_field_types = {
        'fingers': 'kinova_msgs/FingerPosition',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['kinova_msgs', 'msg'], 'FingerPosition'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from kinova_msgs.msg import FingerPosition
        self.fingers = kwargs.get('fingers', FingerPosition())

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
        if self.fingers != other.fingers:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def fingers(self):
        """Message field 'fingers'."""
        return self._fingers

    @fingers.setter
    def fingers(self, value):
        if __debug__:
            from kinova_msgs.msg import FingerPosition
            assert \
                isinstance(value, FingerPosition), \
                "The 'fingers' field must be a sub message of type 'FingerPosition'"
        self._fingers = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetFingersPosition_Feedback(type):
    """Metaclass of message 'SetFingersPosition_Feedback'."""

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
                'kinova_msgs.action.SetFingersPosition_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__feedback

            from kinova_msgs.msg import FingerPosition
            if FingerPosition.__class__._TYPE_SUPPORT is None:
                FingerPosition.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_Feedback(metaclass=Metaclass_SetFingersPosition_Feedback):
    """Message class 'SetFingersPosition_Feedback'."""

    __slots__ = [
        '_fingers',
    ]

    _fields_and_field_types = {
        'fingers': 'kinova_msgs/FingerPosition',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['kinova_msgs', 'msg'], 'FingerPosition'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from kinova_msgs.msg import FingerPosition
        self.fingers = kwargs.get('fingers', FingerPosition())

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
        if self.fingers != other.fingers:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def fingers(self):
        """Message field 'fingers'."""
        return self._fingers

    @fingers.setter
    def fingers(self, value):
        if __debug__:
            from kinova_msgs.msg import FingerPosition
            assert \
                isinstance(value, FingerPosition), \
                "The 'fingers' field must be a sub message of type 'FingerPosition'"
        self._fingers = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetFingersPosition_SendGoal_Request(type):
    """Metaclass of message 'SetFingersPosition_SendGoal_Request'."""

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
                'kinova_msgs.action.SetFingersPosition_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__send_goal__request

            from kinova_msgs.action import SetFingersPosition
            if SetFingersPosition.Goal.__class__._TYPE_SUPPORT is None:
                SetFingersPosition.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_SendGoal_Request(metaclass=Metaclass_SetFingersPosition_SendGoal_Request):
    """Message class 'SetFingersPosition_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'kinova_msgs/SetFingersPosition_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['kinova_msgs', 'action'], 'SetFingersPosition_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from kinova_msgs.action._set_fingers_position import SetFingersPosition_Goal
        self.goal = kwargs.get('goal', SetFingersPosition_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from kinova_msgs.action._set_fingers_position import SetFingersPosition_Goal
            assert \
                isinstance(value, SetFingersPosition_Goal), \
                "The 'goal' field must be a sub message of type 'SetFingersPosition_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetFingersPosition_SendGoal_Response(type):
    """Metaclass of message 'SetFingersPosition_SendGoal_Response'."""

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
                'kinova_msgs.action.SetFingersPosition_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_SendGoal_Response(metaclass=Metaclass_SetFingersPosition_SendGoal_Response):
    """Message class 'SetFingersPosition_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_SetFingersPosition_SendGoal(type):
    """Metaclass of service 'SetFingersPosition_SendGoal'."""

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
                'kinova_msgs.action.SetFingersPosition_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__set_fingers_position__send_goal

            from kinova_msgs.action import _set_fingers_position
            if _set_fingers_position.Metaclass_SetFingersPosition_SendGoal_Request._TYPE_SUPPORT is None:
                _set_fingers_position.Metaclass_SetFingersPosition_SendGoal_Request.__import_type_support__()
            if _set_fingers_position.Metaclass_SetFingersPosition_SendGoal_Response._TYPE_SUPPORT is None:
                _set_fingers_position.Metaclass_SetFingersPosition_SendGoal_Response.__import_type_support__()


class SetFingersPosition_SendGoal(metaclass=Metaclass_SetFingersPosition_SendGoal):
    from kinova_msgs.action._set_fingers_position import SetFingersPosition_SendGoal_Request as Request
    from kinova_msgs.action._set_fingers_position import SetFingersPosition_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetFingersPosition_GetResult_Request(type):
    """Metaclass of message 'SetFingersPosition_GetResult_Request'."""

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
                'kinova_msgs.action.SetFingersPosition_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_GetResult_Request(metaclass=Metaclass_SetFingersPosition_GetResult_Request):
    """Message class 'SetFingersPosition_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetFingersPosition_GetResult_Response(type):
    """Metaclass of message 'SetFingersPosition_GetResult_Response'."""

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
                'kinova_msgs.action.SetFingersPosition_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__get_result__response

            from kinova_msgs.action import SetFingersPosition
            if SetFingersPosition.Result.__class__._TYPE_SUPPORT is None:
                SetFingersPosition.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_GetResult_Response(metaclass=Metaclass_SetFingersPosition_GetResult_Response):
    """Message class 'SetFingersPosition_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'kinova_msgs/SetFingersPosition_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['kinova_msgs', 'action'], 'SetFingersPosition_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from kinova_msgs.action._set_fingers_position import SetFingersPosition_Result
        self.result = kwargs.get('result', SetFingersPosition_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from kinova_msgs.action._set_fingers_position import SetFingersPosition_Result
            assert \
                isinstance(value, SetFingersPosition_Result), \
                "The 'result' field must be a sub message of type 'SetFingersPosition_Result'"
        self._result = value


class Metaclass_SetFingersPosition_GetResult(type):
    """Metaclass of service 'SetFingersPosition_GetResult'."""

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
                'kinova_msgs.action.SetFingersPosition_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__set_fingers_position__get_result

            from kinova_msgs.action import _set_fingers_position
            if _set_fingers_position.Metaclass_SetFingersPosition_GetResult_Request._TYPE_SUPPORT is None:
                _set_fingers_position.Metaclass_SetFingersPosition_GetResult_Request.__import_type_support__()
            if _set_fingers_position.Metaclass_SetFingersPosition_GetResult_Response._TYPE_SUPPORT is None:
                _set_fingers_position.Metaclass_SetFingersPosition_GetResult_Response.__import_type_support__()


class SetFingersPosition_GetResult(metaclass=Metaclass_SetFingersPosition_GetResult):
    from kinova_msgs.action._set_fingers_position import SetFingersPosition_GetResult_Request as Request
    from kinova_msgs.action._set_fingers_position import SetFingersPosition_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SetFingersPosition_FeedbackMessage(type):
    """Metaclass of message 'SetFingersPosition_FeedbackMessage'."""

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
                'kinova_msgs.action.SetFingersPosition_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__set_fingers_position__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__set_fingers_position__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__set_fingers_position__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__set_fingers_position__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__set_fingers_position__feedback_message

            from kinova_msgs.action import SetFingersPosition
            if SetFingersPosition.Feedback.__class__._TYPE_SUPPORT is None:
                SetFingersPosition.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SetFingersPosition_FeedbackMessage(metaclass=Metaclass_SetFingersPosition_FeedbackMessage):
    """Message class 'SetFingersPosition_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'kinova_msgs/SetFingersPosition_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['kinova_msgs', 'action'], 'SetFingersPosition_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from kinova_msgs.action._set_fingers_position import SetFingersPosition_Feedback
        self.feedback = kwargs.get('feedback', SetFingersPosition_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from kinova_msgs.action._set_fingers_position import SetFingersPosition_Feedback
            assert \
                isinstance(value, SetFingersPosition_Feedback), \
                "The 'feedback' field must be a sub message of type 'SetFingersPosition_Feedback'"
        self._feedback = value


class Metaclass_SetFingersPosition(type):
    """Metaclass of action 'SetFingersPosition'."""

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
                'kinova_msgs.action.SetFingersPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__set_fingers_position

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from kinova_msgs.action import _set_fingers_position
            if _set_fingers_position.Metaclass_SetFingersPosition_SendGoal._TYPE_SUPPORT is None:
                _set_fingers_position.Metaclass_SetFingersPosition_SendGoal.__import_type_support__()
            if _set_fingers_position.Metaclass_SetFingersPosition_GetResult._TYPE_SUPPORT is None:
                _set_fingers_position.Metaclass_SetFingersPosition_GetResult.__import_type_support__()
            if _set_fingers_position.Metaclass_SetFingersPosition_FeedbackMessage._TYPE_SUPPORT is None:
                _set_fingers_position.Metaclass_SetFingersPosition_FeedbackMessage.__import_type_support__()


class SetFingersPosition(metaclass=Metaclass_SetFingersPosition):

    # The goal message defined in the action definition.
    from kinova_msgs.action._set_fingers_position import SetFingersPosition_Goal as Goal
    # The result message defined in the action definition.
    from kinova_msgs.action._set_fingers_position import SetFingersPosition_Result as Result
    # The feedback message defined in the action definition.
    from kinova_msgs.action._set_fingers_position import SetFingersPosition_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from kinova_msgs.action._set_fingers_position import SetFingersPosition_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from kinova_msgs.action._set_fingers_position import SetFingersPosition_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from kinova_msgs.action._set_fingers_position import SetFingersPosition_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
