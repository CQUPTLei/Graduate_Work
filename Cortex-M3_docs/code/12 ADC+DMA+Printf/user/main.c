/****************************************************************
                   Source file of main.c
****************************************************************/
#include "public.h"
u8 hour,minute,second;
u8 smgduan[11]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
u16 smgwei[6]={0x7fff,0xbfff,0xdfff,0xefff,0xf7ff,0xfbff};

//此处要注意一维下标为次数二维下标为通道数 因为采集是分次进行的
u16 AD_Value[20][4]; //AD转换结果4个通道每个通道20次
u16 After_filter[4]; //滤波后的数值 共4个通道

/****************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
****************************************************************/
int main()
{
	int i;
	printf_init();
	ADC_Use_DMA_Init();
	DMA_For_ADC_Init();
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	DMA_Cmd(DMA1_Channel1, ENABLE); //启动DMA通道
	delay_ms(1000);delay_ms(1000);//延时一两秒钟使得内存数据可以更新
	while(1)
	{		
		filter();
		for(i=0;i<4;i++)
		{
			printf("Channel=PA%d,ADVal=%d\n",i,After_filter[i]);	
			delay_ms(1000);	
			printf("Voltage=%0.3fV\n\n",After_filter[i]*3.3/4096);
			delay_ms(1000);delay_ms(1000);delay_ms(1000);			
		}	
	}
			
}


