#ifndef TIM_OC_INT_H_
#define TIM_OC_INT_H_

#include "TIM_OC_Prv.h"
#include "TIM_OC_Cfg.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/RCC/RCC_Int.h"
#include "../../MCAL/NVIC/NVIC_Int.h"
//#include "../../MCAL/NVIC/NVIC_Int.h"

typedef struct{
	u8 TXE  	 : 1; // TX buffer empty interrupt
	u8 RXNE 	 : 1; // RX buffer not empty interrupt
	u8 TCE 	 : 1; // Transmission complete interrupt
	u8 Reserved : 5;
}S_TIMER_IRQ_SRC;

typedef struct{
	TIMER_TypeDef 	*TIMERx					 		;
	u8	   			TIMER_CounterMode		 		;
	u16	   			TIMER_Prescaler			 		;
	u16   			TIMER_AutoReload			 	;
	u16		   		TIMER_CLKDivision		 		;
	u16		   		TIMER_RepetitionCounter	 		;
}Timer_BaseConfig_t;

typedef struct{
	u8 		TIMER_Channel			 		;
	u8  	TIMER_OutputCompare_Mode	 	;
	u32 	TIMER_OutputCompare_Pulse		;
	u8  	TIMER_OutputCompare_Polarity	;
	u8  	TIMER_Complement_Output	 		;
    u32 	TIMER_Frequency					;
}Timer_OutputCompare_Config_t;

typedef struct{
	u8 		TIMER_Channel			 		;
	u8  	TIMER_InputCapture_Filter 		;
	u8  	TIMER_InputPrescaler 	 		;
	u8  	TIMER_InputPolarity 			;
    u8 		TIMER_InputSelection			;
}Timer_InputCapture_Config_t;

typedef struct{
	u8  	TIMER_Encoder_Mode 		 		;
	u8  	TIMER_Input1Polarity 			;
	u8  	TIMER_InputCapture1_Filter 		;
	u8  	TIMER_Input2Polarity 			;
	u8  	TIMER_InputCapture2_Filter 		;
}Timer_Encoder_Config_t;


typedef struct {
	Timer_BaseConfig_t 				BaseConfig		 ;
	Timer_OutputCompare_Config_t   	*OCConfig		 ;
	Timer_InputCapture_Config_t	   	*ICConfig		 ;
	Timer_Encoder_Config_t 			*EncoderConfig	 ;
	u8  	   					TIMER_IRQ_Enable ;
    u8 	   					TIMER_DMA_Enable ;
	void (*P_IRQ_Callback)(S_TIMER_IRQ_SRC irq_src)	 ;
} Timer_Config_t;


void MCAL_Timer_Init(Timer_Config_t *Timer_Config);
void MCAL_Timer_DeInit(Timer_Config_t *Timer_Config);

void MCAL_Timer_PWM_Init(Timer_Config_t *Timer_Config, u32 DutyCycle);
void MCAL_Timer_PWM_SetDuty(Timer_Config_t *cfg, u32 DutyCycle);

void MCAL_Timer_Encoder_Init(Timer_Config_t *Timer_Config);
s16 MCAL_Timer_Encoder_GetCounts(Timer_Config_t *Timer_Config);
// void MCAL_Timer_Encoder_SetCounts(Timer_Config_t *Timer_Config, u16 Counts);   //B3DEN


#endif