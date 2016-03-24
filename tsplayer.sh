#!/bin/bash
cd /home/pi/ariss;
while true; do
  rm -fv fifostream;
  mkfifo fifostream;
  sudo killall omxplayer;
  sudo killall omxplayer.bin;
  omxplayer --live -o hdmi --align center --audio_fifo 0.2 --video_fifo 0.2 --video_queue 0.2 --threshold 0.5 --timeout 10 --aspect-mode stretch --win 0,0,1920,1080 --adev local fifostream &
  nc -l -w 10 1234 > fifostream;
done;
