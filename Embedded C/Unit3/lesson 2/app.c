//@learn_in_Depth 
//Mastering Embedded Diploma 
//Author: Ibrahim Arafa 
//lab 1 "Embedded C"

#include"uart.h"

unsigned char string_buffer[100] = "learn-in-depth:<ARAFA>";

void main(void)
{
	Uart_Send_string(string_buffer);

}