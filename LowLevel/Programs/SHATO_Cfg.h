#ifndef SHATO_CFG_H
#define SHATO_CFG_H

#include "../Drivers/MCAL/GPIO/GPIO_Int.h"
#include "../Drivers/HAL/L289/L289_Int.h"
#include "../Drivers/MCAL/TIM_OC/TIM_OC_Int.h"
#include "../Drivers/HAL/Encoder/Encoder_Int.h"
#include "../Drivers/MCAL/UART/UART_Int.h"
///*
//GPIO_PinConfig_t PA0 = {
//    .GPIO_PinNumber = 0,      / Pin 0 /
//    .GPIO_MODE = GPIO_MODE_OP,      /* Output mode */
//    .GPIO_AFx = GPIO_SPEED_HIGH,              /* No alternate function */
//    .GPIO_TYPE = GPIO_TYPE_PP,    /* Push-pull type */
//    .GPIO_PU_PD = GPIO_NO_PULL,        /* No pull-up/pull-down */
//    .GPIO_Output_Speed = GPIO_SPEED_HIGH, /* High speed */
//    .GPIOx = GPIOA
//};*/ */


// MOTORS
GPIO_PinConfig_t M1_DIR1 = {
    .GPIO_PinNumber = 12,      
    .GPIO_MODE = GPIO_MODE_OP,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M1_DIR2 = {
    .GPIO_PinNumber = 13,      
    .GPIO_MODE = GPIO_MODE_OP,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M1_EN = {
    .GPIO_PinNumber = 15,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};


GPIO_PinConfig_t M2_DIR1 = {
    .GPIO_PinNumber = 14, 
    .GPIO_MODE = GPIO_MODE_OP,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M2_DIR2 = {
    .GPIO_PinNumber = 15,      
    .GPIO_MODE = GPIO_MODE_OP,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M2_EN={
    .GPIO_PinNumber = 3,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};



GPIO_PinConfig_t M3_DIR1 = {
    .GPIO_PinNumber = 0,      
    .GPIO_MODE = GPIO_MODE_OP,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};

GPIO_PinConfig_t M3_DIR2 = {
    .GPIO_PinNumber = 1,      
    .GPIO_MODE = GPIO_MODE_OP,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M3_EN={
    .GPIO_PinNumber = 2,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};




GPIO_PinConfig_t M4_DIR1 = {
    .GPIO_PinNumber = 2,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M4_DIR2 = {
    .GPIO_PinNumber = 10,      
    .GPIO_MODE = GPIO_MODE_OP,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M4_EN={
    .GPIO_PinNumber = 3,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};


Timer_Config_t              M1_EN_TIMER_Cfg;
Timer_Config_t              M2_EN_TIMER_Cfg;
Timer_Config_t              M3_EN_TIMER_Cfg;
Timer_Config_t              M4_EN_TIMER_Cfg;

Timer_OutputCompare_Config_t M1_EN_TIMER_OC_Cfg;
Timer_OutputCompare_Config_t M2_EN_TIMER_OC_Cfg;
Timer_OutputCompare_Config_t M3_EN_TIMER_OC_Cfg;
Timer_OutputCompare_Config_t M4_EN_TIMER_OC_Cfg;

#define M1_EN_TIMER       TIMER2
#define M1_EN_CHANNEL     TIMER_Channel_2

#define M2_EN_TIMER       TIMER2
#define M2_EN_CHANNEL     TIMER_Channel_1

#define M3_EN_TIMER       TIMER2
#define M3_EN_CHANNEL     TIMER_Channel_4

#define M4_EN_TIMER       TIMER2
#define M4_EN_CHANNEL     TIMER_Channel_3



// ENCODERS
GPIO_PinConfig_t M1_ENC1={
    .GPIO_PinNumber = 8,
    .GPIO_AFx=GPIO_AF1,     
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};

GPIO_PinConfig_t M1_ENC2={
    .GPIO_PinNumber = 9,
    .GPIO_AFx=GPIO_AF1,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};

GPIO_PinConfig_t M2_ENC1={
    .GPIO_PinNumber = 6,
    .GPIO_AFx=GPIO_AF2,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};

GPIO_PinConfig_t M2_ENC2={
    .GPIO_PinNumber = 7,
    .GPIO_AFx=GPIO_AF2,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};

GPIO_PinConfig_t M3_ENC1={
    .GPIO_PinNumber = 6,
    .GPIO_AFx=GPIO_AF2,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};

GPIO_PinConfig_t M3_ENC2={
    .GPIO_PinNumber = 7,
    .GPIO_AFx=GPIO_AF2,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};

GPIO_PinConfig_t M4_ENC1={
    .GPIO_PinNumber = 0,
    .GPIO_AFx=GPIO_AF2,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};

GPIO_PinConfig_t M4_ENC2={
    .GPIO_PinNumber = 1,
    .GPIO_AFx=GPIO_AF2,      
    .GPIO_MODE = GPIO_MODE_AF,
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};

#define ENC1_TIMER             TIMER1
#define ENC2_TIMER             TIMER3
#define ENC3_TIMER             TIMER4
#define ENC4_TIMER             TIMER5


//UART
#define DIFF_UART     USART1

//GPIO_PinConfig_t DIFF_UART_TX={
//    .GPIO_PinNumber=9,
//    .GPIO_AFx=GPIO_AF7,
//    .GPIO_MODE=GPIO_MODE_AF,
//    .GPIO_TYPE=GPIO_TYPE_PP,
//    .GPIO_PU_PD=GPIO_NO_PULL,
//    .GPIO_Output_Speed=GPIO_SPEED_HIGH,
//    .GPIOx=GPIOA
//};
//
//GPIO_PinConfig_t DIFF_UART_RX={
//    .GPIO_PinNumber=10,
//    .GPIO_AFx=GPIO_AF7,
//    .GPIO_MODE=GPIO_MODE_AF,
//    .GPIO_TYPE=GPIO_TYPE_PP,
//    .GPIO_PU_PD=GPIO_NO_PULL,
//    .GPIO_Output_Speed=GPIO_SPEED_HIGH,
//    .GPIOx=GPIOA
//};

USART_PinConfig_t DIFF_UART_TX_Cfg={
    .USART_Mode= UART_MODE_TX_RX,
    .USART_BaudRate=9600,
    .USART_IRQ_Enable=UART_IRQ_ENABLE_RXNEIE,
    .USART_StopBits=UART_StopBits_1Bit,
    .USART_Sampling=UART_Sampling_16,
    .USART_HW_FlowCTRL=UART_HW_FLW_CTRL_RTS_DIS,
    .USART_ParityMode=UART_Parity_DIS,
    .USART_PayLoad_Lenght=UART_PayLoad_Length_8Bits,
    .P_IRQ_CallBack=NULL
};
 

/*
typedef struct {
	u8 USART_Mode;				// Specifies TX/RX Enable/Disable
								// This parameter must be set base on @ref UART_MODE_define
	u8 USART_PayLoad_Lenght;	// Specifies Number of data bits transmitted or received in data frame
							 	// This parameter must be set base on @ref UART_PayLoad_Length_define
	u8 USART_ParityMode;		// Specifies parity mode
								// This parameter must be set base on @ref UART_Parity_define
	u8 USART_StopBits;			// Specifies the number of stop bits transmitted
								// This parameter must be set base on @ref UART_StopBits_define
	u32 USART_BaudRate;		// This member configures UART communication baudrate
								// This parameter must be set base on @ref UART_BAUDRATE_define
	u8 USART_Sampling;			// This member configures UART Sampling Mode
								// This parameter must be set base on @ref UART_Sampling_define
	u8 USART_HW_FlowCTRL;		// Specifies whether hardware flow control enabled or disabled
						  	    // This parameter must be set base on @ref UART_HW_FLW_CTRL_define
	u8 USART_IRQ_Enable;		// Specifies whether IRQ of USART is Enabled or Disabled
							 	 	// This parameter must be set base on @ref UART_IRQ_ENABLE_define

	void (*P_IRQ_CallBack)(S_USART_IRQ_SRC irq_src);	// Set the C function which will be call when interrupt happens
}USART_PinConfig_t;
*/


void Clock_Init(void){
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_SYSCFG_CLK_EN();
    RCC_TIMER2_CLK_EN();
}

Timer_Config_t TimerCfgTemp;
Timer_OutputCompare_Config_t TimerOcCfgTemp;





#endif
