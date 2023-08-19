/*
 * lcd.h
 *
 *  Created on: Jul 29, 2023
 *      Author: ARAFA
 */

#ifndef LCD_H_
#define LCD_H_

#include "../../MCAL/includes/GPIO_driver.h"
#include "../../MCAL/includes/STM32F103x6.h"

/*

// check data bit mode
#define LCD_DATA_BITS_MODE 		8

#if ((LCD_DATA_BITS_MODE != 4) && ((LCD_DATA_BITS_MODE != 8)))

#error  	"Number of data BITS should be 4 or 8"

#endif
 */
//data information
#define LCD_DATA_PORT   						GPIOA


//control information
#define LCD_CTR_PORT 							GPIOA


#define LCD_E_PIN 								(GPIO_PIN_10)
#define LCD_RS_PIN 								(GPIO_PIN_8)
#define LCD_RW_PIN 								(GPIO_PIN_9)

#define LCD_RW_PIN_READ 						(1)
#define LCD_RW_PIN_WRITE 						(0)

#define LCD_RS_PIN_SET 							(1)
#define LCD_RS_PIN_RESET 						(0)

#define LCD_E_PIN_SET 							(1)
#define LCD_E_PIN_RESET 						(0)

#define LCD_DATA_SHIFT							(4)

//LCD commands
#define LCD_8_BITS_2_LINES_MODE  				(0X38)
#define LCD_4_BITS_2_LINES_MODE 				(0X28)
#define LCD_ENTRY_MODE 							(0X06)
#define LCD_CURSOR_ON 							(0X0E)
#define LCD_CURSOR_OFF							(0X0C)
#define LCD_CLEAR_DISPLAY						(0X01)
#define LCD_CURSOR_HOME 						(OX02)	//Returns cursor to home position (address 0). Also returns display being shifted to the original position. DDRAM contents remains unchanged.
#define LCD_BEGIN_AT_FIRST_ROW					(0x80)
#define LCD_BEGIN_AT_SECOND_ROW					(0xC0)
#define LCD_DISP_ON_CURSOR_BLINK				(0x0F)

// check data BITS mode
//#define LCD_DATA_BITS_MODE 		8

//LCD FUNS
void LCD_init(void);
void LCD_isBusy(void);
void LCD_sendCommand(unsigned char command);
void LCD_displayCharacter(unsigned char data);
void LCD_displayString(const char* str);
void LCD_moveRowColumn(unsigned char row, unsigned char column);
void LCD_clearScreen(void);

#endif /* LCD_H_ */