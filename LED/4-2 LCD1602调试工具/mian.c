#include <at89c51RC2.h>
#include "LCD1602.h"

void main()
{
	LCD_Init();
	LCD_ShowChar(1,1,'a');
	LCD_ShowString(1,3,"Hello world");
	LCD_ShowNum(2,1,123,3);
	while(1)
	{
	}
}