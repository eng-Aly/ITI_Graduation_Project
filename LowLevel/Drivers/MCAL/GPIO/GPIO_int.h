/*
 * GPIO_int.h
 *
 *  Created on: Aug 14, 2025
 *      Author: pc
 *      Version: 0.1
 */

#ifndef MCAL_GPIO_INT_H_
#define MCAL_GPIO_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "GPIO_prv.h"
#include "GPIO_cfg.h"

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

/* Mode */
#define GPIO_MODE_INPUT	 0b00
#define GPIO_MODE_OUTPUT 0b01
#define GPIO_MODE_ALF	 0b10
#define GPIO_MODE_ANALOG 0b11

/* Output type */
#define GPIO_OUT_PUSHPULL	0
#define GPIO_OUT_OPENDREAIN	1

/* Pin value*/
#define GPIO_HIGH	1
#define GPIO_LOW	0

/*output Speed*/
#define GPIO_SPEED_LOW		0b00
#define GPIO_SPEED_MED		0b01
#define GPIO_SPEED_HIGH		0b10
#define GPIO_SPEED_VHIGH	0b11

/* Pull type */
#define GPIO_NO_PULL		0b00
#define GPIO_PULL_UP		0b01
#define GPIO_PULL_DOWN		0b10

/* Ports */
#define GPIO_PORTA	0
#define GPIO_PORTB	1
#define GPIO_PORTC	2

/* Pins */
#define GPIO_PIN0	0
#define GPIO_PIN1	1
#define GPIO_PIN2	2
#define GPIO_PIN3	3
#define GPIO_PIN4	4
#define GPIO_PIN5	5
#define GPIO_PIN6	6
#define GPIO_PIN7	7
#define GPIO_PIN8	8
#define GPIO_PIN9	9
#define GPIO_PIN10	10
#define GPIO_PIN11	11
#define GPIO_PIN12	12
#define GPIO_PIN13	13
#define GPIO_PIN14	14
#define GPIO_PIN15	15

/* Alternate function selection for port x */
#define GPIO_AF0			0
#define GPIO_AF1			1
#define AF2			2
#define AF3			3
#define AF4			4
#define AF5			5
#define AF6			6

#define GPIO_AF7			7
#define AF8			8
#define AF9			9
#define AF10		10
#define AF11		11
#define AF12		12
#define AF13		13
#define AF14		14
#define AF15		15

void MGPIO_vPinInit(GPIOx_PinConfig_t* A_xPinCfg);
void MGPIO_vSetMode(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8Mode);
void MGPIO_vSetOutputType(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8OutputType);
void MGPIO_vSetOutputSpeed(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8OutputSpeed);
void MGPIO_vSetPULLType(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8PushPull);
void MGPIO_vSetPinValue(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8Value);
u8 MGPIO_u8GetPinValue(u8 A_u8PortID, u8 A_u8PinNum);
void MGPIO_vSetAlt(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8AFx);
void MGPIO_vSetPinValueAtomic(u8 A_u8PortID, u8 A_u8PinNum, u8 A_u8Value);
void MGPIO_TogPinValue(u8 A_u8PortID, u8 A_u8PinNum);

#endif /* MCAL_GPIO_INT_H_ */
