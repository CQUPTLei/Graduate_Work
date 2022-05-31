/****************************************************************
                   Source file of main.c
****************************************************************/
#include "public.h"

//define three extern variable
u8 hour,minute,second;

/****************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
****************************************************************/
int main()
{
	hour=9;	minute=30;second=25;
	DsgShowInit();//数码管管脚初始化
	EXTIInti();//外部中断初始化
	TIM6Init();//定时器初始化
	Usart1_Init();//串口初始化
	while(1)
	{
		DsgShowTime();//动态扫描显示时间
	}		
}



