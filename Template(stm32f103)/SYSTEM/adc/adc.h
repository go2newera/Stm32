#ifndef __ADC_H
#define	__ADC_H


#include "stm32f10x.h"

#define ADC_CH1  		1  		//通道1	
#define ConvertedVoltageValue(value) ((value*3300)/4096*1470/470+DiodeVoltageDrop)
#define DiodeVoltageDrop  700

void ADC1_Init(void);
u16 Get_Adc(u8 ch);
u16 Get_Adc_Average(u8 ch);

#endif /* __ADC_H */

