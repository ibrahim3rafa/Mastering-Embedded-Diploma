/*
 * WDT_ATmega32.c
 *
 * Created: 8/28/2023 5:51:49 PM
 * Author : ARAFA
 */ 

#define  F_CPU 1000000

#include <avr/io.h>
#include "avr/interrupt.h"
#include "util/delay.h"

void WDT_Init(){
	//2.1s delay
	WDTCR = (1 << WDE ) | (1 << WDP0) | (1 << WDP1) | (1 << WDP2);
}


void WDT_Reset(){
	
	WDTCR = (1 << WDE) | (1 << WDTOE);
	
	//write 0 within 4 clock cycles
	
	WDTCR =0x00;
}

int main(void)
{
	DDRD |= (1 << PD6);
	PORTD &= ~(1 << PD6);
	WDT_Init();
	PORTD |= (1 << PD6);
	_delay_ms(1000);
	PORTD &= ~(1<<PD6);
    /* Replace with your application code */
    while (1) 
    {
    }
}

