#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "lcd1602.h"

unsigned char Sec=55,Min=59,Hour=23;
void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1, 1, "Clock ");
	LCD_ShowString(1, 7, "  :  :  ");
	while(1)
	{
		LCD_ShowNum(1, 13, Sec, 2);
		LCD_ShowNum(1, 10, Min, 2);
		LCD_ShowNum(1, 7, Hour, 2);
	}
	
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count >= 1000)
	{
		T0Count = 0;
		Sec++;
		if(Sec >= 60)
		{
			Sec = 0;
			Min++;
			if(Min >= 60)
			{
				Min = 0;
				Hour++;
				if(Hour >= 24)
				{
					Hour = 0;
				}
			}
		}
	}
	
}