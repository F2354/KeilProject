#include <at89c51RC2.h>
#include "Delay.h"
#include "LCD1602.h"
#include "MATRIXKEY.h"

unsigned char KeyNum;
void main()
{
    LCD_Init();
    LCD_ShowString(1, 1, "MatrixKey:");
    while (1)
    {
        KeyNum = MatrixKey();
        if(KeyNum)
        {
            LCD_ShowNum(2, 1, KeyNum, 2);
        }

    }
}