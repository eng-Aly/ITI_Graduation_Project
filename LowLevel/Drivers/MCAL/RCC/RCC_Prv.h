#ifndef RCC_PRV_H_
#define RCC_PRV_H_
#include "../../LIB/STD_TYPES.h"



typedef struct{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
			 u32 RESERVED0;
			 u32 RESERVED1;
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	 	 	 u32 RESERVED2;
	 	 	 u32 RESERVED3;
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
			 u32 RESERVED4;
			 u32 RESERVED5;
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
			 u32 RESERVED6;
			 u32 RESERVED7;
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
		     u32 RESERVED8;
		     u32 RESERVED9;
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
		 	 u32 RESERVED10;
		 	 u32 RESERVED11;
	volatile u32 BDCR;
	volatile u32 CSR;
		 	 u32 RESERVED12;
		 	 u32 RESERVED13;
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	 	 	 u32 RESERVED14;
	volatile u32 DCKCFGR;
}RCC_TypeDef;

#define RCC_BASE											0x40023800UL
#define RCC													((RCC_TypeDef *)RCC_BASE)

//ENABLE

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

#endif /* RCC_PRV_H_ */