/*
 * MPU6050_prg.c
 *
 *  Created on: Sep 11, 2025
 *      Author: Mo'men
 */

#include "MPU6050_int.h"

void MPU6050_vInit(void){

	I2C_InitTypeDef I2C1_Config = {
		.I2C_ClockSpeed = SM_1KHZ,
		.strechMode = I2C_STRETCH_ENABLE,
		.I2C_Mode = I2C_MODE_I2C,
		.Slave_Addr = {
			.EN_Dual_Addr = 0,
			.Primary_Slave_Addr = 0,
			.Secondary_Slave_Addr = 0,
			.Addr_Slave_Mode = 0
		},
		.I2C_ACk = I2C_ACK_Enable,
		.General_Call_Add_Detection = 0,
		.P_slave_Event_CallBack = NULL
	};

	// i2c init --> from MCAL i2c driver
	MCAL_I2C_Init(I2C1, &I2C1_Config);

	u8 check[2]={0,0};
	u8 data=0;

	MPU6050_vRead(WHO_AM_I_REG, check, 1);
	// check if isn't work --> wait
	if(check[0] != 104){
		while(1);
	}
	// check if work correct --> init it
	if(check[0] == 104){
		// Set data rate by 1KHz --> write SMPLRT_DIV
		data = 0x05;
		MPU6050_vWrite(SMPLRT_DIV_REG, &data, 1);

		// Set accelerometer config
		data = 0x10;
		MPU6050_vWrite(ACC_CNF_REG, &data, 1);

		// Set gyroscope config
		data = 0x08;
		MPU6050_vWrite(GYRO_CNF_REG, &data, 1);

		// enable the module
		data = 0x00;
		MPU6050_vWrite(PWR_MGMT_1_REG, &data, 1);
	}
}

void MPU6050_vWrite(u8 reg_addr, u8 *data, u8 dataLength){
	u8 i=0;
	u8 buffer[3];
	buffer[0] = (u8)(reg_addr);

	for(i=1; i<(dataLength+1); i++){
		buffer[i] = data[i-1];
	}

	// i2c master send data --> implemented in i2c driver in MCAL
	// with stop
	MCAL_I2C_MASTER_TX(I2C1, MPU6050_BASE_ADRR, buffer, dataLength+1, withStop, start);

}

void MPU6050_vRead(u8 reg_addr, u8 *data, u8 dataLength){
	u8 buffer[2];
	buffer[0] = (u8)(reg_addr);

	// i2c master send data --> implemented in i2c driver in MCAL
	// without stop
	MCAL_I2C_MASTER_TX(I2C1, MPU6050_BASE_ADRR, buffer, 1, withoutStop, start);

	// i2c master recieve data --> implemented in i2c driver in MCAL
	// without stop
	MCAL_I2C_MASTER_RX(I2C1, MPU6050_BASE_ADRR, data, dataLength ,withStop, repeatedStart);
}

f32 readACC(void){
	u8 data1 = 0;
	u8 data[6];
	f32 acc_X = 0;
	f32 acc_Y = 0;
	f32 acc_Z = 0;


	// enable the module
	data1 = 0x00;
	MPU6050_vWrite(PWR_MGMT_1_REG, &data, 1);
	// Set data rate by 1KHz --> write SMPLRT_DIV
	data1 = 0x05;
	MPU6050_vWrite(SMPLRT_DIV_REG, &data, 1);

	// Set accelerometer config
	data1 = 0x10;
	MPU6050_vWrite(ACC_CNF_REG, &data, 1);

	// read acceleration
	MPU6050_vRead(ACC_XOUT_H_REG, data, 6);
	acc_X = (((s16)(data[0] << 8 | data[1])) / 4096.0);
	acc_Y = (((s16)(data[2] << 8 | data[3])) / 4096.0);
	acc_Z = (((s16)(data[4] << 8 | data[5])) / 4096.0);

	return acc_X, acc_Y, acc_Z ;
}

f32 readGyro(void){
	u8 data1 = 0;
	u8 data[6];

	s16 gyro_X = 0;
	s16 gyro_Y = 0;
	s16 gyro_Z = 0;

	f32 gyroX = 0;
	f32 gyroY = 0;
	f32 gyroZ = 0;

	// Set gyroscope config
	data1 = 0x08;
	MPU6050_vWrite(GYRO_CNF_REG, &data, 1);

	// read acceleration
	MPU6050_vRead(GYRO_XOUT_H_REG, data, 6);
	gyro_X = (((s16)(data[0] << 8 | data[1])) / 4096.0);
	gyro_Y = (((s16)(data[2] << 8 | data[3])) / 4096.0);
	gyro_Z = (((s16)(data[4] << 8 | data[5])) / 4096.0);

	gyroX = gyro_X/65.5 + 2.7;
	gyroY = gyro_Y/65.5 - 0.86;
	gyroZ = gyro_Z/65.5 + 0.4;

	return  gyroX, gyroY, gyroZ;
}

f32 readings(void){
	f32 acc_X, acc_Y, acc_Z;
	f32 accAngleX = 0;
	f32 accAngleY = 0;

	f32 gyroX, gyroY, gyroZ;
	f32 gyroAngleX = 0;
	f32 gyroAngleY = 0;
	f32 yaw = 0;

	f32 elapsedTime = 0;

	acc_X,acc_Y,acc_Z = readACC();

	accAngleX = (atan(acc_Y / sqrt(pow(acc_X, 2) + pow(acc_Z, 2))) * 180 / 3.14) - 0.58;
	accAngleY = (atan(-1 * acc_X / sqrt(pow(acc_Y, 2) + pow(acc_Z, 2))) * 180 / 3.14) + 1.58;

	gyroX, gyroY, gyroZ = readGyro();

	// or in main
	MSYSTICK_vStopTimer();
	elapsedTime = MSYSTICK_u32GetElapsedTime_SingleShot();
	elapsedTime/=1000000;

	gyroAngleX += gyroX * elapsedTime;
	gyroAngleY += gyroY * elapsedTime;
	yaw += gyroZ * elapsedTime;

	MSYSTICK_vStartTimer(0x00FFFFFF);

	return accAngleX, accAngleY, yaw;
}
