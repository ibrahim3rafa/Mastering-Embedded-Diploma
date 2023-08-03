/*
 * keypad.h
 *
 *  Created on: Jul 30, 2023
 *      Author: ARAFA
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include"STM32F103C6_gpio_driver.h"
#include"STM32F103x6.h"

#define R0 				(GPIO_PIN_0)
#define R1 				(GPIO_PIN_1)
#define R2				(GPIO_PIN_3)
#define R3				(GPIO_PIN_4)
#define C0				(GPIO_PIN_5)
#define C1				(GPIO_PIN_6)
#define C2				(GPIO_PIN_7)
#define C3				(GPIO_PIN_8)



#define KEYPAD_PORT				GPIOB



//KEYPAD FUNS
void KEYPAD_init();
char KEYPAD_getKey(void);

#endif /* KEYPAD_H_ */
