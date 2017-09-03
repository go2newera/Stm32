#include "SysTick.h"

static __IO u32 TimingDelay;

//配置并启动系统滴答定时器 SysTick
void SysTick_Init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);	//选择外部时钟
	// SystemCoreClock / 100000	 10us中断一次
	// SystemCoreClock / 1000000 1us中断一次
	if (SysTick_Config(SystemCoreClock / 1000000))	// ST3.5.0库版本
	{ 
		while (1);//配置成功返回0。配置不成功，进入死循环。捕捉错误
	}
	//配置成功，先关闭定时器，在需要的时候开启
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;// 关闭滴答定时器  
}


//总的延时时间=中断周期*TimingDelay(nTime)
void Delay_us(__IO u32 nTime)
{ 
	TimingDelay = nTime;	

	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;	// 使能滴答定时器  

	while(TimingDelay != 0);
}

void Delay_ms(__IO u32 nTime)
{ 
	while(nTime != 0)
	{
		Delay_us(1000);
		nTime--;
	}
}

// 获取节拍程序,在SysTick 中断函数 SysTick_Handler()调用
// 中断服务函数每中断1次TimingDelay减1
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{ 
		TimingDelay--;
	}
}
