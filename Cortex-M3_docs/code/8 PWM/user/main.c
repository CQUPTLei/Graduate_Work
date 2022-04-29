/****************************************************************
                   Source file of main.c
****************************************************************/
#include "public.h"
u8 hour,minute,second;
/****************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
****************************************************************/
int main()
{
	u8 dir=1;//方向
	u32 Duty=0;	  	  
	TIM3_PWMInit();	 //PWM初始化
	while(1)
	{
		delay_ms(10);
		if(dir==1)		
		{
			Duty++;
			if(Duty>300)	dir=0;				
		}
		else
		{
			Duty--;
			if(Duty==0)   dir=1;			
		}
		TIM_SetCompare1(TIM3, Duty);//设置TIMx捕获比较1寄存器值	
		TIM_SetCompare2(TIM3, Duty);//设置TIMx捕获比较2寄存器值		
	}
}



