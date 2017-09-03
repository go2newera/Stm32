#include "valves.h" 

void ShutOffValves_GPIO_Config(void)//GPIOB12,GPIOB13
{
	//定义一个GPIO_InitTypeDef类型的结构体GPIO_InitStructure
	GPIO_InitTypeDef GPIO_InitStructure;
	//开启GPIOB的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//选择要控制的GPIOB引脚12,13	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13; 
	//设置引脚模式为上拉输入模式工作状态
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	//调用库函数，初始化GPIOB
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

// 输入  ：GPIOx：x 可以是 A，B，C，D或者E,GPIO_Pin：待读取的端口位 	
ErrorStatus ShutOffValves_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin)
{			
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == SET ) //Warning
	{	   		
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == SET )//Warning  
		{	 
			return 	ERROR;	 
		}
		else
		{
		    return SUCCESS;
		}
	}
	else
	{
		return SUCCESS;
	}
}

