#ifndef SHATO_CFG_H
#define SHATO_CFG_H

#include "../Drivers/MCAL/GPIO/GPIO_Int.h"
#include "../Drivers/HAL/L289/L289_Int.h"
#include "../Drivers/MCAL/TIM_OC/TIM_OC_Int.h"

/*
GPIO_PinConfig_t PA0 = {
    .GPIO_PinNumber = 0,      / Pin 0 /
    .GPIO_MODE = GPIO_MODE_OP,      /* Output mode /
    .GPIO_AFx = GPIO_SPEED_HIGH,              /* No alternate function /
    .GPIO_TYPE = GPIO_TYPE_PP,    /* Push-pull type /
    .GPIO_PU_PD = GPIO_NO_PULL,        /* No pull-up/pull-down /
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, /* High speed /
    .GPIOx = GPIOA
};*/

GPIO_PinConfig_t M1_DIR1 = {
    .GPIO_PinNumber = 12,      
    .GPIO_MODE = GPIO_MODE_OP,      
    .GPIO_AFx = GPIO_SPEED_HIGH,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M1_DIR2 = {
    .GPIO_PinNumber = 13,      
    .GPIO_MODE = GPIO_MODE_OP,     
    .GPIO_AFx = GPIO_SPEED_HIGH,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M1_EN = {
    .GPIO_PinNumber = 15,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};


GPIO_PinConfig_t M2_DIR1 = {
    .GPIO_PinNumber = 14, 
    .GPIO_MODE = GPIO_MODE_OP,      
    .GPIO_AFx = GPIO_SPEED_HIGH,         
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M2_DIR2 = {
    .GPIO_PinNumber = 15,      
    .GPIO_MODE = GPIO_MODE_OP,     
    .GPIO_AFx = GPIO_SPEED_HIGH,             
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M2_EN={
    .GPIO_PinNumber = 3,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};



GPIO_PinConfig_t M3_DIR1 = {
    .GPIO_PinNumber = 0,      
    .GPIO_MODE = GPIO_MODE_OP,      
    .GPIO_AFx = GPIO_SPEED_HIGH,             
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};

GPIO_PinConfig_t M3_DIR2 = {
    .GPIO_PinNumber = 1,      
    .GPIO_MODE = GPIO_MODE_OP,      
    .GPIO_AFx = GPIO_SPEED_HIGH,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,        
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M3_EN={
    .GPIO_PinNumber = 2,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};




GPIO_PinConfig_t M4_DIR1 = {
    .GPIO_PinNumber = 2,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M4_DIR2 = {
    .GPIO_PinNumber = 10,      
    .GPIO_MODE = GPIO_MODE_OP,      
    .GPIO_AFx = GPIO_SPEED_HIGH,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOB
};
GPIO_PinConfig_t M4_EN={
    .GPIO_PinNumber = 3,      
    .GPIO_MODE = GPIO_MODE_AF,      
    .GPIO_AFx = GPIO_AF1,              
    .GPIO_TYPE = GPIO_TYPE_PP,    
    .GPIO_PU_PD = GPIO_NO_PULL,       
    .GPIO_Output_Speed = GPIO_SPEED_HIGH, 
    .GPIOx = GPIOA
};


Timer_Config_t              M1_EN_TIMER_Cfg;
Timer_Config_t              M2_EN_TIMER_Cfg;
Timer_Config_t              M3_EN_TIMER_Cfg;
Timer_Config_t              M4_EN_TIMER_Cfg;

Timer_OutputCompare_Config_t M1_EN_TIMER_OC_Cfg;
Timer_OutputCompare_Config_t M2_EN_TIMER_OC_Cfg;
Timer_OutputCompare_Config_t M3_EN_TIMER_OC_Cfg;
Timer_OutputCompare_Config_t M4_EN_TIMER_OC_Cfg;

#define M1_EN_TIMER       TIMER2
#define M1_EN_CHANNEL     TIMER_Channel_2

#define M2_EN_TIMER       TIMER2
#define M2_EN_CHANNEL     TIMER_Channel_1

#define M3_EN_TIMER       TIMER2
#define M3_EN_CHANNEL     TIMER_Channel_4

#define M4_EN_TIMER       TIMER2
#define M4_EN_CHANNEL     TIMER_Channel_3



/*
    // Timer2 CH1 PWM config 
    Timer2Cfg.BaseConfig.TIMERx = TIMER2;
    Timer2Cfg.OCConfig = &Timer2OC;
    Timer2OC.TIMER_Channel   = TIMER_Channel_1;
    Timer2OC.TIMER_Frequency = 20000;
*/

void Clock_Init(void){
    RCC_GPIOA_CLK_EN();
    RCC_GPIOB_CLK_EN();
    RCC_SYSCFG_CLK_EN();
    RCC_TIMER2_CLK_EN();
}

Timer_Config_t TimerCfgTemp;
Timer_OutputCompare_Config_t TimerOcCfgTemp;





#endif
