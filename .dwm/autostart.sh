#!/bin/bash
export TERMINAL="/usr/bin/gnome-terminal"
export EDITOR="/usr/local/bin"
export SUDO_ASKPASS="/usr/bin/ssh-askpass"
export VISUAL=$EDITOR
export RANGER_LOAD_DEFAULT_RC=FALSE

#setxkbmap -layout "us, us" -variant "altgr-intl,colemak" -option grp:shifts_toggle caps:backspace

setxkbmap us altgr-intl
#-option caps:swapescape

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

compton -f -r 20 &

randomWallpaper.sh &

nm-applet &
blueman-applet &

exit 0
