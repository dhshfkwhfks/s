#ifndef __MPU6050_H
#define __MPU6050_H

#include "main.h"
#include "i2c.h"

#define I2C_HANDLE hi2c1
#define MPU6050_Data MPU6050_SensorData_Structer

#define SMPLRT_DIV 0x19
#define CONFIG 0x1A
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C

#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40

#define TEMP_OUT_H 0x41
#define TEMP_OUT_L 0x42

#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48

#define PWR_MCMT_1 0x6B
#define PWR_MCMT_2 0x6C
#define WHO_AM_I   0x75
#define MPU6050_ADDR 0x68
#define MPU6050_ADDR_WRITE 0xD0
#define MPU6050_ADDR_READ  0xD1

HAL_StatusTypeDef MPU6050_Read(uint8_t Address, uint8_t length, uint8_t *Data);
HAL_StatusTypeDef MPU6050_Write(uint8_t Address, uint8_t length, uint8_t Data);
uint8_t MPU6050_Init(void);
void MPU6050_Read_ACCEL(void);
void MPU6050_Read_GYRO(void);
void MPU6050_Read_TEMP(void);


#endif
