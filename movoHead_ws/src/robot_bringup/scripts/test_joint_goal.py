#!/usr/bin/env python3
"""
Send joint angle goal directly to Kinova driver from current position.
No homing, no custom math — just the raw ArmJointAngles action call.

Usage:
  python3 test_joint_goal.py              # right arm default
  python3 test_joint_goal.py left_arm     # left arm
  python3 test_joint_goal.py both_arms    # both simultaneously
"""

import sys

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from kinova_msgs.action import ArmJointAngles

TARGETS = {
    "right_arm": [261.68, 75.19, 214.16, 310.91, 136.22, 205.17, 239.77],
    "left_arm": [98.32, 284.81, 145.84, 49.09, 223.78, 154.83, 120.23],
}
JOINT_FIELDS = [f"joint{i}" for i in range(1, 8)]


class JointGoalTest(Node):
    def __init__(self, arms):
        super().__init__("test_joint_goal")
        self.arms = arms
        self.act_clients = {}
        for arm in arms:
            pfx = f"/{arm}/{arm}_driver"
            self.act_clients[arm] = ActionClient(self, ArmJointAngles, f"{pfx}/joints_action/joint_angles")

    def run(self):
        log = self.get_logger()

        for arm, cli in self.act_clients.items():
            log.info(f"[{arm}] Waiting for action server ...")
            if not cli.wait_for_server(timeout_sec=15.0):
                log.error(f"[{arm}] Action server not available")
                return

        pending = {}
        for arm, cli in self.act_clients.items():
            target = TARGETS[arm]
            goal = ArmJointAngles.Goal()
            for field, val in zip(JOINT_FIELDS, target):
                setattr(goal.angles, field, float(val))
            log.info(f"[{arm}] Sending goal: {target}")
            pending[arm] = cli.send_goal_async(goal)

        # Wait for all goal handles
        handles = {}
        for arm, fut in pending.items():
            rclpy.spin_until_future_complete(self, fut, timeout_sec=30.0)
            gh = fut.result()
            if not gh or not gh.accepted:
                log.error(f"[{arm}] Goal REJECTED")
                continue
            log.info(f"[{arm}] Goal accepted")
            handles[arm] = gh

        # Wait for all results
        result_futs = {arm: gh.get_result_async() for arm, gh in handles.items()}
        for arm, fut in result_futs.items():
            rclpy.spin_until_future_complete(self, fut, timeout_sec=180.0)
            wrapped = fut.result()
            status = wrapped.status if wrapped else None
            angles = wrapped.result.angles if wrapped else None
            if angles:
                vals = [f"{getattr(angles, f):.2f}" for f in JOINT_FIELDS]
                log.info(f"[{arm}] Final angles: [{', '.join(vals)}]")
            if status == 4:
                log.info(f"[{arm}] SUCCESS")
            else:
                log.error(f"[{arm}] FAILED (status {status})")


def main():
    rclpy.init()
    arg = sys.argv[1] if len(sys.argv) > 1 else "right_arm"
    if arg == "both_arms":
        arms = ["right_arm", "left_arm"]
    elif arg in TARGETS:
        arms = [arg]
    else:
        print(f"Unknown '{arg}'. Use: right_arm | left_arm | both_arms")
        return
    node = JointGoalTest(arms)
    node.run()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
