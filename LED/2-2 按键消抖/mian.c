#include <at89c51RC2.h>
//机械按键的开关闭合瞬间，由于弹性作用会有一个5-10ms的抖动，可以通过delay软件消抖
void Delayms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
		
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}

}


unsigned int right_i = 0; //右移
void main()
{
	while(1)
	{
		if(P3_1 == 0)
		{
			Delayms(20);
			while(P3_1 == 0);
			Delayms(20);//按键消抖
			P2 = 0xFF;
			P2 &= ~(1<<right_i);
			right_i++;
			if(right_i > 7 )
			{
				right_i = 0;
			}
		}
		
	}
}