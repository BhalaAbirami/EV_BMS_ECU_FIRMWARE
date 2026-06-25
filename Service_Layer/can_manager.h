/*
 * CAN_manager.h
 *
 *  Created on: 15-Jun-2026
 *      Author: ABI
 */

#ifndef SERVICES_CAN_MANAGER_H_
#define SERVICES_CAN_MANAGER_H_
#include <fault_manager.h>
#include <stdint.h>
void CAN_Manager_Init(void);
void CAN_Manager_Run(void);
uint8_t CAN_IsInitialized(void);
uint8_t CAN_Manager_IsMessage_Transmitted(void);
void CAN_Manager_SendBMSStatus(void);
#endif /* SERVICES_CAN_MANAGER_H_ */
