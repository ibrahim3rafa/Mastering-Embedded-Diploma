/*
 * usart.c
 *
 *  Created on: Aug 8, 2023
 *      Author: ARAFA
 */


#include"usart.h"
#include"GPIO.h"
void USART_Init(void){
	//Set the Buad rate
		UBRRL = (uint8_t)9600;
		UBRRH = (uint8_t)(9600>>8);

	//Setting the Frame Format
		UCSRC |= (1<<7);		//writing on UCSREC (URSEL)
		UCSRC |= (0b11<<0);		//8 data bit
		UCSRC |= (1<<3);		//one stop bit
	//Enable TX , RX
		UCSRB |= (1<<3) | (1<<4);

}
void USART_sendByte(uint8_t data){
	//Enable TXEN
//	UCSRB |= (1<<3);

	//writing to UDR when empty
	while((BIT_IS_CLEAR(UCSRA,5)));

	UDR = data;

}
uint8_t USART_recieveByte(void){

	//Enable RXEN
	//UCSRB |= (1<<4);

	//wait for data
	while(BIT_IS_CLEAR(UCSRA,7));

	//get data
	return UDR;

}


void USART_sendString(uint8_t * str){
	uint8_t i = 0;
	while(str[i] != '\0'){
		USART_sendByte(str[i]);
		i++;
	}
}



void USART_recieveString(uint8_t * str)
{
	uint8_t i = 0;
	str[i] = USART_recieveByte();
	while(*str != '#'){
		i++;
		str[i] = USART_recieveByte();
	}
	str[i] = '\0';
}
