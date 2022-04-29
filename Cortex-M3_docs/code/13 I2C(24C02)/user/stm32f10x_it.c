/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */
/****************************************************************
                 Source file of stm32f10x_it.c 
****************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "systick.h"
#include "AT24CXX.H"
#include "printf.h"
extern u8 hour,minute,second;


/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

/****************************************************************
* Function Name  : EXTI0_IRQHandler
* Description    : EXTI0 Interrupt program Hour plus 1
* Input          : None
* Output         : None
****************************************************************/
void EXTI0_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line0)==SET) 
	{
		EXTI_ClearFlag(EXTI_Line0);
		delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)==Bit_RESET)
		{	
			delay_ms(10);			
			if(++hour==24) hour=0;	
		}	
	}
}
/****************************************************************
* Function Name  : EXTI1_IRQHandler
* Description    : EXTI1 Interrupt program Minute plus 1
* Input          : None
* Output         : None
****************************************************************/
void EXTI1_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line1)==SET) 
	{
		
		EXTI_ClearFlag(EXTI_Line1);
		delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==Bit_RESET)
		{	
			delay_ms(10);			
			if(++minute==60) minute=0;	
		}		
	}
}




/****************************************************************
* Function Name  : TIM6_IRQHandler
* Description    : TIM6 Interrupts 1 times in 1 second
* Input          : None
* Output         : None
****************************************************************/
void TIM6_IRQHandler(void)
{ 
	TIM_ClearFlag(TIM6,TIM_IT_Update);
	if(++second==60)
	{
		second=0;
		if(++minute==60)
		{
			minute=0;
			if(++hour==24) hour=0;
		}
	}	
}

/****************************************************************
* Function Name  : USART1_IRQHandler
* Description    : USART Interrupts Get Time Value 
* Input          : None
* Output         : None
****************************************************************/
//串口一中断服务程序 静态变量K自加调节设置的小时分钟或是秒
void USART1_IRQHandler(void)	//串口1中断函数
{
	static unsigned char k=0;
	USART_ClearFlag(USART1,USART_FLAG_TC);
	k++;
	if(k%3==1)	hour=USART_ReceiveData(USART1);
	else if(k%3==2) minute= USART_ReceiveData(USART1);
	else second=USART_ReceiveData(USART1);
	USART_SendData(USART1,k);//通过外设USARTx发送单个数据
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==Bit_RESET);
}


/****************************************************************
* Function Name  : EXTI2_IRQHandler
* Description    : EXTI2 Interrupt program Second plus 1
* Input          : None
* Output         : None
****************************************************************/
void EXTI2_IRQHandler(void)
{
	EXTI_ClearFlag(EXTI_Line2);
	delay_ms(40);
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==Bit_RESET)
	{	
		delay_ms(40);	
		AT24Cxx_WriteOneByte(0,hour);
		AT24Cxx_WriteOneByte(1,minute);
		AT24Cxx_WriteOneByte(2,second);
		printf("按键按下时间为:%d:%d:%d\n",hour,minute,second);	
	}		
}



void EXTI3_IRQHandler(void)
{
	u8 ReadHour,ReadMinute,ReadSeond;
	EXTI_ClearFlag(EXTI_Line3);
	delay_ms(50);
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==Bit_RESET)
	{	
		delay_ms(50);	
		printf("当前系统时间:%d:%d:%d\n",hour,minute,second);
		delay_ms(50);	
		ReadHour=AT24Cxx_ReadOneByte(0);
		ReadMinute=AT24Cxx_ReadOneByte(1);
		ReadSeond=AT24Cxx_ReadOneByte(2);
		printf("读取按键时刻:%d:%d:%d\n",ReadHour,ReadMinute,ReadSeond);		
	}	
}

