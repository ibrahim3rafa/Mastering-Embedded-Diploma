/*
 * I2C_EEPROM_SLAVE.c
 *
 *  Created on: Aug 22, 2023
 *      Author: ARAFA
 */


#include"I2C_EEPROM_SLAVE.h"
#include "I2C.h"

void EEPROM_Init(void){
	//I2C INIT
	//	PB6 = SCL
	//	PB7 = SDA

	I2C_Config_t I2C1CFG;

	// i2C ACT AS MASTER
	I2C1CFG.I2C_Acknowledge_Mode = I2C_ACK_RETURNED;
	I2C1CFG.I2C_Clock_Freq = I2C_SCLK_SM_100K;
	I2C1CFG.I2C_Clock_Stretch_Mode = I2C_CLK_STRETCH_EN;
	I2C1CFG.I2C_General_Call_Mode = I2C_GENERAL_CALL_EN;
	I2C1CFG.I2C_SM_Bus_Mode = I2C_I2C_Mode;
	I2C1CFG.P_Slave_Event_CallBack = NULL;

	MCAL_I2C_Set_GPIO_PINS(I2C1);
	MCAL_I2C_Init(I2C1, &I2C1CFG);


}


unsigned char EEPROM_WRITE_NBytes(unsigned int Memory_Address, unsigned char* Bytes, uint8_t datalen){
	uint8_t i ;
	uint8_t buffer[256];
	buffer[0] = (uint8_t)(Memory_Address >> 8);  // higher address
	buffer[1] = (uint8_t)(Memory_Address); 	//lower address

	for(i = 2 ; i<datalen ; i++){
		buffer[i] = Bytes[i-2];}

	MCAL_I2C_Master_TX(I2C1, EEPROM_ADDRESS, buffer, datalen+2 , withstop, start);

	return 0;
}



unsigned char EEPROM_READ_NBytes(unsigned int Address, uint8_t* dataOut, uint8_t datalen){

	unsigned char buffer[2];
	buffer[0] = Address>>8;		//upper address
	buffer[1] = Address ; 			// lower address

	MCAL_I2C_Master_TX(I2C1, EEPROM_ADDRESS, buffer, (2), withoutstop, start);   //write address

	MCAL_I2C_Master_RX(I2C1, EEPROM_ADDRESS, dataOut, datalen, withstop, repeatedstart);		//read

	return 0;
}
