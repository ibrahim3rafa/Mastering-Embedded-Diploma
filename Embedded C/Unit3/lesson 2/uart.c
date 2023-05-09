//@learn_in_Depth 
//Mastering Embedded Diploma 
//Author: Ibrahim Arafa 
//lab 1 "Embedded C"


#include "uart.h"

//uart registers

#define UART0DR  		*((volatile unsigned int *)((unsigned int*)0x101f1000))

void Uart_Send_string(unsigned char* P_tx_string){

	while(*P_tx_string != '\0'){
		UART0DR = (unsigned int)(*P_tx_string);
		P_tx_string++;
	}
}

