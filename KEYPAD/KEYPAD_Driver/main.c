/*
 * main.c
 *
 *  Created on: Jul 30, 2023
 *      Author: ARAFA
 */


#include"lcd.h"
#include"keypad.h"
#include<util/delay.h>


int main(){


	LCD_init();
	KEYPAD_init();
		_delay_ms(50);
		unsigned char key_pressed;
		while(1){
			key_pressed = KEYPAD_getKey();
			switch(key_pressed){
				case 'A':
					break;
				case '?':
					LCD_clearScreen();
					break;
				default:
					LCD_sendCommand(key_pressed);
					break;
			}
		}


	return 0;
}
