/****************************************************************
                   Source file of timer.c
****************************************************************/
#include "timer.h"
/****************************************************************
* Function Name  : TIM6Init
* Description    : TIM6 Initialization
* Input          : None
* Output         : None
* Return         : None
****************************************************************/
void TIM6Init()
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; 
	NVIC_InitTypeDef NVIC_InitStructure;
	//打开TIM6的APB1时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6 , ENABLE);
	//设置自动重装载寄存器周期的值 寄存器的值为周期值-1
	TIM_TimeBaseStructure.TIM_Period = 36000-1; 
	//设置预分频系数 预分频寄存器的值为分频系数-1
	TIM_TimeBaseStructure.TIM_Prescaler = 2000-1;
	//设置时钟分割:TDTS = Tck_tim	
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	//TIM向上计数模式
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	//初始化TIM6定时器
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); 
	//清除TIMx的中断待处理位:TIMx 中断源
	TIM_ClearFlag(TIM6,TIM_FLAG_Update);
	/* 设置中断参数，并打开中断 */
	TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
	//使能或者失能TIMx外设
	TIM_Cmd(TIM6,ENABLE);	
	/* 设置NVIC参数 设优先级 开中断*/
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn; //指定中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;//配置抢占式优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;//配置响应式优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //中断使能
	NVIC_Init(&NVIC_InitStructure); 	
}




