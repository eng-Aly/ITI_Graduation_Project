#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/GPIO/GPIO_int.h"
#include "../MCAL/TIM_IC/TIM_IC_prv.h"
#include "../MCAL/RCC/RCC_int.h"
#include "../MCAL/TIM_IC/TIM_IC_int.h"
#include "../MCAL/NVIC/NVIC_int.h"
#include "../HAL/HC-SR04/HC-SR04_int.h"
#define DELAY_MS(d)		do{unsigned int i = d*4000;while(i--){asm("NOP");} }while(0)
void PrintDistance(u16 distance);
int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1,RCC_GPIOA);
	MRCC_vEnableClk(RCC_AHB1,RCC_GPIOB);
	MRCC_vEnableClk(RCC_APB1,RCC_EN_TIM2);
	MUSART_vInit();


	MNVIC_vEnable_Peripheral_INT(NVIC_IRQ_TIM2);

	GPIOx_PinConfig_t LED1 =
		{GPIO_PORTA,
		GPIO_PIN3,
		.Mode = GPIO_MODE_OUTPUT ,
		.OutputType = GPIO_OUT_PUSHPULL,
		.Speed = GPIO_SPEED_HIGH,
		.PullType = GPIO_PULL_DOWN
		};
	MGPIO_vPinInit(& LED1);


	GPIOx_PinConfig_t LED3 =
		{GPIO_PORTB,
		GPIO_PIN0,
		.Mode = GPIO_MODE_OUTPUT ,
		.OutputType = GPIO_OUT_PUSHPULL,
		.Speed = GPIO_SPEED_HIGH,
		.PullType = GPIO_PULL_DOWN
		};
	MGPIO_vPinInit(& LED3);
	GPIOx_PinConfig_t LED4 =
		{GPIO_PORTB,
		GPIO_PIN1,
		.Mode = GPIO_MODE_OUTPUT ,
		.OutputType = GPIO_OUT_PUSHPULL,
		.Speed = GPIO_SPEED_HIGH,
		.PullType = GPIO_PULL_DOWN
		};
	MGPIO_vPinInit(& LED4);

	GPIOx_PinConfig_t LED5 =
			{GPIO_PORTB,
			GPIO_PIN7,
			.Mode = GPIO_MODE_OUTPUT ,
			.OutputType = GPIO_OUT_PUSHPULL,
			.Speed = GPIO_SPEED_HIGH,
			.PullType = GPIO_PULL_DOWN
			};
		MGPIO_vPinInit(& LED5);



	HCSR04_Handle_t us1 = {
		.TriggerPort = GPIO_PORTA, .TriggerPin = GPIO_PIN1,
		.EchoPort    = GPIO_PORTA, .EchoPin    = GPIO_PIN0,
		.EchoAF      = GPIO_AF1,
		.TimerId     = TIM_ID_2, .Channel    = TIM_CHANNEL1
	};

	HCSR04_vInit(&us1);
//	CLR_BIT(TIM2->SR,TIM_SR_CC1OF);
//	MSYSTICK_vSetDelay_us(100);

//	HCSR04_vTrigger(&us1);
//
//	volatile TIMx_MemMap_t *TIMx = TIM2;
//
//
//	while(us1.isReady == 0);
//	volatile u16 d1 = HCSR04_u16GetDistance(&us1);
//
//	volatile HCSR04_Handle_t usX = us1;
//	HCSR04_vTrigger(&us1);
//
//
////
//	if (GET_BIT(TIM2->SR,TIM_SR_CC1OF)){
//		MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
//	}
	HCSR04_vTrigger(&us1);


//
//	if (GET_BIT(TIM2->SR,TIM_SR_CC1OF)){
//		MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
//	}
//	MSYSTICK_vSetDelay_ms(100);

	while (1)
	{

//		HCSR04_vTrigger(&us1);
		MTIM_vIC_EnableInterrupt(TIM_ID_2, TIM_CHANNEL1);
		MTIM_vIC_EnableCapture(TIM_ID_2, TIM_CHANNEL1);
		volatile u32 x = TIM2->CNT;
		if(GET_BIT(TIM2->SR,TIM_SR_CC1OF))
				{
					MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
				}
		while(us1.isReady == 0);
		volatile u16 distance = us1.distance_cm;
		if(distance >100){
			MGPIO_TogPinValue(GPIO_PORTB,GPIO_PIN7);
		}
		if(GET_BIT(TIM2->SR,TIM_SR_CC1OF))
		{
			MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
		}
		x = TIM2->CNT;

		DELAY_MS(100);
	}
	return 0 ;
}

void PrintDistance(u16 distance) {
    MUSART_vSendString("Distance: ");
    MUSART_vSendNumber(distance);
    MUSART_vSendString(" cm\r\n");
}

