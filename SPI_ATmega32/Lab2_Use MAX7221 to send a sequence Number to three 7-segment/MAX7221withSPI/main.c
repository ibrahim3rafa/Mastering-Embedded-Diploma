/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: ARAFA
 */


#include"avr/io.h"

#include"util/delay.h"

#define SS  		4
#define MOSI		5
#define SCK			7

void excute (unsigned char cmd, unsigned char data){

	PORTB &=~(1<<SS);				/*Make cs low at first*/

	SPDR = cmd;					/*send the cmd first*/

	while(!(SPSR & (1<<SPIF)));		/*wait till the cmd is sent*/

	SPDR = data;				/*Send the data*/

	while(!(SPSR & (1<<SPIF)));		/*wait till the data be sent*/

	PORTB |= (1<<SS);			/*Make cs High to inform the packet */

}


int main(){


	unsigned char index = 0 ;
	unsigned char counter ;
	DDRB |= (1<<SS) | (1<<SCK) | (1<<MOSI);   /*Set the pins as output*/

	SPCR |= (1<<SPE) | (1<<SPR0) | (1<<MSTR); /*Enable SPI // Fclk/16 // MAster mode */


	excute(0x09, 0xFF) ; /*Decode all displays      display 11111111*/
	excute(0x0B, 0x07) ; /*set scan limit (digit0 to digit7*/
	excute(0x0A, 0x0F) ; /*MAx intensity*/
	excute(0x0C, 0x01) ; /*Turn on display*/

	while (1){
			for(index = 0 ; index < 9 ; index++ ){
				excute(index, counter++);
				_delay_ms(1000);
			}
	}


}
