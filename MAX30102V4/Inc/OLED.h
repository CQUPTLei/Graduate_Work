#ifndef __OLED_H
#define	__OLED_H

#include "main.h"

#define OLED_ADDRESS	0x78

void I2C_WriteByte(uint8_t addr,uint8_t data);		//��Ĵ�����������
void OLED_WriteCmd(uint8_t command);					//д����
void OLED_WriteData(uint8_t data);						//д����
void OLED_Init(void);									//�ϵ��ʼ��
void OLED_SetPos(uint8_t x, uint8_t y);				//������ʼ����
void OLED_Clear(void);								//����
void OLED_ON(void); 									//������Ļ
void OLED_OFF(void);									//�ر���Ļ
void OLED_ShowChar(uint8_t x,uint8_t y, uint8_t c);     //��ʾ�ַ���
void OLED_ShowCN(uint8_t x,uint8_t y,uint8_t n);					//��ʾ����
void OLED_DrawBMP(uint8_t x0,uint8_t y0,uint8_t x1,uint8_t y1);  //��ʾͼ��
void OLED_ShowNum(uint8_t x,uint8_t y,uint8_t num);
#endif
