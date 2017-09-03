					文档使用说明
USER  		文件夹用来存放用户层代码,包括主函数main.c。
FWlib 		文件夹用来存放ST官方提供的库函数源码文件,inc和src这两个文件夹包含芯片上所有驱动。
CMSIS		文件夹用来存放库为我们提供的启动文件和一些位于CMSIS层的文件。
Ouput 		文件夹用来存放编译后输出的文件。
Listing   	文件夹用来存放工程文件和编译后生成的链接文件。
Document	文件夹用来存放使用文档说明。
SYSTEM		文件夹用来存放STM32驱动文件。
HARDWARE	文件夹用来存放主板硬件驱动程序。   


					启动文件的说明
    startup_stm32f10x_ld.s
    startup_stm32f10x_md.s
    startup_stm32f10x_hd.s
ST提供的3个启动文件，分别适用于不同容量的STM32芯片。
其中ld.s适用于小容量产品,md.s适用于中等容量产品,hd适用于大容量产品。
这里的容量是指FLASH的大小。
判断方法如下：
       小容量：FLASH≤32K
       中容量：64K≤FLASH≤128K
       大容量：256K≤FLASH
所以,请大家根据自己所用的STM32芯片选择不同的.s文件。