#include "Programs/Shato_Sensors_Cfg.h"


void PrintDistance(u16 distance) {
    MUSART_vSendString("Distance: ");
    MUSART_vSendNumber(distance);
    MUSART_vSendString(" cm\r\n");
}

void int_to_str(s16 num, s8 *str) {
    u8 i = 0, j;
    s8 buf[10];

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    while (num > 0) {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    // reverse into str
    for (j = 0; j < i; j++) {
        str[j] = buf[i - j - 1];
    }
    str[j] = '\0';
}

void SETUP(){
	MRCC_vInit();
	MRCC_vEnableClk(RCC_AHB1,RCC_GPIOA);
	MRCC_vEnableClk(RCC_AHB1,RCC_GPIOB);
	MRCC_vEnableClk(RCC_APB1,RCC_EN_TIM2);
	MUSART_vInit();
	MNVIC_vEnable_Peripheral_INT(NVIC_IRQ_TIM2);
	MGPIO_vPinInit(& LED1);
	MGPIO_vPinInit(& LED3);
	MGPIO_vPinInit(& LED4);
	MGPIO_vPinInit(& LED5);
	HCSR04_vInit(&us1);
    MCAL_UART_Init(DIFF_UART,&DIFF_UART_TX_Cfg);
}


void LOOP(){
		u8 buffer[10];
		HCSR04_vTrigger(&us1);
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
		int_to_str(distance, (s8 *)buffer);
		MCAL_UART_SendString(DIFF_UART, (u8 *)buffer);
		DELAY_MS(100);
}

int main(void)
{
	SETUP();
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
//	


//
//	if (GET_BIT(TIM2->SR,TIM_SR_CC1OF)){
//		MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
//	}
//	MSYSTICK_vSetDelay_ms(100);

	while (1)
	{
		LOOP();
	}
	return 0 ;
}



