#!/usr/bin/env python3
"""
MOVO startup: opens 3 terminals, SSHs into each NUC, runs commands.
"""

import os
import shutil
import subprocess
import sys
import tempfile
import time

ARMS_HOST = "192.168.131.10"
ARMS_USER = "movo"
ARMS_PASS = "movo420"

BASE_HOST = "192.168.131.100"
BASE_USER = "movo_base"
BASE_PASS = "movo420"

DELAY = 3
REMOTE_CLEANUP = (
    "echo '[CLEANUP] Stopping old ROS/bridge processes...'; "
    "pkill -9 -f '[r]oslaunch' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[r]oscore' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[r]osmaster' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[r]osout' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[m]ove_group' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[m]ovo_servo' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[s]ervo' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[k]inova' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[r]ealsense' >/dev/null 2>&1 || true; "
    "pkill -9 -f '[r]viz' >/dev/null 2>&1 || true; "
    "docker rm -f ros_bridge >/dev/null 2>&1 || true; "
    "sleep 1"
)


def write_script(content):
    fd, path = tempfile.mkstemp(suffix=".sh", prefix="movo_")
    with os.fdopen(fd, "w") as f:
        f.write("#!/bin/bash\n" + content + "\n")
    os.chmod(path, 0o755)
    return path


def open_terminal(title, script_path):
    subprocess.Popen(["gnome-terminal", "--title", title, "--", "bash", script_path])


def main():
    if not shutil.which("sshpass"):
        print("[ERROR] sshpass not installed. Run: sudo apt install -y sshpass")
        sys.exit(1)

    # Terminal 1: Arms NUC - headless MoveIt Servo middleware (ROS1 Noetic)
    # This becomes the ROS1 master and routes bridge commands through Servo
    arms = write_script(
        f"sshpass -p '{ARMS_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {ARMS_USER}@{ARMS_HOST}"
        f""" 'bash -ic "{REMOTE_CLEANUP} && source /opt/ros/noetic/setup.bash && """
        f"""source ~/movo_servo_ws/devel/setup.bash && """
        f"""export ROS_MASTER_URI=http://{ARMS_HOST}:11311 && """
        f"""export ROS_IP={ARMS_HOST} && """
        f"""roslaunch movo_servo_teleop_demo movo_servo_rosbridge_single_master.launch """
        f"""local_machine_ip:={ARMS_HOST} use_real_arms:=true rviz:=false launch_joy:=false """
        f"""launch_realsense_d455:=false live_octomap_refresh:=false load_test_obstacle:=false"'"""
        f"\necho '[ARMS] Process stopped. Reconnecting to SSH...'"
        f"\nexec sshpass -p '{ARMS_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {ARMS_USER}@{ARMS_HOST}"
    )

    # Terminal 2: Base NUC - bridge script (runs as docker container "ros_bridge")
    # Check if already running first to avoid docker name conflict
    bridge = write_script(
        f"sshpass -p '{BASE_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {BASE_USER}@{BASE_HOST}"
        f""" 'bash -ic "{REMOTE_CLEANUP} && if docker ps --format {{{{.Names}}}} | grep -q ros_bridge; then"""
        f"""   echo '[BRIDGE] ros_bridge container already running, skipping.';"""
        f"""   docker logs -f ros_bridge;"""
        f""" else"""
        f"""   cd ~ && ./ros-humble-ros1-bridge-builder/kinova_ros1_bridge_101.sh;"""
        f""" fi"'"""
        f"\necho '[BRIDGE] Process stopped. Reconnecting to SSH...'"
        f"\nexec sshpass -p '{BASE_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {BASE_USER}@{BASE_HOST}"
    )
        # f"""   cd ~ && ./ros-humble-ros1-bridge-builder/kinova_ros1_bridge_v2.sh;"""

    # Terminal 3: Base NUC - base bringup (placeholder)
    
    bringup = write_script(
        f"sshpass -p '{BASE_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {BASE_USER}@{BASE_HOST}"
        f""" 'bash -ic "sleep 5 && ros2 launch movobase_activation movobase_activation.launch.py "'"""
        f"\necho '[BRINGUP] Process stopped. Reconnecting to SSH...'"
        f"\nexec sshpass -p '{BASE_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {BASE_USER}@{BASE_HOST}"
    )

    print("============================================================")
    print("  MOVO Robot Startup")
    print("============================================================")

    print("[1/3] Arms NUC...")
    open_terminal("ARMS_NUC", arms)
    time.sleep(DELAY)

    print("[2/3] Base NUC bridge...") 
    open_terminal("BASE_NUC_BRIDGE", bridge)
    time.sleep(DELAY)

    print("[3/3] Base NUC bringup...")
    open_terminal("BASE_NUC_BRINGUP", bringup)

    print("[DONE] Check terminal windows.")


if __name__ == "__main__":
    main()
