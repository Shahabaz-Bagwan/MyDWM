#!/bin/bash
export TERMINAL="/usr/local/bin/st"
export EDITOR="/usr/bin/vim"
export VISUAL=$EDITOR
export RANGER_LOAD_DEFAULT_RC=FALSE
setxkbmap -option caps:swapescape
setxkbmap -layout us -variant altgr-intl

xinput set-prop "SYN1B7D:01 06CB:2991 Touchpad" "libinput Tapping Enabled" 1
xinput set-prop "SYN1B7D:01 06CB:2991 Touchpad" "libinput Natural Scrolling Enabled" 1
xinput set-prop "SYNA2393:00 06CB:7A13 Touchpad" "libinput Tapping Enabled" 1
xinput set-prop "SYNA2393:00 06CB:7A13 Touchpad" "libinput Natural Scrolling Enabled" 1

killall dwmblocks nm-applet blueman-applet pasystray
dwmblocks 2>&1 >/dev/null &

compton &

~/github/randomWallpaper.sh &

nm-applet &
blueman-applet &
pasystray &

exit 0
