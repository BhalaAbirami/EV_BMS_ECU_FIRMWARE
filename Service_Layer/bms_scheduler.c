/*
 * bms_scheduler.c
 *
 *  Created on: 28-May-2026
 *      Author: ABI
 */
#include "bms_scheduler.h"
#include "fault_manager.h"
#include "precharge_manager.h"
#include "soc_manager.h"
#include "soh_manager.h"
#include "can_manager.h"
#include "bms_fsm.h"
#include "sensor_manager.h"
#include "watchdog.h"
#include "main.h"

static uint32_t PreviousTick_10ms = 0;
static uint32_t PreviousTick_100ms = 0;
static uint8_t BMS_SCHEDULER_Initialized = 0U;

void BMS_Scheduler_Init(void)
{
	BMS_SCHEDULER_Initialized = 1U;
}

void BMS_Scheduler_Run(void)
{
    uint32_t CurrentTick = HAL_GetTick();

    if((CurrentTick - PreviousTick_10ms) >= 10)
    {
        PreviousTick_10ms = CurrentTick;

        Task_10ms();
    }

    if((CurrentTick - PreviousTick_100ms) >= 100)
    {
        PreviousTick_100ms = CurrentTick;

        Task_100ms();
    }
}

void Task_10ms(void)
{
	Sensor_Manager_Run();
	Fault_Manager_Run();
    BMS_FSM_Run();
    Watchdog_Kick();

}

void Task_100ms(void)
{
	CAN_Manager_Run();
	SOC_Manager_Run();
	SOH_Manager_Run();
}

uint8_t BMS_SCHEDULER_IsInitialized(void)
{
	return BMS_SCHEDULER_Initialized;
}

