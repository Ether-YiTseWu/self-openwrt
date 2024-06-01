#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define USB_PATH "/dev/sda1"
#define USB_MOUNT_PATH "/mnt"
#define FIRMWARE_FILE_PATH "/mnt/fw.img"

int main() 
{
    printf("UPGRADE INIT!\n");

    char cmd[128] = {0};
    while (1) 
    {
        if (access(USB_PATH, F_OK) == -1)
        {
            sleep(1);
            continue;
        }

        printf("Insert USB.\n");
        sleep(3);

        while (1)
        {
            sprintf(cmd, "mount %s %s", USB_PATH, USB_MOUNT_PATH);
            system(cmd);
            sleep(5);
            
            if (access(FIRMWARE_FILE_PATH, F_OK) != -1) 
            {    
                printf("Firmware installing...\n");
                sprintf(cmd, "sysupgrade -F -n %s", FIRMWARE_FILE_PATH);
                system(cmd);     
                sleep(60);
            } 
            else 
            {
                printf("Firmware file not found.\n");
                break;
            }
        }

        sleep(1);
    }

    return 0;
}