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