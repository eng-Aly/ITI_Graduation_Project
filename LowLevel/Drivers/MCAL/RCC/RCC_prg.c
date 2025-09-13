/*
 * RCC_prg.c
 *
 *  Created on: Aug 14, 2025
 *      Author: pc
 *      Version: 0.1
 */

#include "RCC_int.h"



void MRCC_vInit(void)
{
#if RCC_SYS_CLK == HSE_CLK
	// choose bypass
#if HSE_BYPASS == RC_CLK
	SET_BIT(RCC->CR, HSEBYP);
#elif HSE_BYPASS == MECHANICAL_CLK
	CLR_BIT(RCC->CR, HSEBYP);
#endif
	// HSE on
	SET_BIT(RCC->CR, 16);

	// wait till flag is set
	while(GET_BIT(RCC->CR,17) == 0)
		;
	// switch to hse
	CLR_BIT(RCC->CFGR, 1);
	SET_BIT(RCC->CFGR, 0);

	// CSSON enable/disable


#elif RCC_SYS_CLK == HSI_CLK
	// HSI on
	SET_BIT(RCC->CR, 0);

	// wait till flag is set
	while(GET_BIT(RCC->CR,1) == 0)
		;
	// switch to hsi
	CLR_BIT(RCC->CFGR, 1);
	CLR_BIT(RCC->CFGR, 0);

#elif RCC_SYS_CLK == PLL_CLK


#else
#error "Invalid option"
#endif

}
void MRCC_vEnableClk(u8 A_u8BusID, u8 A_u8PeripheralID)
{
	switch(A_u8BusID)
	{
	case RCC_AHB1:
		switch(A_u8PeripheralID)
		{
		case RCC_GPIOA: SET_BIT(RCC->AHB1ENR, GPIOAEN);break;
		case RCC_GPIOB: SET_BIT(RCC->AHB1ENR, GPIOBEN);break;
		}
		SET_BIT(RCC->AHB1ENR, A_u8PeripheralID);

		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR, A_u8PeripheralID);
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR, A_u8PeripheralID);
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB2ENR, A_u8PeripheralID);
		break;
	}
}
void MRCC_vDisableClk(u8 A_u8BusID, u8 A_u8PeripheralID)
{
	switch(A_u8BusID)
	{
	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR, A_u8PeripheralID);
		break;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR, A_u8PeripheralID);
		break;
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR, A_u8PeripheralID);
		break;
	case RCC_APB2:
		CLR_BIT(RCC->APB2ENR, A_u8PeripheralID);
		break;
	}
}
