/*
 * main.c
 *
 *  Created on: Aug 8, 2023
 *      Author: ARAFA
 */


#include"GPIO.h"
#include"usart.h"
#include"lcd.h"



int main(){

	Pin_Direction(PORTD, 1, OUTPUT);
	Pin_Direction(PORTD, 0, INPUT);

	LCD_INIT();
	USART_Init();

	USART_sendByte('a');
	uint8_t key ;
	while(1){
		key = USART_recieveByte();
	LCD_WRITE_CHAR(key);
	}
}
