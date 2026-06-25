/*
 * precharge_manager.h
 *
 *  Created on: 19-Jun-2026
 *      Author: ABI
 */

#ifndef APP_PRECHARGE_MANAGER_H_
#define APP_PRECHARGE_MANAGER_H_
#include <stdint.h>
void Precharge_Manager_Init(void);
void Precharge_Manager_Run(void);
uint8_t Precharge_Manager_IsComplete(void);
uint8_t PRECHARGE_MANAGER_IsInitialized(void);

#endif /* APP_PRECHARGE_MANAGER_H_ */
