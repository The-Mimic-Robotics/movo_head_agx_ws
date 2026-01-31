# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kinova_msgs:msg/FingerPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FingerPosition(type):
    """Metaclass of message 'FingerPosition'."""

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
                'kinova_msgs.msg.FingerPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__finger_position
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__finger_position
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__finger_position
            cls._TYPE_SUPPORT = module.type_support_msg__msg__finger_position
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__finger_position

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FingerPosition(metaclass=Metaclass_FingerPosition):
    """Message class 'FingerPosition'."""

    __slots__ = [
        '_finger1',
        '_finger2',
        '_finger3',
    ]

    _fields_and_field_types = {
        'finger1': 'float',
        'finger2': 'float',
        'finger3': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.finger1 = kwargs.get('finger1', float())
        self.finger2 = kwargs.get('finger2', float())
        self.finger3 = kwargs.get('finger3', float())

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
        if self.finger1 != other.finger1:
            return False
        if self.finger2 != other.finger2:
            return False
        if self.finger3 != other.finger3:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def finger1(self):
        """Message field 'finger1'."""
        return self._finger1

    @finger1.setter
    def finger1(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'finger1' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'finger1' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._finger1 = value

    @builtins.property
    def finger2(self):
        """Message field 'finger2'."""
        return self._finger2

    @finger2.setter
    def finger2(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'finger2' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'finger2' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._finger2 = value

    @builtins.property
    def finger3(self):
        """Message field 'finger3'."""
        return self._finger3

    @finger3.setter
    def finger3(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'finger3' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'finger3' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._finger3 = value
