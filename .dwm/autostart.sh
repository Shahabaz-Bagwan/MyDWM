#!/bin/bash
export TERMINAL="/usr/local/bin/st"
export EDITOR="/usr/bin/vim"
export SUDO_ASKPASS="/usr/bin/ssh-askpass"
export VISUAL=$EDITOR
export RANGER_LOAD_DEFAULT_RC=FALSE
setxkbmap -option caps:swapescape
setxkbmap -layout us -variant altgr-intl

# Generic
xinput set-prop "SynPS/2 Synaptics TouchPad" "libinput Tapping Enabled" 1
xinput set-prop "SynPS/2 Synaptics TouchPad" "libinput Natural Scrolling Enabled" 1

# Thinkpad
xinput set-prop "SYN1B7D:01 06CB:2991 Touchpad" "libinput Tapping Enabled" 1
xinput set-prop "SYN1B7D:01 06CB:2991 Touchpad" "libinput Natural Scrolling Enabled" 1

# Precision
xinput set-prop "SYNA2393:00 06CB:7A13 Touchpad" "libinput Tapping Enabled" 1
xinput set-prop "SYNA2393:00 06CB:7A13 Touchpad" "libinput Natural Scrolling Enabled" 1

killall dwmblocks nm-applet blueman-applet
dwmblocks 2>&1 >/dev/null &

compton &
picom &

randomWallpaper.sh &

nm-applet &
blueman-applet &

exit 0
