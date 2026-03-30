#!/usr/bin/env bash
# Use Intel iwd as the Wi-Fi backend for the Realtek rtl8852cu USB adapter only, so
# WPA3-SAE on 6 GHz works with NetworkManager on Ubuntu 22.04 (NM 1.36 cannot set
# 802-11-wireless.band=6ghz; wpa_supplicant often fails to associate on 6 GHz here).
#
# Run:  sudo bash /home/agx/Desktop/movo_ws/scripts/setup-iwd-for-rtl8852cu-6ghz.sh
# Then: sudo systemctl restart NetworkManager
#       (re-plug USB Wi-Fi or reboot if the device stays disconnected)
#
# Undo: sudo rm /etc/NetworkManager/conf.d/25-wifi-iwd-rtl8852cu.conf
#       sudo rm -rf /etc/systemd/system/iwd.service.d
#       sudo systemctl daemon-reload && sudo systemctl restart iwd NetworkManager
#       (optional) sudo apt remove iwd
#
# Important: iwd must NOT attach to the onboard Wi-Fi (phy0) while NetworkManager
# still uses wpa_supplicant there (e.g. eduroam). Otherwise both daemons fight for
# nl80211 frame watches (-114 / "another supplicant running") and iwd can crash.

set -euo pipefail

if [[ "${EUID:-0}" -ne 0 ]]; then
  exec sudo -E bash "$0" "$@"
fi

export DEBIAN_FRONTEND=noninteractive
apt-get install -y iwd

install -m 644 /dev/stdin /etc/NetworkManager/conf.d/25-wifi-iwd-rtl8852cu.conf <<'EOF'
# NetworkManager 1.36: no 6 GHz band in connection profiles; iwd handles 6 GHz + SAE better.
[device]
match-device=driver:rtl8852cu
wifi.backend=iwd
EOF

# Ignore onboard wiphy (phy0 = internal rtl88x2ce here). USB Archer is phy1.
install -d -m 755 /etc/systemd/system/iwd.service.d
install -m 644 /dev/stdin /etc/systemd/system/iwd.service.d/50-nophys-internal.conf <<'EOF'
[Service]
ExecStart=
ExecStart=/usr/libexec/iwd -P phy0
EOF

systemctl daemon-reload
systemctl enable iwd
systemctl restart iwd
systemctl restart NetworkManager

echo
echo "Done. Try: nmcli connection up MOVONET_6G"
echo "If 6G still fails, reboot once. If only this match is ignored by NM, see script comments for global wifi.backend=iwd."
