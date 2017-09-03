#include "stm32f10x.h"
#include "led.h"
#include "valves.h" 
#include "usart.h"
#include "exti.h"
#include "adc.h"
#include "SysTick.h"
#include "i2c.h"
#include "spi.h"




int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
	SysTick_Init();//配置Sys_Tick为1us中断1次
	RUN_LED_GPIO_Config();//RUN_LED初始化
	ALARM_LED_GPIO_Config();//ALARM_LED初始化
	ShutOffValves_GPIO_Config();//切断阀端口初始化
	USART1_Config(115200);//串口1初始化
	ADC1_Init();//ADC初始化
	RUN_LED(ENABLE);//点亮运行指示灯
	
	Printf_Init();//打印参数信息
//	EXTI_PA0_Config();

	while(1)
	{

	}
}
