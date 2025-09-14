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
void HCSR04_IC_Handler(u8 ChannelId);

void HCSR04_vInit(HCSR04_Handle_t *hcsr)
{

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
		.Filter    = 0,
		.TimerPrescaler = 24
	};
	MTIM_vIC_Init(&ic_cfg);

	/* --- Register handle --- */
	hcsr_map[hcsr->Channel -1] = hcsr;

    /* --- Register callback --- */
	MTIM_vTIMCallback(hcsr->TimerId, HCSR04_IC_Handler);
}

void HCSR04_vTrigger(HCSR04_Handle_t *hcsr) {
    // Reset state
    hcsr->isRisingCaptured = 0;
    hcsr->isReady = 0;

    // Send high 10 us
    MGPIO_vSetPinValue(hcsr->TriggerPort, hcsr->TriggerPin, GPIO_HIGH);
    MSYSTICK_vSetDelay_us(15);
    MGPIO_vSetPinValue(hcsr->TriggerPort, hcsr->TriggerPin,GPIO_LOW);
    TIM2->CNT = 0;

}

void HCSR04_IC_Handler(u8 ChannelId) {

	HCSR04_Handle_t *hcsr = hcsr_map[ChannelId - 1];

	// if overcapture measurment invalid

	if(GET_BIT(TIM2->SR,TIM_SR_CC1OF)){
		// wait for another rising edge
		hcsr->isRisingCaptured = 0;
		// set polarity to rising edge
		CLR_BIT(TIM2->CCER,TIM_CCER_CC1P);
		// clear flags
		CLR_BIT(TIM2->SR,TIM_SR_CC1OF);
		CLR_BIT(TIM2->SR,TIM_SR_CC1IF);
	}

	else if (0 == hcsr->isRisingCaptured) {
		// set polarity to falling edge
		SET_BIT(TIM2->CCER,TIM_CCER_CC1P);
		MGPIO_TogPinValue(GPIO_PORTB,GPIO_PIN0);
		// capture
		hcsr->IC_Value1 = TIM2->CCR1;
		// rising edge captured flag
		hcsr->isRisingCaptured = 1;
		// clear flag
		CLR_BIT(TIM2->SR, TIM_SR_CC1IF);

		return;
	}
	else if (1 == hcsr->isRisingCaptured)
	{
		MGPIO_TogPinValue(GPIO_PORTB,GPIO_PIN1);
		// capture value 2
		hcsr->IC_Value2 = TIM2->CCR1;
		// set ready flag
		hcsr->isReady = 1;
		// reset rising edge captured flag
		hcsr->isRisingCaptured = 0;
		// clear flag
		CLR_BIT(TIM2->SR, TIM_SR_CC1IF);
		// set polarity to rising
		CLR_BIT(TIM2->CCER,TIM_CCER_CC1P);

		if (hcsr->IC_Value2 >= hcsr->IC_Value1)
			hcsr->IC_Diff = hcsr->IC_Value2 - hcsr->IC_Value1;
		else
			hcsr->IC_Diff = (0xFFFFFFFF - hcsr->IC_Value1) + hcsr->IC_Value2;

//		hcsr->distance_cm = (u16)((hcsr->IC_Diff * 3.40) / 2.0f);
//		hcsr->distance_cm = (u16)(hcsr->IC_Diff / 58)* 0.0625;
		hcsr->distance_cm = (u16)(hcsr->IC_Diff / 58);

		hcsr->isReady = 1;
		hcsr->isRisingCaptured = 0;
		MTIM_vIC_DisableInterrupt(hcsr->TimerId,hcsr->Channel);
		return;

	}
//	}
}
