#include "../Programs/SHATO_Cfg.h"


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
}

void loop_test(void){
    HL289_vSetSpeed(&M1_DIR1,&M1_DIR2,&M1_EN_TIMER_Cfg,50);
    HL289_vSetSpeed(&M2_DIR1,&M2_DIR2,&M2_EN_TIMER_Cfg,50);
    HL289_vSetSpeed(&M3_DIR1,&M3_DIR2,&M3_EN_TIMER_Cfg,50);
    HL289_vSetSpeed(&M4_DIR1,&M4_DIR2,&M4_EN_TIMER_Cfg,50);
//    for(int i=0;i<1000000;i++); //delay
//    HL289_vSetSpeed(&M1_DIR1,&M1_DIR2,&M1_EN_TIMER_Cfg,0);
//    HL289_vSetSpeed(&M2_DIR1,&M2_DIR2,&M2_EN_TIMER_Cfg,0);
//    HL289_vSetSpeed(&M3_DIR1,&M3_DIR2,&M3_EN_TIMER_Cfg,0);
//    HL289_vSetSpeed(&M4_DIR1,&M4_DIR2,&M4_EN_TIMER_Cfg,0);
//    for(int i=0;i<1000000;i++); //delay
//    HL289_vSetSpeed(&M1_DIR1,&M1_DIR2,&M1_EN_TIMER_Cfg,-50);
//    HL289_vSetSpeed(&M2_DIR1,&M2_DIR2,&M2_EN_TIMER_Cfg,-50);
//    HL289_vSetSpeed(&M3_DIR1,&M3_DIR2,&M3_EN_TIMER_Cfg,-50);
//    HL289_vSetSpeed(&M4_DIR1,&M4_DIR2,&M4_EN_TIMER_Cfg,-50);
}

int main(void){
    SETUP();
    while(1){
        loop_test();
    }
    return 0;
}
