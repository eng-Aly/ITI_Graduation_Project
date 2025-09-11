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

#define GPIO_AF0	0b0000
#define GPIO_AF1	0b0001
#define GPIO_AF2	0b0010
#define GPIO_AF3	0b0011
#define GPIO_AF4	0b0100
#define GPIO_AF5	0b0101
#define GPIO_AF6	0b0110
#define GPIO_AF7	0b0111
#define GPIO_AF8	0b1000
#define GPIO_AF9	0b1001
#define GPIO_AF10	0b1010
#define GPIO_AF11	0b1011
#define GPIO_AF12	0b1100
#define GPIO_AF13	0b1101
#define GPIO_AF14	0b1110
#define GPIO_AF15	0b1111

#endif 