/*
 * contactor_manager.h
 *
 *  Created on: 20-Jun-2026
 *      Author: ABI
 */

#ifndef APP_CONTACTOR_MANAGER_H_
#define APP_CONTACTOR_MANAGER_H_

#include <stdint.h>

void Contactor_Manager_Init(void);

void Contactor_Manager_CloseCharge(void);
void Contactor_Manager_OpenCharge(void);

void Contactor_Manager_CloseDischarge(void);
void Contactor_Manager_OpenDischarge(void);

uint8_t Contactor_Manager_IsChargeClosed(void);
uint8_t Contactor_Manager_IsDischargeClosed(void);

uint8_t Contactor_Manager_GetChargeFeedback(void);
uint8_t Contactor_Manager_GetDischargeFeedback(void);
uint8_t CONTACTOR_MANAGER_IsInitialized(void);

#endif /* APP_CONTACTOR_MANAGER_H_ */
