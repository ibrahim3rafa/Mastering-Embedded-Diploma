/*
 * Timer0_Driver.c
 *
 * Created: 8/28/2023 9:40:03 AM
 * Author : ARAFA
 */ 

#define  F_CPU 8000000UL
#include <avr/io.h>
#include "Timer0.h"

extern uint8_t g_overflow;

void ARAFA_CALLBACK(){
	PORTA = ~PORTA;
}
int main(void)
{
    /* Replace with your application code */
	DDRA = 0xFF;
	sei();
	Timer0_overcompare(ARAFA_CALLBACK);
	Config_Struct_t config = {Normal,CLK8,OCIE0};
	Timer0_SET_OCR0(0xF0);	
	Timer0_Init(&config);
	
    while (1) 
    {
    }
}

