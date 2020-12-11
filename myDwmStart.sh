#!/bin/bash

#set statusbar
#while true
#do
   #if acpi -a | grep off-line > /dev/null; then
       #xsetroot -name "Bat. $(awk 'sub(/,/,"") {print $3, $4}' <(acpi -b)) \
       #| Vol. $(awk '/dB/ { gsub(/[\[\]]/,""); print $5}' <(amixer get Master)) \
       #| $(date +"%a, %b %d %R")"
   #else
       #xsetroot -name "Vol. $(awk '/dB/ { gsub(/[\[\]]/,""); print $5}' <(amixer get Master)) \
       #| $(date +"%a, %b %d %R")"
   #fi
   #sleep 1s   
#done &

##Loop
while true; do
  dwm >/dev/null 2>&1
done
