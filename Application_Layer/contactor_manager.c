/*
 * contactor_manager.c
 *
 *  Created on: 20-Jun-2026
 *      Author: ABI
 */
#include "contactor_manager.h"

static uint8_t ChargeContactorClosed = 0U;
static uint8_t DischargeContactorClosed = 0U;

static uint8_t ChargeContactorFeedback = 0U;
static uint8_t DischargeContactorFeedback = 0U;
static uint8_t CONTACTOR_MANAGER_Initialized = 0U;


void Contactor_Manager_Init(void)
{
	CONTACTOR_MANAGER_Initialized = 1U;
    ChargeContactorClosed = 0U;
    DischargeContactorClosed = 0U;

    ChargeContactorFeedback = 0U;
    DischargeContactorFeedback = 0U;
}

void Contactor_Manager_CloseCharge(void)
{
    ChargeContactorClosed = 1U;
    ChargeContactorFeedback = 1U;
}

void Contactor_Manager_OpenCharge(void)
{
    ChargeContactorClosed = 0U;
    ChargeContactorFeedback = 0U;
}

void Contactor_Manager_CloseDischarge(void)
{

    DischargeContactorClosed = 1U;
    DischargeContactorFeedback = 1U;
}

void Contactor_Manager_OpenDischarge(void)
{
    DischargeContactorClosed = 0U;
    DischargeContactorFeedback = 0U;

}

uint8_t Contactor_Manager_IsChargeClosed(void)
{
    return ChargeContactorClosed;
}

uint8_t Contactor_Manager_IsDischargeClosed(void)
{
    return DischargeContactorClosed;
}

uint8_t Contactor_Manager_GetChargeFeedback(void)
{
    return ChargeContactorFeedback;
}

uint8_t Contactor_Manager_GetDischargeFeedback(void)
{
    return DischargeContactorFeedback;
}

uint8_t CONTACTOR_MANAGER_IsInitialized(void)
{
	return CONTACTOR_MANAGER_Initialized;
}
