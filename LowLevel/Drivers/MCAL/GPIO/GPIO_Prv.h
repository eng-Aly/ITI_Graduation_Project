#ifndef GPIO_PRV_H_	
#define GPIO_PRV_H_

#include "../../LIB/STD_TYPES.h"
#include "../RCC/RCC_Int.h"

typedef struct{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFR[2];
}GPIO_TypeDef;


#define GPIOA_BASE											0x40020000UL
#define GPIOB_BASE											0x40020400UL
#define GPIOC_BASE											0x40020800UL
#define GPIOD_BASE											0x40020C00UL
#define GPIOE_BASE											0x40021000UL
#define GPIOH_BASE											0x40021C00UL

#define GPIOA								((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB								((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC								((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD								((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE								((GPIO_TypeDef *)GPIOE_BASE)


#define GPIO_MODE_IP								0x00000000u      // Input (reset state)
#define GPIO_MODE_OP								0x00000001u      // General purpose output mode
#define GPIO_MODE_AF								0x00000002u      // Alternate function mode
#define GPIO_MODE_Analog							0x00000003u      // Analog mode


#define RCC_GPIOA_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 0))
#define RCC_GPIOB_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 1))
#define RCC_GPIOC_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 2))
#define RCC_GPIOD_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 3))
#define RCC_GPIOE_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 4))
#define RCC_GPIOH_CLK_RST_SET()				(RCC->AHB1RSTR |= (1 << 4))

#endif 