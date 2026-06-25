/*
 * soh_manager.c
 *
 *  Created on: 17-Jun-2026
 *      Author: ABI
 */
#include "soh_manager.h"

static uint8_t SOH = 100U;
static uint32_t CycleCount = 0U;
static uint8_t SOH_MANAGER_Initialized = 0U;

void SOH_Manager_Init(void)
{
    SOH = 100U;
    SOH_MANAGER_Initialized = 1U;

}

void SOH_Manager_Run(void)
{
	CycleCount++;

	if(CycleCount >= 1000U)
	{
	    CycleCount = 0U;

	    if(SOH > 80U)
	    {
	        SOH--;
	    }
	}

}

uint8_t SOH_Manager_GetSOH(void)
{
    return SOH;
}

uint8_t SOH_IsInitialized(void)
{
	return SOH_MANAGER_Initialized;

}
