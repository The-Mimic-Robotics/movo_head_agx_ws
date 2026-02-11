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

DELAY = 2


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

    # Terminal 1: Arms NUC - roscore + dual arms
    # bash -ic makes it interactive so .bashrc is sourced automatically
    # roslaunch is long-running so SSH stays open
    arms = write_script(
        f"sshpass -p '{ARMS_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {ARMS_USER}@{ARMS_HOST}"
        f""" 'bash -ic "roscore & sleep 4 && roslaunch kinova_bringup dual_arms.launch"'"""
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
        f""" 'if docker ps --format {{{{.Names}}}} | grep -q ros_bridge; then"""
        f"""   echo "[BRIDGE] ros_bridge container already running, skipping.";"""
        f"""   docker logs -f ros_bridge;"""
        f""" else"""
        f"""   cd ~ && ./ros-humble-ros1-bridge-builder/kinova_ros1_bridge_v2.sh;"""
        f""" fi'"""
        f"\necho '[BRIDGE] Process stopped. Reconnecting to SSH...'"
        f"\nexec sshpass -p '{BASE_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {BASE_USER}@{BASE_HOST}"
    )

    # Terminal 3: Base NUC - base bringup (placeholder)
    # TODO: replace echo with: ros2 launch <package> base_bringup.launch.py
    bringup = write_script(
        f"sshpass -p '{BASE_PASS}' ssh -tt"
        f" -o StrictHostKeyChecking=no -o UserKnownHostsFile=/dev/null"
        f" {BASE_USER}@{BASE_HOST}"
        f""" 'echo "[BRINGUP] placeholder - edit start_robot.py when ready"'"""
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
