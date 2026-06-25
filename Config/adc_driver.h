/*
 * adc_driver.h
 *
 *  Created on: 15-Jun-2026
 *      Author: ABI
 */

#ifndef BMS_DRIVERS_ADC_DRIVER_H_
#define BMS_DRIVERS_ADC_DRIVER_H_
#include <stdint.h>
void ADC_Init(void);
uint16_t ADC_ReadVoltage(void);
uint16_t ADC_ReadTemperature(void);
uint8_t ADC_IsInitialized(void);

#endif /* BMS_DRIVERS_ADC_DRIVER_H_ */
