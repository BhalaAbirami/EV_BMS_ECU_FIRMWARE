/*
 * soc_manager.c
 *
 *  Created on: 17-Jun-2026
 *      Author: ABI
 */
#include "soc_manager.h"
#include "sensor_manager.h"
static uint8_t SOC =100U;
static uint8_t SOC_MANAGER_Initialized = 0U;

void SOC_Manager_Init(void)
{
	SOC = 100U;
	SOC_MANAGER_Initialized = 1U;
}
void SOC_Manager_Run(void)
{
	SensorData_t SensorData;

	SensorData = SensorManager_GetSensorData();

	if(SensorData.CellVoltage_mV >= 4200U)
	{
	    SOC = 100U;
	}
	else if(SensorData.CellVoltage_mV <= 3000U)
	{
	    SOC = 0U;
	}
	else
	{
	    SOC = (uint8_t)
	    (
	        ((SensorData.CellVoltage_mV - 3000U) * 100U)/(4200U - 3000U)
	    );
	}
}
uint8_t SOC_Manager_GetSOC(void)
{
	return SOC;
}

uint8_t SOC_IsInitialized(void)
{
	return SOC_MANAGER_Initialized;
}
