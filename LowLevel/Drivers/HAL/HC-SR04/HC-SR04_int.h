/*
 * HC-SR04_int.h
 *
 *  Created on: Sep 8, 2025
 *      Author: pc
 */

#ifndef HAL_HC_SR04_HC_SR04_INT_H_
#define HAL_HC_SR04_HC_SR04_INT_H_


#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_int.h"
#include "../../MCAL/TIM_IC/TIM_IC_int.h"

typedef struct {
    // Trigger pin
	u8 TriggerPort;
	u8 TriggerPin;

	// Echo pin
	u8 EchoPort;
	u8 EchoPin;

	u8 EchoAF;           // AF1 (TIM2) or AF2

	// Timer capture
	TIM_Id_t TimerId;
	TIM_Channel_t Channel;

    volatile u32 IC_Value1;
    volatile u32 IC_Value2;
    volatile u32 IC_Diff;
    volatile u32  isRisingCaptured;
    volatile u8  isReady;
    volatile u16 distance_cm;
    volatile u8 first_capture;
} HCSR04_Handle_t;


/* Initializes ultrasonic sensor (GPIO + timer IC setup) */
void HCSR04_vInit(HCSR04_Handle_t *hcsr);

/* Triggers the ultrasonic sensor (sends 10 µs pulse) */
void HCSR04_vTrigger(HCSR04_Handle_t *hcsr);

/* Measures distance in centimeters */
u32 HCSR04_u32GetDistance();
//global u32 hcsr;




#endif /* HAL_HC_SR04_HC_SR04_INT_H_ */
