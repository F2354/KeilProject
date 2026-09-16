#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Key.h"
#include "Timer0.h"


unsigned char KeyNum,Mode,TimeSetSelect;

void TimeShow()
{
	DS1302_ReadTime();//读取时间
	LCD_ShowNum(1,1,DS1302_Time[0],2);//显示年
	LCD_ShowNum(1,4,DS1302_Time[1],2);//显示月
	LCD_ShowNum(1,7,DS1302_Time[2],2);//显示日
	LCD_ShowNum(2,1,DS1302_Time[3],2);//显示时
	LCD_ShowNum(2,4,DS1302_Time[4],2);//显示分
	LCD_ShowNum(2,7,DS1302_Time[5],2);//显示秒
}

void TimeSet()
{
	if(KeyNum==2)
	{
		TimeSetSelect++;
		TimeSetSelect%=6;
	}
	if(KeyNum==3)
	{
		DS1302_Time[TimeSetSelect]++;
		if(DS1302_Time[0]>99)//年
		{
			DS1302_Time[0]=0;
		}
		if(DS1302_Time[1]>12)
		{
			DS1302_Time[1]=1;
		}
		if(DS1302_Time[1]==2)//闰年判断
		{
			if(DS1302_Time[0]%4==0&&DS1302_Time[0]%100!=0||DS1302_Time[0]%400==0)
			{
				if(DS1302_Time[2]>29)//日
				{
					DS1302_Time[2]=1;
				}
			}
			else
			{
				if(DS1302_Time[2]>28)//日
				{
					DS1302_Time[2]=1;
				}
			}
		}
		if(DS1302_Time[1]==1||DS1302_Time[1]==3||DS1302_Time[1]==5||DS1302_Time[1]==7||DS1302_Time[1]==8||DS1302_Time[1]==10||DS1302_Time[1]==12)
		{
			if(DS1302_Time[2]>31)//日
			{
				DS1302_Time[2]=1;
			}
		}
		if(DS1302_Time[1]==4||DS1302_Time[1]==6||DS1302_Time[1]==9||DS1302_Time[1]==11)
		{
			if(DS1302_Time[2]>30)//日
			{
				DS1302_Time[2]=1;
			}
		}
		if(DS1302_Time[3]>23)
		{
			DS1302_Time[3]=0;
		}
		if(DS1302_Time[4]>59)
		{
			DS1302_Time[4]=0;
		}
		if(DS1302_Time[5]>59)
		{
			DS1302_Time[5]=0;
		}
	}
	if(KeyNum==4)
	{
		DS1302_Time[TimeSetSelect]--;
		if(DS1302_Time[0]<0)
		{
			DS1302_Time[0]=99;
		}
		if(DS1302_Time[1]<1)
		{
			DS1302_Time[1]=12;
		}
		if(DS1302_Time[2]<1)
		{
			if(DS1302_Time[1]==2)//闰年判断
			{
				if(DS1302_Time[0]%4==0)
				{
					DS1302_Time[2]=29;
				}
				else
				{
					DS1302_Time[2]=28;
				}
			}
			if(DS1302_Time[1]==1||DS1302_Time[1]==3||DS1302_Time[1]==5||DS1302_Time[1]==7||DS1302_Time[1]==8||DS1302_Time[1]==10||DS1302_Time[1]==12)
			{
				DS1302_Time[2]=31;
			}
			if(DS1302_Time[1]==4||DS1302_Time[1]==6||DS1302_Time[1]==9||DS1302_Time[1]==11)
			{
				DS1302_Time[2]=30;
			}
		}
		if(DS1302_Time[3]<0)
		{
			DS1302_Time[3]=23;
		}
		if(DS1302_Time[4]<0)
		{
			DS1302_Time[4]=59;
		}
		if(DS1302_Time[5]<0)
		{
			DS1302_Time[5]=59;
		}
	}
	LCD_ShowNum(2,10,TimeSetSelect,2);//显示选择

	LCD_ShowNum(1,1,DS1302_Time[0],2);//显示年
	LCD_ShowNum(1,4,DS1302_Time[1],2);//显示月
	LCD_ShowNum(1,7,DS1302_Time[2],2);//显示日
	LCD_ShowNum(2,1,DS1302_Time[3],2);//显示时
	LCD_ShowNum(2,4,DS1302_Time[4],2);//显示分
	LCD_ShowNum(2,7,DS1302_Time[5],2);//显示秒
}

void main()
{
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1,1,"  -  -  ");//静态字符初始化显示
	LCD_ShowString(2,1,"  :  :  ");
	
	
	
	while(1)
	{
		DS1302_SetTime();//设置时间
		KeyNum = Key();
		if(KeyNum==1)
		{
			if(Mode==0)Mode=1;
			else Mode=0;
		}
		switch(Mode)
		{
			case 0:TimeShow();break;
			case 1:TimeSet();break;
		}

	}
}

