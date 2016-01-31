#!/bin/bash
cd /home/pi/ariss;
sudo killall fbi;
# Wait for network
sudo fbi -T 1 -noverbose -a Black_Goonhilly_Connecting.png;
while ! ping -c 1 -W 3 10.155.0.1 > /dev/null; do
  sleep 1;
done;
sudo killall fbi;
sudo fbi -T 1 -noverbose -a Black_Goonhilly_Standingby.png;

while true; do
  sleep 1;
  # Check network connection
  if ! ifconfig | grep -F "10.155.0." > /dev/null; then
    sudo killall fbi;
    # Wait for network
    sudo fbi -T 1 -noverbose -a Black_Goonhilly_Connecting.png;
    while ! ping -c 1 -W 3 10.155.0.1 > /dev/null; do
      sleep 1;
    done;
    sudo killall fbi;
    sudo fbi -T 1 -noverbose -a Black_Goonhilly_Standingby.png;
  fi
done;
