#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

#define RUN_LED(a)	if (a)	\
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);\
					else		\
					GPIO_SetBits(GPIOA,GPIO_Pin_8)					

#define ALARM_LED(a)	if (a)	\
					GPIO_ResetBits(GPIOB,GPIO_Pin_5);\
					else		\
					GPIO_SetBits(GPIOB,GPIO_Pin_5)
					
#define RUN_LED_Flash GPIO_WriteBit(GPIOC, GPIO_Pin_3,BitAction)(1-(GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3))))
					
void RUN_LED_GPIO_Config(void);
void ALARM_LED_GPIO_Config(void);
					
#endif 
