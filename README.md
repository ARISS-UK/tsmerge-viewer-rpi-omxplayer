# principia-ariss-displaypi

Scripts to allow a Pi to function as a display for the MPEG2/MP2 Transport Stream stripped from the ISS DVB-S by Tutioune.

## Pi Setup

```
sudo apt-get install vim fbi rpi-update openvpn git
sudo rpi-update
reboot
```

## Installation

```
[clone git and cd]
sudo cp boot-config.txt /boot/config.txt
sudo cp rc.local /etc/rc.local
sudo cp -r omxplayer-30thJan/* /
```

Edit /etc/rc.local to enable the relevant script (goonhilly/landrover)

```
reboot
```
