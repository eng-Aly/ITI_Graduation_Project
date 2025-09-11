#ifndef GPIO_CFG_H_
#define GPIO_CFG_H_
#include "../../LIB/STD_TYPES.h"

#define GPIO_PIN_SET					1
#define GPIO_PIN_RST					0

#define HIGH                            1
#define LOW                             0

#define GPIO_RET_LOCK_EN				1
#define GPIO_RET_LOCK_DIS				0

#define GPIO_SPEED_LOW								0x00000000u      // Low speed
#define GPIO_SPEED_MEDIUM 							0x00000001u      // Medium speed
#define GPIO_SPEED_HIGH								0x00000002u      // High speed
#define GPIO_SPEED_VERY_HIGH						0x00000003u      // Very high speed

#define GPIO_TYPE_PP								0x00000000u      // Output push-pull (reset state)
#define GPIO_TYPE_OD								0x00000001u      // Output open-drain



#define GPIO_NO_PULL                      0
#define GPIO_PULL_UP                      1
#define GPIO_PULL_DOWN                    2

#endif