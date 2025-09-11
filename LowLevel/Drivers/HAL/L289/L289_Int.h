#ifndef DRIVERS_HAL_L289_L289_INT_H_
#define DRIVERS_HAL_L289_L289_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "L289_prv.h"
#include "L289_cfg.h"
#include "../../MCAL/GPIO/GPIO_Int.h"
#include "../../MCAL/TIM_OC/TIM_OC_Int.h"

void HL289_vInit(GPIO_PinConfig_t* dir1,GPIO_PinConfig_t* dir2,GPIO_PinConfig_t* en);
void HL289_vTIM_Init(Timer_Config_t* TimerCfg,Timer_OutputCompare_Config_t* OCcfg,TIMER_TypeDef *TIMERx ,u32 CHx);
void HL289_vSetSpeed(GPIO_PinConfig_t* dir1,GPIO_PinConfig_t* dir2,Timer_Config_t* TimerCfg,u8 speed);


#endif
