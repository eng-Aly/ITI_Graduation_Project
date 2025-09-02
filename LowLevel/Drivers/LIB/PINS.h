#ifndef LIB_PINS_H
#define LIB_PINS_H

#include "STD_TYPES.h"

typedef struct
{
	u8 Port;
	u8 Pin;
	u8 Mode;
	u8 OutputType;
	u8 Speed;
	u8 PullType;
	u8 Altfunc;
}GPIOx_PinConfig_t;

//Example
#define PA1   GPIOx_PinConfig_t{GPIOA, 1, GPIO_MODE_OUTPUT, GPIO_OUTPUT_PP, GPIO_SPEED_2MHZ, GPIO_PULLUP, 0}


#endif



/*=================================================================================================*/
/*CONSIDER REMAPPING PINS OF THE ST TO THE DEVELOPMENT BOARD OUTPUT */
/*EXAMPLE:GPIO_PinMode(port,pin,mode)->GPIO_PinMode(pin)*/
/*==================================================================================================*/