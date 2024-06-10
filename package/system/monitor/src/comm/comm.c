#include "/home/ether/self-openwrt/package/system/monitor/include/systemshm.h"
#include <sys/shm.h>
#include <stddef.h>
#include <stdbool.h>

#define PROCESS_NAME "comm.c"

int main()
{
	printf("[%s] START!\n", PROCESS_NAME);

	// Check shm is ready
	while(initShm(PROCESS_NAME) != true);
	systemShm->ProcessShmStatus.bits.commStatus = 1;
	while(readyShm(PROCESS_NAME) != true);

	while(1)
	{

	}

	return 0;
}
