/****************************************************************
                  Source file of DMA-ADC.C
****************************************************************/
#include "DMA-ADC.H"
extern u16 AD_Value[20][4]; //AD转换结果4个通道每个通道20次
extern u16 After_filter[4]; //滤波后的数值 共4个通道

//使用DMA传输的ADC初始化程序
void ADC_Use_DMA_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	ADC_InitTypeDef ADC_InitStructure; 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 
	GPIO_Init(GPIOA, &GPIO_InitStructure); 	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO|RCC_APB2Periph_ADC1 , ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent; 
	ADC_InitStructure.ADC_ScanConvMode = ENABLE; 
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE; 
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; 
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 
	ADC_InitStructure.ADC_NbrOfChannel = 4; //此次转换共六个通道PA0~PA3
	ADC_Init(ADC1, &ADC_InitStructure); 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5 ); 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_55Cycles5 ); 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 3, ADC_SampleTime_55Cycles5 ); 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 4, ADC_SampleTime_55Cycles5 ); 
	ADC_DMACmd(ADC1, ENABLE);//开启ADC的DMA支持 具体数据读取还需要进一步配置DMA	
	ADC_Cmd(ADC1,ENABLE);
	ADC_ResetCalibration(ADC1); 
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);

}

//DMA控制器初始化程序
void DMA_For_ADC_Init()
{
	DMA_InitTypeDef DMA_InitStructure;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE); //开启DMA时钟

	DMA_DeInit(DMA1_Channel1); //初始化为缺省值
	DMA_InitStructure.DMA_PeripheralBaseAddr = (u32)&ADC1->DR; //DMA外设ADC基地址
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&AD_Value; //DMA内存基地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC; //内存作为DMA目的地址
	DMA_InitStructure.DMA_BufferSize = 4*20; //缓冲区的大小
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //外设基地址不变
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; //内存基址递增
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; //数据宽度16位
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord; //数据宽度16位
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular; //工作在循环缓存模式
	DMA_InitStructure.DMA_Priority = DMA_Priority_High; //DMA高优先级
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //DMA没有设置为内存到内存模式
	DMA_Init(DMA1_Channel1, &DMA_InitStructure); //初始化


}

//ADC转换结果中值滤波函数
void filter()
{
	u32 sum = 0;
	u8 i,j;
	//4个通道20次
	for(i=0;i<4;i++)
	{
		sum=0;
		for(j=0;j<20;j++)	sum += AD_Value[j][i];	
		After_filter[i]=sum/20;
	}
}



