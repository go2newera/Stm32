#include "exti.h"

//描述  ：配置嵌套向量中断控制器NVIC
static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;// 配置P[A|B|C|D|E]0为中断源
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0X02;//抢占优先级2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0X01;//子优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

//描述  ：配置 PA0 为线中断口，并设置中断优先级
void EXTI_PA0_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	// config the extiline(PA0) clock and AFIO clock 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO,ENABLE);
												
	// config the NVIC(PA0) 
	NVIC_Configuration();

	// EXTI line gpio config(PA0) 	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//PA0       
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;	 // 上拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化PA0

	// EXTI line(PA0) mode config,中断线以及中断初始化配置 
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0); 
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;//选择EXTI_Line0线进行配置
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//给EXTI_Mode成员赋值
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿触发中断
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//把EXTI_LineCmd设置为使能
	EXTI_Init(&EXTI_InitStructure); //把EXTI初始化结构体的参数写入寄存器
}


void EXTI0_IRQHandler(void)
{
	EXTI_ClearITPendingBit(EXTI_Line0);  //清除EXTI0线路挂起位
}