#include <stdint.h>
#include "MPU6050.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_i2c.h"

#define MPU_Timeout 200

	int16_t ACCEL_X;
	int16_t ACCEL_Y;
	int16_t ACCEL_Z;
	int16_t GYRO_X;
	int16_t GYRO_Y;
	int16_t GYRO_Z;
	int16_t TEMP;

HAL_StatusTypeDef MPU6050_Read(uint8_t Address, uint8_t length, uint8_t *Data){
	return HAL_I2C_Mem_Read(&I2C_HANDLE, MPU6050_ADDR_READ, Address, I2C_MEMADD_SIZE_8BIT, Data, length, MPU_Timeout);

}
HAL_StatusTypeDef MPU6050_Write(uint8_t Address, uint8_t length, uint8_t Data){
	return HAL_I2C_Mem_Write(&I2C_HANDLE, MPU6050_ADDR_WRITE, Address, I2C_MEMADD_SIZE_8BIT, &Data, length, MPU_Timeout);

}

uint8_t MPU6050_Init(void){
	if( HAL_I2C_IsDeviceReady(&I2C_HANDLE, MPU6050_ADDR, 1, MPU_Timeout) == HAL_OK){
		MPU6050_Write(PWR_MCMT_1, 1, 0X00);
		MPU6050_Write(SMPLRT_DIV, 1, 0X00);
		MPU6050_Write(GYRO_CONFIG, 1, 0X00);
		MPU6050_Write(ACCEL_CONFIG, 1, 0x00);
		MPU6050_Write(CONFIG, 1, 0x00);
		return 1;
	}
	return 0;
}
void MPU6050_Read_GYRO(void){
	uint8_t Buf[6];
	MPU6050_Read(GYRO_XOUT_H, 6, Buf);
	GYRO_X = (Buf[0]<<8)|Buf[1];
	GYRO_Y = (Buf[2]<<8)|Buf[3];
	GYRO_Z = (Buf[4]<<8)|Buf[5];
}
void MPU6050_Read_ACCEL(void){
	uint8_t Buf[6];
	MPU6050_Read(ACCEL_XOUT_H, 6, Buf);
	ACCEL_X = (Buf[0]<<8)|Buf[1];
	ACCEL_Y = (Buf[2]<<8)|Buf[3];
	ACCEL_Z = (Buf[4]<<8)|Buf[5];
}
void MPU6050_Read_TEMP(void){
	uint8_t Buf[2];
	MPU6050_Read(TEMP_OUT_H, 2, Buf);
	TEMP = (Buf[0]<<8)|Buf[1];
}
