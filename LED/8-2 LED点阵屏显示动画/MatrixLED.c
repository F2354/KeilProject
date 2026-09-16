#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3^5;	//RCLK 给高电平把数据送到io口
sbit SCK = P3^6;	//SRCLK 给高电平时移位，即下移
sbit SER = P3^4;	//SER 存01数据的

#define MATRIX_LED_PORT P0

/**
  * @brief  74HC595写入一个字节
  * @param 写入的字节
  * @retval 
  */
void _74HC595_WriteBytes(unsigned char Bytes)
{
	unsigned char i;
	for(i = 0;i<8;i++)
	{
		SER = Bytes&(0x80>>i); //非0即1
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

/**
  * @brief LED显示一列数据
  * @param Column为要选择的列 0-7，Data是要显示的数据，高位在上，1点亮
  * @retval 
  */
void MatrixLED_ShowColumn(unsigned char Column,unsigned char Data)
{
	_74HC595_WriteBytes(Data);
	MATRIX_LED_PORT = ~(0x80>>Column);//列是阴极，低电平点亮
	Delay(1);
	MATRIX_LED_PORT = 0xFF;
}

/**
  * @brief 初始化
  * @param 
  * @retval 
  */
void MatrixLED_Init()
{
	SCK = 0;
	RCK = 0;
}