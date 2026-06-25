/*
 * bms_scheduler.h
 *
 *  Created on: 28-May-2026
 *      Author: ABI
 */

#ifndef SERVICES_BMS_SCHEDULER_H_
#define SERVICES_BMS_SCHEDULER_H_

#include <stdint.h>
void BMS_Scheduler_Init(void);
void BMS_Scheduler_Run(void);
void Task_10ms(void);
void Task_100ms(void);
uint8_t BMS_SCHEDULER_IsInitialized(void);


#endif /* SERVICES_BMS_SCHEDULER_H_ */
