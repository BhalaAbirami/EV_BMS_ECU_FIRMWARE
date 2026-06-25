/*
 * fault_manager.h
 *
 *  Created on: 31-May-2026
 *      Author: ABI
 */

#ifndef APP_FAULT_MANAGER_H_
#define APP_FAULT_MANAGER_H_
#include <stdint.h>
typedef enum
{
	FAULT_NONE=0,
	FAULT_OVERVOLTAGE,
	FAULT_UNDERVOLTAGE,
	FAULT_OVERTEMP,
	FAULT_WATCHDOG,
	FAULT_SENSOR_VOLTAGE_INVALID,
	FAULT_SENSOR_TEMP_INVALID,
	FAULT_SENSOR_STRUCK_VOLTAGE,
	FAULT_SENSOR_STRUCK_TEMP,
	FAULT_CAN_TIMEOUT,
	FAULT_CONTACTOR_FEEDBACK
}Fault_t;

void Fault_Manager_Init(void);
void Fault_Manager_Run(void);
void Fault_Manager_ClearFault(void);
Fault_t Fault_Manager_GetFault(void);
void Fault_Manager_SetFault(Fault_t Fault);
uint8_t Fault_Manager_IsFaultActive(void);
uint8_t FAULT_MANAGER_IsInitialized(void);


#endif /* APP_FAULT_MANAGER_H_ */
