#ifndef __VALVES_H
#define	__VALVES_H

#include "stm32f10x.h"

void ShutOffValves_GPIO_Config(void);
ErrorStatus ShutOffValves_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin);

#endif 
