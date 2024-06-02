## Ether.Wu OpenWRT
For self-learning and teaching~    
The final target is to build a safety watcher for home.     

## Source
### Hardware
- Raspberry Pi 3B+
- Arduino
- Logitech C920

### OS
- OpenWRT on Raspberry Pi
- FreeRTOS on Arduino

### Software
-

## Usage
- putToSD.sh : put img into sd card (do partition)
- putToUSB.sh : copy img into USB flash (no partition, it's raw img)
- /package/system/monitor : It's the side project codebase
- /package/base-files/files/etc/rc.local : It activate the monitor program when booting
- /Makefile_Experiment : Learn Makefile

