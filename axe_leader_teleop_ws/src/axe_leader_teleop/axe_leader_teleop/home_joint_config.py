"""home_joints.yaml → axis map string + leader (x,y,z) → Kinova linear cmd.

Leader frame (AXE leader, UDP, Xbox sticks): +x forward, +y left, +z up.

YAML key ``movo_linear_axis_map`` (per ``homing_pose_name``, per arm) lists three tokens:
which *leader* component feeds Kinova base linear X, Y, Z (optional leading '-' negates).
Example: "-y,-z,x" → Kinova X = −leader_y, Kinova Y = −leader_z, Kinova Z = leader_x.

Legacy key ``teleop_axis`` is still read if ``movo_linear_axis_map`` is absent.

The axe_leader_teleop package ships config/home_joints.yaml for standalone installs.
"""

from __future__ import annotations

import os
from pathlib import Path
from typing import Any, Optional, Tuple

import yaml

try:
    from ament_index_python.packages import PackageNotFoundError, get_package_share_directory
except ImportError:
    PackageNotFoundError = Exception  # type: ignore[misc,assignment]

    def get_package_share_directory(_name: str) -> str:
        raise PackageNotFoundError()


FILENAME = "home_joints.yaml"
DEFAULT_AXIS = "x,y,z"

_ALIASES = {
    "fwd_towards_base": "y,z,x",
    "fwd_away_from_base": "-x,z,-y",
    "away_base_l_ccw90": "y,z,-x",
    "away_base_r_cw90": "-y,z,x",
}


def _yaml_paths() -> list[Path]:
    out: list[Path] = []
    seen: set[str] = set()

    def add(p: Path) -> None:
        try:
            r = p.resolve()
        except OSError:
            return
        k = str(r)
        if k in seen or not r.is_file():
            return
        seen.add(k)
        out.append(r)

    o = os.environ.get("MOVO_HOME_JOINTS_YAML", "").strip()
    if o:
        add(Path(o).expanduser())
        if out:
            return out

    try:
        here = Path(__file__).resolve()
    except OSError:
        here = Path(__file__)
    for anc in here.parents:
        if anc.name == "axe_leader_teleop_ws":
            add(anc / "src" / "axe_leader_teleop" / "config" / FILENAME)
        if anc.name == "kinova_arms_ws":
            add(anc.parent / "movoHead_ws" / "src" / "robot_bringup" / "config" / FILENAME)
        if anc.name == "movoHead_ws":
            add(anc / "src" / "robot_bringup" / "config" / FILENAME)
        add(anc / "movoHead_ws" / "src" / "robot_bringup" / "config" / FILENAME)
    try:
        add(Path(get_package_share_directory("axe_leader_teleop")) / "config" / FILENAME)
    except (PackageNotFoundError, ValueError):
        pass
    try:
        add(Path(get_package_share_directory("robot_bringup")) / "config" / FILENAME)
    except (PackageNotFoundError, ValueError):
        pass
    return out


def load_home_joints_yaml() -> Tuple[Optional[dict[str, Any]], Optional[Path]]:
    for path in _yaml_paths():
        try:
            with open(path, "r", encoding="utf-8") as f:
                return yaml.safe_load(f), path
        except OSError:
            continue
    return None, None


def movo_linear_axis_map_for_arm(arm: str) -> str:
    """movo_linear_axis_map[homing_pose_name][arm], else x,y,z. Falls back to teleop_axis."""
    cfg, _ = load_home_joints_yaml()
    if not cfg or not isinstance(cfg, dict):
        return DEFAULT_AXIS
    arm = (arm or "").strip()
    if not arm:
        return DEFAULT_AXIS
    pose = str(cfg.get("homing_pose_name") or "default").strip() or "default"
    block = cfg.get("movo_linear_axis_map") or cfg.get("teleop_axis")
    if isinstance(block, dict):
        row = block.get(pose) or block.get("default")
        if isinstance(row, dict) and arm in row and row[arm] is not None:
            return str(row[arm]).strip()
    return DEFAULT_AXIS


def axis_map_for_arm(arm: str) -> str:
    """Deprecated alias for :func:`movo_linear_axis_map_for_arm`."""
    return movo_linear_axis_map_for_arm(arm)


def parse_axis_map(spec: str) -> list[tuple[int, int]]:
    """Comma map: x,y,z = identity; -y,z,x = negate Y, etc."""
    s = (spec or DEFAULT_AXIS).strip().lower().replace(" ", "")
    if s in _ALIASES:
        s = _ALIASES[s]
    ax = {"x": 0, "y": 1, "z": 2}
    out: list[tuple[int, int]] = []
    for part in s.split(","):
        if not part:
            continue
        if part.startswith("-"):
            sign, letter = -1, part[1:]
        else:
            sign, letter = 1, part
        if letter not in ax:
            return parse_axis_map(DEFAULT_AXIS)
        out.append((ax[letter], sign))
    if len(out) != 3:
        return parse_axis_map(DEFAULT_AXIS)
    return out


def apply_linear(v: list[float], spec_or_parsed: str | list[tuple[int, int]]) -> list[float]:
    m = parse_axis_map(spec_or_parsed) if isinstance(spec_or_parsed, str) else spec_or_parsed
    return [float(v[m[i][0]]) * m[i][1] for i in range(3)]
