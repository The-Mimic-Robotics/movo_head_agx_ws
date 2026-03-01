#!/usr/bin/env python3
"""
Custom home service for MOVO arms.
Sends ArmJointAngles goals directly — no Kinova native home.

Services:
  /movo/home_right_arm  - right arm to desired joint config
  /movo/home_left_arm   - left arm to desired joint config
  /movo/home_both_arms  - both arms simultaneously
"""

import os
import time

import rclpy
import yaml
from ament_index_python.packages import get_package_share_directory
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

from kinova_msgs.action import ArmJointAngles
from kinova_msgs.srv import HomeArm

ARMS = {
    "right_arm": "/right_arm/right_arm_driver",
    "left_arm": "/left_arm/left_arm_driver",
}
JOINT_FIELDS = [f"joint{i}" for i in range(1, 8)]


class MovoCustomHomeService(Node):
    def __init__(self):
        super().__init__("movo_custom_home_service")
        cfg = self._load_config()
        cb = ReentrantCallbackGroup()

        self._targets = {arm: [float(cfg[arm][k]) for k in JOINT_FIELDS] for arm in ARMS}

        self._joint_act = {
            arm: ActionClient(self, ArmJointAngles,
                              f"{pfx}/joints_action/joint_angles", callback_group=cb)
            for arm, pfx in ARMS.items()
        }

        for arm in ARMS:
            self.create_service(
                HomeArm, f"/movo/home_{arm}",
                lambda req, rsp, a=arm: self._home_single(rsp, a),
                callback_group=cb,
            )
        self.create_service(
            HomeArm, "/movo/home_both_arms",
            lambda req, rsp: self._home_both(rsp),
            callback_group=cb,
        )

        self.get_logger().info("=== MOVO Custom Home Service READY ===")
        for arm in ARMS:
            self.get_logger().info(f"  /movo/home_{arm} -> {self._targets[arm]}")
        self.get_logger().info("  /movo/home_both_arms -> both simultaneously")

    def _load_config(self):
        path = os.path.join(get_package_share_directory("robot_bringup"), "config", "home_joints.yaml")
        with open(path, "r", encoding="utf-8") as f:
            return yaml.safe_load(f)

    def _home_single(self, response, arm):
        log = self.get_logger()
        log.info(f"[{arm}] Custom home START")

        ok, msg = self._send_and_wait(arm)
        if ok:
            log.info(f"[{arm}] HOMING DONE")
            response.homearm_result = "SUCCESS"
        else:
            log.error(f"[{arm}] {msg}")
            response.homearm_result = f"FAIL: {msg}"
        return response

    def _home_both(self, response):
        log = self.get_logger()
        log.info("[both_arms] Custom home START")

        results = self._send_both_and_wait()
        all_ok = all(ok for ok, _ in results.values())

        for arm, (ok, msg) in results.items():
            if ok:
                log.info(f"[{arm}] HOMING DONE")
            else:
                log.error(f"[{arm}] {msg}")

        response.homearm_result = "SUCCESS" if all_ok else "FAIL: " + "; ".join(
            f"{a}: {m}" for a, (ok, m) in results.items() if not ok
        )
        return response

    def _send_and_wait(self, arm):
        cli = self._joint_act[arm]
        if not cli.wait_for_server(timeout_sec=15.0):
            return False, "action server unavailable"

        goal = self._make_goal(arm)
        gh_fut = cli.send_goal_async(goal)
        if not self._poll(gh_fut, 30.0):
            return False, "send_goal timeout"

        gh = gh_fut.result()
        if not gh or not gh.accepted:
            return False, "goal rejected"

        res_fut = gh.get_result_async()
        if not self._poll(res_fut, 180.0):
            return False, "motion timeout"

        wrapped = res_fut.result()
        if wrapped and wrapped.status == 4:
            return True, "ok"
        return False, f"action status={getattr(wrapped, 'status', None)}"

    def _send_both_and_wait(self):
        for arm, cli in self._joint_act.items():
            if not cli.wait_for_server(timeout_sec=15.0):
                return {arm: (False, "action server unavailable") for arm in ARMS}

        gh_futs = {arm: self._joint_act[arm].send_goal_async(self._make_goal(arm)) for arm in ARMS}

        handles = {}
        for arm, fut in gh_futs.items():
            if not self._poll(fut, 30.0):
                handles[arm] = None
                continue
            gh = fut.result()
            handles[arm] = gh if gh and gh.accepted else None

        res_futs = {}
        for arm, gh in handles.items():
            if gh:
                res_futs[arm] = gh.get_result_async()

        results = {}
        for arm in ARMS:
            if arm not in res_futs:
                results[arm] = (False, "goal rejected or send timeout")
                continue
            if not self._poll(res_futs[arm], 180.0):
                results[arm] = (False, "motion timeout")
                continue
            wrapped = res_futs[arm].result()
            if wrapped and wrapped.status == 4:
                results[arm] = (True, "ok")
            else:
                results[arm] = (False, f"action status={getattr(wrapped, 'status', None)}")
        return results

    def _make_goal(self, arm):
        goal = ArmJointAngles.Goal()
        for field, val in zip(JOINT_FIELDS, self._targets[arm]):
            setattr(goal.angles, field, float(val))
        return goal

    @staticmethod
    def _poll(future, timeout):
        t0 = time.monotonic()
        while rclpy.ok() and not future.done():
            if time.monotonic() - t0 > timeout:
                return False
            time.sleep(0.05)
        return future.done()


def main(args=None):
    rclpy.init(args=args)
    node = MovoCustomHomeService()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
