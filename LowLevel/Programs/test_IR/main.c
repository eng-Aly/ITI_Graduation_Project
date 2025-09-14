#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/RCC/RCC_int.h"
#include "../MCAL/GPIO/GPIO_int.h"
#include "../HAL/IR_TCRT5000/TCRT5000_int.h"


int main(void)
{
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1, GPIO_PORTA);

	TCRT5000_Init((u8[]){GPIO_PORTA, GPIO_PORTA}, (u8[]){GPIO_PIN0, GPIO_PIN1});

	GPIOx_PinConfig_t led = {
			.Port = GPIO_PORTA,
			.Pin = GPIO_PIN3,
			.Mode = GPIO_MODE_OUTPUT,
			.Speed = GPIO_SPEED_LOW,
			.OutputType = GPIO_OT_PUSHPULL,
			.PullType = GPIO_PULL_DOWN
	};
	MGPIO_vPinInit(&led);

	while(1)
	{
		if(TCRT5000_ReadDigital())
		{
			MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
		}
		else{
			MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);
		}
	}
	return 0 ;
}
