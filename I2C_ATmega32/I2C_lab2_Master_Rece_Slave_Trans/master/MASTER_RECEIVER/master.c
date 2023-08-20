/*
 * master.c
 *
 *  Created on: Aug 20, 2023
 *      Author: ARAFA
 */



#include"avr/io.h"
#include"util/delay.h"

#define PRESCALER 1

void I2C_Init(unsigned long SCL_Clock){

	//setting buad rate
	TWBR = (unsigned char) (((F_CPU / SCL_Clock) - 16 ) / (2* PRESCALER));

	if(PRESCALER == 0)
		TWSR = 0;
	else if(PRESCALER == 4)
		TWSR = 1;
	else if(PRESCALER == 16)
		TWSR = 2;
	else if(PRESCALER == 64)
		TWSR = 3;

}


void I2C_Start(){

	//set Intterupt pin  , Enabel Twi  , set start bit
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);

	//wait till start transmission done
	while (((TWCR & (1<<7)) == 0));

	//wait till start transmission done  and confirm thar from status register
	while ((TWSR) != 0x08);

}



void I2C_Write(unsigned char cByte){

	//put data in data register
	TWDR = cByte;

	//set Intterupt pin  , Enabel Twi
	TWCR = (1<<TWINT) | (1<<TWEN);

	//wait till write done
	while ((TWCR & (0x80)) == 0);

}

unsigned char I2C_Read(unsigned char ack){
	TWCR |= (1<<TWINT) | (1<<TWEN) | (ack<<TWEA);
	while ((TWCR & 0x80) == 0);
	return TWDR;
}

void I2C_Stop(){
	//set Intterupt pin  , Enabel Twi  , set start bit
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);

}



int main (){
	DDRA = 0xFF;
	unsigned char ch = 0 ;
	I2C_Init(0x48);
	while(1){
		_delay_ms(1000);
		I2C_Start();		//transimit start
		I2C_Write(0b11010000+1);   //
		ch = I2C_Read(0);
		I2C_Stop();
		PORTA = ch;

	}
}
