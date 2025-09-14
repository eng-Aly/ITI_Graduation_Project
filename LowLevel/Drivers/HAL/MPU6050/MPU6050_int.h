/*
 * MPU6050_int.h
 *
 *  Created on: Sep 11, 2025
 *      Author: Mo'men
 */

#ifndef HAL_MPU6050_MPU6050_INT_H_
#define HAL_MPU6050_MPU6050_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "math.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"
#include "../../MCAL/I2C/I2C_int.h"

#define MPU6050_BASE_ADRR		0x68

#define SMPLRT_DIV_REG			0x1A
#define GYRO_CNF_REG			0x1B
#define ACC_CNF_REG		    	0x1C
#define ACC_XOUT_H_REG			0x3B
#define GYRO_XOUT_H_REG			0x43
#define TEMP_OUT_H_REG			0x41
#define PWR_MGMT_1_REG			0x6B
#define WHO_AM_I_REG			0x75


void MPU6050_vInit(void);
void MPU6050_vWrite(u8 reg_addr, u8 *data, u8 dataLength);
void MPU6050_vRead(u8 reg_addr, u8 *data, u8 dataLength);

f32 readACC(void);
f32 readACC(void);
f32 readings(void);

#endif /* HAL_MPU6050_MPU6050_INT_H_ */
