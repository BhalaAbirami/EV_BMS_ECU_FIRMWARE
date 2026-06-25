/*
 * bms_fsm.c
 *
 *  Created on: 27-May-2026
 *      Author: ABI
 */
#include "bootstrap.h"
#include "contactor_manager.h"
#include "fault_manager.h"
#include "precharge_manager.h"
#include "bms_fsm.h"
#include "sensor_manager.h"
static BMS_State_t CurrentState;


void BMS_FSM_Init(void)
{

	CurrentState=BMS_INIT;

}
void BMS_FSM_Run(void)
{
	if(Fault_Manager_GetFault() != FAULT_NONE)
	{
	    CurrentState = BMS_FAULT;
	}
	if(Sensor_Manager_IsShutdownRequested() == 1U)
	{
	    CurrentState = BMS_SHUTDOWN;
	}

	switch(CurrentState)
	{
	case BMS_INIT:


			if(Bootstrap_IsComplete() == 1U)
			{
				CurrentState=BMS_IDLE;
			}
		break;

	case BMS_IDLE:
		if(Sensor_Manager_IsShutdownRequested() == 1U)
		{
		    CurrentState = BMS_SHUTDOWN;
		}

		else if(Sensor_Manager_IsChargerConnected() == 1U)
		{
			CurrentState = BMS_PRECHARGING;
		}
		else if (Sensor_Manager_IsLoadConnected() == 1U)
		{
			CurrentState = BMS_DISCHARGING;
		}

		break;

	case BMS_PRECHARGING:
		 Precharge_Manager_Run();

		if(Precharge_Manager_IsComplete() == 1U)
		{
			CurrentState = BMS_CHARGING;
		}

		break;

	case BMS_CHARGING:
		Contactor_Manager_CloseCharge();

		if(Sensor_Manager_IsChargerConnected() == 0U)
			{
		        Contactor_Manager_OpenCharge();

				CurrentState = BMS_IDLE;
			}

		break;

	case BMS_DISCHARGING:
		Contactor_Manager_CloseDischarge();
		if(Sensor_Manager_IsLoadConnected() == 0U)
		{
	        Contactor_Manager_OpenDischarge();

			CurrentState = BMS_IDLE;
		}

		break;

	case BMS_FAULT:
		Contactor_Manager_OpenCharge();
		Contactor_Manager_OpenDischarge();

	    if(Fault_Manager_IsFaultActive() == 0U)
	    {
	        Fault_Manager_ClearFault();
	        CurrentState = BMS_IDLE;
	    }

		break;

	case BMS_SHUTDOWN:

	    Contactor_Manager_OpenCharge();
	    Contactor_Manager_OpenDischarge();
		break;

	default:

		CurrentState=BMS_FAULT;
		break;
	}
}

BMS_State_t BMS_FSM_GetState(void)
{
    return CurrentState;
}


