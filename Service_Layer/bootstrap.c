/*
 * bootstrap.c
 *
 *  Created on: 14-Jun-2026
 *      Author: ABI
 */
#include "bms_scheduler.h"
#include "bootstrap.h"
#include "contactor_manager.h"
#include "fault_manager.h"
#include "precharge_manager.h"
#include "soc_manager.h"
#include "soh_manager.h"
#include "can_manager.h"
#include "bms_fsm.h"
#include "sensor_manager.h"
# include "watchdog.h"
#include "adc_driver.h"
static uint8_t BootstrapComplete = 0U;
void Bootstrap_Init(void)
{

	      ADC_Init();
	      CAN_Manager_Init();
	      Sensor_Manager_Init();
	 	  Fault_Manager_Init();
	 	  SOC_Manager_Init();
	 	  SOH_Manager_Init();
	 	  Precharge_Manager_Init();
	 	 Contactor_Manager_Init();
	 BootstrapComplete = 0U;
}
void Bootstrap_Run(void)
{
	if((BMS_SCHEDULER_IsInitialized() == 1U)&&(ADC_IsInitialized() == 1U) &&(CAN_IsInitialized() == 1U)&&(CONTACTOR_MANAGER_IsInitialized() == 1U)&&(FAULT_MANAGER_IsInitialized() == 1U)&&(PRECHARGE_MANAGER_IsInitialized() == 1U)&&(SENSOR_MANAGER_IsInitialized() == 1U)&&(SOC_IsInitialized() == 1U)&&(SOH_IsInitialized() == 1U))

	{
	    BootstrapComplete = 1U;
	}
}
uint8_t Bootstrap_IsComplete(void)
{
	return BootstrapComplete;
}

