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



void SPI_Master_Init(void){
	DDRB |= (1<<SS) | (1<<MOSI) | (1<<SCK);  /*Set pins output*/

	DDRB &=~(1<<MISO);					/*set pin input*/

	SPCR |= (1<<SPR0) | (1<<MSTR) | (1<<SPE);  /*Master mode//  fclk/16  //Enable SPI*/

}

unsigned char SPI_Master_Transmit(unsigned char cdata){
	SPDR = cdata;     /*PUt data in data register */

	while(!(SPSR & (1<<SPIF)));				/*wait till data transmitted*/

	return SPDR;			/*receive data*/
}


int main(){

	unsigned char x= 0 , data = '' ;
	SPI_Master_Init();
	
	
	
	

}
