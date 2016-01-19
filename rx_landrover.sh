#!/bin/bash
cd /home/pi/ariss;
sudo killall fbi;
sudo fbi -T 1 -noverbose -a ARISS_On_Black.png;
while true;
do
rm -fv fifostream;
mkfifo fifostream;
sudo killall omxplayer;
sudo killall omxplayer.bin;
omxplayer --live -o hdmi --subtitles landrover.srt --align center --audio_fifo 0.2 --video_fifo 0.2 --video_queue 0.2 --threshold 0.5 --timeout 15 fifostream &
nc -p 1234 -l -w 15 > fifostream
done;
