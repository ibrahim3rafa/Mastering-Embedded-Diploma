/*
 * usart.h
 *
 *  Created on: Aug 8, 2023
 *      Author: ARAFA
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>

#define UBRRL					*(volatile uint8_t *)0x29
#define UBRRH					*(volatile uint8_t *)0x40
#define UCSRC					*(volatile uint8_t *)0x40
#define UDR						*(volatile uint8_t *)0x2C
#define UCSRA					*(volatile uint8_t *)0x2B
#define UCSRB					*(volatile uint8_t *)0x2A


/*This is function to setup the protocol configuration */
void USART_Init(void);
void USART_sendByte(uint8_t data);
uint8_t USART_recieveByte(void);

#endif /* USART_H_ */
