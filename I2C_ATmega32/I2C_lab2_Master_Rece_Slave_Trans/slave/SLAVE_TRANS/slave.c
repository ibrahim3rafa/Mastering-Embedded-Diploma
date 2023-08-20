/*
 * slave.c
 *
 *  Created on: Aug 20, 2023
 *      Author: ARAFA
 */



#include"avr/io.h"

void I2C_Set_Address (unsigned char address){

	TWAR = address;
}

unsigned char I2C_Read(unsigned char ack){
	unsigned char  x = 0;
	TWCR = (1<<TWINT) | (1<<TWEN) | (ack<<TWEA);
	while((TWCR & (1<<7)) == 0); 		//wait till read
	while (TWSR != 0x60)	x = TWSR; //Own SLA + W received


	TWCR = (1<<TWINT) | (1<<TWEN) | (ack<<TWEA);
	while((TWCR & (1<<7)) == 0); 	//wait till read
	while (TWSR != 0x80)	x = TWSR; //Data transmitted and ack returned

	return TWDR;
}


void I2C_Write(unsigned char cByte){

	TWDR = cByte;

	TWCR = (1<<TWINT) | (1<<TWEN);

	while((TWCR&0x80) == 0);
}

int main (){
	unsigned char ch = 0 ;
	I2C_Set_Address(0b11010000);
	while(1){
		I2C_Read(1);
		I2C_Write(ch++);

	}
}
