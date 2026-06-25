/*
 * adc_driver.c
 *
 *  Created on: 15-Jun-2026
 *      Author: ABI
 */
#include "adc_driver.h"
static uint8_t ADC_Initialized = 0U;
void ADC_Init(void)
{
	ADC_Initialized = 1U;
}

uint16_t ADC_ReadVoltage(void)
{
	return 3000U;
}

uint16_t ADC_ReadTemperature(void)
{
	return 30U;
}

uint8_t ADC_IsInitialized(void)
{
	return ADC_Initialized;
}

