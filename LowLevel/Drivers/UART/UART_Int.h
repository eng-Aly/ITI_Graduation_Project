#ifndef UART_INT_H_
#define UART_INT_H_

#include "../../LIB/STD_TYPES.h"
#include "../RCC/RCC_int.h"
#include "../GPIO/GPIO_int.h"
#include "../NVIC/NVIC_int.h"
#include "UART_Prv.h"
#include "UART_Cfg.h"


typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}USART_TypeDef;

typedef struct{
	u8 TXE  	 : 1; // TX buffer empty interrupt
	u8 RXNE 	 : 1; // RX buffer not empty interrupt
	u8 TCE 	 : 1; // Transmission complete interrupt
	u8 Reserved : 5;
}S_USART_IRQ_SRC;

typedef struct {
	u8 USART_Mode;				// Specifies TX/RX Enable/Disable
								// This parameter must be set base on @ref UART_MODE_define
	u8 USART_PayLoad_Lenght;	// Specifies Number of data bits transmitted or received in data frame
							 	// This parameter must be set base on @ref UART_PayLoad_Length_define
	u8 USART_ParityMode;		// Specifies parity mode
								// This parameter must be set base on @ref UART_Parity_define
	u8 USART_StopBits;			// Specifies the number of stop bits transmitted
								// This parameter must be set base on @ref UART_StopBits_define
	u32 USART_BaudRate;		// This member configures UART communication baudrate
								// This parameter must be set base on @ref UART_BAUDRATE_define
	u8 USART_Sampling;			// This member configures UART Sampling Mode
								// This parameter must be set base on @ref UART_Sampling_define
	u8 USART_HW_FlowCTRL;		// Specifies whether hardware flow control enabled or disabled
						  	    // This parameter must be set base on @ref UART_HW_FLW_CTRL_define
	u8 USART_IRQ_Enable;		// Specifies whether IRQ of USART is Enabled or Disabled
							 	 	// This parameter must be set base on @ref UART_IRQ_ENABLE_define

	void (*P_IRQ_CallBack)(S_USART_IRQ_SRC irq_src);	// Set the C function which will be call when interrupt happens
}USART_PinConfig_t;

#define USART1_BASE											0x40011000UL
#define USART2_BASE											0x40004400UL
#define USART6_BASE											0x40011400UL


#define USART1								((USART_TypeDef *)USART1_BASE)
#define USART2								((USART_TypeDef *)USART2_BASE)
#define USART6								((USART_TypeDef *)USART6_BASE)

typedef enum {
	Disable, Enable
} PollingMechanism_t;

void MCAL_UART_Init(USART_TypeDef *UARTx, USART_PinConfig_t *UART_config);
void MCAL_UART_DeInit(USART_TypeDef *UARTx);

void MCAL_UART_SendData(USART_TypeDef *USARTx, u8 *PxBuffer, PollingMechanism_t polling_status);
u8 MCAL_UART_ReceiveData(USART_TypeDef *USARTx, u8 *PxBuffer, PollingMechanism_t polling_status);

void MCAL_UART_SendString(USART_TypeDef *USARTx, u8 *str);
u8 *MCAL_UART_ReceiveString(USART_TypeDef *USARTx, u8 *str);


#endif

