#ifndef TIM_OC_PRV_H_
#define TIM_OC_PRV_H_

#include "../../LIB/STD_TYPES.h"

typedef struct{
	volatile u32 CR1		;
	volatile u32 CR2		;
	volatile u32 SMCR		;
	volatile u32 DIER		;
	volatile u32 SR		;
	volatile u32 EGR		;
	volatile u32 CCMR1		;
	volatile u32 CCMR2		;
	volatile u32 CCER		;
	volatile u32 CNT		;
	volatile u32 PSC		;
	volatile u32 ARR		;
	volatile u32 RCR		;
	volatile u32 CCR1		;
	volatile u32 CCR2		;
	volatile u32 CCR3		;
	volatile u32 CCR4		;
	volatile u32 BDTR		;
	volatile u32 DCR		;
	volatile u32 DMAR		;
}TIMER_TypeDef;


// TIMER 2 & 3 & 4 & 5
#define TIMER1_BASE											0x40010000UL
#define TIMER2_BASE											0x40000000UL
#define TIMER3_BASE											0x40000400UL
#define TIMER4_BASE											0x40000800UL
#define TIMER5_BASE											0x40000C00UL


#define TIMER1								((TIMER_TypeDef *)TIMER1_BASE)
#define TIMER2								((TIMER_TypeDef *)TIMER2_BASE)
#define TIMER3								((TIMER_TypeDef *)TIMER3_BASE)
#define TIMER4								((TIMER_TypeDef *)TIMER4_BASE)
#define TIMER5								((TIMER_TypeDef *)TIMER5_BASE)

#define TIMER_Channel_1							(u32)(1)
#define TIMER_Channel_2							(u32)(2)
#define TIMER_Channel_3							(u32)(3)
#define TIMER_Channel_4							(u32)(4)



#define TIMER_IRQ_Mode_None					(u32)(0)
#define TIMER_IRQ_Mode_UIE					(u32)(1 << 0)
#define TIMER_IRQ_Mode_CC1IE				(u32)(1 << 1)
#define TIMER_IRQ_Mode_CC2IE				(u32)(1 << 2)
#define TIMER_IRQ_Mode_CC3IE				(u32)(1 << 3)
#define TIMER_IRQ_Mode_CC4IE				(u32)(1 << 4)
#define TIMER_IRQ_Mode_TIE					(u32)(1 << 6)
#define TIMER_IRQ_Mode_BIE					(u32)(1 << 7)

#define TIMER_OCMODE_Frozen						(u32)(0)
#define TIMER_OCMODE_Active						(u32)(1 << 4)
#define TIMER_OCMODE_InActive					(u32)(2 << 4)
#define TIMER_OCMODE_Toggle						(u32)(3 << 4)
#define TIMER_OCMODE_Force_InActive				(u32)(4 << 4)
#define TIMER_OCMODE_Force_Active				(u32)(5 << 4)
#define TIMER_OCMODE_PWM1						(u32)(6 << 4)
#define TIMER_OCMODE_PWM2						(u32)(7 << 4)

#define TIMER_OC1PE   (1 << 3)
#define TIMER_OC2PE   (1 << 11)
#define TIMER_OC3PE   (1 << 3)
#define TIMER_OC4PE   (1 << 11)

#define TIMER_CH1_OPC						(u32)(0)
#define TIMER_CH1_IPC_TI1					(u32)(1 << 0)
#define TIMER_CH1_IPC_TI2					(u32)(2 << 0)
#define TIMER_CH1_IPC_TRC					(u32)(3 << 0)

#define TIMER_CH2_OPC						(u32)(0)
#define TIMER_CH2_IPC_TI1					(u32)(1 << 8)
#define TIMER_CH2_IPC_TI2					(u32)(2 << 8)
#define TIMER_CH2_IPC_TRC					(u32)(3 << 8)


#define TIMER_OutputCompare_Polarity_High_CH1	~(u32)(1 << 1)
#define TIMER_OutputCompare_Polarity_High_CH2	~(u32)(1 << 5)

#define TIMER_OutputCompare_Polarity_Low_CH1	(u32)(1 << 1)
#define TIMER_OutputCompare_Polarity_Low_CH2	(u32)(1 << 5)
#define TIMER_OutputCompare_Polarity_Low_CH3	(u32)(1 << 9)
#define TIMER_OutputCompare_Polarity_Low_CH4	(u32)(1 << 13)


#define TIMER_Encoder_Mode_DIS				(u32)(0)
#define TIMER_Encoder_Mode1					(u32)(1 << 0)
#define TIMER_Encoder_Mode2					(u32)(2 << 0)
#define TIMER_Encoder_Mode3					(u32)(3 << 0)




#endif