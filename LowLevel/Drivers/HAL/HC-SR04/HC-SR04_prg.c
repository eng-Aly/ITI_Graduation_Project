/*
 * HC-SR04_prg.c
 *
 *  Created on: Sep 8, 2025
 *      Author: pc
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TIM_IC/TIM_IC_int.h"
#include "../../MCAL/TIM_IC/TIM_IC_prv.h"
#include "../../MCAL/TIM_IC/TIM_IC_cfg.h"
#include "../../MCAL/SYSTICK/SYSTICK_int.h"
#include "HC-SR04_int.h"
#include "HC-SR04_cfg.h"

static HCSR04_Handle_t* hcsr_map[4] = {0};
void HCSR04_IC_Handler() ;

void HCSR04_vInit(HCSR04_Handle_t *hcsr)
{

	hcsr->first_capture = 1;
	// Trigger pin
	GPIOx_PinConfig_t trig = {
		.Port = hcsr->TriggerPort,
		.Pin = hcsr->TriggerPin,
		.Mode = GPIO_MODE_OUTPUT,
		.OutputType = GPIO_OUT_PUSHPULL,
		.Speed = GPIO_SPEED_HIGH,
		.PullType = GPIO_NO_PULL
	};
	MGPIO_vPinInit(&trig);

	// Echo pin
	GPIOx_PinConfig_t echo = {
		.Port = hcsr->EchoPort,
		.Pin = hcsr->EchoPin,
		.Mode = GPIO_MODE_ALF,
		.Altfunc = hcsr->EchoAF,
		.PullType = GPIO_NO_PULL
	};
	MGPIO_vPinInit(&echo);

	// Timer Input Capture
	TIM_IC_Config_t ic_cfg = {
		.TimerId   = hcsr->TimerId,
		.Channel   = hcsr->Channel,
		.Polarity  = TIM_POLARITY_RISING,
		.Prescaler = 0,
		.Filter    = 0
//		.TimerPrescaler = 24
	};
	MTIM_vIC_Init(&ic_cfg);

	/* --- Register handle --- */
	hcsr_map[0] = hcsr;

    /* --- Register callback --- */
	MTIM_vTIMCallback(hcsr->TimerId, HCSR04_IC_Handler);
}

void HCSR04_vTrigger(HCSR04_Handle_t *hcsr) {
    // Reset state
    hcsr->isRisingCaptured = 0;
    hcsr->isReady = 0;

	MTIM_vIC_ClearFlag(hcsr->TimerId, hcsr->Channel);
//    MTIM_vIC_EnableInterrupt(hcsr->TimerId, hcsr->Channel);
    // Send 10 us
    MGPIO_vSetPinValue(hcsr->TriggerPort, hcsr->TriggerPin, GPIO_HIGH);
//    DELAY_MS(10);
    MSYSTICK_vSetDelay_ms(10);
    MGPIO_vSetPinValue(hcsr->TriggerPort, hcsr->TriggerPin,GPIO_LOW);
//    MSYSTICK_vSetDelay_us(100);
//    DELAY_MS(10);
    TIM2->CNT = 0;
//    MTIM_vIC_EnableInterrupt(hcsr->TimerId, hcsr->Channel);
//    MTIM_vIC_EnableCapture(hcsr->TimerId, hcsr->Channel);

}

void HCSR04_IC_Handler() {

	HCSR04_Handle_t *hcsr = hcsr_map[0];

//	if (hcsr->first_capture == 1){
//		// skip pulse by clearing interrupt and overflow flag
//		CLR_BIT(TIM2->SR, TIM_SR_CC1IF);
//		CLR_BIT(TIM2->SR, TIM_SR_CC1OF);
//		// led for debugging
//		MGPIO_vSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
//		return;
//	}
//
//	else {

	if (0 == hcsr->isRisingCaptured) {
		SET_BIT(TIM2->CCER,TIM_CCER_CC1P);
		MGPIO_TogPinValue(GPIO_PORTB,GPIO_PIN0);
		// capture
		hcsr->IC_Value1 = TIM2->CCR1;
		// rising edge captures
		hcsr->isRisingCaptured = 1;
//		CLR_BIT(TIM2->SR, TIM_SR_CC1IF);
	//		MTIM_vIC_SetPolarity(TimerId,ChannelId,TIM_POLARITY_FALLING);
//		TIM2->CCER &= ~(TIM_CCER_CC1P_Msk | TIM_CCER_CC1NP_Msk);
//		TIM2->CCER |= TIM_CCER_CC1P_Msk;
//		CLR_BIT(TIM2->CCER, TIM_CCER_CC1E);


//		SET_BIT(TIM2->CCER, TIM_CCER_CC1E);

		return;
	}
	else if (1 == hcsr->isRisingCaptured)
	{
		MGPIO_TogPinValue(GPIO_PORTB,GPIO_PIN1);
		hcsr->IC_Value2 = TIM2->CCR1;
		hcsr->isReady = 1;
		hcsr->isRisingCaptured = 0;
		CLR_BIT(TIM2->SR, TIM_SR_CC1IF);
//		MTIM_vIC_SetPolarity(TimerId,ChannelId,TIM_POLARITY_RISING);
//		TIM2->CCER &= ~(TIM_CCER_CC1P_Msk | TIM_CCER_CC1NP_Msk);
		CLR_BIT(TIM2->CCER,TIM_CCER_CC1P);

		if (hcsr->IC_Value2 >= hcsr->IC_Value1)
			hcsr->IC_Diff = hcsr->IC_Value2 - hcsr->IC_Value1;
		else
			hcsr->IC_Diff = (0xFFFFFFFF - hcsr->IC_Value1) + hcsr->IC_Value2;

		hcsr->distance_cm = (u16)((hcsr->IC_Diff * 3.40) / 2.0f);
//		hcsr->distance_cm = (u16)(hcsr->IC_Diff / 58);

		hcsr->isReady = 1;
		hcsr->isRisingCaptured = 0;
		MTIM_vIC_DisableInterrupt(hcsr->TimerId,hcsr->Channel);
		return;

	}
//	}
}
