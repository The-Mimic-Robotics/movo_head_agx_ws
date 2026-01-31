import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/agx/Desktop/movo_ws/kinova_arms_ws/src/arms_xbox_ctr/install/arms_xbox_ctr'
