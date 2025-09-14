
#include "../../LIB/STD_TYPES.h"
#include "I2C_prv.h"

typedef struct
{
	u16 EN_Dual_Addr;
	u16 Primary_Slave_Addr;
	u16 Secondary_Slave_Addr;
	u32 Addr_Slave_Mode;   			 // @ref I2C_AddrSlaveMode_define
}I2C_Slave_Device_ADDR;

typedef enum{
	I2C_EV_Data_Req,
	I2C_EV_Data_Rcv

}Slave_State;

typedef enum
{
	I2C_FLAG_BUSY =0,
	EV5,						// SB=1, cleared by reading SR1 register followed by writing DR register with Address
	EV6,						// ADDR=1, cleared by reading SR1 register followed by reading SR2.	
	EV7,						// RxNE=1, cleared by reading DR register
	EV8,						// TxE=1, shift register not empty, data register empty, cleared by writing DR register
	EV8_1,						// BTF=1, Data register empty,
	MASTER_BYTR_TRANSMITTING = ((u32)0x00070008) 	// check on TRA, MSL, BUSY and TXE

}Status;

typedef struct
{
	u32 I2C_ClockSpeed;     			// Specifies the clock frequency.
	                        			// This parameter must be set to a value @ref I2C_SCLK_define lower than 400kHz
	u32 strechMode;      				// Specifies the I2C mode.
	                        			// This parameter can be a value of @ref I2C_stretchMode_define
	u32 I2C_Mode;						// Specifies the I2C mode.
	                        			// This parameter can be a value of @ref I2C_Mode_define
	I2C_Slave_Device_ADDR Slave_Addr;	// Specifies the I2C slave address
										
	u32 I2C_ACk;						// Specifies the I2C acknowledge
										// This parameter can be a value of @ref I2C_ACK_define
	u32 General_Call_Add_Detection;		// Specifies the I2C General Call Address
										// This parameter can be a value of @ref I2C_general_call_addr_define
	void(* P_slave_Event_CallBack)(Slave_State state); 
}I2C_InitTypeDef;



typedef enum{
	RESET = 0,
	SET = 1
}Flag_Status;

typedef enum{
	withStop,
	withoutStop
}Stop_Condition;

typedef enum {
	start, 
	repeatedStart
}RepeatedStart;

typedef enum{
	Disable = 0,
	Enable = 1
}FunctionalState;

typedef enum{
	readWrite_transmitter = 0,
	readWrite_reciever = 1
}readWrite_direction;

void MCAL_I2C_Init(I2C_MemMap_t* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
// void MCAL_I2C_DInit(I2C_MemMap_t* I2Cx);

void MCAL_I2C_GPIO_Set_Pins(I2C_MemMap_t* I2Cx);

void MCAL_I2C_MASTER_TX(I2C_MemMap_t* I2Cx, u16 devAddr, u8* dataOut, u32 dataLen, Stop_Condition stop, RepeatedStart start);
void MCAL_I2C_MASTER_RX(I2C_MemMap_t* I2Cx, u16 devAddr, u8* dataOut, u32 dataLen, Stop_Condition stop, RepeatedStart start);

void I2C_GenerateStart(I2C_MemMap_t* I2Cx, FunctionalState NewState, RepeatedStart start);
void I2C_GenerateStop(I2C_MemMap_t* I2Cx, FunctionalState NewState);
void I2C_SendAddress(I2C_MemMap_t* I2Cx, u16 devAddr, readWrite_direction readWrite);

Flag_Status I2C_Get_Flag_Status(I2C_MemMap_t* I2Cx, Status flag);