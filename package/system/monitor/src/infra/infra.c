#include "/home/ether/self-openwrt/package/system/monitor/include/systemshm.h"
#include <stdio.h>

#define PROCESS_NAME "infra.c"

int main()
{
    printf("[%s] START!\n", PROCESS_NAME);

    system("/app/comm &");
    system("/app/monitor &");
    system("/app/upgrade &");

    // Check shm is ready
    while(initShm(PROCESS_NAME) != true);
    systemShm->ProcessShmStatus.bits.infraStatus = 1;
    while(readyShm(PROCESS_NAME) != true);
    
    return 0;
}
