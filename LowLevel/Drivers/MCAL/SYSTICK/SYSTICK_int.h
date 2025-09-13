/*
 * SYSTICK_int.h
 *
 *  Created on: Aug 21, 2025
 *      Author: Mo'men
 */

#ifndef MCAL_SYSTICK_SYSTICK_INT_H_
#define MCAL_SYSTICK_SYSTICK_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "SYSTICK_prv.h"
#include "SYSTICK_cfg.h"

u16 GTicks_ms; // Global variable to hold the number of ticks in milliseconds

typedef struct {
    u8  InterruptEnable;     // Enable or disable the interrupt
    u8  CLK_SRC;             // ClK_SRC_AHB or ClK_SRC_AHB_DIV_8
    u32 LoadValue;          // Load value for the Systick timer
}MSYSTICK_Config_t;


void MSYSTICK_vInit(MSYSTICK_Config_t *A_xCfg);

void MSYSTICK_vStartTimer(u32 A_u32LoadValue);

void MSYSTICK_vStopTimer(void);

void MSYSTICK_vSetDelay_us(u32 A_u32Delay_us);
void MSYSTICK_vSetDelay_ms(u32 A_u32Delay_ms);
void MSYSTICK_vSetInterval_Single(u32 A_u32Delay_ms, void(*A_xFptr)(void));
void MSYSTICK_vSetInterval_Multi(u32 A_u32Delay_ms, void(*A_xFptr)(void));

u32 MSYSTICK_u32GetElapsedTime_SingleShot(void);
u32 MSYSTICK_u32GetRemainingTime_SingleShot(void);

// Interrupt enable/disable options
#define INT_ENABLE          1
#define INT_DISABLE         0

// Clock source options
#define ClK_SRC_AHB         1
#define ClK_SRC_AHB_DIV_8   0

#endif /* MCAL_SYSTICK_SYSTICK_INT_H_ */
