/*
 * CAN_manager.c
 *
 *  Created on: 15-Jun-2026
 *      Author: ABI
 */

#include "fault_manager.h"
#include "soc_manager.h"
#include "soh_manager.h"
#include "can_manager.h"
#include "main.h"
#include "sensor_manager.h"
#include "bms_fsm.h"
extern CAN_HandleTypeDef hcan1;

static uint8_t CAN_Initialized = 0U;
static uint8_t CAN_MessageTransmitted = 0U;
static CAN_TxHeaderTypeDef TxHeader;
static uint32_t TxMailbox;
static uint8_t TxData[8];
void CAN_Manager_Init(void)
{
	TxHeader.StdId = 0x100;
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.DLC = 8;
	if(HAL_CAN_Start(&hcan1) == HAL_OK)
	{
	    CAN_Initialized = 1U;
	}

}
void CAN_Manager_SendBMSStatus(void)
{
	TxData[0] = SOC_Manager_GetSOC();
	TxData[1] = SOH_Manager_GetSOH();
	TxData[2] = BMS_FSM_GetState();
	TxData[3] = Fault_Manager_GetFault();
	TxData[4] = 0U;
	TxData[5] = 0U;
	TxData[6] = 0U;
	TxData[7] = 0U;



	    if(HAL_CAN_AddTxMessage(
	            &hcan1,
	            &TxHeader,
	            TxData,
	            &TxMailbox) == HAL_OK)
	    {
	        CAN_MessageTransmitted = 1U;
	    }
	    else
	    {
	        CAN_MessageTransmitted = 0U;
	    }


}


void CAN_Manager_Run(void)
{

	CAN_Manager_SendBMSStatus();
}

uint8_t CAN_IsInitialized(void)
{
	return CAN_Initialized;
}

uint8_t CAN_Manager_IsMessage_Transmitted(void)
{
	return CAN_MessageTransmitted;
}

