#ifndef GPIO_INT_H_
#define GPIO_INT_H_

#include "GPIO_Prv.h"
#include "GPIO_Cfg.h"
#include "../../LIB/STD_TYPES.h"
#include "../RCC/RCC_Int.h"

typedef struct{
	u16 GPIO_PinNumber;        // Specifies GPIO pin to configure			         	// This Parameter can be set based on @ref GPIO_PIN_def
	u16 GPIO_MODE;	        	// Specifies the Mode of GPIO				   	    // This Parameter can be value at @ref GPIO_MODE_def
	u16 GPIO_AFx;				// Specifies the Alternate Function Number						// This Parameter can be value at @ref GPIO_AFx_def
	u16 GPIO_TYPE;	        	// Specifies the Type of GPIO				   	    // This Parameter can be value at @ref GPIO_TYPE_def
	u16 GPIO_PU_PD;	        // Specifies if the GPIO is Pull-Up of Pull-Down						// This Parameter can be value at @ref GPIO_PU_PD_def
	u16 GPIO_Output_Speed;		// Specifies the output speed of the GPIO
   // This Parameter can be value at @ref GPIO_SPEED_define
}GPIO_PinConfig_t;


void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_Denit(GPIO_TypeDef *GPIOx);
u8 MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, u16 PinNumber);
u16 MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, u16 PinNumber, u16 value);
void MCAL_GPIO_WritePinAtomic(GPIO_TypeDef *GPIOx, u16 PinNumber, u16 value);
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, u16 value);
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, u16 PinNumber);
u8 MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, u16 PinNumber);

#endif 