#ifndef UART_PRV_H_
#define UART_PRV_H_

#include "../../LIB/STD_TYPES.h"





#define UART_Parity_DIS						(u32)(0)
#define UART_Parity_Even					(u32)((1 << 10) | (0))
#define UART_Parity_Odd						(u32)((1 << 10) | (1 << 9))

#define UART_StopBits_Half_Bit				(u32)(1 << 12)
#define UART_StopBits_1Bit					(u32)(0)
#define UART_StopBits_1_Half_Bit			(u32)(3 << 12)
#define UART_StopBits_2_Bit					(u32)(2 << 12)

// @ref UART_BAUDRATE_define
#define UART_BaudRate_2400						2400
#define UART_BaudRate_9600						9600
#define UART_BaudRate_19200						19200
#define UART_BaudRate_57600						57600
#define UART_BaudRate_115200					115200
#define UART_BaudRate_230400					230400
#define UART_BaudRate_460800					460800
#define UART_BaudRate_921600					921600
#define UART_BaudRate_2250000					2250000
#define UART_BaudRate_4500000					4500000


#define UART_Sampling_16					(u32)(0)
#define UART_Sampling_8						(u32)(1 << 15)

#define UART_HW_FLW_CTRL_RTS_DIS			(u32)(0)
#define UART_HW_FLW_CTRL_CTS_DIS			(u32)(0)
#define UART_HW_FLW_CTRL_RTS_CTS_DIS		(u32)(0)
#define UART_HW_FLW_CTRL_RTS				(u32)(1 << 8)
#define UART_HW_FLW_CTRL_CTS				(u32)(1 << 9)
#define UART_HW_FLW_CTRL_CTS_RTS			(u32)((1 << 8) | (1 << 9))


#define UART_IRQ_ENABLE_NONE				(u32)(0)
#define UART_IRQ_ENABLE_RXNEIE				(u32)(1 << 5)
#define UART_IRQ_ENABLE_TCIE				(u32)(1 << 6)
#define UART_IRQ_ENABLE_TXEIE				(u32)(1 << 7)
#define UART_IRQ_ENABLE_TXEIE_RXNEIE		(u32)((1 << 7) | (1 << 5))
#define UART_IRQ_ENABLE_PEIE				(u32)(1 << 8)

#define UART_MODE_RX						(u32)(1 << 2)
#define UART_MODE_TX						(u32)(1 << 3)
#define UART_MODE_TX_RX						(u32)(3 << 2)


#define UART_PayLoad_Length_8Bits			(u32)(0)
#define UART_PayLoad_Length_9Bits			(u32)(1 << 12)



#define UART_IRQ_ENABLE_NONE				(u32)(0)
#define UART_IRQ_ENABLE_RXNEIE				(u32)(1 << 5)
#define UART_IRQ_ENABLE_TCIE				(u32)(1 << 6)
#define UART_IRQ_ENABLE_TXEIE				(u32)(1 << 7)
#define UART_IRQ_ENABLE_TXEIE_RXNEIE		(u32)((1 << 7) | (1 << 5))
#define UART_IRQ_ENABLE_PEIE				(u32)(1 << 8)

#define UART_StopBits_Half_Bit				(u32)(1 << 12)
#define UART_StopBits_1Bit					(u32)(0)
#define UART_StopBits_1_Half_Bit			(u32)(3 << 12)
#define UART_StopBits_2_Bit					(u32)(2 << 12)

#define UART_Sampling_16					(u32)(0)
#define UART_Sampling_8						(u32)(1 << 15)

#endif

