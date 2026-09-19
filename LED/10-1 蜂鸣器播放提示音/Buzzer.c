#include <REGX52.H>

#include <INTRINS.H>
sbit Buzzer = P2^5;
/**
  * @brief 延时500ms
  * @param 
  * @retval 
  */
void Buzzer_Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}
/**
  * @brief 蜂鸣器发声
  * @param ms 发声的时长
  * @retval 
  */
void Buzzer_Time(unsigned int ms)
{      
	unsigned char data i;	
    for(i=0;i<ms*2;i++)
    {
        Buzzer = !Buzzer;
        Buzzer_Delay500us();
    }
}