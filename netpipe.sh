#!/bin/bash
while true; do
  echo "Started pipe"
  nc -w 10 88.80.184.32 5679 > /home/pi/fifostream;
  echo "Stopped."
done;
