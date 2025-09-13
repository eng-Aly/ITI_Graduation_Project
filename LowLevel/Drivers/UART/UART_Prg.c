#include "UART_Int.h"
#include "UART_Prv.h"
#include "UART_Cfg.h"

USART_PinConfig_t *G_UART_config = NULL;
u8 G_Buffer[50];

/*
 * ========================================================================
 * 				 				  ISR
 * ========================================================================
 */
void USART1_IRQHandler(void){
	S_USART_IRQ_SRC irq_src;

	irq_src.TXE  = ((USART1->SR &  (1<<7)) >> 7);
	irq_src.RXNE = ((USART1->SR &  (1<<5)) >> 5);
	irq_src.TCE  = ((USART1->SR &  (1<<6)) >> 6);

	G_UART_config->P_IRQ_CallBack(irq_src);
}

void USART2_IRQHandler(void){
	S_USART_IRQ_SRC irq_src;

	irq_src.TXE  = ((USART2->SR &  (1<<7)) >> 7);
	irq_src.RXNE = ((USART2->SR &  (1<<5)) >> 5);
	irq_src.TCE  = ((USART2->SR &  (1<<6)) >> 6);

	G_UART_config->P_IRQ_CallBack(irq_src);
}

void USART6_IRQHandler(void){
	S_USART_IRQ_SRC irq_src;

	irq_src.TXE  = ((USART6->SR &  (1<<7)) >> 7);
	irq_src.RXNE = ((USART6->SR &  (1<<5)) >> 5);
	irq_src.TCE  = ((USART6->SR &  (1<<6)) >> 6);

	G_UART_config->P_IRQ_CallBack(irq_src);
}

static void MCAL_USART_SetPins(USART_TypeDef *USARTx);

void MCAL_UART_Init(USART_TypeDef *UARTx, USART_PinConfig_t *UART_config){
	G_UART_config = UART_config;

	// Enable USART Clock
	if(UARTx == USART1){
		RCC_USART1_CLK_EN();
		MCAL_USART_SetPins(USART1);
	}
	else if(UARTx == USART2){
		RCC_USART2_CLK_EN();
		MCAL_USART_SetPins(USART2);
	}
	else if(UARTx == USART6){
		RCC_USART6_CLK_EN();
		MCAL_USART_SetPins(USART6);
	}

	UARTx->CR1 = 0;
	UARTx->CR2 = 0;
	UARTx->CR3 = 0;

	// Enable UART
	UARTx->CR1 |= (1 << 13);

	// Choose Mode (TX/RX)
	UARTx->CR1 |= UART_config->USART_Mode;

	// Select Word Length
	UARTx->CR1 |= UART_config->USART_PayLoad_Lenght;

	// Choose Parity Mode
	UARTx->CR1 |= UART_config->USART_ParityMode;

	// Choose Number of Stop Bits
	UARTx->CR2 |= UART_config->USART_StopBits;

	// Set BaudRate
	UARTx->BRR |= (((162 & 0xFFFF) << 4) | 12);

	// Choose Sample Mode
	UARTx->CR1 |= UART_config->USART_Sampling;

	// Configure Hardware Flow Control
	UARTx->CR3 |= UART_config->USART_HW_FlowCTRL;

	// Enable Interrupt
	if(UART_config->USART_IRQ_Enable != UART_IRQ_ENABLE_NONE){
		UARTx->CR1 |= UART_config->USART_IRQ_Enable;

		if(UARTx == USART1){
			NVIC_IRQ_USART1_EN();
		}
		else if(UARTx == USART2){
			NVIC_IRQ_USART2_EN();
		}
		else if(UARTx == USART6){
			NVIC_IRQ_USART6_EN();
		}
	}
	else{
		UARTx->CR1 &= ~( (1<<5) | (1<<6) | (1<<7) | (1<<8) ); // clear RXNEIE,TCIE,TXEIE,PEIE
	}
}

void MCAL_UART_DeInit(USART_TypeDef *UARTx){
	if(UARTx == USART1){
		RCC_USART1_CLK_RST_SET();
		NVIC_IRQ_USART1_DIS();
	}
	else if(UARTx == USART2){
		RCC_USART2_CLK_RST_SET();
		NVIC_IRQ_USART1_DIS();
	}
	else if(UARTx == USART6){
		RCC_USART6_CLK_RST_SET();
		NVIC_IRQ_USART1_DIS();
	}
}

void MCAL_UART_SendData(USART_TypeDef *USARTx, u8 *PxBuffer, PollingMechanism_t polling_status){
	if(Enable == polling_status){
		while(!((USARTx->SR) & (1 << 7)));

		if((G_UART_config->USART_PayLoad_Lenght) == UART_PayLoad_Length_8Bits){
			// This for Data sent 8-bit
			USARTx->DR = (*PxBuffer & (u16)0xFF);
		}
		else{
			// This for Data sent 9-bit
			USARTx->DR = (*PxBuffer & (u16)0x01FF);
		}
	}
	else{
		if((G_UART_config->USART_PayLoad_Lenght) == UART_PayLoad_Length_8Bits){
			// This for Data sent 8-bit
			USARTx->DR = (*PxBuffer & (u16)0xFF);
		}
		else{
			// This for Data sent 9-bit
			USARTx->DR = (*PxBuffer & (u16)0x01FF);
		}

	    USARTx->CR1 |= (1 << 7);
	}
}

u8 MCAL_UART_ReceiveData(USART_TypeDef *USARTx, u8 *PxBuffer, PollingMechanism_t polling_status){
	if(Enable == polling_status){
		while (!(USARTx->SR & (1 << 5)));

		if(G_UART_config->USART_PayLoad_Lenght == UART_PayLoad_Length_9Bits){
			// This for Data sent 9-bit
			if(G_UART_config->USART_ParityMode == UART_Parity_DIS){
				*(PxBuffer) = USARTx->DR;
			}
			else{
				*(PxBuffer) = (USARTx->DR & (u8)0xFF);
			}
		}
		else{
			// This for Data sent 8-bit
			if(G_UART_config->USART_ParityMode == UART_Parity_DIS){
				*(PxBuffer) = USARTx->DR;
				// No parity So all 8bit are considered data
				*(PxBuffer) = (USARTx->DR  & (u8)0xFF) ;
			}
			else{
				// Parity is used, so 7 bits will be of user data and 1 bit is parity
				*(PxBuffer) = (USARTx->DR  & (u8)0X7F);
			}
		}

	}
	else{
		if(G_UART_config->USART_PayLoad_Lenght == UART_PayLoad_Length_9Bits){
			// This for Data sent 9-bit
			if(G_UART_config->USART_ParityMode == UART_Parity_DIS){
				*(PxBuffer) = USARTx->DR;
			}
			else{
				*(PxBuffer) = (USARTx->DR & (u8)0xFF);
			}
		}
		else{
			// This for Data sent 8-bit
			if(G_UART_config->USART_ParityMode == UART_Parity_DIS){
				*(PxBuffer) = USARTx->DR;
				// No parity So all 8bit are considered data
				*(PxBuffer) = (USARTx->DR  & (u8)0xFF) ;
			}
			else{
				// Parity is used, so 7 bits will be of user data and 1 bit is parity
				*(PxBuffer) = (USARTx->DR  & (u8)0X7F);
			}
		}
	}

	return (*PxBuffer);
}

void MCAL_UART_SendString(USART_TypeDef *USARTx, u8 *str){
	u8 index = 0;
	while(str[index] != '\0'){
		MCAL_UART_SendData(USARTx, &str[index++], Disable);
	}
}

u8 *MCAL_UART_ReceiveString(USART_TypeDef *USARTx, u8 *str) {
    u8 index = 0;
    u8 data;

    while (1) {
        // receive one character
        data = MCAL_UART_ReceiveData(USARTx, &str[index++], Disable);

        if (data == '\r') {       // stop on carriage return
            break;
        }

        str[index++] = data;      // store into buffer
    }

    str[index] = '\0';  // null terminate
    return str;
}
/*
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
GPIO_MODE_ALF
*/

static void MCAL_USART_SetPins(USART_TypeDef *USARTx){
	GPIOx_PinConfig_t USART_PinConfig;

	if(USARTx == USART1){
		USART_PinConfig.Pin = 9;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF7;
		MGPIO_vPinInit(&USART_PinConfig);

		// RX  ===> PA10uint8_t
		USART_PinConfig.Pin = 10;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF7;
		MGPIO_vPinInit(&USART_PinConfig);

		// CLK ===> PA8
		USART_PinConfig.Pin = 8;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF7;
		MGPIO_vPinInit(&USART_PinConfig);

		// CTS ===> PA11
		if((G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_CTS) | (G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_RTS)){
			USART_PinConfig.Pin = 11;
			USART_PinConfig.Mode = GPIO_MODE_ALF;
			USART_PinConfig.Altfunc = GPIO_AF7;
			MGPIO_vPinInit(&USART_PinConfig);
		}
		// RTS ===> PA12
		if((G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_CTS) | (G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_RTS)){
			USART_PinConfig.Pin = 12;
			USART_PinConfig.Mode = GPIO_MODE_ALF;
			USART_PinConfig.Altfunc = GPIO_AF7;
			MGPIO_vPinInit(&USART_PinConfig);
		}
	}

	else if(USARTx == USART2){
		// TX  ===> PA2
		// RX  ===> PA3
		// CLK ===> PA4
		// CTS ===> PA0
		// RTS ===> PA1

		// TX  ===> PA2
		USART_PinConfig.Pin = 2;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF7;
		MGPIO_vPinInit(&USART_PinConfig);

		// RX  ===> PA3
		USART_PinConfig.Pin = 3;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF7;
		MGPIO_vPinInit(&USART_PinConfig);

		// CLK ===> PA4
		USART_PinConfig.Pin = 4;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF7;
		MGPIO_vPinInit(&USART_PinConfig);

		// CTS ===> PA0
		if((G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_CTS) | (G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_RTS)){
			USART_PinConfig.Pin = 0;
			USART_PinConfig.Mode = GPIO_MODE_ALF;
			USART_PinConfig.Altfunc = GPIO_AF7;
			MGPIO_vPinInit(&USART_PinConfig);
		}
		// RTS ===> PA1
		if((G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_CTS) | (G_UART_config->USART_HW_FlowCTRL == UART_HW_FLW_CTRL_RTS)){
			USART_PinConfig.Pin = 1;
			USART_PinConfig.Mode = GPIO_MODE_ALF;
			USART_PinConfig.Altfunc = GPIO_AF7;
			MGPIO_vPinInit(&USART_PinConfig);
		}
	}

	else if(USARTx == USART6){
		// TX  ===> PA11
		// RX  ===> PA12

		// TX  ===> PA11
		USART_PinConfig.Pin = 11;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF8;
		MGPIO_vPinInit(&USART_PinConfig);

		// RX  ===> PA12
		USART_PinConfig.Pin = 12;
		USART_PinConfig.Mode = GPIO_MODE_ALF;
		USART_PinConfig.Altfunc = GPIO_AF8;
		MGPIO_vPinInit(&USART_PinConfig);
	}
}
