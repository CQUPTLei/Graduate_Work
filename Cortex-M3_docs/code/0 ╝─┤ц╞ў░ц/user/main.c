#include "public.h"
int main()
{
	u32 i;
	RCC->APB2ENR=0x0010;
	GPIOC->CRL=0x11111111;
	while(1)
	{	
		GPIOC->BSRR=0xFFFF0000;	
		for(i=0;i<6000000;i++) ;
		GPIOC->BSRR=0x0000FFFF;
		for(i=0;i<6000000;i++) ;	
	}	
}



