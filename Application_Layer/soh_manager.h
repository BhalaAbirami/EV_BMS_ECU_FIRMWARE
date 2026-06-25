/*
 * soh_manager.h
 *
 *  Created on: 17-Jun-2026
 *      Author: ABI
 */

#ifndef APP_SOH_MANAGER_H_
#define APP_SOH_MANAGER_H_


#include <stdint.h>

void SOH_Manager_Init(void);
void SOH_Manager_Run(void);
uint8_t SOH_IsInitialized(void);

uint8_t SOH_Manager_GetSOH(void);


#endif /* APP_SOH_MANAGER_H_ */
