#include "/home/ether/self-openwrt/package/system/monitor/include/systemshm.h"
#include <sys/shm.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

tSystemShm *systemShm;

bool initShm(const char* PROCESS_NAME)
{
	usleep(50*1000);
	int shmId = shmget(KEY_SYSTEM_SHM, sizeof(tSystemShm), IPC_CREAT | 0666);
	if (shmId == -1)
	{
		printf("[%s] Fail to shmget tShmArduinoData\n", PROCESS_NAME);
		return false;
	}

    systemShm = (tSystemShm*) shmat(shmId, NULL, 0);
	if (systemShm == (void*)-1)
	{
		printf("[%s] Fail to shmat tShmArduinoData\n", PROCESS_NAME);
		return false;
	}

	return true;
}

bool readyShm(const char* PROCESS_NAME)
{
	usleep(50*1000);
	if ((systemShm->ProcessShmStatus.status & 0b00001111) == 0b00001111)
	{
		printf("[%s] All process Shm is ready\n", PROCESS_NAME);
		return true;
	}
	printf("[%s] systemShm->ProcessShmStatus.status = %d\n", PROCESS_NAME, systemShm->ProcessShmStatus.status);
	return false;
}