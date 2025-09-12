#include "../Programs/SHATO_Cfg.h"

s16 M1_SETPOINT;
s16 M2_SETPOINT;
s16 M3_SETPOINT;
s16 M4_SETPOINT;

s16 M1_ENC_COUNT;
s16 M2_ENC_COUNT;
s16 M3_ENC_COUNT;
s16 M4_ENC_COUNT;

s16 M1_ENC_SPEED;
s16 M2_ENC_SPEED;
s16 M3_ENC_SPEED;
s16 M4_ENC_SPEED;

u8 CONTROL_MSG[10];
u8 *msg;

void UART_RX_INT_HANDLER(S_USART_IRQ_SRC irq_src){
	if(irq_src.RXNE){
		//MCAL_UART_ReceiveData(DIFF_UART, CONTROL_MSG, Disable);  --> working test
        MCAL_UART_ReceiveString(DIFF_UART, CONTROL_MSG);
		//MCAL_GPIO_TogglePin(GPIOA, 0);                           --> working test
        //MCAL_UART_SendData(DIFF_UART, CONTROL_MSG, Disable);     --> working test

		s16 *targets[4] = { &M1_SETPOINT, &M2_SETPOINT, &M3_SETPOINT, &M4_SETPOINT };

		u8 num = 0;
		u8 idx = 0;

		for (u8 i = 0; CONTROL_MSG[i] != '\0'; i++) {
			if (CONTROL_MSG[i] >= '0' && CONTROL_MSG[i] <= '9') {
				num = num * 10 + (CONTROL_MSG[i] - '0');  // build number
			} else if (CONTROL_MSG[i] == ',') {
				if (idx < 4) {
					*targets[idx] = num;  // store into correct speedX
				}
				idx++;
				num = 0;
			}
		}
		// store last number
		if (idx < 4) {
			*targets[idx] = num;
		}
	}
}

void int_to_str(s16 num, s8 *str) {
    u8 i = 0, j;
    s8 buf[10];

    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }

    while (num > 0) {
        buf[i++] = (num % 10) + '0';
        num /= 10;
    }

    // reverse into str
    for (j = 0; j < i; j++) {
        str[j] = buf[i - j - 1];
    }
    str[j] = '\0';
}

void SETUP(void){
    Clock_Init();
    HL289_vInit(&M1_DIR1,&M1_DIR2,&M1_EN);
    HL289_vInit(&M2_DIR1,&M2_DIR2,&M2_EN);
    HL289_vInit(&M3_DIR1,&M3_DIR2,&M3_EN);
    HL289_vInit(&M4_DIR1,&M4_DIR2,&M4_EN);

    HL289_vTIM_Init(&M1_EN_TIMER_Cfg,&M1_EN_TIMER_OC_Cfg,M1_EN_TIMER,M1_EN_CHANNEL);
    HL289_vTIM_Init(&M2_EN_TIMER_Cfg,&M2_EN_TIMER_OC_Cfg,M2_EN_TIMER,M2_EN_CHANNEL);
    HL289_vTIM_Init(&M3_EN_TIMER_Cfg,&M3_EN_TIMER_OC_Cfg,M3_EN_TIMER,M3_EN_CHANNEL);
    HL289_vTIM_Init(&M4_EN_TIMER_Cfg,&M4_EN_TIMER_OC_Cfg,M4_EN_TIMER,M4_EN_CHANNEL);

    HEncoder_vInit(&M1_ENC1,&M1_ENC2);
    HEncoder_vInit(&M2_ENC1,&M2_ENC2);
    HEncoder_vInit(&M3_ENC1,&M3_ENC2);
    HEncoder_vInit(&M4_ENC1,&M4_ENC2);

    HEncoder_vTIM_Init(ENC1_TIMER);
    HEncoder_vTIM_Init(ENC2_TIMER);
    HEncoder_vTIM_Init(ENC3_TIMER);
    HEncoder_vTIM_Init(ENC4_TIMER);

    DIFF_UART_TX_Cfg.P_IRQ_CallBack=UART_RX_INT_HANDLER;

    MCAL_UART_Init(DIFF_UART,&DIFF_UART_TX_Cfg);

}

void loop_test(void){
    s8 buffer[30];
    s8 temp[8];
    u8 pos = 0, i;


    HL289_vSetSpeed(&M1_DIR1,&M1_DIR2,&M1_EN_TIMER_Cfg,M1_SETPOINT);
    HL289_vSetSpeed(&M2_DIR1,&M2_DIR2,&M2_EN_TIMER_Cfg,M2_SETPOINT);
    HL289_vSetSpeed(&M3_DIR1,&M3_DIR2,&M3_EN_TIMER_Cfg,M3_SETPOINT);
    HL289_vSetSpeed(&M4_DIR1,&M4_DIR2,&M4_EN_TIMER_Cfg,M4_SETPOINT);


    M1_ENC_COUNT = HEncoder_vGetCounts(ENC1_TIMER);
    M2_ENC_COUNT = HEncoder_vGetCounts(ENC2_TIMER);
    M3_ENC_COUNT = HEncoder_vGetCounts(ENC3_TIMER);
    M4_ENC_COUNT = HEncoder_vGetCounts(ENC4_TIMER);

    int_to_str(M1_ENC_COUNT, temp);
    for (i = 0; temp[i]; i++) buffer[pos++] = temp[i];
    buffer[pos++] = ',';
    int_to_str(M2_ENC_COUNT, temp);
    for (i = 0; temp[i]; i++) buffer[pos++] = temp[i];
    buffer[pos++] = ',';
    int_to_str(M3_ENC_COUNT, temp);
    for (i = 0; temp[i]; i++) buffer[pos++] = temp[i];
    buffer[pos++] = ',';
    int_to_str(M4_ENC_COUNT, temp);
    for (i = 0; temp[i]; i++) buffer[pos++] = temp[i];
    buffer[pos++] = ',';

    MCAL_UART_SendString(DIFF_UART, (u8 *)buffer);

    for(int i=0;i<1000000;i++); //delay
    HL289_vSetSpeed(&M1_DIR1,&M1_DIR2,&M1_EN_TIMER_Cfg,0);
    HL289_vSetSpeed(&M2_DIR1,&M2_DIR2,&M2_EN_TIMER_Cfg,0);
    HL289_vSetSpeed(&M3_DIR1,&M3_DIR2,&M3_EN_TIMER_Cfg,0);
    HL289_vSetSpeed(&M4_DIR1,&M4_DIR2,&M4_EN_TIMER_Cfg,0);
    for(int i=0;i<1000000;i++); //delay
    HL289_vSetSpeed(&M1_DIR1,&M1_DIR2,&M1_EN_TIMER_Cfg,-50);
    HL289_vSetSpeed(&M2_DIR1,&M2_DIR2,&M2_EN_TIMER_Cfg,-50);
    HL289_vSetSpeed(&M3_DIR1,&M3_DIR2,&M3_EN_TIMER_Cfg,-50);
    HL289_vSetSpeed(&M4_DIR1,&M4_DIR2,&M4_EN_TIMER_Cfg,-50);
}

int main(void){
    RCC->CR |= (1 << 16);
    while (!(RCC->CR & (1 << 17)));
    RCC->CFGR &= ~(0x3 << 0);
    RCC->CFGR |= (0x1 << 0);
    while (((RCC->CFGR >> 2) & 0x3) != 0x1);

    SETUP();
	GPIO_PinConfig_t pin;
	pin.GPIO_PinNumber = 0;
	pin.GPIO_MODE = GPIO_MODE_OP;
	pin.GPIO_Output_Speed = GPIO_SPEED_LOW;
	pin.GPIO_TYPE = GPIO_TYPE_PP;
	pin.GPIO_PU_PD = GPIO_NO_PULL;
	MCAL_GPIO_Init(GPIOA, &pin);

	MCAL_UART_ReceiveString(USART1,CONTROL_MSG);

    while(1){
        loop_test();
    }
    return 0;
}
