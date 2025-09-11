#include "L289_Int.h"

/* DON'T FORGET */
/*
Timer_Config_t Timer2Cfg;
Timer_OutputCompare_Config_t Timer2OC;

GPIO_PinConfig_t PA0 = {
    .GPIO_PinNumber = 0,      / Pin 0 /
    .GPIO_MODE = GPIO_MODE_OP,      /* Output mode /
    .GPIO_AFx = GPIO_SPEED_HIGH,              /* No alternate function /
    .GPIO_TYPE = GPIO_TYPE_PP,    /* Push-pull type /
    .GPIO_PU_PD = GPIO_NO_PULL,        /* No pull-up/pull-down /
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, /* High speed /
    .GPIOx = GPIOA
};


void Clock_Init(void){
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_SYSCFG_CLK_EN();
    RCC_TIMER2_CLK_EN();
}
*/




void HL289_vInit(GPIO_PinConfig_t* dir1,GPIO_PinConfig_t* dir2,GPIO_PinConfig_t* en)
{
    dir1->GPIO_MODE=GPIO_MODE_OP;
    dir1->GPIO_TYPE=GPIO_TYPE_PP;
    dir1->GPIO_PU_PD=GPIO_NO_PULL;
    dir1->GPIO_Output_Speed=GPIO_SPEED_HIGH;
    MCAL_GPIO_Init(dir1->GPIOx,dir1);

    dir2->GPIO_MODE=GPIO_MODE_OP;
    dir2->GPIO_TYPE=GPIO_TYPE_PP;
    dir2->GPIO_PU_PD=GPIO_NO_PULL;
    dir2->GPIO_Output_Speed=GPIO_SPEED_HIGH;
    MCAL_GPIO_Init(dir2->GPIOx,dir2);

    en->GPIO_MODE=GPIO_MODE_AF;
    en->GPIO_TYPE=GPIO_TYPE_PP;
    en->GPIO_Output_Speed=GPIO_SPEED_HIGH;
    en->GPIO_PU_PD=GPIO_NO_PULL;
    en->GPIO_AFx=GPIO_AF1;
    MCAL_GPIO_Init(en->GPIOx,en);

}

void HL289_vTIM_Init(Timer_Config_t* TimerCfg,Timer_OutputCompare_Config_t* OCcfg,TIMER_TypeDef *TIMERx ,u32 CHx)
{
    /* Timer2 CH1 PWM config */
    TimerCfg->BaseConfig.TIMERx = TIMERx;
    TimerCfg->OCConfig = OCcfg;    // where is the init
    OCcfg->TIMER_Channel   = CHx;
    OCcfg->TIMER_Frequency = 20000;
    MCAL_Timer_PWM_Init(TimerCfg, 0);
}

void HL289_vSetSpeed(GPIO_PinConfig_t* dir1,GPIO_PinConfig_t* dir2,Timer_Config_t* TimerCfg,u8 speed)
{
    if(speed >0){
        MCAL_GPIO_WritePin(dir1->GPIOx,dir1->GPIO_PinNumber,HIGH);
        MCAL_GPIO_WritePin(dir2->GPIOx,dir2->GPIO_PinNumber,LOW);
    }
    else if(speed <0){
        MCAL_GPIO_WritePin(dir1->GPIOx,dir1->GPIO_PinNumber,LOW);
        MCAL_GPIO_WritePin(dir2->GPIOx,dir2->GPIO_PinNumber,HIGH);
        speed*=-1;
    }
    else{
        MCAL_GPIO_WritePin(dir1->GPIOx,dir1->GPIO_PinNumber,LOW);
        MCAL_GPIO_WritePin(dir2->GPIOx,dir2->GPIO_PinNumber,LOW);
    }
    if (speed > 100) speed = 100;    //why not map to 255 ?! nig
    MCAL_Timer_PWM_SetDuty(TimerCfg, speed);
}