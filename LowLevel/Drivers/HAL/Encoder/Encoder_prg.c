/*
 * Encoder_prg.c
 *
 * Created on: Sep 11, 2025
 * Author: Ahmed Ezzat
 */

#include "Encoder_Int.h"

void HEncoder_vInit(GPIO_PinConfig_t* ch1,GPIO_PinConfig_t* ch2){
	ch1->GPIO_MODE      = GPIO_MODE_AF;
	ch1->GPIO_AFx       = GPIO_AF2;   //MAKE SURE
	ch1->GPIO_PU_PD     = GPIO_PULL_UP;
	MCAL_GPIO_Init(ch1->GPIOx, ch1);

    ch2->GPIO_MODE      = GPIO_MODE_AF;
    ch2->GPIO_AFx       = GPIO_AF2;
    ch2->GPIO_PU_PD     = GPIO_PULL_UP;
	MCAL_GPIO_Init(ch2->GPIOx, ch2);
}

void HEncoder_vTIM_Init(TIMER_TypeDef* Timer){
    MCAL_Timer_Encoder_Init(Timer);
}

s16 HEncoder_vGetCounts(TIMER_TypeDef *Timer_Config){
	s16 Counts;
	Counts = MCAL_Timer_Encoder_GetCounts(Timer_Config);
	return Counts;
}

s16 HEncoder_vGetSpeed(Timer_Config_t *Timer_Config){

}



