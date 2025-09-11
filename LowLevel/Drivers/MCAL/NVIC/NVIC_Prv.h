#ifndef NVIC_PRV_H_
#define NVIC_PRV_H_

#include "../../LIB/STD_TYPES.h"

#define NVIC_BASE               							(0xE000E100UL)

#define NVIC_ISER0_BASE        								(*(volatile u32 *)(NVIC_BASE + 0x00))
#define NVIC_ISER1_BASE         							(*(volatile u32 *)(NVIC_BASE + 0x04))
#define NVIC_ISER2_BASE        						        (*(volatile u32 *)(NVIC_BASE + 0x08))
#define NVIC_ICER0_BASE         							(*(volatile u32 *)(NVIC_BASE + 0x80))
#define NVIC_ICER1_BASE         						  	(*(volatile u32 *)(NVIC_BASE + 0x84))
#define NVIC_ICER2_BASE         							(*(volatile u32 *)(NVIC_BASE + 0x88))


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

// Enable
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

#endif /* NVIC_PRV_H_ */
