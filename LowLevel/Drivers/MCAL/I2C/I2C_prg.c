
#include "I2C_int.h"
#include "I2C_prv.h"


I2C_InitTypeDef I2C_CNFG[3] = {NULL, NULL, NULL};

#define I2C1_Index          0
#define I2C2_Index          1
#define I2C3_Index          2


void MCAL_I2C_Init(I2C_MemMap_t* I2Cx, I2C_InitTypeDef* I2C_InitStruct){
    u16 tmpReg =0, freqRange = 0;
    u32 pclk1 = 25000000;
    u16 result = 0;
    // Enable RCC Clock
    if(I2Cx == I2C1){
        I2C_CNFG[I2C1_Index] = *I2C_InitStruct;
        RCC_I2C1_CLK_EN();
    }
    else if (I2Cx == I2C2)
    {
        I2C_CNFG[I2C2_Index] = *I2C_InitStruct;
        RCC_I2C2_CLK_EN();
    }
    else
    {
        I2C_CNFG[I2C3_Index] = *I2C_InitStruct;
        RCC_I2C3_CLK_EN();
    }

    if(I2C_InitStruct->I2C_Mode == I2C_MODE_I2C){
        // Initialize timimg
        tmpReg = I2Cx->CR2;
        // clear freq[5:0] bits
        tmpReg &= ~(0x3FU<<0);
        // set freq
        freqRange = (u16)(pclk1 / 1000000);
        tmpReg |= freqRange;
        I2Cx->CR2 = tmpReg;
        // configure CCR
        // Disable I2C PE 
        CLR_BIT(I2Cx->CR1, 0);
        tmpReg =0;
        // config SM
        result = (u16)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed << 1));
        tmpReg |= result;
        I2Cx->CCR = tmpReg;

        // time rise config
        I2Cx->TRISE = freqRange + 1;
    }
    // CR1 configure
    tmpReg = I2Cx->CR1;
    tmpReg |= (u16)(I2C_InitStruct->I2C_ACk | I2C_InitStruct->General_Call_Add_Detection | I2C_InitStruct->I2C_Mode | I2C_InitStruct->strechMode);
    I2Cx->CR1 = tmpReg;

    // configure OAR1 & OAR2
    tmpReg = 0;
    if(I2C_InitStruct->Slave_Addr.EN_Dual_Addr == 1){
        tmpReg = I2C_OAR2_ENDUAL;
        tmpReg |= I2C_InitStruct->Slave_Addr.Secondary_Slave_Addr << 1U; 
    }
    tmpReg = 0;
    tmpReg |= I2C_InitStruct->Slave_Addr.Primary_Slave_Addr << 1U; 
    tmpReg |= I2C_InitStruct->Slave_Addr.Addr_Slave_Mode;
    I2Cx->OAR1 = tmpReg; 

    // Interrupt Mode (Slave mode)


    // enable i2c peripheral
    SET_BIT(I2Cx->CR1, 0); 
}
// void MCAL_I2C_DInit(I2C_MemMap_t* I2Cx){

// }

void MCAL_I2C_GPIO_Set_Pins(I2C_MemMap_t* I2Cx){
    if(I2Cx == I2C1)
    {
        GPIOx_PinConfig_t SCL = {
			.Port = GPIO_PORTB,
			.Pin = GPIO_PIN6,
			.Mode = GPIO_MODE_ALF
	    };
	    MGPIO_vPinInit(&SCL);
    
        GPIOx_PinConfig_t SDA = {
			.Port = GPIO_PORTB,
			.Pin = GPIO_PIN7,
			.Mode = GPIO_MODE_ALF
	    };
	    MGPIO_vPinInit(&SDA);
    }
    else if (I2Cx == I2C2)
    {
        GPIOx_PinConfig_t SCL = {
			.Port = GPIO_PORTB,
			.Pin = GPIO_PIN10,
			.Mode = GPIO_MODE_ALF
	    };
	    MGPIO_vPinInit(&SCL);
    
        GPIOx_PinConfig_t SDA = {
			.Port = GPIO_PORTB,
			.Pin = GPIO_PIN11,
			.Mode = GPIO_MODE_ALF
	    };
	    MGPIO_vPinInit(&SDA);
    }
    else
    {
        GPIOx_PinConfig_t SCL = {
			.Port = GPIO_PORTA,
			.Pin = GPIO_PIN8,
			.Mode = GPIO_MODE_ALF
	    };
	    MGPIO_vPinInit(&SCL);
    
        GPIOx_PinConfig_t SDA = {
			.Port = GPIO_PORTC,
			.Pin = GPIO_PIN9,
			.Mode = GPIO_MODE_ALF
	    };
	    MGPIO_vPinInit(&SDA);
    }
}

void MCAL_I2C_MASTER_TX(I2C_MemMap_t* I2Cx, u16 devAddr, u8* dataOut, u32 dataLen, Stop_Condition stop, RepeatedStart start)
{
    s32 i =0;
    // 1- Set start bit to generate start condition
    I2C_GenerateStart(I2Cx, Enable, start);

    // 2- wait for EV5
    while (!I2C_Get_Flag_Status(I2Cx, EV5));

    // 3- send address
    // write to DR register the address and the r/w bit
    I2C_SendAddress(I2Cx, devAddr, readWrite_transmitter);

    // 4- wait for address phase to be completed (EV6)
    // wait until ADDR is set in SR1
    while (!I2C_Get_Flag_Status(I2Cx, EV6));

    // 5- Busy / MSL / TRA / TXE flags set
    while (!I2C_Get_Flag_Status(I2Cx, MASTER_BYTR_TRANSMITTING));

    // 6- send data
    for(i=0; i<dataLen; i++){
        // write data to DR register
        I2Cx->DR = dataOut[i];
        // wait EV8
        while (!I2C_Get_Flag_Status(I2Cx, EV8));
    }
    // 7- wait until BTF is set (EV8_2)
    // while (!I2C_Get_Flag_Status(I2Cx, EV8_2));

    // 8- generate stop condition
    if(stop == withStop){
        I2C_GenerateStop(I2Cx, Enable);
    }
}

void MCAL_I2C_MASTER_RX(I2C_MemMap_t* I2Cx, u16 devAddr, u8* dataOut, u32 dataLen, Stop_Condition stop, RepeatedStart start)
{
    s32 i =0;
    u8 index =0;
    if(I2Cx == I2C1)
        index = I2C1_Index;
    else if (I2Cx == I2C2)
        index = I2C2_Index;
    else
        index = I2C3_Index;
    
    // 1- Set start bit to generate start condition
    I2C_GenerateStart(I2Cx, Enable, start);

    // 2- wait for EV5
    while (!I2C_Get_Flag_Status(I2Cx, EV5));

    // 3- send address
    // write to DR register the address and the r/w bit
    I2C_SendAddress(I2Cx, devAddr, readWrite_reciever);

    // 4- wait for address phase to be completed (EV6)
    // wait until ADDR is set in SR1
    while (!I2C_Get_Flag_Status(I2Cx, EV6));

    // 5- read data
    // enable ACK
    SET_BIT(I2Cx->CR1, I2C_ACK_ENABLE);

    if(dataLen)
    {
        // read data in loop
        for(i=dataLen; i>1; i--){
            // wait EV7
            while (!I2C_Get_Flag_Status(I2Cx, EV7));
            // read data from DR register
            *dataOut = I2Cx->DR;
            dataOut++; // point to next byte
        }
        // disable ACK
        CLR_BIT(I2Cx->CR1, I2C_ACK_ENABLE);
    }

    //6- generate stop condition
    if(stop == withStop){
        I2C_GenerateStop(I2Cx, Enable);
    }

    //7- re-enable ACK
    if(I2C_CNFG[index].I2C_ACk == I2C_ACK_Enable)
    {
        SET_BIT(I2Cx->CR1, I2C_ACK_ENABLE);
    }
    
}

void I2C_GenerateStart(I2C_MemMap_t* I2Cx, FunctionalState NewState, RepeatedStart start){
    if(start != repeatedStart){
        // check the bus is ideal
        while (I2C_Get_Flag_Status(I2Cx, I2C_FLAG_BUSY));        
    }
    if (NewState != Disable){
        I2Cx->CR1 |= I2C_CR1_Start;
    }
    else{
        I2Cx->CR1 &= ~(I2C_CR1_Start);
    }
}

void I2C_GenerateStop(I2C_MemMap_t* I2Cx, FunctionalState NewState){
    if (NewState != Disable){
        I2Cx->CR1 |= I2C_CR1_Stop;
    }
    else{
        I2Cx->CR1 &= ~(I2C_CR1_Stop);
    }
}

void I2C_SendAddress(I2C_MemMap_t* I2Cx, u16 devAddr, readWrite_direction readWrite){
    u8 address = (u8)(devAddr << 1);
    if (readWrite != readWrite_transmitter){
        // Set bit0 for read
        address |= 1<<0;
    }
    else{
        // Reset bit0 for write
        address &= ~(1<<0);

    }
    // send address
    I2Cx->DR = address;

}

Flag_Status I2C_Get_Flag_Status(I2C_MemMap_t* I2Cx, Status flag)
{
    volatile u32 DRead;
    Flag_Status BitStatus = RESET;
    u32 flag1 =0, flag2 =0, resultEvent =0;
    switch (flag)
    {
    case I2C_FLAG_BUSY:
        if((I2Cx->SR2) & (I2C_SR2_BUSY))
            BitStatus = SET;
        else
            BitStatus = RESET;
        break;
    
    case EV5:
        if((I2Cx->SR1) & I2C_SR1_SB)
            BitStatus = SET;
        else
            BitStatus = RESET;
        break;
    
    case EV6:
        DRead = I2Cx->SR1;
        if((DRead) & I2C_SR1_ADDR)
        BitStatus = SET;
        else
        BitStatus = RESET;

        // clear ADDR flag by reading SR1 followed by reading SR2
        DRead = I2Cx->SR2;
        break;

    case MASTER_BYTR_TRANSMITTING:
        flag1 = I2Cx->SR1;
        flag2 = I2Cx->SR2;
        flag2 = flag2 << 16U;
        resultEvent = (flag1 | flag2) & ((u32)0x00FFFFFF);

        // check on TRA, MSL, BUSY and TXE
        if((resultEvent & flag)== flag)
            BitStatus = SET;
        else
            BitStatus = RESET;
        break;

    case EV8_1:
    case EV8:
        if((I2Cx->SR1) & (I2C_SR1_TXE))
            BitStatus = SET;
        else
            BitStatus = RESET;
        break;

    case EV7:
        if((I2Cx->SR1) & (I2C_SR1_RXNE))
            BitStatus = SET;
        else
            BitStatus = RESET;
        break;

    default:
        break;
    }

    return BitStatus;
}
