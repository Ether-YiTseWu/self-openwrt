#ifndef _SYSTEMSHM_H_
#define _SYSTEMSHM_H_

#include <stdint.h>
#include <stdbool.h>

#define KEY_SYSTEM_SHM 1

typedef struct
{
	uint8_t temperature;
	uint8_t moisture;
}tShmArduinoData;

typedef union
{
	uint8_t status;
	struct
	{
		uint8_t commStatus    : 1; 
		uint8_t infraStatus   : 1; 
		uint8_t monitorStatus : 1; 
		uint8_t upgradeStatus : 1; 
		uint8_t notUse1Status : 1; 
		uint8_t notUse2Status : 1; 
		uint8_t notUse3Status : 1; 
		uint8_t notUse4Status : 1; 
	}bits;
	
}tShmReadyStatus;


typedef struct
{
	tShmArduinoData	ArduinoData;
	tShmReadyStatus	ProcessShmStatus;
}tSystemShm;

extern tSystemShm *systemShm;

bool initShm();
bool readyShm();

#endif