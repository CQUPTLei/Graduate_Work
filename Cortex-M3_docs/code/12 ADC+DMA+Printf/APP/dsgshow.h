/********************************************************************
                     文件"dsgshow.h"源程序
********************************************************************/
#ifndef _DSGSHOW_H
#define _DSGSHOW_H
#include "stm32f10x.h"
void DsgShowInit(void);
void DsgShowNum(void);
void DsgShowTime(void);
void ShowADval(u8 cnum, u32 ADVal);
#endif


