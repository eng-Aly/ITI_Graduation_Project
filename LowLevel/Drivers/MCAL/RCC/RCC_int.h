/*
 * RCC_int.h
 *
 *  Created on: Aug 14, 2025
 *      Author: pc
 *      Version: 0.1
 */

#ifndef MCAL_RCC_INT_H_
#define MCAL_RCC_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "RCC_prv.h"
#include "RCC_cfg.h"

/* Buses */
#define RCC_AHB1	0
#define RCC_AHB2	1
#define RCC_APB1	2
#define RCC_APB2	3

/* ------- Peripherals --------*/
// Bus : RCC_AHB1
#define RCC_GPIOA	0
#define RCC_GPIOB	1

/*********** AHB1 peripheral clock enable register ***************/

#define RCC_EN_GPIOA     0
#define RCC_EN_GPIOB     1
#define RCC_EN_GPIOC     2
#define RCC_EN_GPIOD     3
#define RCC_EN_GPIOE     4
#define RCC_EN_GPIOH     7
#define RCC_EN_CRC	     12
#define RCC_EN_DMA1      21
#define RCC_EN_DMA2      22


/********* APB1 peripheral clock enable register *********/

#define RCC_EN_TIM2						0
#define RCC_EN_TIM3						1
#define RCC_EN_TIM4						2
#define RCC_EN_TIM5					    3
#define RCC_EN_TIM6						4
#define RCC_EN_TIM7						5
#define RCC_EN_TIM12					6
#define RCC_EN_TIM13					7
#define RCC_EN_TIM14					8
#define RCC_EN_WWDG						11
#define RCC_EN_SPI2						14
#define RCC_EN_SPI3						15
#define RCC_EN_UART2					17
#define RCC_EN_UART3					18
#define RCC_EN_UART4					19
#define RCC_EN_UART5					20
#define RCC_EN_I2C1						21
#define RCC_EN_I2C2						22
#define RCC_EN_I2C3						23
#define RCC_EN_CAN1						25
#define RCC_EN_CAN2						26
#define RCC_EN_PWR						28
#define RCC_EN_DAC						29



/********** APB2 peripheral clock enable register (RCC_APB2ENR) *********/

#define RCC_EN_TIM1  				 0
#define RCC_EN_TIM8					 1
#define RCC_EN_USART1				 4
#define RCC_EN_USART6				 5
#define RCC_EN_ADC1					 8
#define RCC_EN_ADC2					 9
#define RCC_EN_ADC3					 10
#define RCC_EN_SDIO					 11
#define RCC_EN_SPI1					 12
#define RCC_EN_SYSCFG				 14
#define RCC_EN_TIM9					 16
#define RCC_EN_TIM10			     17
#define RCC_EN_TIM11 				 18


void MRCC_vInit(void);
void MRCC_vEnableClk(u8 A_u8BusID, u8 A_u8PeripheralID);
void MRCC_vDisableClk(u8 A_u8BusID, u8 A_u8PeripheralID);

#endif /* MCAL_RCC_INT_H_ */
