/*
 * Generate_500Khz_CLK.c
 *
 * Created: 8/28/2023 12:32:08 PM
 * Author : ARAFA
 */ 

#define F_CPU 1000000UL
unsigned char g_tick = 0;

#include <avr/io.h>
#include "avr/interrupt.h"
#include "util/delay.h"

void PWM_mode(unsigned char tick){
	TCNT0 = 0;
	
	OCR0 = tick;
	
	
	/*prescaler 8 , pwm mode , clear on compare(non inverting )*/
	TCCR0 = (1 << CS01) | (1 << WGM01) | (1 << WGM00) | (1 << COM01);
	
}

int main(void)
{
	DDRB |= (1 << PB3);
	sei();
	PWM_mode(128);
	_delay_ms(5000);
	PWM_mode(64);
	    /* Replace with your application code */
    while (1) 
    {
    }
}

