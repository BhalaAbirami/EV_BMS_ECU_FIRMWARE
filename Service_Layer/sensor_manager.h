/*
 * sensor_manager.h
 *
 *  Created on: 01-Jun-2026
 *      Author: ABI
 */

#ifndef SERVICES_SENSOR_MANAGER_H_
#define SERVICES_SENSOR_MANAGER_H_

#include <stdint.h>
void Sensor_Manager_Init(void);
void Sensor_Manager_Run(void);
uint8_t Sensor_Manager_IsChargerConnected(void);
uint8_t Sensor_Manager_IsLoadConnected(void);
uint8_t Sensor_Manager_IsVoltageSensor_Struck(void);
uint8_t Sensor_Manager_IsTempSensor_Struck(void);
uint8_t Sensor_Manager_IsShutdownRequested(void);
uint8_t SENSOR_MANAGER_IsInitialized(void);

typedef struct
{
    uint16_t CellVoltage_mV;
    uint16_t CellTemp_C;
} SensorData_t;
SensorData_t SensorManager_GetSensorData(void);


#endif /* SERVICES_SENSOR_MANAGER_H_ */
