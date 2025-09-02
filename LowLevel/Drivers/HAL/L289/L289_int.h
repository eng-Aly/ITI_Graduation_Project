#ifndef DRIVERS_HAL_L289_L289_INT_H_
#define DRIVERS_HAL_L289_L289_INT_H_

#include "../../LIB/STD_TYPES.h"

void HL289_vInit(u8 dir1,u8 dir2,u8 en1);
void HL289_vSetMotorSpeed(int speed);

#endif
