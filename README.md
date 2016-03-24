# principia-ariss-displaypi

Scripts to allow a Pi to function as a display for the MPEG2/MP2 Transport Stream stripped from the ISS DVB-S by Tutioune.

## Pi Setup

```
sudo apt-get install vim rpi-update openvpn git
sudo rpi-update
reboot
```

## Install omxplayer from source

```
git submodule update --init
cd omxplayer/
./prepare-native-raspbian.sh
make ffmpeg
make
sudo make install
```

## Install OpenVG Libraries

```
sudo apt-get install libjpeg8-dev indent libfreetype6-dev ttf-dejavu-core
cd openvg/
make
make library
sudo make install
```

## Compile Graphics (only required for new code / new arch)
```
cd graphic/
make
```

## Installation

```
[clone git and cd]
sudo cp boot-config.txt /boot/config.txt
sudo cp rc.local /etc/rc.local
```

Edit /etc/rc.local to enable the relevant script (goonhilly/landrover)

```
reboot
```
