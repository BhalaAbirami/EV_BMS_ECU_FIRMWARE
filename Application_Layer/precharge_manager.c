/*
 * precharge_manager.c
 *
 *  Created on: 19-Jun-2026
 *      Author: ABI
 */
#include "precharge_manager.h"
static uint8_t PrechargeComplete = 0U;
static uint16_t PrechargeCounter = 0U;
static uint8_t PRECHARGE_MANAGER_Initialized = 0U;

void Precharge_Manager_Init(void)
{
	PrechargeComplete = 0U;
	PrechargeCounter = 0U;
	PRECHARGE_MANAGER_Initialized = 1U;
}
void Precharge_Manager_Run(void)
{
	if(PrechargeComplete == 0U)
	{
		PrechargeCounter++;
		if(PrechargeCounter>=50U)
		{
			PrechargeComplete = 1U;
		}
	}
}

uint8_t Precharge_Manager_IsComplete(void)
{
	return PrechargeComplete;
}

uint8_t PRECHARGE_MANAGER_IsInitialized(void)
{
	return PRECHARGE_MANAGER_Initialized;
}
