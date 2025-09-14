/*
    TCRT5000_int.h
    Library for using TCRT5000 IR Reflective Optical Sensor Module with Interrupts
    Date: 2025-09-09
    Author: Moamen Elwazan
    Version: 0.1
*/
#ifndef TCRT5000_INT_H
#define TCRT5000_INT_H

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h" 

void TCRT5000_Init(u8 GPIO_PORTx[2], u8 GPIO_PINx[2]);
u8 TCRT5000_ReadDigital(void);

#endif // TCRT5000_INT_H