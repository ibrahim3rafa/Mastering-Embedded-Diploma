/*
 * main.c
 *
 *  Created on: Aug 19, 2023
 *      Author: ARAFA
 */


#include"avr/io.h"
#include"util/delay.h"


#define SS 			4
#define MOSI		5
#define MISO		6
#define SCK			7

#define MASTER	 1
#define SLAVE	 0

#define SPI_MODE	 SLAVE

void SPI_Init(void){

#ifdef	SPI_MODE MASTER
	DDRB |= (1<<SS) | (1<<MOSI) | (1<<SCK);  /*Set pins output*/

	DDRB &=~(1<<MISO);					/*set pin input*/

	SPCR |= (1<<SPR0) | (1<<MSTR) | (1<<SPE);  /*Master mode//  fclk/16  //Enable SPI*/
#elif	SPI_MODE SLAVE

	DDRB |= (1<<MISO);  /*Set pin output*/

	DDRB &=~(1<<5) & ~(1<<4) & ~(1<<7);					/*set pins input*/

	SPCR |= (1<<SPR0) | (1<<SPE);  /*slave mode//  fclk/16  //Enable SPI*/
#endif
}

unsigned char SPI_Transmit_Receive(unsigned char cdata){
	SPDR = cdata;     /*PUt data in data register */

	while(!(SPSR & (1<<SPIF)));				/*wait till data transmitted*/

	return SPDR;			/*receive data*/
}


int main(){

	unsigned char x = 0 , data = 'A' , rece_data ;
	SPI_Master_Init();
	LCD_init();
	LCD_moveRowColumn(1, 1);
	LCD_displayString("master");
	while(1){
		rece_data = SPI_Master_Transmit(data);
		data++;
		if(data == 'Z'+1){
			data = 'A';
		}
		LCD_moveRowColumn(1, 9);
		LCD_displayCharacter(rece_data);
		LCD_moveRowColumn(2, 0);
		LCD_displayCharacter(x);
		_delay_ms(1000);
		x++;
		if(x==9+1){
			x=0;
		}
	}
	
	

}
