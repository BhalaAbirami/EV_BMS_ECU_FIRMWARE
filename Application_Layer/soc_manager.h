/*
 * soc_manager.h
 *
 *  Created on: 17-Jun-2026
 *      Author: ABI
 */

#ifndef APP_SOC_MANAGER_H_
#define APP_SOC_MANAGER_H_
#include <stdint.h>
void SOC_Manager_Init(void);
void SOC_Manager_Run(void);
uint8_t SOC_Manager_GetSOC(void);
uint8_t SOC_IsInitialized(void);

#endif /* APP_SOC_MANAGER_H_ */
