#include <at89c51RC2.h>
#include "Delay.h"


/**
  * @brief  逐列扫描矩阵键盘
  * @param  无
  * @retval 松开时返回矩阵键盘的对应值
  */
unsigned char MatrixKey()
{
    unsigned char key = 0;
    P1 = 0xFF;
    P1_3 = 0;
    if(P1_7 == 0){Delayms(20); while(P1_7 == 0);Delayms(20); key = 1;}
    if(P1_6 == 0){Delayms(20); while(P1_6 == 0);Delayms(20); key = 5;}
    if(P1_5 == 0){Delayms(20); while(P1_5 == 0);Delayms(20); key = 9;}
    if(P1_4 == 0){Delayms(20); while(P1_4 == 0);Delayms(20); key = 13;}

    P1 = 0xFF;
    P1_2 = 0;
    if(P1_7 == 0){Delayms(20); while(P1_7 == 0);Delayms(20); key = 2;}
    if(P1_6 == 0){Delayms(20); while(P1_6 == 0);Delayms(20); key = 6;}
    if(P1_5 == 0){Delayms(20); while(P1_5 == 0);Delayms(20); key = 10;}
    if(P1_4 == 0){Delayms(20); while(P1_4 == 0);Delayms(20); key = 14;}

    P1 = 0xFF;
    P1_1 = 0;
    if(P1_7 == 0){Delayms(20); while(P1_7 == 0);Delayms(20); key = 3;}
    if(P1_6 == 0){Delayms(20); while(P1_6 == 0);Delayms(20); key = 7;}
    if(P1_5 == 0){Delayms(20); while(P1_5 == 0);Delayms(20); key = 11;}
    if(P1_4 == 0){Delayms(20); while(P1_4 == 0);Delayms(20); key = 15;}

    
    P1 = 0xFF;
    P1_0 = 0;
    if(P1_7 == 0){Delayms(20); while(P1_7 == 0);Delayms(20); key = 4;}
    if(P1_6 == 0){Delayms(20); while(P1_6 == 0);Delayms(20); key = 8;}
    if(P1_5 == 0){Delayms(20); while(P1_5 == 0);Delayms(20); key = 12;}
    if(P1_4 == 0){Delayms(20); while(P1_4 == 0);Delayms(20); key = 16;}

    return key;
}