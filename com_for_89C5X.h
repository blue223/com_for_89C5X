//实现com_intrrupt(char temp)函数
#include <reg52.h>
void send_string_to_com(unsigned char *point);	 //串口发送字符串
void seng_char_to_com(char temp);                //串口发送字符
void init_com();	                             //串口初始化