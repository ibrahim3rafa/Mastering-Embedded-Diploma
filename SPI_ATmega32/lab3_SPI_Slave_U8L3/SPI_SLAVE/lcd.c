/*
 * lcd.c
 *
 *  Created on: Jul 29, 2023
 *      Author: ARAFA
 */


#include"lcd.h"

void LCD_init(void){
	_delay_ms(20);
	LCD_DATA_PORT_DIR = 0xff;
	LCD_CTR_PORT_DIR  |=(1<<LCD_RW_PIN) | (1<<LCD_RS_PIN) |(1<<LCD_E_PIN);
	LCD_CTR_PORT &=~(1<<LCD_RW_PIN | 1<<LCD_RS_PIN | 1<<LCD_E_PIN);
	_delay_ms(15);

	LCD_clearScreen();
#if (LCD_DATA_BITS_MODE == 8)
	LCD_sendCommand(LCD_8_BITS_2_LINES_MODE);
#endif

#if (LCD_DATA_BITS_MODE == 4)
	LCD_sendCommand(LCD_CURSOR_HOME);
	LCD_sendCommand(LCD_8_BITS_2_LINES_MODE);
#endif

	LCD_sendCommand(LCD_ENTRY_MODE);
	LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_sendCommand(LCD_DISP_ON_CURSOR_BLINK);

}
void LCD_isBusy(void){


	LCD_DATA_PORT_DIR &= ~(0xff<<LCD_DATA_SHIFT);

	LCD_CTR_PORT |= (1<<LCD_RW_PIN);
	LCD_CTR_PORT &= ~(1<<LCD_RS_PIN);

	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	_delay_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

	LCD_DATA_PORT_DIR |= (0xff<<LCD_DATA_SHIFT);
	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN);



}
void LCD_sendCommand(unsigned char command){
#if (LCD_DATA_BITS_MODE == 8)
	LCD_isBusy();
	LCD_DATA_PORT = command;
	LCD_CTR_PORT &= ~((1<<LCD_RS_PIN) | (1<<LCD_RW_PIN)) ;
	_delay_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	_delay_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);


#endif

#if (LCD_DATA_BITS_MODE == 4)
	LCD_isBusy();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (command & 0xf0);
	LCD_CTR_PORT &= ~((1<<LCD_RS_PIN) | (1<<LCD_RW_PIN)) ;
	_delay_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	_delay_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | ((command<<4));
	LCD_CTR_PORT &= ~((1<<LCD_RS_PIN) | (1<<LCD_RW_PIN)) ;
	_delay_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	_delay_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

#endif
}
void LCD_displayCharacter(unsigned char data){
#if (LCD_DATA_BITS_MODE == 8)
	LCD_isBusy();
	LCD_DATA_PORT = data;
	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN) ;
	LCD_CTR_PORT |= (1<<LCD_RS_PIN);
	_delay_ms(1);

	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	_delay_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);


#endif

#if (LCD_DATA_BITS_MODE == 4)
	LCD_isBusy();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (data & 0XF0);
	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN) ;
	LCD_CTR_PORT |= (1<<LCD_RS_PIN);
	_delay_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	_delay_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (data << 4);
	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN) ;
	LCD_CTR_PORT |= (1<<LCD_RS_PIN);
	_delay_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	_delay_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

#endif
}
void LCD_displayString(const char* str){

	int count = 0;

	while(*str>0){
		count ++;
		LCD_displayCharacter(*str++);
		if(count == 16 ){
			LCD_moveRowColumn(2,0);
		}else if(count == 32){
			LCD_clearScreen();
			LCD_moveRowColumn(1,0);
			count = 0;
		}
	}
}
void LCD_moveRowColumn(unsigned char row, unsigned char column){

	if(row == 1 ){
		if(column >= 0 && column < 16){
			LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW+column);
		}
	}
	if(row == 2 ){
		if(column >= 0 && column < 16){
			LCD_sendCommand(LCD_BEGIN_AT_SECOND_ROW+column);
		}
	}
}
void LCD_clearScreen(void){
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}
