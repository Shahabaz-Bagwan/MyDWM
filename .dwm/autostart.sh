#!/bin/bash

setxkbmap -option caps:swapescape

xinput set-prop "SYN1B7D:01 06CB:2991 Touchpad" "libinput Tapping Enabled" 1

xinput set-prop "SYN1B7D:01 06CB:2991 Touchpad" "libinput Natural Scrolling Enabled" 1
dwmblocks
