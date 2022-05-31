/****************************************************************
                   Source file of main.c
****************************************************************/
#include "public.h"
u8 hour,minute,second;
u8 smgduan[11]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
u16 smgwei[6]={0x7fff,0xbfff,0xdfff,0xefff,0xf7ff,0xfbff};
/****************************************************************
* Function Name  : ShowADval
* Description    : Display ADC Value
* Input          : None
* Output         : None
****************************************************************/
//显示AD转换后的数值
void ShowADval(u8 cnum, u32 ADVal)
{
	u16 i,j;
	for(i=0;i<6000;i++)
	{
		GPIO_Write(GPIOE,smgwei[0]);	
		GPIO_Write(GPIOG,smgduan[cnum+1]);//显示通道号
		for(j=0;j<400;j++);
		GPIO_Write(GPIOE,smgwei[1]);	
		GPIO_Write(GPIOG,0xbf);//显示"-"
		for(j=0;j<400;j++);
		
		GPIO_Write(GPIOE,smgwei[2]);	
		GPIO_Write(GPIOG,smgduan[ADVal/1000]);
		for(j=0;j<400;j++);
		GPIO_Write(GPIOE,smgwei[3]);	
		GPIO_Write(GPIOG,smgduan[ADVal/100%10]);
		for(j=0;j<400;j++);
		
		GPIO_Write(GPIOE,smgwei[4]);	
		GPIO_Write(GPIOG,smgduan[ADVal%100/10]);
		for(j=0;j<400;j++);
		GPIO_Write(GPIOE,smgwei[5]);	
		GPIO_Write(GPIOG,smgduan[ADVal%10]);
		for(j=0;j<400;j++);		
	}
	GPIO_Write(GPIOG,0xff);//关所有数码管
}

/****************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
****************************************************************/
int main()
{
		u8 i; 
		u8 cnum;//通道号,0表示通道0	
		u32 ADVal;//AD转换结果
	
		DsgShowInit();//数码显示初始化
		adc1_init();//AD转换初始化
		while(1)
		{
			ADVal=0;		
			for(cnum=0;cnum<4;cnum++)
			{
				ADVal=0;
				ADC_RegularChannelConfig(ADC1, cnum, 1, ADC_SampleTime_55Cycles5 ); 
				for(i=0;i<20;i++)
					{
						ADC_SoftwareStartConvCmd(ADC1, ENABLE);
						while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//检测是否转换完成
						ADVal=ADVal+ADC_GetConversionValue(ADC1); 		
					}
				ADVal=ADVal/20;				
				ShowADval(cnum, ADVal);	//AD转换结果显示
			}
		}
	
}


