#include "usart.h"
#include <stdarg.h>
#include "stm32f10x.h"
#include "adc.h"

void USART1_Config(uint32_t UsartBaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	// config USART1 clock ，开启串口1/GPIOA的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	// USART1 GPIO config 
	// Configure USART1 Tx (PA9) as alternate function push-pull
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//PA9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推免输出模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);   
	
	// Configure USART1 Rx (PA10) as input floating ，浮空输入模式或带上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	  //Usart1 NVIC 配置
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	
	// USART1 mode config 初始化设置
	USART_InitStructure.USART_BaudRate = UsartBaudRate;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//配置串口传输的字长，8位字长
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//配置停止位，1位停止位
	USART_InitStructure.USART_Parity = USART_Parity_No ;//配置奇偶校验位，不设置奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//配置硬件流控制，不采用硬件流
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//配置串口的模式，全双工通信
	USART_Init(USART1, &USART_InitStructure); //调用库函数向寄存器写入配置参数
	USART_Cmd(USART1, ENABLE);//使能串口1外设
}

void USART2_Config(uint32_t UsartBaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	// config USART2 clock ,开启串口2/GPIOA的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART2 | RCC_APB2Periph_GPIOA, ENABLE);

	// USART2 GPIO config 
	// Configure USART2 Tx (PA2) as alternate function push-pull，复用推免输出模式 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	    
	// Configure USART2 Rx (PA3) as input floating ，浮空输入模式或带上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	// Configure the NVIC Preemption Priority Bits  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	// Enable the USARTy Interrupt 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	 //配置串口2中断向量
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;//抢占优先性
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;//响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能中断向量的中断响应
	NVIC_Init(&NVIC_InitStructure);
	
	// USART2 mode config 
	USART_InitStructure.USART_BaudRate = UsartBaudRate;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//配置串口传输的字长，8位字长
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//配置停止位，1位停止位
	USART_InitStructure.USART_Parity = USART_Parity_No ;//配置奇偶校验位，不设置奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//配置硬件流控制，不采用硬件流
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//配置串口的模式，全双工通信

	USART_Init(USART2, &USART_InitStructure); //调用库函数向寄存器写入配置参数
	USART_Cmd(USART2, ENABLE);//使能串口2外设
}

void USART3_Config(uint32_t UsartBaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	// config USART3 clock ,开启串口3/GPIOB的外设时钟
	RCC_APB2PeriphClockCmd(RCC_APB1Periph_USART3 | RCC_APB2Periph_GPIOB, ENABLE);
	
	// USART3 GPIO config 
	// Configure USART3 Tx (PB10) as alternate function push-pull ，复用推免输出模式 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	    
	// Configure USART2 Rx (PB11) as input floating ，浮空输入模式或带上拉输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	  
	// USART3 mode config 
	USART_InitStructure.USART_BaudRate = UsartBaudRate;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//配置串口传输的字长，8位字长
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//配置停止位，1位停止位
	USART_InitStructure.USART_Parity = USART_Parity_No ;//配置奇偶校验位，不设置奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//配置硬件流控制，不采用硬件流
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//配置串口的模式，全双工通信

	USART_Init(USART3, &USART_InitStructure); //调用库函数向寄存器写入配置参数
	USART_Cmd(USART3, ENABLE);//使能串口3外设
}


/*
 * 函数名:fputc
 * 描述  ：重定向c库函数printf到USART
 * 调用  ：由printf调用
 */
int fputc(int ch, FILE *f)
{
	// 将Printf内容发往串口 
	USART_SendData(USART1, (unsigned char) ch);
	while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);	
	return (ch);
}

/*
 * 函数名：itoa
 * 描述  ：将整形数据转换成字符串
 * 输入  ：-radix =10 表示10进制，其他结果为0
 *         -value 要转换的整形数
 *         -buf 转换后的字符串
 *         -radix = 10
 * 输出  ：无
 * 返回  ：无
 * 调用  ：被USART_printf()调用
 */
static char *itoa(int value, char *string, int radix)
{
	int     i, d;
	int     flag = 0;
	char    *ptr = string;
	
	/* This implementation only works for decimal numbers. */
	if (radix != 10)
	{
	    *ptr = 0;
	    return string;
	}
	
	if (!value)
	{
	    *ptr++ = 0x30;
	    *ptr = 0;
	    return string;
	}
	
	/* if this is a negative value insert the minus sign. */
	if (value < 0)
	{
	    *ptr++ = '-';
	
	    /* Make the value positive. */
	    value *= -1;
	}
	
	for (i = 10000; i > 0; i /= 10)
	{
	    d = value / i;
	
	    if (d || flag)
	    {
	        *ptr++ = (char)(d + 0x30);
	        value -= (d * i);
	        flag = 1;
	    }
	}
	
	/* Null terminate the string. */
	*ptr = 0;
	
	return string;

} 

/*
 * 描述  ：格式化输出，类似于C库中的printf，但这里没有用到C库
 * 输入  ：-USARTx 串口通道，这里只用到了串口，即USART
 *		   -Data   要发送到串口的内容的指针
 *		   -...    其他参数
 *         典型应用USART_printf( USART1, "\r\n this is a demo \r\n" );
 *            	   USART_printf( USART1, "\r\n %d \r\n", i );
 *            	   USART_printf( USART1, "\r\n %s \r\n", j );
 */
void USART_printf(USART_TypeDef* USARTx, uint8_t *Data,...)
{
	const char *s;
	int d;   
	char buf[16];
	
	va_list ap;
	va_start(ap, Data);
	
	while ( *Data != 0)     // 判断是否到达字符串结束符
	{				                          
		if ( *Data == 0x5c )  //'\'
		{									  
			switch ( *++Data )
			{
				case 'r':							          //回车符
					USART_SendData(USARTx, 0x0d);
					Data ++;
					break;
		
				case 'n':							          //换行符
					USART_SendData(USARTx, 0x0a);	
					Data ++;
					break;
				default:
					Data ++;
					break;
			}			 
		}
		else if ( *Data == '%')//
		{									  
			switch ( *++Data )
			{				
				case 's':										  //字符串
					s = va_arg(ap, const char *);
					for ( ; *s; s++) 
					{
						USART_SendData(USARTx,*s);
						while( USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET );
					}
					Data++;
					break;
				case 'd':										//十进制
					d = va_arg(ap, int);
					itoa(d, buf, 10);
					for (s = buf; *s; s++) 
					{
						USART_SendData(USARTx,*s);
						while( USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET );
					}
					Data++;
					break;
				default:
					Data++;
					break;
			}		 
		} 
		else 
		{
			USART_SendData(USARTx, *Data++);
		}
		while( USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET );
	}
}

static void Get_ChipInfo(void)//获取芯片序列号
{
	uint32_t ChipUniqueID[3];
	u16 temp[6];
	ChipUniqueID[0] = *(__IO u32 *)(0X1FFFF7F0); // 高字节
	ChipUniqueID[1] = *(__IO u32 *)(0X1FFFF7EC); //
	ChipUniqueID[2] = *(__IO u32 *)(0X1FFFF7E8); // 低字节
	temp[5]=(u16)(ChipUniqueID[0] & 0x0000FFFF);
	temp[4]=(u16)((ChipUniqueID[0] & 0xFFFF0000)>>16);
	temp[3]=(u16)(ChipUniqueID[1] & 0x0000FFFF);
	temp[2]=(u16)((ChipUniqueID[1] & 0xFFFF0000)>>16);
	temp[1]=(u16)(ChipUniqueID[2] & 0x0000FFFF);
	temp[0]=(u16)((ChipUniqueID[2] & 0xFFFF0000)>>16);
	USART_printf(USART1,"\n\r Chip ID: %d%d-%d%d-%d%d \n\r ",temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]);  
	
}

void Printf_Init(void)
{
	//uint32_t ulTmp;
	u16 STM32_FLASH_SIZE;
	const uint8_t newera[] = {"\r\n"\
           "_________________www.go2newera.com_________________\r\n"\
           "\r\n"};
	USART_printf(USART1,"%s", newera); 
	
	Get_ChipInfo();//打印芯片序列号
	
	USART_printf(USART1,"STM32F103 Standard Peripheral Library version: V%d.%d.%d \n\r",
	__STM32F10X_STDPERIPH_VERSION_MAIN,__STM32F10X_STDPERIPH_VERSION_SUB1,__STM32F10X_STDPERIPH_VERSION_SUB2);//使用固件库版本号
		
	USART_printf(USART1," Download date: "__DATE__" - "__TIME__"");//程序烧录时间	   
	
	STM32_FLASH_SIZE= *(u16*)(0x1FFFF7E0);    
	USART_printf(USART1,"\n\r Flash Size: %dK \n\r ", STM32_FLASH_SIZE);//闪存容量寄存器 
		   
	USART_printf(USART1,"SystemCoreClock: %d MHz.\n\r",SystemCoreClock/1000000);//系统时钟
	
	USART_printf(USART1," The Current Voltage Value: %d MV \n\r", ConvertedVoltageValue(Get_Adc_Average(ADC_CH1))); //电池电压
}


