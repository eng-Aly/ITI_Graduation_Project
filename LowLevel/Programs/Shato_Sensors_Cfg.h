#include "../Drivers/MCAL/GPIO/GPIO_int.h"
#include "../Drivers/MCAL/GPIO/GPIO_int.h"
#include "../Drivers/MCAL/TIM_IC/TIM_IC_prv.h"
#include "../Drivers/MCAL/RCC/RCC_int.h"
#include "../Drivers/MCAL/TIM_IC/TIM_IC_int.h"
#include "../Drivers/MCAL/NVIC/NVIC_int.h"
#include "../Drivers/HAL/HC-SR04/HC-SR04_int.h"
#include "../Drivers/LIB/STD_TYPES.h"
#include "../Drivers/LIB/BIT_MATH.h"

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