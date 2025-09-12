/*
 * Encoder_Int.h
 *
 * Created on: Sep 11, 2025
 * Author: Ahmed Ezzat
 */

#ifndef DRIVERS_HAL_ENCODER_ENCODER_INT_H_
#define DRIVERS_HAL_ENCODER_ENCODER_INT_H_

#include "Encoder_cfg.h"
#include "Encoder_prv.h"
#include "../../MCAL/GPIO/GPIO_Int.h"
#include "../../MCAL/TIM_OC/TIM_OC_Int.h"

void HEncoder_vInit(GPIO_PinConfig_t* ch1,GPIO_PinConfig_t* ch2);
void HEncoder_vTIM_Init(TIMER_TypeDef* Timer);

s16 HEncoder_vGetCounts(TIMER_TypeDef *Timer_Config);
s16 HEncoder_vGetSpeed(Timer_Config_t *Timer_Config);

#endif /* DRIVERS_HAL_ENCODER_ENCODER_INT_H_ */
