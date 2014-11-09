#include <com_for_89C5X.h>
void send_string_to_com(unsigned char *point)  //串口发送字符串
{
 	for(;*point!='\0';point++)
	{
		SBUF=*point;
		while(TI == 0);
		TI = 0;	
	}
}
void seng_char_to_com(char temp)	//串口发送字符
{
	SBUF = temp;
	while(TI == 0)
	TI = 0;
}
void ser() interrupt 4 //接受中断
{  
	RI=0;
	com_intrrupt(SBUF);
}
void init_com()	  //串口初始化
{
	SCON = 0x40;
	TMOD = 0x20;
	TH1  = 0xfd;
	TL1  = 0xfd;
	TI   = 0;
	TR1  = 1;
	REN=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;
}