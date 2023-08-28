/*
 * Control_LED_Brightness.c
 *
 * Created: 8/28/2023 3:37:26 PM
 * Author : ARAFA
 */ 

#define  F_CPU  1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
/*unsigned char g_tick = 0;*/
/*
ISR(TIMER0_COMP_vect)
{
	g_tick++;
	if (g_tick == 2)
	{
		
	}else if (g_tick == 4)
	{
	}
	
}
*/
void PWM_Mode(unsigned char tick){
	
	TCNT0 = 0;
	
	OCR0 = tick;
	
	//TIMSK = (1 << OCIE0);
	
	TCCR0 = (1 << CS01) | (1 << COM01) | (1 << WGM01 ) | (1 << WGM00) ;
	
}


int main(void)
{
	DDRB |= (1 << PB3);
	

				

    /* Replace with your application code */
    while (1) 
    {
			PWM_Mode(64);
			
			_delay_ms(5000);
			
			PWM_Mode(128);
			
			_delay_ms(5000);
			
			PWM_Mode(250);
			
			_delay_ms(5000);
    }
}

