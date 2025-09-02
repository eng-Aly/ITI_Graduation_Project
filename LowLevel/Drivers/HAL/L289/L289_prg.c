#include "L289_int.h"

void HL289_vInit(u8 dir1,u8 dir2,u8 en1)
{
    GPIO_PinInit(dir1,GPIO_MODE_OUTPUT);
    GPIO_PinInit(dir2,GPIO_MODE_OUTPUT);
    GPIO_PinInit(en1,GPIO_MODE_ALF);


}