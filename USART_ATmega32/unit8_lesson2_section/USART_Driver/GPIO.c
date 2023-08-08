/*
 * GPIO.c
 *
 *  Created on: Aug 8, 2023
 *      Author: ARAFA
 */


#include"GPIO.h"


void Port_Direction(uint8_t port, uint8_t state){
	if(state == OUTPUT){
		port = 0xFF;
	}else if (state == INPUT){
		port = 0x00;
	}
}



void Pin_Direction (uint8_t port, uint8_t pin_num, uint8_t state){
	if(state == OUTPUT){
		port |= (1<<pin_num);
	}else if(state == INPUT)
	{
		port &= ~(1<<pin_num);
	}
}
