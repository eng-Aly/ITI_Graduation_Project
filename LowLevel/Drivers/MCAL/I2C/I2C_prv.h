#ifndef I2C_PRV_H
#define I2C_PRV_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../RCC/RCC_int.h"
#include "../GPIO/GPIO_int.h"

#define I2C1_BASE_ADDR       0x40005400U
#define I2C2_BASE_ADDR       0x40005800U
#define I2C3_BASE_ADDR       0x40005C00U

typedef struct
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 OAR1;
    volatile u32 OAR2;
    volatile u32 DR;
    volatile u32 SR1;
    volatile u32 SR2;
    volatile u32 CCR;
    volatile u32 TRISE;
    volatile u32 FLTR;
}I2C_MemMap_t;

#define I2C1                ((volatile I2C_MemMap_t*)(I2C1_BASE_ADDR))
#define I2C2                ((volatile I2C_MemMap_t*)(I2C2_BASE_ADDR))
#define I2C3                ((volatile I2C_MemMap_t*)(I2C3_BASE_ADDR))

#define I2C1_EN             21
#define I2C2_EN             22
#define I2C3_EN             23

#define I2C1_EV_IRQ         31
#define I2C1_ER_IRQ         32
#define I2C2_EV_IRQ         33
#define I2C2_ER_IRQ         34
#define I2C3_EV_IRQ         72
#define I2C3_ER_IRQ         73

// RCC EN
#define RCC_I2C1_CLK_EN()      MRCC_vEnableClk(RCC_APB1, I2C1_EN)
#define RCC_I2C2_CLK_EN()      MRCC_vEnableClk(RCC_APB1, I2C2_EN)
#define RCC_I2C3_CLK_EN()      MRCC_vEnableClk(RCC_APB1, I2C3_EN)

//  I2C1(PB6/7), I2C2(PB10/3), I2C3(PA8/PB4), 

//@ref I2C_SCLK_define
#define SM_1KHZ    1000U
#define SM_2KHZ    2000U
#define SM_5KHZ    5000U
#define SM_10KHZ   10000U
#define SM_20KHZ   20000U
#define SM_50KHZ   50000U
#define SM_100KHZ  100000U

// @ref I2C_stretchMode_define
#define I2C_STRETCH_ENABLE     0U
#define I2C_STRETCH_DISABLE    ((u16)(1<<7))

// @ref I2C_Mode_define
#define I2C_MODE_I2C     0U
#define I2C_MODE_SMBUS   ((u16)(1<<1))

// @ref I2C_AddrSlaveMode_define
#define Addr_SlaveMode_7BIT    0U
#define Addr_SlaveMode_10BIT   ((u16)(1<<15))

// @ref I2C_ACK_define
#define I2C_ACK_Enable         ((u16)(1<<10)) 
#define I2C_ACK_Disable        0U

// @ref I2C_general_call_addr_define
#define I2C_general_call_addr_enable        ((u16)(1<<6))   
#define I2C_general_call_addr_disable       0U
#define I2C_ACK_ENABLE                      (10)

#define I2C_OAR2_ENDUAL        ((u16)(1<<0))
#define I2C_SR2_BUSY           ((u16)(1<<1))
#define I2C_CR1_Start          ((u16)(1<<8))
#define I2C_SR1_SB             ((u16)(1<<0))
#define I2C_SR1_ADDR           ((u16)(1<<1))
#define I2C_SR1_TXE            ((u16)(1<<7))
#define I2C_CR1_Stop           ((u16)(1<<9))
#define I2C_SR1_RXNE           ((u16)(1<<6))

// I2C Events
#define I2C_EVENT_MASTER_BYTR_TRANSMITTING          ((u32)0x00070008) // TRA, BUSY, MSL, TXE

#endif /* I2C_PRV_H */