/****************************************************************
                   Source file of EXTI.C
****************************************************************/

#include "EXTI.H"
/****************************************************************
* Function Name  : EXTIInti
* Description    : EXTI Initialization
* Input          : None
* Output         : None
* Return         : None
****************************************************************/
void EXTIInti()
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure; 
	NVIC_InitTypeDef NVIC_InitStructure;
		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO , ENABLE);
	/* 	GPIO管脚初始化 上拉输入模式  */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_Init(GPIOE, &GPIO_InitStructure); 
	//选择GPIO管脚用作外部中断线路  此处一定要记住给端口管脚加上中断外部线路
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource0); //PE0:hour+
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource1); //PE1:minute+
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2); //PE2:second+
	
 
	 /* 设置外部中断的模式 PE0 PE1 PE2中断初始化*/ 
	EXTI_InitStructure.EXTI_Line = EXTI_Line0|EXTI_Line1|EXTI_Line2;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt; 
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; 
	EXTI_InitStructure.EXTI_LineCmd = ENABLE; 
	EXTI_Init(&EXTI_InitStructure); 
	
	//NVIC优先级分组 抢占式优先2位四级 响应式优先级2位四级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	/* 设置NVIC参数 */	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; //指定中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;//配置抢占式优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//配置响应式优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //中断使能
	NVIC_Init(&NVIC_InitStructure); 	
	
	/* 设置NVIC参数 */	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn; //指定中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;//配置抢占式优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//配置响应式优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //中断使能
	NVIC_Init(&NVIC_InitStructure); 	
	
	/* 设置NVIC参数 */	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn; //指定中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;//配置抢占式优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;//配置响应式优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //中断使能
	NVIC_Init(&NVIC_InitStructure); 	

}


