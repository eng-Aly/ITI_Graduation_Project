/*
 * TIM_IC_prv.h
 *
 *  Created on: Sep 7, 2025
 *      Author: Toqa Shalash
 */

#ifndef MCAL_TIM_IC_TIM_IC_PRV_H_
#define MCAL_TIM_IC_TIM_IC_PRV_H_

/* ================= Base Addresses ================= */
#define TIM2_BASE_ADDR       0x40000000U
#define TIM3_BASE_ADDR       0x40000400U
#define TIM4_BASE_ADDR       0x40000800U
#define TIM5_BASE_ADDR       0x40000C00U

/* ================= Register Map ================= */
typedef struct {
	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 Reserved0;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 Reserved1;
	u32 DCR;
	u32 DMAR;
	u32 OR;
}TIMx_MemMap_t;

/* ================= Peripheral Instances ================= */
#define TIM2                ((volatile TIMx_MemMap_t *)(TIM2_BASE_ADDR))
#define TIM3   				((volatile TIMx_MemMap_t *)(TIM3_BASE_ADDR))
#define TIM4   				((volatile TIMx_MemMap_t *)(TIM4_BASE_ADDR))
#define TIM5               	((volatile TIMx_MemMap_t *)(TIM5_BASE_ADDR))


/* ================= Bit Definitions ================= */
/* TIMx_CR1 */
#define TIM_CR1_CEN       0   /* Counter enable */

/* TIMx_DIER */
#define TIM_DIER_CC1IE    1   /* Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE    2
#define TIM_DIER_CC3IE    3
#define TIM_DIER_CC4IE    4

/* TIMx_SR */
#define TIM_SR_CC1IF      1   /* Capture/Compare 1 interrupt flag */
#define TIM_SR_CC2IF      2
#define TIM_SR_CC3IF      3
#define TIM_SR_CC4IF      4

#define TIM_SR_CC1OF      9   /* Overcapture flags */
#define TIM_SR_CC2OF      10
#define TIM_SR_CC3OF      11
#define TIM_SR_CC4OF      12

/* TIMx_CCER */
#define TIM_CCER_CC1E     0   /* Capture/Compare 1 output enable */
#define TIM_CCER_CC1P     1   /* Capture/Compare 1 polarity */
#define TIM_CCER_CC1NP    3

#define TIM_CCER_CC2E     4
#define TIM_CCER_CC2P     5
#define TIM_CCER_CC2NP    7

/* TIMx_CCMR1 (CC1S[1:0]) */
#define TIM_CCMR1_CC1S_Pos     0U
#define TIM_CCMR1_CC1S_Msk     (0x3U << TIM_CCMR1_CC1S_Pos)

#define TIM_CCMR1_CC1S_OUTPUT  (0x0U << TIM_CCMR1_CC1S_Pos) /* CC1 as output */
#define TIM_CCMR1_CC1S_TI1     (0x1U << TIM_CCMR1_CC1S_Pos) /* CC1 input mapped on TI1 */
#define TIM_CCMR1_CC1S_TI2     (0x2U << TIM_CCMR1_CC1S_Pos) /* CC1 input mapped on TI2 */
#define TIM_CCMR1_CC1S_TRC     (0x3U << TIM_CCMR1_CC1S_Pos) /* CC1 input mapped on TRC */

#define TIM_CCMR1_CC2S_Pos     8U
#define TIM_CCMR1_CC2S_Msk     (0x3U << TIM_CCMR1_CC2S_Pos)

#define TIM_CCMR1_CC2S_OUTPUT  (0x0U << TIM_CCMR1_CC2S_Pos) /* CC2 as output */
#define TIM_CCMR1_CC2S_TI2     (0x1U << TIM_CCMR1_CC2S_Pos) /* CC2 input mapped on TI2 */
#define TIM_CCMR1_CC2S_TI1     (0x2U << TIM_CCMR1_CC2S_Pos) /* CC2 input mapped on TI1 */
#define TIM_CCMR1_CC2S_TRC     (0x3U << TIM_CCMR1_CC2S_Pos) /* CC2 input mapped on TRC */

/* TIMx_CCMR1 (IC1PSC[1:0]) */
#define TIM_CCMR1_IC1PSC_Pos     2U
#define TIM_CCMR1_IC1PSC_Msk     (0x3U << TIM_CCMR1_IC1PSC_Pos)

#define TIM_CCMR1_IC1PSC_DIV1    (0x0U << TIM_CCMR1_IC1PSC_Pos) /* No prescaler, capture each edge */
#define TIM_CCMR1_IC1PSC_DIV2    (0x1U << TIM_CCMR1_IC1PSC_Pos) /* Capture every 2 events */
#define TIM_CCMR1_IC1PSC_DIV4    (0x2U << TIM_CCMR1_IC1PSC_Pos) /* Capture every 4 events */
#define TIM_CCMR1_IC1PSC_DIV8    (0x3U << TIM_CCMR1_IC1PSC_Pos) /* Capture every 8 events */

/* TIMx_CCMR1 (IC2PSC[1:0]) */
#define TIM_CCMR1_IC2PSC_Pos     10U
#define TIM_CCMR1_IC2PSC_Msk     (0x3U << TIM_CCMR1_IC2PSC_Pos)

#define TIM_CCMR1_IC2PSC_DIV1    (0x0U << TIM_CCMR1_IC2PSC_Pos) /* No prescaler, capture each edge */
#define TIM_CCMR1_IC2PSC_DIV2    (0x1U << TIM_CCMR1_IC2PSC_Pos) /* Capture every 2 events */
#define TIM_CCMR1_IC2PSC_DIV4    (0x2U << TIM_CCMR1_IC2PSC_Pos) /* Capture every 4 events */
#define TIM_CCMR1_IC2PSC_DIV8    (0x3U << TIM_CCMR1_IC2PSC_Pos) /* Capture every 8 events */

/* TIMx_CCMR1 (IC1F[3:0]) */
#define TIM_CCMR1_IC1F_Pos     4U
#define TIM_CCMR1_IC1F_Msk     (0xFU << TIM_CCMR1_IC1F_Pos)

#define TIM_CCMR1_IC1F_NOFILTER   (0x0U << TIM_CCMR1_IC1F_Pos)  /* No filter */
#define TIM_CCMR1_IC1F_FCKINT_N2  (0x1U << TIM_CCMR1_IC1F_Pos)  /* fSAMPLING=fCK_INT, N=2 */
#define TIM_CCMR1_IC1F_FCKINT_N4  (0x2U << TIM_CCMR1_IC1F_Pos)  /* fSAMPLING=fCK_INT, N=4 */
#define TIM_CCMR1_IC1F_FCKINT_N8  (0x3U << TIM_CCMR1_IC1F_Pos)  /* fSAMPLING=fCK_INT, N=8 */

/* TIMx_CCMR1 (IC2F[3:0]) */
#define TIM_CCMR1_IC2F_Pos       12U
#define TIM_CCMR1_IC2F_Msk       (0xFU << TIM_CCMR1_IC2F_Pos)

#define TIM_CCMR1_IC2F_NOFILTER   (0x0U << TIM_CCMR1_IC2F_Pos) /* No filter */
#define TIM_CCMR1_IC2F_FCKINT_N2  (0x1U << TIM_CCMR1_IC2F_Pos) /* fSAMPLING=fCK_INT, N=2 */
#define TIM_CCMR1_IC2F_FCKINT_N4  (0x2U << TIM_CCMR1_IC2F_Pos) /* fSAMPLING=fCK_INT, N=4 */
#define TIM_CCMR1_IC2F_FCKINT_N8  (0x3U << TIM_CCMR1_IC2F_Pos) /* fSAMPLING=fCK_INT, N=8 */

/* TIMx_CCER: (CC1P, CC1NP) */
#define TIM_CCER_CC1P_Pos     1U
#define TIM_CCER_CC1P_Msk     (1U << TIM_CCER_CC1P_Pos)

#define TIM_CCER_CC1NP_Pos    3U
#define TIM_CCER_CC1NP_Msk    (1U << TIM_CCER_CC1NP_Pos)

#define TIM_CCER_POLARITY_RISING   (0U)                                      /* 00: rising */
#define TIM_CCER_POLARITY_FALLING  (TIM_CCER_CC1P_Msk)                       /* 01: falling */
#define TIM_CCER_POLARITY_BOTH     (TIM_CCER_CC1P_Msk | TIM_CCER_CC1NP_Msk)  /* 11: both */

/* TIMx_CCER (CC2P, CC2NP) */
#define TIM_CCER_CC2P_Pos     5U
#define TIM_CCER_CC2P_Msk     (1U << TIM_CCER_CC2P_Pos)

#define TIM_CCER_CC2NP_Pos    7U
#define TIM_CCER_CC2NP_Msk    (1U << TIM_CCER_CC2NP_Pos)

#define TIM_CCER_POLARITY2_RISING   (0U)                                      /* 00: rising */
#define TIM_CCER_POLARITY2_FALLING  (TIM_CCER_CC2P_Msk)                       /* 01: falling */
#define TIM_CCER_POLARITY2_BOTH     (TIM_CCER_CC2P_Msk | TIM_CCER_CC2NP_Msk)  /* 11: both */


#endif /* MCAL_TIM_IC_TIM_IC_PRV_H_ */
