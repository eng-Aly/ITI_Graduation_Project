#include "../Drivers/MCAL/GPIO/GPIO_int.h"
#include "../Drivers/MCAL/GPIO/GPIO_int.h"
#include "../Drivers/MCAL/TIM_IC/TIM_IC_prv.h"
#include "../Drivers/MCAL/RCC/RCC_int.h"
#include "../Drivers/MCAL/TIM_IC/TIM_IC_int.h"
#include "../Drivers/MCAL/NVIC/NVIC_int.h"
#include "../Drivers/HAL/HC-SR04/HC-SR04_int.h"
#include "../Drivers/LIB/STD_TYPES.h"
#include "../Drivers/LIB/BIT_MATH.h"
#include "../Drivers/UART/UART_Int.h"

#define DELAY_MS(d)		do{unsigned int i = d*4000;while(i--){asm("NOP");} }while(0)


GPIOx_PinConfig_t LED1 =
	{GPIO_PORTA,
	GPIO_PIN3,
	.Mode = GPIO_MODE_OUTPUT ,
	.OutputType = GPIO_OUT_PUSHPULL,
	.Speed = GPIO_SPEED_HIGH,
	.PullType = GPIO_PULL_DOWN
	};

GPIOx_PinConfig_t LED3 =
	{GPIO_PORTB,
	GPIO_PIN0,
	.Mode = GPIO_MODE_OUTPUT ,
	.OutputType = GPIO_OUT_PUSHPULL,
	.Speed = GPIO_SPEED_HIGH,
	.PullType = GPIO_PULL_DOWN
	};

GPIOx_PinConfig_t LED4 =
	{GPIO_PORTB,
	GPIO_PIN1,
	.Mode = GPIO_MODE_OUTPUT ,
	.OutputType = GPIO_OUT_PUSHPULL,
	.Speed = GPIO_SPEED_HIGH,
	.PullType = GPIO_PULL_DOWN
	};    

GPIOx_PinConfig_t LED5 =
		{GPIO_PORTB,
		GPIO_PIN7,
		.Mode = GPIO_MODE_OUTPUT ,
		.OutputType = GPIO_OUT_PUSHPULL,
		.Speed = GPIO_SPEED_HIGH,
		.PullType = GPIO_PULL_DOWN
		};

HCSR04_Handle_t us1 = {
	.TriggerPort = GPIO_PORTA, .TriggerPin = GPIO_PIN1,
	.EchoPort    = GPIO_PORTA, .EchoPin    = GPIO_PIN0,
	.EchoAF      = GPIO_AF1,
	.TimerId     = TIM_ID_2, .Channel    = TIM_CHANNEL1
};


#define DIFF_UART     USART1

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