/*
 * RCC_prv.h
 *
 *  Created on: Aug 14, 2025
 *      Author: pc
 *      Version: 0.1
 */

#ifndef MCAL_RCC_PRV_H_
#define MCAL_RCC_PRV_H_

#define RCC_BASE_ADDR 		0x40023800U

typedef struct{
	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;

	u32 Reserved1;
	u32 Reserved2;

	u32 APB1RSTR;
	u32 APB2RSTR;

	u32 Reserved3;
	u32 Reserved4;

	u32 AHB1ENR;
	u32 AHB2ENR;

	u32 Reserved5;
	u32 Reserved6;

	u32 APB1ENR;
	u32 APB2ENR;

	u32 Reserved7;
	u32 Reserved8;

	u32 AHB1LPENR;
	u32 AHB2LPENR;

	u32 Reserved9;
	u32 Reserved10;

	u32 APB1LPENR;
	u32 APB2LPENR;

	u32 Reserved11;
	u32 Reserved12;

	u32 BDCR;
	u32 CSR;

	u32 Reserved13;
	u32 Reserved14;

	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 DCKCFGR;


}RCC_MemMap_t;


#define RCC 				((volatile RCC_MemMap_t*)(RCC_BASE_ADDR))


/* RCC_SYS_CLK --- options --- */
#define HSE_CLK		1
#define HSI_CLK		2
#define PLL_CLK		3

/* HSE_BYPASS --- options --- */
#define RC_CLK			0
#define MECHANICAL_CLK  1




/* Resigters */

#define HSEBYP		18

#define GPIOAEN		0
#define GPIOBEN		1




//ENABLE
#define RCC_SYSCFG_CLK_EN()					(RCC->APB2ENR |= (1 << 14))

#define RCC_GPIOA_CLK_EN()					(RCC->AHB1ENR |= (1 << 0))
#define RCC_GPIOB_CLK_EN()					(RCC->AHB1ENR |= (1 << 1))
#define RCC_GPIOC_CLK_EN()					(RCC->AHB1ENR |= (1 << 2))
#define RCC_GPIOD_CLK_EN()					(RCC->AHB1ENR |= (1 << 3))
#define RCC_GPIOE_CLK_EN()					(RCC->AHB1ENR |= (1 << 4))
#define RCC_GPIOH_CLK_EN()					(RCC->AHB1ENR |= (1 << 7))

#define RCC_USART1_CLK_EN()					(RCC->APB2ENR |= (1 << 4))
#define RCC_USART2_CLK_EN()					(RCC->APB1ENR |= (1 << 17))
#define RCC_USART6_CLK_EN()					(RCC->APB2ENR |= (1 << 5))

#define RCC_SPI1_CLK_EN()					(RCC->APB2ENR |= (1 << 12))
#define RCC_SPI2_CLK_EN()					(RCC->APB1ENR |= (1 << 14))
#define RCC_SPI3_CLK_EN()					(RCC->APB1ENR |= (1 << 15))

#define RCC_TIMER1_CLK_EN()					(RCC->APB2ENR |= (1 << 0))
#define RCC_TIMER2_CLK_EN()					(RCC->APB1ENR |= (1 << 0))
#define RCC_TIMER3_CLK_EN()					(RCC->APB1ENR |= (1 << 1))
#define RCC_TIMER4_CLK_EN()					(RCC->APB1ENR |= (1 << 2))
#define RCC_TIMER5_CLK_EN()					(RCC->APB1ENR |= (1 << 3))


// Reset
#define RCC_SYSCFG_CLK_RST_SET()			(RCC->APB2RSTR |= (1 << 14))

#define RCC_GPIOA_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 0))
#define RCC_GPIOB_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 1))
#define RCC_GPIOC_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 2))
#define RCC_GPIOD_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 3))
#define RCC_GPIOE_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 4))
#define RCC_GPIOH_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 4))

#define RCC_USART1_CLK_RST_SET()			(RCC->APB2RSTR |= (1 << 4))
#define RCC_USART2_CLK_RST_SET()			(RCC->APB1RSTR |= (1 << 17))
#define RCC_USART6_CLK_RST_SET()			(RCC->APB2RSTR |= (1 << 5))

#define RCC_SPI1_CLK_RST_SET()				(RCC->APB2RSTR |= (1 << 12))
#define RCC_SPI2_CLK_RST_SET()				(RCC->APB1RSTR |= (1 << 14))
#define RCC_SPI3_CLK_RST_SET()				(RCC->APB1RSTR |= (1 << 15))

#define RCC_TIMER1_CLK_RST_SET()			(RCC->APB2RSTR |= (1 << 0))
#define RCC_TIMER2_CLK_RST_SET()			(RCC->APB1RSTR |= (1 << 0))
#define RCC_TIMER3_CLK_RST_SET()			(RCC->APB1RSTR |= (1 << 1))
#define RCC_TIMER4_CLK_RST_SET()			(RCC->APB1RSTR |= (1 << 2))
#define RCC_TIMER5_CLK_RST_SET()			(RCC->APB1RSTR |= (1 << 3))


#endif /* MCAL_RCC_PRV_H_ */
