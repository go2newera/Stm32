#include "adc.h"
#include "SysTick.h"

__IO uint16_t ADC_ConvertedValue; //用于保存转换计算后的电压值


//使能ADC1时钟，初始化PA.01
static void ADC1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
		
	// Enable ADC1 and GPIOC clock 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6); //设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M	
	// Configure PA.01  as analog input
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;//模拟输入模式
	GPIO_Init(GPIOA, &GPIO_InitStructure);				
}


// ADC1 configuration 
static void ADC1_Mode_Config(void)
{
	ADC_InitTypeDef ADC_InitStructure;
	
	ADC_DeInit(ADC1);  //复位ADC1,将外设 ADC1 的全部寄存器重设为缺省值
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//独立ADC模式
	ADC_InitStructure.ADC_ScanConvMode = DISABLE ; 	 //禁止扫描模式，扫描模式用于多通道采集
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	//开启连续转换模式，即不停地进行ADC转换
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//不使用外部触发转换
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 	//采集数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 1;	 	//要转换的通道数目1
	ADC_Init(ADC1, &ADC_InitStructure);
	
	ADC_Cmd(ADC1, ENABLE);//使能指定的ADC1
	ADC_ResetCalibration(ADC1);	 //复位校准寄存器   
	while(ADC_GetResetCalibrationStatus(ADC1));	//等待校准寄存器复位完成 
	ADC_StartCalibration(ADC1);	 //开启AD校准 
	while(ADC_GetCalibrationStatus(ADC1));	//等待校准完成
	
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//软件触发ADC转换
}

// 函数名：ADC1_Init
void ADC1_Init(void)
{
	ADC1_GPIO_Config();//ADC所用IO端口
	ADC1_Mode_Config();
}

//获得ADC值
//ch:通道值 0~3
u16 Get_Adc(u8 ch)   
{
  	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		//使能指定的ADC1的软件转换启动功能	
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));//等待转换结束

	return ADC_GetConversionValue(ADC1);	//返回最近一次ADC1规则组的转换结果
}

//Bubble sort
static void BubbleSort(u16 *pData,u16 Count)
{
	u16 iTemp,i,j;
	for(i=1;i<Count;i++)
	{
		for(j=Count-1;j>=i;j--)
		{
			if(pData[j]<pData[j-1])
			{
				iTemp=pData[j-1];
				pData[j-1]=pData[j];
				pData[j]=iTemp;
			}
		}
	}
}

//ADC remove extreme value
u16 Get_Adc_Average(u8 ch)
{
	  u16 iLoop=0,a=0;
	  u16 ADC_ConvertedValue[20];
	  for(iLoop=0;iLoop<20;iLoop++)
	  {
	     ADC_ConvertedValue[iLoop] = Get_Adc(ch);
		 Delay_ms(10);
	  }
	  BubbleSort(ADC_ConvertedValue,20);//data sort,small to large
   	  for (iLoop=8;iLoop<12;iLoop++)
   	  {
       	  a += ADC_ConvertedValue[iLoop];
   	  }
   	  a>>=2;
   	  return a;	
}
 
