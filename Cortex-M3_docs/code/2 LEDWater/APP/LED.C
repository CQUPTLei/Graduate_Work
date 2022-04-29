#include "LED.h"

void LEDInit()
{
		
	GPIO_InitTypeDef GPIO_InitStructure; 
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE); 
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ; 
	GPIO_Init(GPIOC, &GPIO_InitStructure); 

}	

void LEDdisplay()
{ 
	u32 i;
  GPIO_SetBits(GPIOC, GPIO_Pin_All);	
	GPIO_ResetBits(GPIOC, GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_6); 
	for(i=0;i<18000000;i++) ;
	while(1)
	{
	GPIO_Write(GPIOC, 0xfe); 
	for(i=0;i<6000000;i++) ;
	GPIO_Write(GPIOC, 0xfd); 
	for(i=0;i<6000000;i++) ;
	GPIO_Write(GPIOC, 0xfb); 
	for(i=0;i<6000000;i++) ;
	GPIO_Write(GPIOC, 0xf7); 
	for(i=0;i<6000000;i++) ;
	GPIO_Write(GPIOC, 0xef); 
	for(i=0;i<6000000;i++) ;
	GPIO_Write(GPIOC, 0xdf); 
	for(i=0;i<6000000;i++) ;
	GPIO_Write(GPIOC, 0xbf); 
	for(i=0;i<6000000;i++) ;
	GPIO_Write(GPIOC, 0x7f); 
	for(i=0;i<6000000;i++) ;
	}
 

}
