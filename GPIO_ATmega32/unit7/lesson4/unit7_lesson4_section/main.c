/*
 * main.c
 *
 *  Created on: Aug 6, 2023
 *      Author: ARAFA
 */


#include "lcd.h"
#include"gpio.h"

int main(){

//	 Port_Direction(PORTA,OUTPUT);


	 LCD_INIT();

	 LCD_WRITE_STRING("Learn In Depth");


	while(1){

	}
}
