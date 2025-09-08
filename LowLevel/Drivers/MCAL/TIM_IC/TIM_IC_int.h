/*
 * TIM_IC_int.h
 *
 *  Created on: Sep 7, 2025
 *      Author: Toqa Shalash
 */

#ifndef MCAL_TIM_IC_TIM_IC_INT_H_
#define MCAL_TIM_IC_TIM_IC_INT_H_

/* Timer IDs */
typedef enum {
    TIM_ID_2 = 0,
    TIM_ID_3,
    TIM_ID_4,
    TIM_ID_5
} TIM_Id_t;

/* Timer Channels */
typedef enum {
    TIM_CHANNEL1 = 1,
    TIM_CHANNEL2,
    TIM_CHANNEL3,
    TIM_CHANNEL4
} TIM_Channel_t;

/* Timer Polarity */
typedef enum {
    TIM_POLARITY_RISING = 0,
    TIM_POLARITY_FALLING,
    TIM_POLARITY_BOTH
} TIM_ICPolarity_t;

/* Timer Config */
typedef struct {
	TIM_Id_t TimerId;
    TIM_Channel_t Channel;      // which channel (1–4)
    TIM_ICPolarity_t Polarity;	// rising, falling, or both
    u32 Prescaler;      		// input capture prescaler (1, 2, 4, 8)
    u32 Filter;         		// digital filter (0–15)
    u32 TimerPrescaler; 		// PSC -> timer clock divider
    u32 TimerPeriod;    		// ARR -> counter max
} TIM_IC_Config_t;


/* -------- Input Capture -------- */
void MTIM_vIC_Init(const TIM_IC_Config_t *cfg);
u8 MTIM_u8IC_IsCaptureFlag(TIM_Id_t TimerId, TIM_Channel_t Channel);
void MTIM_vIC_ClearFlag(TIM_Id_t TimerId, TIM_Channel_t Channel);
void MTIM_vIC_EnableInterrupt(TIM_Id_t TimerId, TIM_Channel_t Channel);
void MTIM_vIC_DisableInterrupt(TIM_Id_t TimerId, TIM_Channel_t Channel);
u32 MTIM_u32IC_GetCapture(TIM_Id_t TimerId, TIM_Channel_t Channel);
void MTIM_vIC_ResetCounter(TIM_Id_t TimerId);


#endif /* MCAL_TIM_IC_TIM_IC_INT_H_ */
