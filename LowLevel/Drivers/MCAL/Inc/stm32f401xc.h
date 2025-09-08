/*
 * stm32f401xc.h
 *
 * Created on: Jul 19, 2025
 * Author: Ahmed Ezzat
 */

#ifndef STM32F401XC_H_
#define STM32F401XC_H_

//------------------------------
// Includes
//------------------------------
#include "Platforms_Types.h"

//------------------------------
// Base Addresses for Memories
//------------------------------
#define SYSTEM_MEMORY_BASE									0x1FFF0000UL
#define FLASH_MEMORY_BASE									0x08000000UL
#define SRAM_MEMORY_BASE								    0x20000000UL

#define Peripherals_BASE									0x40000000UL

#define Cortex_M4_Internal_Peripherals_BASE					0xE0000000UL

#define SysTicK_BASE										0xE000E010UL

//-----------------------------
//Base addresses for NVIC
//-----------------------------
#define NVIC_BASE               							(0xE000E100UL)

#define NVIC_ISER0_BASE        								(*(volatile uint32_t *)(NVIC_BASE + 0x00))
#define NVIC_ISER1_BASE         							(*(volatile uint32_t *)(NVIC_BASE + 0x04))
#define NVIC_ISER2_BASE        						        (*(volatile uint32_t *)(NVIC_BASE + 0x08))

#define NVIC_ICER0_BASE         							(*(volatile uint32_t *)(NVIC_BASE + 0x80))
#define NVIC_ICER1_BASE         						  	(*(volatile uint32_t *)(NVIC_BASE + 0x84))
#define NVIC_ICER2_BASE         							(*(volatile uint32_t *)(NVIC_BASE + 0x88))




//============================================================

//-----------------------------------------------------
// Base Addresses for Bus Peripherals
//-----------------------------------------------------

//---------------------------------------
// Base Addresses for AHB1 Peripherals
//---------------------------------------

// RCC
#define RCC_BASE											0x40023800UL

//---------------------------------------
// Base Addresses for APB1 Peripherals
//---------------------------------------

// USART 2
#define USART2_BASE											0x40004400UL

// SPI 2 & 3
#define SPI2_BASE											0x40003800UL
#define SPI3_BASE											0x40003C00UL

// TIMER 2 & 3 & 4 & 5
#define TIMER2_BASE											0x40000000UL
#define TIMER3_BASE											0x40000400UL
#define TIMER4_BASE											0x40000800UL
#define TIMER5_BASE											0x40000C00UL

//---------------------------------------
// Base Addresses for APB2 Peripherals
//---------------------------------------

// SYSCFG BASE
#define SYSCFG_BASE											0x40013800UL

// GPIO
// A,B fully included in LQFP48 package
#define GPIOA_BASE											0x40020000UL
#define GPIOB_BASE											0x40020400UL
// C partial included in LQFP48 package
#define GPIOC_BASE											0x40020800UL
// E,D,H not included in LQFP48 package
#define GPIOD_BASE											0x40020C00UL
#define GPIOE_BASE											0x40021000UL
#define GPIOH_BASE											0x40021C00UL

// EXTI
#define EXTI_BASE											0x40013C00UL

// USART 1 & 6
#define USART1_BASE											0x40011000UL
#define USART6_BASE											0x40011400UL

// SPI 1
#define SPI1_BASE											0x40013000UL
#define SPI4_BASE											0x40013400UL

// TIMER 1
#define TIMER1_BASE											0x40010000UL

//---------------------------------------
// Base Addresses for AHB2 Peripherals
//---------------------------------------

//============================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: SysTick
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	 volatile uint32_t CTRL	 ;
	 volatile uint32_t LOAD	 ;
	 volatile uint32_t VAL	 ;
	 volatile uint32_t CALIB ;

}SysTick_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: SYSCFG
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CMPCR;
}SYSCFG_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
			 uint32_t RESERVED0;
			 uint32_t RESERVED1;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	 	 	 uint32_t RESERVED2;
	 	 	 uint32_t RESERVED3;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
			 uint32_t RESERVED4;
			 uint32_t RESERVED5;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
			 uint32_t RESERVED6;
			 uint32_t RESERVED7;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
		     uint32_t RESERVED8;
		     uint32_t RESERVED9;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
		 	 uint32_t RESERVED10;
		 	 uint32_t RESERVED11;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
		 	 uint32_t RESERVED12;
		 	 uint32_t RESERVED13;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	 	 	 uint32_t RESERVED14;
	volatile uint32_t DCKCFGR;
}RCC_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: USART
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
}USART_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: SPI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t CR1		;
	volatile uint32_t CR2		;
	volatile uint32_t SR		;
	volatile uint32_t DR		;
	volatile uint32_t CRCPR		;
	volatile uint32_t RXCRCR	;
	volatile uint32_t TXCRCR	;
	volatile uint32_t I2SCFGR	;
	volatile uint32_t I2SPR	;
}SPI_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Register: TIMERS
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef struct{
	volatile uint32_t CR1		;
	volatile uint32_t CR2		;
	volatile uint32_t SMCR		;
	volatile uint32_t DIER		;
	volatile uint32_t SR		;
	volatile uint32_t EGR		;
	volatile uint32_t CCMR1		;
	volatile uint32_t CCMR2		;
	volatile uint32_t CCER		;
	volatile uint32_t CNT		;
	volatile uint32_t PSC		;
	volatile uint32_t ARR		;
	volatile uint32_t RCR		;
	volatile uint32_t CCR1		;
	volatile uint32_t CCR2		;
	volatile uint32_t CCR3		;
	volatile uint32_t CCR4		;
	volatile uint32_t BDTR		;
	volatile uint32_t DCR		;
	volatile uint32_t DMAR		;
}TIMER_TypeDef;

//============================================================

//-*-*-*-*-*-*-*-*-*-*-*-
// Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-
#define SysTick								((SysTick_Typedef *)SysTicK_BASE)

#define SYSCFG								((SYSCFG_Typedef *)SYSCFG_BASE)

#define RCC									((RCC_TypeDef *)RCC_BASE)

#define GPIOA								((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB								((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC								((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD								((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE								((GPIO_TypeDef *)GPIOE_BASE)

#define EXTI								((EXTI_TypeDef *)EXTI_BASE)

#define AFIO								((AFIO_TypeDef *)AFIO_BASE)

#define USART1								((USART_TypeDef *)USART1_BASE)
#define USART2								((USART_TypeDef *)USART2_BASE)
#define USART6								((USART_TypeDef *)USART6_BASE)

#define SPI1								((SPI_Typedef *)SPI1_BASE)
#define SPI2								((SPI_Typedef *)SPI2_BASE)
#define SPI3								((SPI_Typedef *)SPI3_BASE)

#define TIMER1								((TIMER_TypeDef *)TIMER1_BASE)
#define TIMER2								((TIMER_TypeDef *)TIMER2_BASE)
#define TIMER3								((TIMER_TypeDef *)TIMER3_BASE)
#define TIMER4								((TIMER_TypeDef *)TIMER4_BASE)
#define TIMER5								((TIMER_TypeDef *)TIMER5_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
// Clock Enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-

// Clock Enable
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

//-*-*-*-*-
// IVT
//-*-*-*-*-
// EXTI
#define EXTI0_IRQ			6
#define EXTI1_IRQ			7
#define EXTI2_IRQ			8
#define EXTI3_IRQ			9
#define EXTI4_IRQ			10
#define EXTI5_IRQ			23
#define EXTI6_IRQ			23
#define EXTI7_IRQ			23
#define EXTI8_IRQ			23
#define EXTI9_IRQ			23
#define EXTI10_IRQ			40
#define EXTI11_IRQ			40
#define EXTI12_IRQ			40
#define EXTI13_IRQ			40
#define EXTI14_IRQ			40
#define EXTI15_IRQ			40

// USART
#define USART1_IRQ			37
#define USART2_IRQ			38
#define USART6_IRQ			71

#define SPI1_IRQ			35
#define SPI2_IRQ			36
#define SPI3_IRQ			51
#define SPI4_IRQ			84

#define TIMER1_BRK_IRQ		24
#define TIMER1_UP_IRQ		25
#define TIMER1_TRIG_COM_IRQ	26
#define TIMER1_CC_IRQ		27
#define TIMER2_IRQ			28
#define TIMER3_IRQ			29
#define TIMER4_IRQ			30
#define TIMER5_IRQ			50

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//NVIC IRQ Enable/Disable macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
// Enable
#define NVIC_IRQ6_EXTI0_EN()				(NVIC_ISER0_BASE |= (1 << 6))
#define NVIC_IRQ7_EXTI1_EN()				(NVIC_ISER0_BASE |= (1 << 7))
#define NVIC_IRQ8_EXTI2_EN()				(NVIC_ISER0_BASE |= (1 << 8))
#define NVIC_IRQ9_EXTI3_EN()				(NVIC_ISER0_BASE |= (1 << 9))
#define NVIC_IRQ10_EXTI4_EN()				(NVIC_ISER0_BASE |= (1 << 10))
#define NVIC_IRQ23_EXTI_5_9_EN()			(NVIC_ISER0_BASE |= (1 << 23))
#define NVIC_IRQ40_EXTI_10_15_EN()			(NVIC_ISER1_BASE |= (1 << 8))

#define NVIC_IRQ_USART1_EN()				(NVIC_ISER1_BASE |= (1 << (USART1_IRQ - 32)))
#define NVIC_IRQ_USART2_EN()				(NVIC_ISER1_BASE |= (1 << (USART2_IRQ - 32)))
#define NVIC_IRQ_USART6_EN()				(NVIC_ISER2_BASE |= (1 << (USART6_IRQ - 64)))

#define NVIC_IRQ_SPI1_EN()					(NVIC_ISER1_BASE |= (1 << (SPI1_IRQ - 32)))
#define NVIC_IRQ_SPI2_EN()					(NVIC_ISER1_BASE |= (1 << (SPI2_IRQ - 32)))
#define NVIC_IRQ_SPI3_EN()					(NVIC_ISER1_BASE |= (1 << (SPI3_IRQ - 32)))
#define NVIC_IRQ_SPI4_EN()					(NVIC_ISER2_BASE |= (1 << (SPI4_IRQ - 64)))

#define NVIC_IRQ_TIMER1_BRK_EN()			(NVIC_ISER0_BASE |= (1 << 24))
#define NVIC_IRQ_TIMER1_UP_EN()				(NVIC_ISER0_BASE |= (1 << 25))
#define NVIC_IRQ_TIMER1_TRIG_COM_EN()		(NVIC_ISER0_BASE |= (1 << 26))
#define NVIC_IRQ_TIMER1_CC_EN()				(NVIC_ISER0_BASE |= (1 << 27))
#define NVIC_IRQ_TIMER2_EN()				(NVIC_ISER0_BASE |= (1 << 28))
#define NVIC_IRQ_TIMER3_EN()				(NVIC_ISER0_BASE |= (1 << 29))
#define NVIC_IRQ_TIMER4_EN()				(NVIC_ISER0_BASE |= (1 << 30))
#define NVIC_IRQ_TIMER5_EN()				(NVIC_ISER1_BASE |= (1 << (TIMER5_IRQ - 32)))

// Disable
#define NVIC_IRQ6_EXTI0_DIS()				(NVIC_ICER0_BASE |= (1 << 6))
#define NVIC_IRQ7_EXTI1_DIS()				(NVIC_ICER0_BASE |= (1 << 7))
#define NVIC_IRQ8_EXTI2_DIS()				(NVIC_ICER0_BASE |= (1 << 8))
#define NVIC_IRQ9_EXTI3_DIS()				(NVIC_ICER0_BASE |= (1 << 9))
#define NVIC_IRQ10_EXTI4_DIS()			    (NVIC_ICER0_BASE |= (1 << 10))
#define NVIC_IRQ23_EXTI_5_9_DIS()			(NVIC_ICER0_BASE |= (1 << 23))
#define NVIC_IRQ40_EXTI_10_15_DIS()			(NVIC_ICER1_BASE |= (1 << 8))

#define NVIC_IRQ_USART1_DIS()				(NVIC_ICER1_BASE |= (1 << (USART1_IRQ - 32)))
#define NVIC_IRQ_USART2_DIS()				(NVIC_ICER1_BASE |= (1 << (USART2_IRQ - 32)))
#define NVIC_IRQ_USART6_DIS()				(NVIC_ICER2_BASE |= (1 << (USART6_IRQ - 64)))

#define NVIC_IRQ_SPI1_DIS()					(NVIC_ICER1_BASE |= (1 << (SPI1_IRQ - 32)))
#define NVIC_IRQ_SPI2_DIS()					(NVIC_ICER1_BASE |= (1 << (SPI2_IRQ - 32)))
#define NVIC_IRQ_SPI3_DIS()					(NVIC_ICER1_BASE |= (1 << (SPI3_IRQ - 32)))
#define NVIC_IRQ_SPI4_DIS()					(NVIC_ICER2_BASE |= (1 << (SPI1_IRQ - 64)))

#define NVIC_IRQ_TIMER1_BRK_DIS()			(NVIC_ICER0_BASE |= (1 << 24))
#define NVIC_IRQ_TIMER1_UP_DIS()			(NVIC_ICER0_BASE |= (1 << 25))
#define NVIC_IRQ_TIMER1_TRIG_COM_DIS()		(NVIC_ICER0_BASE |= (1 << 26))
#define NVIC_IRQ_TIMER1_CC_DIS()			(NVIC_ICER0_BASE |= (1 << 27))
#define NVIC_IRQ_TIMER2_DIS()				(NVIC_ICER0_BASE |= (1 << 28))
#define NVIC_IRQ_TIMER3_DIS()				(NVIC_ICER0_BASE |= (1 << 29))
#define NVIC_IRQ_TIMER4_DIS()				(NVIC_ICER0_BASE |= (1 << 30))
#define NVIC_IRQ_TIMER5_DIS()				(NVIC_ICER1_BASE |= (1 << (TIMER5_IRQ - 32)))

//-*-*-*-*-*-*-*-*-*-*-*-
// Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-
#define ENABLE						1
#define DISABLE						0

#define HIGH						1
#define LOW							0

#define GET_BIT(VAL, BIT) 			((VAL >> BIT) & 1)

#endif
