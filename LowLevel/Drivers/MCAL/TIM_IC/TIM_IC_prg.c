/*
 * TIM_IC_prg.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Toqa Shalash
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_int.h"
#include "TIM_IC_int.h"
#include "TIM_IC_prv.h"
#include "TIM_IC_cfg.h"

void (*G_TIMFpt[4])(void)={NULL};

static inline volatile TIMx_MemMap_t* TIM_GetInstance(TIM_Id_t id) {
    switch (id) {
        case TIM_ID_2: return TIM2;
        case TIM_ID_3: return TIM3;
        case TIM_ID_4: return TIM4;
        case TIM_ID_5: return TIM5;
        default:       return TIM2;
    }
}

void MTIM_vIC_Init(const TIM_IC_Config_t *cfg)
{
    volatile TIMx_MemMap_t *TIMx = TIM_GetInstance(cfg->TimerId);

    // Disable counter while configuring
    CLR_BIT(TIMx->CR1, TIM_CR1_CEN);

    switch (cfg->Channel)
    {
    case TIM_CHANNEL1:
        /* --- CC1 configuration --- */
        TIMx->CCMR1 &= ~TIM_CCMR1_CC1S_Msk;
        TIMx->CCMR1 |= TIM_CCMR1_CC1S_TI1;   // select input mapping

        // Prescaler
        TIMx->CCMR1 &= ~TIM_CCMR1_IC1PSC_Msk;
        TIMx->CCMR1 |= (cfg->Prescaler << TIM_CCMR1_IC1PSC_Pos) & TIM_CCMR1_IC1PSC_Msk;

        // Filter
        TIMx->CCMR1 &= ~TIM_CCMR1_IC1F_Msk;
        TIMx->CCMR1 |= (cfg->Filter << TIM_CCMR1_IC1F_Pos) & TIM_CCMR1_IC1F_Msk;

        // Polarity
        TIMx->CCER &= ~(TIM_CCER_CC1P_Msk | TIM_CCER_CC1NP_Msk);
        if (cfg->Polarity == TIM_POLARITY_FALLING)
            TIMx->CCER |= TIM_CCER_CC1P_Msk;
        else if (cfg->Polarity == TIM_POLARITY_BOTH)
            TIMx->CCER |= (TIM_CCER_CC1P_Msk | TIM_CCER_CC1NP_Msk);

        // Enable capture + interrupt
        SET_BIT(TIMx->CCER, TIM_CCER_CC1E);
        SET_BIT(TIMx->DIER, TIM_DIER_CC1IE);
        break;

    case TIM_CHANNEL2:
        /* --- CC2 configuration --- */
        TIMx->CCMR1 &= ~TIM_CCMR1_CC2S_Msk;
        TIMx->CCMR1 |= TIM_CCMR1_CC2S_TI2;   // select input mapping

        // Prescaler
        TIMx->CCMR1 &= ~TIM_CCMR1_IC2PSC_Msk;
        TIMx->CCMR1 |= (cfg->Prescaler << TIM_CCMR1_IC2PSC_Pos) & TIM_CCMR1_IC2PSC_Msk;

        // Filter
        TIMx->CCMR1 &= ~TIM_CCMR1_IC2F_Msk;
        TIMx->CCMR1 |= (cfg->Filter << TIM_CCMR1_IC2F_Pos) & TIM_CCMR1_IC2F_Msk;

        // Polarity
        TIMx->CCER &= ~(TIM_CCER_CC2P_Msk | TIM_CCER_CC2NP_Msk);
        if (cfg->Polarity == TIM_POLARITY_FALLING)
            TIMx->CCER |= TIM_CCER_CC2P_Msk;
        else if (cfg->Polarity == TIM_POLARITY_BOTH)
            TIMx->CCER |= (TIM_CCER_CC2P_Msk | TIM_CCER_CC2NP_Msk);

        // Enable capture + interrupt
        SET_BIT(TIMx->CCER, TIM_CCER_CC2E);
        SET_BIT(TIMx->DIER, TIM_DIER_CC2IE);
        break;

    case TIM_CHANNEL3:
    	/* To be implemented */
//
        break;

    case TIM_CHANNEL4:
//        /* To be implemented */
        break;
    }

    // Enable counter
    SET_BIT(TIMx->CR1, TIM_CR1_CEN);
}


u8 MTIM_u8IC_IsCaptureFlag(TIM_Id_t TimerId, TIM_Channel_t Channel)
{
    volatile TIMx_MemMap_t *TIMx = TIM_GetInstance(TimerId);

    switch(Channel)
    {
    case TIM_CHANNEL1: return GET_BIT(TIMx->SR, TIM_SR_CC1IF);
    case TIM_CHANNEL2: return GET_BIT(TIMx->SR, TIM_SR_CC2IF);
    case TIM_CHANNEL3: return GET_BIT(TIMx->SR, TIM_SR_CC3IF);
    case TIM_CHANNEL4: return GET_BIT(TIMx->SR, TIM_SR_CC4IF);
    default: return 0;
    }
}

void MTIM_vIC_ClearFlag(TIM_Id_t TimerId, TIM_Channel_t Channel)
{
    volatile TIMx_MemMap_t *TIMx = TIM_GetInstance(TimerId);

    switch(Channel)
    {
    case TIM_CHANNEL1: CLR_BIT(TIMx->SR, TIM_SR_CC1IF); break;
    case TIM_CHANNEL2: CLR_BIT(TIMx->SR, TIM_SR_CC2IF); break;
    case TIM_CHANNEL3: CLR_BIT(TIMx->SR, TIM_SR_CC3IF); break;
    case TIM_CHANNEL4: CLR_BIT(TIMx->SR, TIM_SR_CC4IF); break;
    }
}

void MTIM_vIC_EnableInterrupt(TIM_Id_t TimerId, TIM_Channel_t Channel)
{
    volatile TIMx_MemMap_t *TIMx = TIM_GetInstance(TimerId);

    switch(Channel)
    {
    case TIM_CHANNEL1: SET_BIT(TIMx->DIER, TIM_DIER_CC1IE); break;
    case TIM_CHANNEL2: SET_BIT(TIMx->DIER, TIM_DIER_CC2IE); break;
    case TIM_CHANNEL3: SET_BIT(TIMx->DIER, TIM_DIER_CC3IE); break;
    case TIM_CHANNEL4: SET_BIT(TIMx->DIER, TIM_DIER_CC4IE); break;
    }
}

void MTIM_vIC_DisableInterrupt(TIM_Id_t TimerId, TIM_Channel_t Channel)
{
    volatile TIMx_MemMap_t *TIMx = TIM_GetInstance(TimerId);

    switch(Channel)
    {
    case TIM_CHANNEL1: CLR_BIT(TIMx->DIER, TIM_DIER_CC1IE); break;
    case TIM_CHANNEL2: CLR_BIT(TIMx->DIER, TIM_DIER_CC2IE); break;
    case TIM_CHANNEL3: CLR_BIT(TIMx->DIER, TIM_DIER_CC3IE); break;
    case TIM_CHANNEL4: CLR_BIT(TIMx->DIER, TIM_DIER_CC4IE); break;
    }
}

u32 MTIM_u32IC_GetCapture(TIM_Id_t TimerId, TIM_Channel_t Channel)
{
    volatile TIMx_MemMap_t *TIMx = TIM_GetInstance(TimerId);

    switch(Channel)
    {
    case TIM_CHANNEL1: return TIMx->CCR1;
    case TIM_CHANNEL2: return TIMx->CCR2;
    case TIM_CHANNEL3: return TIMx->CCR3;
    case TIM_CHANNEL4: return TIMx->CCR4;
    default: return 0;
    }
}

void MTIM_vIC_ResetCounter(TIM_Id_t TimerId)
{
    volatile TIMx_MemMap_t *TIMx = TIM_GetInstance(TimerId);
    TIMx->CNT = 0;
}

void MTIM_vTIMCallback(TIM_Id_t TimerId, void(*Fptr)(void)) {
    u8 L_u8index = (TimerId==0)?0:TimerId==1?1:TimerId==2?2:3;
    G_TIMFpt[L_u8index] = Fptr;

}

void TIM2_IRQHandler(){
	if(G_TIMFpt[0] != NULL)
	{
		G_TIMFpt[0]();
	}
	// clear flag
	TIM2->SR &= ~TIM_SR_CC1IF;
}

//
//// Timer ISR
//void TIM2_IRQHandler(void)
//{
//    if (TIM2->SR & TIM_SR_CC1IF) {
//        // call registered callback if any
//        if (ic_callback) ic_callback(TIM2->CCR1);
//
//        // for testing: toggle LED
//        MGPIO_TogPinValue(GPIO_PORTA, GPIO_PIN1);
//
//        // clear flag
//        TIM2->SR &= ~TIM_SR_CC1IF;
//    }
//}
