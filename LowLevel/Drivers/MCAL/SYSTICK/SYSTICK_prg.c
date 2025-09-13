/*
 * SYSTICK_prg.c
 *
 *  Created on: Aug 21, 2025
 *      Author: Mo'men
 */


#include "SYSTICK_int.h"

static void (*G_xFptr)(void) = NULL; // Global pointer to hold the callback function for intervals
static u8 G_uSingleFlag = 0; // Flag to indicate if a single shot interval is set

void MSYSTICK_vInit(MSYSTICK_Config_t *A_xCfg){
    /* Stop Systick Counter */
    // CLR_BIT(SYSTICK->CTRL, ENABLE); // Clear the Enable bit
    MSYSTICK_vStopTimer();
    /* interrupt enable/disable*/
    if(A_xCfg->InterruptEnable == INT_ENABLE){
        SET_BIT(SYSTICK->CTRL, TICKINT); // Set the TICKINT bit to enable interrupt
    } else{
        CLR_BIT(SYSTICK->CTRL, TICKINT); // Clear the TICKINT bit to disable interrupt
    }
    /* Clock source selection AHB or AHB/8*/
    if(A_xCfg->CLK_SRC == ClK_SRC_AHB){
        SET_BIT(SYSTICK->CTRL, CLKSOURCE); // Set the CLKSOURCE bit for AHB clock
        GTicks_ms = (1000 * SYS_FREQ); // SYS_FREQ in Cfg -- Assuming the system clock is 25 MHz, 1 ms = 25000 ticks
    } else if (A_xCfg->CLK_SRC == ClK_SRC_AHB_DIV_8){
        CLR_BIT(SYSTICK->CTRL, CLKSOURCE); // Clear the CLKSOURCE bit for AHB/8 clock
        GTicks_ms = ((1000 * SYS_FREQ) / 8); // SYS_FREQ in Cfg -- Assuming the system clock is 25 MHz, 1 ms = 3125 ticks
    }
}

void MSYSTICK_vStartTimer(u32 A_u32LoadValue){
    /* Load the value into the LOAD register */
    SYSTICK->LOAD = A_u32LoadValue;
    /* Clear the current value in VAL register */
    SYSTICK->VAL = 0;
    /* Enable the Systick Counter */
    SET_BIT(SYSTICK->CTRL, ENABLE); // Set the Enable bit to start the timer
}

void MSYSTICK_vStopTimer(void){
    /* Stop Systick Counter */
    CLR_BIT(SYSTICK->CTRL, ENABLE); // Clear the Enable bit to stop the timer
}

void MSYSTICK_vSetDelay_ms(u32 A_u32Delay_ms){
    /* Calculate the load value based on the delay in milliseconds */
    u32 L_u32Ticks = (A_u32Delay_ms * GTicks_ms); // Calculate the number of ticks for the delay
    /* Reset Timer*/
    SYSTICK->VAL = 0; // Clear val register
    if (L_u32Ticks >= 0x00000001 && L_u32Ticks <= 0x00FFFFFF) {
        MSYSTICK_vStartTimer(L_u32Ticks);// Load the calculated ticks
        /* wait till timer flag is raised */
        while (GET_BIT(SYSTICK->CTRL, COUNTFLAG) == 0);
        /* Stop the timer after the delay */
        MSYSTICK_vStopTimer();
    }
}
void MSYSTICK_vSetDelay_us(u32 A_u32Delay_us)
{
	// in case clksrc = 25Mhz/8
	u32 L_u32Ticks = (u32)(A_u32Delay_us * 3.125);

	// Reset Timer
	SYSTICK->VAL = 0;
	if((L_u32Ticks > 0x00000001) && (L_u32Ticks < 0x00FFFFFF))
	{
		MSYSTICK_vStartTimer(L_u32Ticks);

		// wait till timer flag is raised
		while(GET_BIT(SYSTICK->CTRL, COUNTFLAG) == 0);

		MSYSTICK_vStopTimer();
	}
}
void MSYSTICK_vSetInterval_Single(u32 A_u32Delay_ms, void(*A_xFptr)(void)){
    G_uSingleFlag = 1; // Set the single shot flag
    /* Calculate the load value based on the delay in milliseconds */
    u32 L_u32Ticks = (A_u32Delay_ms * GTicks_ms); // Calculate the number of ticks for the interval
    G_xFptr = A_xFptr; // Store the callback function pointer globally
    /* Reset Timer*/
    SYSTICK->VAL = 0; // Clear val register
    if ((L_u32Ticks >= 0x00000001) && (L_u32Ticks <= 0x00FFFFFF)) {
        MSYSTICK_vStartTimer(L_u32Ticks); // Load the calculated ticks
    }
}
void MSYSTICK_vSetInterval_Multi(u32 A_u32Delay_ms, void(*A_xFptr)(void)){
    G_uSingleFlag = 0; // Clear the single shot flag
    /* Calculate the load value based on the delay in milliseconds */
    u32 L_u32Ticks = (A_u32Delay_ms * GTicks_ms); // Calculate the number of ticks for the interval
    G_xFptr = A_xFptr; // Store the callback function pointer globally
    /* Reset Timer*/
    SYSTICK->VAL = 0; // Clear val register
    if ((L_u32Ticks >= 0x00000001) && (L_u32Ticks <= 0x00FFFFFF)) {
        MSYSTICK_vStartTimer(L_u32Ticks); // Load the calculated ticks
    }
}


u32 MSYSTICK_u32GetElapsedTime_SingleShot(void){
    return SYSTICK->LOAD - SYSTICK->VAL; // Calculate elapsed ticks
}
u32 MSYSTICK_u32GetRemainingTime_SingleShot(void){
    return SYSTICK->VAL; // Return the remaining ticks
}

void Systick_Handler(void){
    /* This function is called when the Systick interrupt occurs */
    if (G_xFptr != NULL) {
        G_xFptr(); // Call the registered callback function
    }
    if (G_uSingleFlag == 1){
        MSYSTICK_vStopTimer();
    }
}
