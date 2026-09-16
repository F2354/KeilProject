#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__
void _74HC595_WriteBytes(unsigned char Bytes);
void MatrixLED_ShowColumn(unsigned char Column,unsigned char Data);
void MatrixLED_Init();
#endif
