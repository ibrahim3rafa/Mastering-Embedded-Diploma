/*
 * GPIO.h
 *
 *  Created on: Aug 6, 2023
 *      Author: ARAFA
 */

#ifndef GPIO_H_
#define GPIO_H_


#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

void Port_Direction(uint8_t port, uint8_t state);
void Pin_Direction (uint8_t port, uint8_t pin_num, uint8_t state);


#define PORTA 					*(volatile uint8_t*)0x3B
#define DDRA 					*(volatile uint8_t*)0x3A
#define PINA 					*(volatile uint8_t*)0x39



#define PORTB 					*(volatile uint8_t*)0x38
#define DDRB 					*(volatile uint8_t*)0x37
#define PINB 					*(volatile uint8_t*)0x36


#define PORTC 					*(volatile uint8_t*)0x35
#define DDRC					*(volatile uint8_t*)0x34
#define PINC 					*(volatile uint8_t*)0x33



#define PORTD 					*(volatile uint8_t*)0x32
#define DDRD 					*(volatile uint8_t*)0x31
#define PIND 					*(volatile uint8_t*)0x30


#define OUTPUT 								(1)
#define INPUT								(0)



#define SET_BIT(REG,BIT)						(REG |= (1<<BIT))
#define CLEAR_BIT(REG,BIT)						( REG &= (~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT)						( REG^= (1<<BIT))
#define BIT_IS_SET(REG,BIT)						(REG & (1<<BIT))
#define BIT_IS_CLEAR(REG,BIT)					(!(REG & (1<<BIT)))
#define GET_BIT(REG,BIT)						(((REG >> BIT) & 1))
#define ROTATE_R(REG,NUM)						((REG = (REG>>NUM) | (REG<<(8-NUM))))
#define ROTATE_L(REG,NUM)						((REG = (REG<<NUM) | (REG>>(8-NUM))))

#endif /* GPIO_H_ */
