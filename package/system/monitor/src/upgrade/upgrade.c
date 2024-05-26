#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define USB_MOUNT_PATH "/mnt/usb"
#define FIRMWARE_FILE_PATH "/mnt/usb/fw.bin"
#define FIRMWARE_DEST_PATH "/tmp/fw.bin"

int main() 
{
    char buf[256];

    while (1) 
    {
        FILE *udev_monitor = popen("udevadm monitor -u -s usb", "r");
        if (!udev_monitor) 
        {
            perror("Error opening udev monitor");
            return 1;
        }

        while (fgets(buf, sizeof(buf), udev_monitor) != NULL) 
        {
            if (strstr(buf, "add") != NULL && strstr(buf, "usb") != NULL) 
            {
                printf("USB inserted. Updating firmware...\n");

                if (system("mount /dev/sda1 " USB_MOUNT_PATH) == -1)
                {
                    perror("Error mounting USB device");
                    return 1;
                }

                if (access(FIRMWARE_FILE_PATH, F_OK) != -1) 
                {
                    if (rename(FIRMWARE_FILE_PATH, FIRMWARE_DEST_PATH) == -1) 
                    {
                        perror("Error updating firmware");
                        return 1;
                    }
                    system("sysupgrade -v /tmp/fw.bin");
                    printf("Firmware updated.\n");
                } 
                else 
                {
                    printf("Firmware file not found.\n");
                }

                if (system("umount " USB_MOUNT_PATH) == -1) 
                {
                    perror("Error unmounting USB device");
                    return 1;
                }
            }
        }

        pclose(udev_monitor);
    }

    return 0;
}