/*
 * sensor_manager.c
 *
 *  Created on: 01-Jun-2026
 *      Author: ABI
 */
#include "sensor_manager.h"
#include "adc_driver.h"
static SensorData_t SensorData;

uint8_t ChargerConnected = 1U;
uint8_t LoadConnected = 0U;
static uint8_t SENSOR_MANAGER_Initialized = 0U;


static uint16_t PreviousVoltage = 0U;
static uint8_t StruckCounter_Voltage = 0U;
static uint8_t SensorStruck_Voltage = 0U;

static uint16_t PreviousTemp = 0U;
static uint8_t StruckCounter_Temp = 0U;
static uint8_t SensorStruck_Temp = 0U;
static uint8_t ShutdownRequested = 0U;

void Sensor_Manager_Init(void)
{
	SENSOR_MANAGER_Initialized = 1U;
	SensorData.CellVoltage_mV=3700U;
	SensorData.CellTemp_C=25U;

	  PreviousVoltage = 0U;
	  StruckCounter_Voltage = 0U;
	  SensorStruck_Voltage = 0U;

	  PreviousTemp = 0U;
	  StruckCounter_Temp = 0U;
	  SensorStruck_Temp = 0U;

}

void Sensor_Manager_Run(void)
{
	SensorData.CellVoltage_mV=ADC_ReadVoltage();
	SensorData.CellTemp_C=ADC_ReadTemperature();
	if(SensorData.CellVoltage_mV > 5000U)
	{
		SensorData.CellVoltage_mV = 0U;
	}
	else if(SensorData.CellTemp_C > 120U)
	{
		SensorData.CellTemp_C =0U;
	}

	if(SensorData.CellVoltage_mV == PreviousVoltage)
	{
		StruckCounter_Voltage ++;
		if(StruckCounter_Voltage>= 50U)
		{
			SensorStruck_Voltage = 1U;
		}
	}
	else
	{
		StruckCounter_Voltage = 0U;
		SensorStruck_Voltage = 0U;
	}
	PreviousVoltage = SensorData.CellVoltage_mV;

	if(SensorData.CellTemp_C == PreviousTemp)
		{
			StruckCounter_Temp ++;
			if(StruckCounter_Temp>= 50U)
			{
				SensorStruck_Temp = 1U;
			}
		}
		else
		{
			StruckCounter_Temp = 0U;
			SensorStruck_Temp = 0U;
		}
		PreviousTemp = SensorData.CellTemp_C;


}


SensorData_t SensorManager_GetSensorData(void)
{
	return SensorData;
}



uint8_t Sensor_Manager_IsChargerConnected(void)
{
	return ChargerConnected;
}

uint8_t Sensor_Manager_IsLoadConnected(void)
{
	return LoadConnected;
}

uint8_t Sensor_Manager_IsTempSensor_Struck(void)
{
	return SensorStruck_Temp;
}

uint8_t Sensor_Manager_IsVoltageSensor_Struck(void)
{
	return SensorStruck_Voltage;
}



uint8_t Sensor_Manager_IsShutdownRequested(void)
{
    return ShutdownRequested;
}

uint8_t SENSOR_MANAGER_IsInitialized(void)
{
	return SENSOR_MANAGER_Initialized;
}
