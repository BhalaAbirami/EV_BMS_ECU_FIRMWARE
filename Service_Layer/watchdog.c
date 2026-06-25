/*
 * watchdog.c
 *
 *  Created on: 09-Jun-2026
 *      Author: ABI
 */
#include "watchdog.h"
#include "main.h"

extern IWDG_HandleTypeDef hiwdg;
void Watchdog_Kick(void)
{
	HAL_IWDG_Refresh(&hiwdg);
}
