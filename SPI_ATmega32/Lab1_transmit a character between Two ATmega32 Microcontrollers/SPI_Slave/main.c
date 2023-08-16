/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: ARAFA
 */



#include"avr/io.h"
#include"util/delay.h"


#define SS 			4
#define MOSI		5
#define MISO		6
#define SCK			7



void SPI_Slave_Init(void){
	DDRB |= (1<<MISO);  /*Set pin output*/

	DDRB &=~(1<<MOSI) & ~(1<<SS) & ~(1<<SCK);					/*set pins input*/

	SPCR |= (1<<SPR0) | (1<<SPE);  /*slave mode//  fclk/16  //Enable SPI*/

}

unsigned char SPI_Slave_Receive(unsigned char cdata){
	SPDR = cdata;     /*PUt data in data register */

	while(!(SPSR & (1<<SPIF)));				/*wait till data transmitted*/

	return SPDR;			/*return receive data*/
}


int main(){

	unsigned char ch= 255;
	SPI_Slave_Init();

	DDRA = 0xff;

	for(ch = 255 ; ch>=0 ; ch--){
		_delay_ms(1000);
		PORTA = SPI_Slave_Receive(ch);  /*Send and receive and show on PORTA*/
	}

}
