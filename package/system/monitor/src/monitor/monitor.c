#include "/home/ether/self-openwrt/package/system/monitor/include/systemshm.h"
#include <stdio.h>
#include <sys/shm.h>

#define PROCESS_NAME "upgrade.c"

int main()
{
    printf("[%s] START!\n", PROCESS_NAME);

    // Check shm is ready
    while(initShm(PROCESS_NAME) != true);
    systemShm->ProcessShmStatus.bits.monitorStatus = 1;
    while(readyShm(PROCESS_NAME) != true);
    
    return 0;
}
