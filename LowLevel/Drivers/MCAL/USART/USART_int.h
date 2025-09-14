/*
 * USART_int.h
 *
 *  Created on: Sep 1, 2025
 *      Author: pc
 */

#ifndef MCAL_USART_USART_INT_H_
#define MCAL_USART_USART_INT_H_
#include "../../LIB/STD_TYPES.h"
void MUSART_vInit(void);
void MUSART_vSendData(u8 A_u8Data);
u8   MUSART_u8ReceiveData();

void MUSART_vSendString(char* A_u8ptrStr);
u8* MUSART_u8ptrReceiveString(void);
void MUSART_vUSARTCallback(u8 A_u8USARTNo, void(*Fptr)(void));


#endif /* MCAL_USART_USART_INT_H_ */
