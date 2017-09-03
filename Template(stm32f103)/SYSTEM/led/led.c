#include "led.h"

void RUN_LED_GPIO_Config(void)//GPIOA8
{		
	//定义一个GPIO_InitTypeDef类型的结构体GPIO_InitStructure
	GPIO_InitTypeDef GPIO_InitStructure;

	//开启GPIOA的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); 

	//选择要控制的GPIOA引脚															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	

	//设置引脚模式为通用推挽输出工作状态
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	//设置引脚速率为50MHz   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	//调用库函数，初始化GPIOA
  	GPIO_Init(GPIOA, &GPIO_InitStructure);		  

	//关闭led灯
	GPIO_SetBits(GPIOA, GPIO_Pin_8);	 
}


void ALARM_LED_GPIO_Config(void)//GPIOB5
{		
	//定义一个GPIO_InitTypeDef类型的结构体GPIO_InitStructure
	GPIO_InitTypeDef GPIO_InitStructure;

	//开启GPIOA的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 

	//选择要控制的GPIOA引脚															   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	

	//设置引脚模式为通用推挽输出工作状态
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

	//设置引脚速率为50MHz   
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

	//调用库函数，初始化GPIOB
  	GPIO_Init(GPIOB, &GPIO_InitStructure);		  

	//关闭led灯
	GPIO_SetBits(GPIOB, GPIO_Pin_5);	 
}
