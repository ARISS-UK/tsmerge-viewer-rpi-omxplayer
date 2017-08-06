#!/bin/bash
while true; do
  echo "Starting player.."
  omxplayer --live -o hdmi --align center --audio_fifo 0.5 --video_fifo 0.5 --video_queue 0.5 --threshold 0.5 --timeout 10 --aspect-mode stretch --win 0,0,1920,1080 --adev local /home/pi/fifostream;
  echo "Stopped."
done;
