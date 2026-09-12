#include <at89c51RC2.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MATRIXKEY.h"

unsigned char KeyNum;

unsigned int password,count;

void main()
{
    LCD_Init();
    LCD_ShowString(1, 1, "Password:");
    while (1)
    {
        KeyNum = MatrixKey();
        if(KeyNum)
        {
            if(KeyNum <= 10&& count<4)//s1-s10是密码按键
            {
				password *= 10;//左移一位
                password += KeyNum % 10;
				count++;//计数4次
				LCD_ShowNum(2, 1, password, 4);
            }
            if(KeyNum == 11)//s11为确认
			{
				if(password == 829) 
				{
					LCD_ShowString(1,14,"OK ");
					password = 0;
					count = 0;
					LCD_ShowNum(2, 1, password, 4);
				}
				else
				{
					LCD_ShowString(1,14,"ERR");
					password = 0;
					count = 0;	
					LCD_ShowNum(2, 1, password, 4);
				}
			}
			if(KeyNum == 12)//取消键
			{
				password = 0;
				count = 0;
				KeyNum = 0;
				LCD_ShowNum(2, 1, password, 4);
				LCD_ShowString(1,14,"   ");				
			}

        }

    }
}