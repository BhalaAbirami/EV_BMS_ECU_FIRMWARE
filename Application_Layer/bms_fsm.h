/*
 * bms_fsm.h
 *
 *  Created on: 27-May-2026
 *      Author: ABI
 */

#ifndef APP_BMS_FSM_H_
#define APP_BMS_FSM_H_
#include<stdint.h>
typedef enum
{
	BMS_INIT=0,
	BMS_IDLE,
	BMS_PRECHARGING,
	BMS_CHARGING,
	BMS_DISCHARGING,
	BMS_FAULT,
	BMS_SHUTDOWN
}BMS_State_t;
void BMS_FSM_Init(void);
void BMS_FSM_Run(void);
BMS_State_t BMS_FSM_GetState(void);



#endif /* APP_BMS_FSM_H_ */
