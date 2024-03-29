/*
 * lcd.c
 *
 *  Created on: Jul 29, 2023
 *      Author: ARAFA
 */


#include <STM32F103x8.h>
#include "lcd.h"

#include "../../MCAL/includes/GPIO_driver.h"

//global variable
GPIO_pinConfig pinCFG ;


void wait_ms(uint32_t time){
	uint32_t i,j ;
	for(i=0 ; i<time ; i++){
		for(j=0 ; j<255; j++);
	}
}

void LCD_tick(){
	/*
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	wait_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);
	 */
	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_E_PIN, LCD_E_PIN_SET);
	asm volatile ("nop");
	asm volatile ("nop");
	wait_ms(50);
	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_E_PIN, LCD_E_PIN_RESET);
}

void LCD_GPIO_init(){
	pinCFG.GPIO_PinNum = LCD_E_PIN;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTR_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = LCD_RW_PIN;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTR_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = LCD_RS_PIN;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_CTR_PORT, &pinCFG);


	//	LCD_DATA_PORT_DIR = 0xff;
	pinCFG.GPIO_PinNum = GPIO_PIN_0;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_1;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_2;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);


	pinCFG.GPIO_PinNum = GPIO_PIN_3;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_4;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_5;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_6;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_7;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);



	//	LCD_CTR_PORT &=~(1<<LCD_RW_PIN | 1<<LCD_RS_PIN | 1<<LCD_E_PIN);
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, LCD_RW_PIN , GPIO_PIN_RESET);
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, LCD_RS_PIN , GPIO_PIN_RESET);
	MCAL_GPIO_Write_Pin(LCD_DATA_PORT, LCD_E_PIN , GPIO_PIN_RESET);



}
void LCD_init(void){


	wait_ms(20);

	LCD_GPIO_init();

	wait_ms(15);


	LCD_clearScreen();
	/*
#if (LCD_DATA_BITS_MODE == 8)
	LCD_sendCommand(LCD_8_BITS_2_LINES_MODE);
#endif

#if (LCD_DATA_BITS_MODE == 4)
	LCD_sendCommand(LCD_CURSOR_HOME);
	LCD_sendCommand(LCD_8_BITS_2_LINES_MODE);
#endif
	 */
	LCD_sendCommand(LCD_8_BITS_2_LINES_MODE);
	LCD_sendCommand(LCD_ENTRY_MODE);
	LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_sendCommand(LCD_DISP_ON_CURSOR_BLINK);

}
void LCD_isBusy(void){


	/*	LCD_DATA_PORT_DIR &= ~(0xff<<LCD_DATA_SHIFT);*/
	pinCFG.GPIO_PinNum = GPIO_PIN_0;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_1;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_2;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_3;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_4;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_5;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_6;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_7;
	pinCFG.GPIO_PinMode = INPUT_FLOATING_MODE;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	//	LCD_CTR_PORT &= ~(1<<LCD_RS_PIN);
	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_RS_PIN, LCD_RS_PIN_RESET);

	//	LCD_CTR_PORT |= (1<<LCD_RW_PIN);
	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_RW_PIN, LCD_RW_PIN_READ);



	LCD_tick();

/*

	//	LCD_DATA_PORT_DIR = 0xff;
	pinCFG.GPIO_PinNum = GPIO_PIN_0;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_1;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_2;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);


	pinCFG.GPIO_PinNum = GPIO_PIN_3;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_4;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_5;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_6;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

	pinCFG.GPIO_PinNum = GPIO_PIN_7;
	pinCFG.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(LCD_DATA_PORT, &pinCFG);

*/

	/*	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN);*/

	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_RW_PIN, LCD_RW_PIN_WRITE);


}
void LCD_sendCommand(unsigned char command){
	//#if (LCD_DATA_BITS_MODE == 8)
	//LCD_isBusy();
	/*	LCD_DATA_PORT = command; */
	MCAL_GPIO_Write_Port(LCD_DATA_PORT, command);

	/*	LCD_CTR_PORT &= ~((1<<LCD_RS_PIN) | (1<<LCD_RW_PIN)) ;*/
	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_RS_PIN, LCD_RS_PIN_RESET);
	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_RW_PIN, LCD_RW_PIN_WRITE);

	wait_ms(1);

	/*
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	wait_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);
	 */
	LCD_tick();

	//#endif

	/*
#if (LCD_DATA_BITS_MODE == 4)
	LCD_isBusy();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | (command & 0xf0);
	LCD_CTR_PORT &= ~((1<<LCD_RS_PIN) | (1<<LCD_RW_PIN)) ;
	wait_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	wait_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0f) | ((command<<4));
	LCD_CTR_PORT &= ~((1<<LCD_RS_PIN) | (1<<LCD_RW_PIN)) ;
	wait_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	wait_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

#endif
	 */
}
void LCD_displayCharacter(unsigned char data){
	/*#if (LCD_DATA_BITS_MODE == 8)*/
	//LCD_isBusy();
	MCAL_GPIO_Write_Port(LCD_DATA_PORT, data);

	/*	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN) ;
	LCD_CTR_PORT |= (1<<LCD_RS_PIN);*/

	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_RS_PIN, LCD_RS_PIN_SET);
	MCAL_GPIO_Write_Pin(LCD_CTR_PORT, LCD_RW_PIN, LCD_RW_PIN_WRITE);

	wait_ms(1);
	/*

	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	wait_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);
	 */

	LCD_tick();


	/*#endif*/
	/*

#if (LCD_DATA_BITS_MODE == 4)
	LCD_isBusy();
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (data & 0XF0);
	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN) ;
	LCD_CTR_PORT |= (1<<LCD_RS_PIN);
	wait_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	wait_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (data << 4);
	LCD_CTR_PORT &= ~(1<<LCD_RW_PIN) ;
	LCD_CTR_PORT |= (1<<LCD_RS_PIN);
	wait_ms(1);
	LCD_CTR_PORT |= (1<<LCD_E_PIN);
	wait_ms(50);
	LCD_CTR_PORT &= ~(1<<LCD_E_PIN);

#endif
	 */
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
