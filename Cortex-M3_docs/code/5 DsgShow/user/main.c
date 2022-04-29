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
* Return         : None
****************************************************************/
int main()
{
	hour=9;
	minute=30;
	second=15;
	DsgShowInit();
	DsgShowTime();	
}



