#include <REGX52.H>
/**
  * @brief 串口初始化，4800bps@11.0592MHz
  * @param 
  * @retval 
  */
void UART_Init() 
{
	PCON &= 0x80;		//波特率不倍速
	SCON = 0x50;		//允许接受
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA = 1;
	ES = 1;
}
/**
  * @brief 发送串口数据，一字节
  * @param 一个字节
  * @retval 
  */
void UART_SendBytes(unsigned char Bytes)
{
	SBUF = Bytes;
	while(TI == 0);
	TI = 0;
}

/*串口终端函数模板
void UART_Routine() interrupt 4
{
	if(RI == 1)
	{
		RI = 0;
	}
}

*/

