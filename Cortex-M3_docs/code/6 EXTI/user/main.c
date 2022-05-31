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
	hour=9;	minute=6;second=18;
	DsgShowInit();
	EXTIInti();
	while(1)
	{
		DsgShowTime();
	}		
}



