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
		u8 Email[]="22102600@qq.com";
		OLED_Init();			//初始化OLED  
		OLED_Clear()  	;

		OLED_ShowCHinese(20,0,0);//苏
		OLED_ShowCHinese(44,0,1);//州
		OLED_ShowCHinese(68,0,2);//大
		OLED_ShowCHinese(92,0,3);//学
		OLED_Show_CHinese32X32(8,2,0);//黄		
		OLED_Show_CHinese32X32(48,2,1);	//克
		OLED_Show_CHinese32X32(88,2,2);	//亚	
		OLED_ShowString(4,6,Email);
}


