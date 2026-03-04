#!/usr/bin/env python3
"""
Test for joint-1-locked Cartesian control — 10cm cube + single-axis modes.

Sends position offsets via UDP. kinova_teleop converts them to velocity:
    vel = clamp((position - zero_ref) * udp_gain, max_lin_vel)
This is a proportional position controller — the arm chases the target.

Kinova base frame (as mounted on MOVO):
    +Y = up       -Y = down
    +Z = forward  -Z = backward
    +X = left     -X = right  (requires J1 — may be limited)

Usage:
    # 10cm cube (Y and Z faces, safest):
    python3 test_j1_locked.py --pattern cube

    # Single axis:
    python3 test_j1_locked.py --pattern y
    python3 test_j1_locked.py --pattern z

    # Faster (increase offset = bigger position error = faster arm):
    python3 test_j1_locked.py --pattern cube --offset 0.03

    # Dry run:
    python3 test_j1_locked.py --pattern cube --dry-run
"""

import argparse
import socket
import struct
import subprocess
import sys
import time


def get_joint1_angle():
    try:
        result = subprocess.run(
            ["ros2", "topic", "echo",
             "/left_arm/left_arm_driver/out/joint_angles",
             "--once", "--no-arr"],
            capture_output=True, text=True, timeout=3,
        )
        for line in result.stdout.splitlines():
            if line.strip().startswith("joint1:"):
                return float(line.split(":")[1].strip())
    except Exception as e:
        print(f"  [warn] Could not read joint1: {e}")
    return None


def send_pos(sock, addr, x, y, z):
    qw, qx, qy, qz = 1.0, 0.0, 0.0, 0.0
    payload = struct.pack("<fffffff", x, y, z, qw, qx, qy, qz)
    sock.sendto(payload, addr)


def build_pattern(name, off):
    """Return list of (label, x, y, z, hold_seconds)."""
    o = off
    cx, cy, cz = 0.0, 0.0, 0.0

    if name == "x":
        return [
            ("center",     cx,    cy, cz, 1.0),
            ("+X (left)",  cx+o,  cy, cz, 3.0),
            ("center",     cx,    cy, cz, 1.5),
            ("-X (right)", cx-o,  cy, cz, 3.0),
            ("center",     cx,    cy, cz, 1.5),
        ]
    elif name == "y":
        return [
            ("center",   cx, cy,    cz, 1.0),
            ("+Y (up)",  cx, cy+o,  cz, 3.0),
            ("center",   cx, cy,    cz, 1.5),
            ("-Y (down)",cx, cy-o,  cz, 3.0),
            ("center",   cx, cy,    cz, 1.5),
        ]
    elif name == "z":
        return [
            ("center",      cx, cy, cz,    1.0),
            ("+Z (forward)",cx, cy, cz+o,  3.0),
            ("center",      cx, cy, cz,    1.5),
            ("-Z (back)",   cx, cy, cz-o,  3.0),
            ("center",      cx, cy, cz,    1.5),
        ]
    elif name == "xyz":
        return [
            ("center",      cx,    cy,    cz,    1.0),
            ("+X (left)",   cx+o,  cy,    cz,    3.0),
            ("center",      cx,    cy,    cz,    1.5),
            ("-X (right)",  cx-o,  cy,    cz,    3.0),
            ("center",      cx,    cy,    cz,    1.5),
            ("+Y (up)",     cx,    cy+o,  cz,    3.0),
            ("center",      cx,    cy,    cz,    1.5),
            ("-Y (down)",   cx,    cy-o,  cz,    3.0),
            ("center",      cx,    cy,    cz,    1.5),
            ("+Z (forward)",cx,    cy,    cz+o,  3.0),
            ("center",      cx,    cy,    cz,    1.5),
            ("-Z (back)",   cx,    cy,    cz-o,  3.0),
            ("center",      cx,    cy,    cz,    1.5),
        ]
    elif name == "cube":
        # Trace the front 10cm x 10cm square face (Y-Z plane at X=0)
        # offset = edge length, so corners are at ±offset/2
        h = o / 2.0
        return [
            ("center",       cx, cy,    cz,    1.0),
            # Top-right corner (+Y up, +Z forward)
            ("top-right",    cx, cy+h,  cz+h,  2.5),
            # Top-left corner (+Y up, -Z back)
            ("top-left",     cx, cy+h,  cz-h,  2.5),
            # Bottom-left corner (-Y down, -Z back)
            ("bottom-left",  cx, cy-h,  cz-h,  2.5),
            # Bottom-right corner (-Y down, +Z forward)
            ("bottom-right", cx, cy-h,  cz+h,  2.5),
            # Close the square back to top-right
            ("top-right",    cx, cy+h,  cz+h,  2.5),
            # Back to center
            ("center",       cx, cy,    cz,    2.0),
        ]
    else:
        print(f"Unknown pattern: {name}")
        sys.exit(1)


def main():
    parser = argparse.ArgumentParser(description="Test J1-locked Cartesian control")
    parser.add_argument("--ip", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=5005)
    parser.add_argument("--pattern", default="cube",
                        choices=["x", "y", "z", "xyz", "cube"],
                        help="Movement pattern (x=left/right, y=up/down, z=fwd/back)")
    parser.add_argument("--offset", type=float, default=0.02,
                        help="Position offset (m). For cube, this is the edge length. "
                             "Larger = faster arm motion (vel = offset * udp_gain).")
    parser.add_argument("--j1-threshold", type=float, default=3.0,
                        help="Max allowed joint 1 drift in degrees")
    parser.add_argument("--rate", type=float, default=50.0, help="UDP send rate (Hz)")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    addr = (args.ip, args.port)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    dt = 1.0 / args.rate

    moves = build_pattern(args.pattern, args.offset)

    print("=== J1-Locked Control Test ===")
    print(f"Pattern: {args.pattern}  offset: {args.offset} m")
    print(f"  With udp_gain=2.0 → max vel ≈ {args.offset * 2.0:.3f} m/s")
    print(f"  Kinova axes: +Y=up, +Z=forward")
    print(f"J1 drift threshold: {args.j1_threshold} deg")
    print()

    j1_start = get_joint1_angle()
    if j1_start is None:
        print("ERROR: Cannot read joint 1. Is the driver running?")
        sys.exit(1)
    print(f"Joint 1 start: {j1_start:.2f} deg")
    print()

    if args.dry_run:
        print("DRY RUN:")
        for label, x, y, z, d in moves:
            print(f"  {label:18s}  pos=({x:+.4f}, {y:+.4f}, {z:+.4f})  {d:.1f}s")
        sys.exit(0)

    aborted = False
    j1_max_drift = 0.0

    try:
        for label, x, y, z, hold in moves:
            print(f"  {label:18s}  ({x:+.4f},{y:+.4f},{z:+.4f})  {hold:.1f}s  ",
                  end="", flush=True)
            steps = max(1, int(hold * args.rate))
            for _ in range(steps):
                send_pos(sock, addr, x, y, z)
                time.sleep(dt)

            j1_now = get_joint1_angle()
            if j1_now is not None:
                drift = abs(j1_now - j1_start)
                j1_max_drift = max(j1_max_drift, drift)
                ok = "OK" if drift < args.j1_threshold else "DRIFT!"
                print(f"j1={j1_now:.2f}  drift={drift:.2f} [{ok}]")
                if drift >= args.j1_threshold:
                    print(f"\n  STOP: J1 drifted {drift:.2f} deg")
                    aborted = True
                    break
            else:
                print("j1=? (read failed)")
    except KeyboardInterrupt:
        print("\n  Interrupted.")
        aborted = True
    finally:
        print("  Sending center (stop)...")
        for _ in range(50):
            send_pos(sock, addr, 0, 0, 0)
            time.sleep(dt)

    print()
    j1_end = get_joint1_angle()
    print("=== Results ===")
    print(f"  J1 start:     {j1_start:.2f} deg")
    if j1_end is not None:
        print(f"  J1 end:       {j1_end:.2f} deg")
        print(f"  J1 net drift: {abs(j1_end - j1_start):.2f} deg")
    print(f"  J1 max drift: {j1_max_drift:.2f} deg")
    print(f"  Status:       {'ABORTED' if aborted else 'PASS'}")


if __name__ == "__main__":
    main()
