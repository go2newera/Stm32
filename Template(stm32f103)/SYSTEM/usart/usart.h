#ifndef __USART_H
#define	__USART_H

#include "stm32f10x.h"
#include <stdio.h>

											 
void USART1_Config(uint32_t UsartBaudRate);
void USART2_Config(uint32_t UsartBaudRate);
void USART3_Config(uint32_t UsartBaudRate);
int  fputc(int ch, FILE *f);
void USART_printf(USART_TypeDef* USARTx, uint8_t *Data,...);
void Printf_Init(void);//¥Ú”°–æ∆¨–≈œ¢

#endif 
