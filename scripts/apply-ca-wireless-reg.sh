#!/usr/bin/env bash
# Ubuntu/Jetson: persist CA regulatory domain + align rtl8852cu with OS reg.
# Run once:  sudo bash /home/agx/Desktop/movo_ws/scripts/apply-ca-wireless-reg.sh
# Then:      sudo reboot

set -euo pipefail

if [[ "${EUID:-0}" -ne 0 ]]; then
  exec sudo -E bash "$0" "$@"
fi

# cfg80211 is a module on this kernel; sets global regdom at load time.
install -m 644 /dev/stdin /etc/modprobe.d/cfg80211-regdom-CA.conf <<'EOF'
# ISO 3166-1 alpha-2; matches Canada (6 GHz / DFS rules from Linux regdb)
options cfg80211 ieee80211_regdom=CA
EOF

CONF=/etc/modprobe.d/8852cu.conf
if [[ ! -f "$CONF" ]]; then
  echo "Missing $CONF" >&2
  exit 1
fi

cp -a "$CONF" "${CONF}.bak.$(date +%Y%m%d%H%M%S)"
# Drop duplicate single-option lines; replace with one merged line.
sed -i \
  -e '/^options 8852cu rtw_switch_usb_mode=0$/d' \
  -e '/^options 8852cu rtw_country_code=CA$/d' \
  "$CONF"

if ! grep -q '^options 8852cu rtw_switch_usb_mode=0 rtw_country_code=CA rtw_regd_src=1 rtw_dfs_region_domain=1$' "$CONF"; then
  sed -i '/^blacklist rtw89_8852cu_git$/a options 8852cu rtw_switch_usb_mode=0 rtw_country_code=CA rtw_regd_src=1 rtw_dfs_region_domain=1' "$CONF"
fi

echo "Installed:"
echo "  /etc/modprobe.d/cfg80211-regdom-CA.conf"
echo "  Updated $CONF (backup with .bak.* next to it)"
echo
echo "Reboot to apply:  sudo reboot"
echo "After boot:       iw reg get    (expect country CA on applicable phys)"
echo
echo "Note: /etc/conf.d/wireless-regdom is not used on Ubuntu; use modprobe.d as above."
