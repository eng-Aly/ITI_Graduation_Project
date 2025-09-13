/*
 * NVIC_int.h
 *
 *  Created on: Aug 19, 2025
 *      Author: Nada Mamdouh
 *      Version: 0.0
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

typedef enum{
	Group16Sub0 = 3,
	Group8Sub2,
	Group4Sub4,
	Group2Sub8,
	Group0Sub16
}NVIC_Group_t;

void MNVIC_vEnable_Peripheral_INT(u8 A_u8Position);
void MNVIC_vDisable_Peripheral_INT(u8 A_u8Position);

void MNVIC_vSetPendingFlag(u8 A_u8Position);
void MNVIC_vCLRPendingFlag(u8 A_u8Position);
u8 MNVIC_u8GETFlagStatus(u8 A_u8Position);

void MNVIC_vSetGroupPriority(NVIC_Group_t A_xGroupPriority);
void MNVIC_vSetPeripheralPeriority(u8 A_u8Position, u8 A_u8Group, u8 A_u8SubGroup);


/***************************************************************************************
	| IRQ Number | Position in NVIC                                  | Interrupt Source |
	| ---------- | ------------------------------------------------- | ---------------- |
	| 0–15       | Cortex-M exceptions (Reset, NMI, HardFault, etc.) |                  |
	| 6          | EXTI Line0 interrupt (for PA0, PB0, PC0, …)       |                  |
	| 7          | EXTI Line1                                        |                  |
	| 8          | EXTI Line2                                        |                  |
	| 9          | EXTI Line3                                        |                  |
	| 10         | EXTI Line\[4]                                     |                  |
	| 23         | EXTI Line\[9:5]                                   |                  |
	| 40         | EXTI Line\[15:10]                                 |                  |
 ***************************************************************************************/



/* NVIC IRQ numbers (vector table positions) */

#define NVIC_IRQ_WWDG        0
#define NVIC_IRQ_EXTI0       6
#define NVIC_IRQ_EXTI1       7
#define NVIC_IRQ_EXTI2       8
#define NVIC_IRQ_EXTI3       9
#define NVIC_IRQ_EXTI4       10
#define NVIC_IRQ_DMA1_Stream0 11
#define NVIC_IRQ_TIM2       28
#define NVIC_IRQ_TIM3       29
#define NVIC_IRQ_TIM4       30
#define NVIC_IRQ_TIM5       50



#endif /* MCAL_NVIC_NVIC_INT_H_ */
