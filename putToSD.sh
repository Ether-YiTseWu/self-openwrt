cd /home/ether/self-openwrt/bin/targets/bcm27xx/bcm2710
gunzip -d openwrt-bcm27xx-bcm2710-rpi-3-ext4-factory.img.gz

sudo umount /dev/sdb1

sudo dd if=openwrt-bcm27xx-bcm2710-rpi-3-ext4-factory.img of=/dev/sdb bs=2M
sync
