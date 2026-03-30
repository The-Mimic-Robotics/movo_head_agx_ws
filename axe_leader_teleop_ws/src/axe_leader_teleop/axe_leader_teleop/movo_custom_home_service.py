#!/usr/bin/env python3
"""
Custom home service for MOVO arms.
Sends ArmJointAngles goals to move arms to a predefined home position.

Services:
  /movo/home_right_arm   - home right arm
  /movo/home_left_arm    - home left arm
  /movo/home_both_arms   - home both arms simultaneously
"""

import time
from pathlib import Path

import rclpy
import yaml
from ament_index_python.packages import get_package_share_directory
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

from kinova_msgs.action import ArmJointAngles
from kinova_msgs.srv import HomeArm


class MovoCustomHomeService(Node):
    def __init__(self):
        super().__init__("movo_custom_home_service")

        config = self.load_config()
        cb_group = ReentrantCallbackGroup()

        pose_key = str(config.get("homing_pose_name") or "default").strip() or "default"
        self.get_logger().info(f"  homing_pose_name (home + teleop profile key): {pose_key}")

        home_poses = config.get("home_poses") or {}
        if isinstance(home_poses, dict) and pose_key in home_poses and isinstance(
            home_poses[pose_key], dict
        ):
            block = home_poses[pose_key]
        elif "left_arm" in config and "right_arm" in config:
            block = config
        else:
            raise KeyError(
                f"home_joints.yaml: no home_poses['{pose_key}'] and no top-level left_arm/right_arm"
            )

        self.right_arm_target = [float(block["right_arm"][f"joint{i}"]) for i in range(1, 8)]
        self.left_arm_target = [float(block["left_arm"][f"joint{i}"]) for i in range(1, 8)]

        self.right_arm_client = ActionClient(
            self, ArmJointAngles,
            "/right_arm/right_arm_driver/joints_action/joint_angles",
            callback_group=cb_group,
        )
        self.left_arm_client = ActionClient(
            self, ArmJointAngles,
            "/left_arm/left_arm_driver/joints_action/joint_angles",
            callback_group=cb_group,
        )

        self.create_service(HomeArm, "/movo/home_right_arm", self.handle_home_right, callback_group=cb_group)
        self.create_service(HomeArm, "/movo/home_left_arm", self.handle_home_left, callback_group=cb_group)
        self.create_service(HomeArm, "/movo/home_both_arms", self.handle_home_both, callback_group=cb_group)

        self.get_logger().info("=== MOVO Custom Home Service READY ===")
        self.get_logger().info(f"  /movo/home_right_arm -> {self.right_arm_target}")
        self.get_logger().info(f"  /movo/home_left_arm  -> {self.left_arm_target}")
        self.get_logger().info(f"  /movo/home_both_arms -> simultaneous")

    def load_config(self):
        """Prefer workspace src (even when this node runs from install/); else share install."""
        name = "home_joints.yaml"
        here = Path(__file__).resolve()
        ordered = []

        # 1) Monorepo / dev tree: walk parents so install/lib/.../site-packages still finds
        #    .../movo_ws/movoHead_ws/src/robot_bringup/config/home_joints.yaml
        for anc in here.parents:
            for rel in (
                ("axe_leader_teleop_ws", "src", "axe_leader_teleop", "config", name),
                ("movoHead_ws", "src", "robot_bringup", "config", name),
                ("src", "robot_bringup", "config", name),
            ):
                p = anc.joinpath(*rel)
                if p.is_file():
                    ordered.append(p)
                    break
            if ordered:
                break

        legacy = here.parent.parent / "config" / name
        if legacy.is_file() and legacy not in ordered:
            ordered.append(legacy)

        for pkg in ("axe_leader_teleop", "robot_bringup"):
            try:
                share = Path(get_package_share_directory(pkg)) / "config" / name
                if share.is_file() and share not in ordered:
                    ordered.append(share)
            except Exception:
                pass

        for path in ordered:
            with open(path, "r", encoding="utf-8") as f:
                cfg = yaml.safe_load(f)
            self.get_logger().info(f"Home joints YAML: {path}")
            return cfg

        tried = ", ".join(str(p) for p in ordered) if ordered else "(none)"
        raise FileNotFoundError(f"Missing {name} (tried {tried})")

    def make_goal(self, target_angles):
        goal = ArmJointAngles.Goal()
        for i, val in enumerate(target_angles, start=1):
            setattr(goal.angles, f"joint{i}", float(val))
        return goal

    def poll_future(self, future, timeout):
        """Block until future is done or timeout (seconds) expires."""
        deadline = time.monotonic() + timeout
        while rclpy.ok() and not future.done():
            if time.monotonic() > deadline:
                return False
            time.sleep(0.05)
        return future.done()

    def poll_all_futures(self, futures, timeout):
        """Block until ALL futures are done or timeout (seconds) expires."""
        deadline = time.monotonic() + timeout
        while rclpy.ok():
            if all(f.done() for f in futures):
                return True
            if time.monotonic() > deadline:
                return False
            time.sleep(0.05)
        return all(f.done() for f in futures)

    def send_arm_home(self, client, target, arm_name):
        """Send one arm to its home position and block until done. Returns (ok, msg)."""
        if not client.wait_for_server(timeout_sec=15.0):
            return False, "action server unavailable"

        goal_future = client.send_goal_async(self.make_goal(target))
        if not self.poll_future(goal_future, 30.0):
            return False, "send_goal timeout"

        goal_handle = goal_future.result()
        if not goal_handle or not goal_handle.accepted:
            return False, "goal rejected"

        self.get_logger().info(f"[{arm_name}] Goal accepted, arm is moving...")

        result_future = goal_handle.get_result_async()
        if not self.poll_future(result_future, 180.0):
            return False, "motion timeout"

        wrapped = result_future.result()
        if wrapped and wrapped.status == 4:
            return True, "ok"
        return False, f"action status={getattr(wrapped, 'status', None)}"

    # ── Service callbacks ──

    def handle_home_right(self, request, response):
        self.get_logger().info("[right_arm] Home START")
        ok, msg = self.send_arm_home(self.right_arm_client, self.right_arm_target, "right_arm")
        response.homearm_result = "SUCCESS" if ok else f"FAIL: {msg}"
        self.get_logger().info(f"[right_arm] {response.homearm_result}")
        return response

    def handle_home_left(self, request, response):
        self.get_logger().info("[left_arm] Home START")
        ok, msg = self.send_arm_home(self.left_arm_client, self.left_arm_target, "left_arm")
        response.homearm_result = "SUCCESS" if ok else f"FAIL: {msg}"
        self.get_logger().info(f"[left_arm] {response.homearm_result}")
        return response

    def _attempt_home_both(self, stagger_sec: float = 0.1):
        """
        Send both arms home simultaneously (with a small stagger so they complete
        at offset times, avoiding concurrent Kinova API calls in the driver).

        Returns (right_ok, left_ok, error_list).
        """
        log = self.get_logger()

        if not self.right_arm_client.wait_for_server(timeout_sec=30.0):
            return False, False, ["right arm action server unavailable"]
        if not self.left_arm_client.wait_for_server(timeout_sec=30.0):
            return False, False, ["left arm action server unavailable"]

        # Fire right arm first, then stagger before left so their Kinova API
        # completion callbacks don't race inside the arm driver.
        right_goal_fut = self.right_arm_client.send_goal_async(self.make_goal(self.right_arm_target))
        time.sleep(stagger_sec)
        left_goal_fut = self.left_arm_client.send_goal_async(self.make_goal(self.left_arm_target))

        if not self.poll_all_futures([right_goal_fut, left_goal_fut], 30.0):
            return False, False, ["send_goal timeout"]

        right_handle = right_goal_fut.result()
        left_handle = left_goal_fut.result()

        right_accepted = bool(right_handle and right_handle.accepted)
        left_accepted = bool(left_handle and left_handle.accepted)

        if right_accepted:
            log.info("[right_arm] Goal accepted, arm is moving...")
        else:
            log.error("[right_arm] Goal rejected")

        if left_accepted:
            log.info("[left_arm] Goal accepted, arm is moving...")
        else:
            log.error("[left_arm] Goal rejected")

        if not right_accepted and not left_accepted:
            return False, False, ["both goals rejected"]

        right_res_fut = right_handle.get_result_async() if right_accepted else None
        left_res_fut = left_handle.get_result_async() if left_accepted else None

        waiting = [f for f in (right_res_fut, left_res_fut) if f is not None]
        if not self.poll_all_futures(waiting, 60.0):
            return False, False, ["motion timeout"]

        errors = []

        if not right_accepted:
            errors.append("right_arm: goal rejected")
            right_ok = False
        else:
            wrapped = right_res_fut.result()
            right_ok = bool(wrapped and wrapped.status == 4)
            if right_ok:
                log.info("[right_arm] Home DONE")
            else:
                status = getattr(wrapped, "status", None)
                log.warn(f"[right_arm] FAIL: action status={status}")
                errors.append(f"right_arm: status={status}")

        if not left_accepted:
            errors.append("left_arm: goal rejected")
            left_ok = False
        else:
            wrapped = left_res_fut.result()
            left_ok = bool(wrapped and wrapped.status == 4)
            if left_ok:
                log.info("[left_arm] Home DONE")
            else:
                status = getattr(wrapped, "status", None)
                log.warn(f"[left_arm] FAIL: action status={status}")
                errors.append(f"left_arm: status={status}")

        return right_ok, left_ok, errors

    def handle_home_both(self, request, response):
        log = self.get_logger()
        log.info("[both_arms] Home START")

        # The Kinova arm driver can crash with KinovaCommException when both arms
        # complete their homing trajectories at the exact same time (concurrent API
        # calls in the driver's setSucceeded callback). A 0.5 s stagger between
        # goal submissions offsets their completion times so the API calls are
        # serialised. If a driver/bridge crash still occurs, we wait for recovery
        # and retry once.
        max_attempts = 3
        recovery_wait_sec = 8.0

        for attempt in range(1, max_attempts + 1):
            if attempt > 1:
                log.warn(
                    f"[both_arms] Attempt {attempt - 1} failed — "
                    f"waiting {recovery_wait_sec:.0f} s for driver/bridge recovery ..."
                )
                time.sleep(recovery_wait_sec)
                log.info(f"[both_arms] Retry attempt {attempt}")

            right_ok, left_ok, errors = self._attempt_home_both(stagger_sec=0.1)

            if right_ok and left_ok:
                response.homearm_result = "SUCCESS"
                log.info("[both_arms] Home DONE")
                return response

            if attempt == max_attempts:
                break

        response.homearm_result = "FAIL: " + "; ".join(errors)
        log.error(f"[both_arms] {response.homearm_result}")
        return response


def main(args=None):
    rclpy.init(args=args)
    node = MovoCustomHomeService()
    # MultiThreadedExecutor needed so action-client responses can arrive
    # while a service callback is blocked waiting for results.
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
