/*
 * fault_manager.c
 *
 *  Created on: 31-May-2026
 *      Author: ABI
 */
#include "contactor_manager.h"
#include "fault_manager.h"
#include "can_manager.h"
#include "bms_config.h"
#include "sensor_manager.h"
static Fault_t CurrentFault;
static uint8_t FaultLatched = 0U;
static uint8_t OverVoltage_Counter = 0U;
static uint8_t OverTemp_Counter = 0U;
static uint8_t UnderVoltageCounter = 0U;
static uint8_t Voltage_Invalid_Counter = 0U;
static uint8_t Temp_Invalid_Counter = 0U;
static uint8_t Voltage_Struck_Counter = 0U;
static uint8_t Temp_Struck_Counter = 0U;
static uint8_t CAN_Timeout_Counter = 0U;
static uint8_t ContactorFeedbackCounter =0U;

static uint8_t FAULT_MANAGER_Initialized = 0U;

void Fault_Manager_Init(void)
{
	CurrentFault=FAULT_NONE;
	FAULT_MANAGER_Initialized = 1U;
	FaultLatched = 0U;

}
void Fault_Manager_Run(void)
{
	SensorData_t SensorData;
	SensorData = SensorManager_GetSensorData();
	if(FaultLatched==0U)
	{
	    if(SensorData.CellVoltage_mV > MAX_CELL_VOLTAGE_MV)
		{
		    OverVoltage_Counter++;
		}
	    else
	    {
	    	OverVoltage_Counter = 0U;
	    }
	    if(SensorData.CellTemp_C > MAX_CELL_TEMPERATURE_C)
	  	{
	    	OverTemp_Counter++;
	  	}
	    else
	    {
	    	OverTemp_Counter = 0U;
	    }
	    if(SensorData.CellVoltage_mV < MIN_CELL_VOLTAGE_MV)
	    {
	        UnderVoltageCounter++;
	    }
	    else
	    {
	        UnderVoltageCounter = 0U;
	    }

	    if(SensorData.CellVoltage_mV == 0U)
	    {
	    	Voltage_Invalid_Counter++;
	    }
	   else
	   {
		   Voltage_Invalid_Counter = 0U;
	   }
	    if(SensorData.CellTemp_C == 0U)
	    {
	    	Temp_Invalid_Counter++;
	    }
	    else
	    {
	    	Temp_Invalid_Counter = 0U;
	    }
	    if(Sensor_Manager_IsTempSensor_Struck() == 1U)
	    {
	    	Temp_Struck_Counter++;
	    }
	    else
	    {
	    	Temp_Struck_Counter = 0U;
	    }
	    if(Sensor_Manager_IsVoltageSensor_Struck() == 1U)
	    {
	    	Voltage_Struck_Counter++;
	    }
	    else
	    {
	    	Voltage_Struck_Counter = 0U;
	    }
	    if(CAN_Manager_IsMessage_Transmitted()== 0U)
	    {
	    	CAN_Timeout_Counter++;
	    }
	    else
	    {
	    	CAN_Timeout_Counter = 0U;
	    }
	    if(Contactor_Manager_IsChargeClosed() !=
	       Contactor_Manager_GetChargeFeedback())
	    {
	        ContactorFeedbackCounter++;
	    }
	    else
	    {
	        ContactorFeedbackCounter = 0U;
	    }


	     if(Voltage_Invalid_Counter >= 3U)
	    {
	        CurrentFault = FAULT_SENSOR_VOLTAGE_INVALID;
	        FaultLatched = 1U;
	    }
	    else if(Temp_Invalid_Counter >= 3U)
	    {
	        CurrentFault = FAULT_SENSOR_TEMP_INVALID;
	        FaultLatched = 1U;
	    }
	    else if(OverVoltage_Counter >= 3U)
	    {
	        CurrentFault = FAULT_OVERVOLTAGE;
	        FaultLatched = 1U;
	    }
	    else if(OverTemp_Counter >= 3U)
	    {
	        CurrentFault = FAULT_OVERTEMP;
	        FaultLatched = 1U;
	    }
	    else if(UnderVoltageCounter >= 3U)
	    {
	        CurrentFault = FAULT_UNDERVOLTAGE;
	        FaultLatched = 1U;
	    }
	    else if(Voltage_Struck_Counter >= 3U)
		{
	    	CurrentFault = FAULT_SENSOR_STRUCK_VOLTAGE;
	    	FaultLatched = 1U;
		}
	    else if(Temp_Struck_Counter >= 3U)
	    {
	    	CurrentFault = FAULT_SENSOR_STRUCK_TEMP;
	    	FaultLatched = 1U;

	    }
	    else if(CAN_Timeout_Counter >=10U)
	    {
	    	CurrentFault = FAULT_CAN_TIMEOUT;
	    	FaultLatched = 1U;
	    }
	    else if(ContactorFeedbackCounter >= 3U)
	     {
	         Fault_Manager_SetFault(FAULT_CONTACTOR_FEEDBACK);
	         FaultLatched = 1U;
	     }

	    else
	    {
	        CurrentFault = FAULT_NONE;
	    }
     }
}
Fault_t Fault_Manager_GetFault(void)
{
	return CurrentFault;
}
void Fault_Manager_SetFault(Fault_t Fault)
{
	CurrentFault=Fault;
}

void Fault_Manager_ClearFault(void)
{
	CurrentFault= FAULT_NONE;
	FaultLatched = 0U;
	  OverVoltage_Counter = 0U;
	  OverTemp_Counter = 0U;
	  UnderVoltageCounter = 0U;
	  Voltage_Invalid_Counter = 0U;
	  Temp_Invalid_Counter = 0U;
	  Voltage_Struck_Counter = 0U;
	  Temp_Struck_Counter = 0U;
	  CAN_Timeout_Counter = 0U;
	  ContactorFeedbackCounter =0U;
}

uint8_t Fault_Manager_IsFaultActive(void)
{
    return (CurrentFault != FAULT_NONE);
}

uint8_t FAULT_MANAGER_IsInitialized(void)
{
	return FAULT_MANAGER_Initialized;
}
