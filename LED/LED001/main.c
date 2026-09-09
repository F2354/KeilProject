#include <at89c51RC2.h>
#include <INTRINS.H>
//liushuideng
void Delayms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j, k; //i wei xunhuancishu yici wei 100ms

	_nop_();
	i = xms-1;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{

	while(1){
		int i;		
		for(i = 0;i<8;i++)
		{
			P2 = 0xFF;
			P2 &= ~(1<<i);
			Delayms(5);
		}
		
	}
}