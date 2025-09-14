
#include "TCRT5000_int.h"

u8 GGPIO_PORTx[2] = {0};
u8 GGPIO_PINx[2] = {0};

void TCRT5000_Init(u8 GPIO_PORTx[2], u8 GPIO_PINx[2]){
    GGPIO_PORTx[0] = GPIO_PORTx[0];
    GGPIO_PINx[0] = GPIO_PINx[0];
    GPIOx_PinConfig_t DPin = {
        .Port = GPIO_PORTx[0], 
        .Pin = GPIO_PINx[0],     
        .Mode = GPIO_MODE_INPUT,
        .PullType = GPIO_PULL_UP,
    };

    GGPIO_PORTx[1] = GPIO_PORTx[1];
    GGPIO_PINx[1] = GPIO_PINx[1];
    MGPIO_vPinInit(&DPin);                               // Initialize Digital Pin as Input
    GPIOx_PinConfig_t APin = {
        .Port = GPIO_PORTx[1],    
        .Pin = GPIO_PINx[1],
        .Mode = GPIO_MODE_ANALOG,
        .PullType = GPIO_NO_PULL,
    };
    MGPIO_vPinInit(&APin);                               // Initialize Analog Pin as Input

}

u8 TCRT5000_ReadDigital(void){
    // High when no object is detected (black), Low when an object is detected (white)
    return MGPIO_u8GetPinValue(GGPIO_PORTx[0], GGPIO_PINx[0]); // Read and return the digital state (High / Low) of the pin
}