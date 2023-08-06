/*
 * main.c
 *
 *  Created on: Jul 27, 2023
 *      Author: ARAFA
 */


#define PIND  *(volatile unsigned char *)0x30
#define DDRD  *(volatile unsigned char *)0x31
#define PORTD  *(volatile unsigned char *)0x32



int main(){

	DDRD = 0XF0;     //SET pins output
	PORTD = 0;		// set all off at begining
	while(1){
		PORTD |= (1<<5);
		for(int i = 0 ; i<1000 ; i++);			// turn on pd5 for a while
		PORTD |= (1<<6);
		for(int i = 0 ; i<1000 ; i++);		// turn on pd6 for a while
		PORTD |= (1<<7);
		for(int i = 0 ; i<1000 ; i++);		// turn on pd7 for a while
		PORTD |= (1<<4);
		for(int i = 0 ; i<1000 ; i++);		// turn on pd4 (buzzer for a while
		PORTD = 0;
		for(int i = 0 ; i<1000 ; i++);			// turn off all for a while



	}

	return 0;
}
