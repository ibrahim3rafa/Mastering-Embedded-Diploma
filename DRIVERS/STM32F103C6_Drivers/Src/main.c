/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "STM32F103C6_gpio_driver.h"
#include"STM32F103x6.h"
#include"stdio.h"



void clock_init(void){
	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled

	RCC_GPIOA_CLK_EN();


	//	Bit 3 IOPBEN: IO port B clock enable
	//	Set and cleared by software.
	//	0: IO port B clock disabled
	//	1: IO port B clock enabled
	RCC_GPIOB_CLK_EN();

}

void GPIO_Init(void){

	//PA1 input pin
	 // input mode
	 //01: Floating input (reset state)
	GPIO_pinConfig pinCFG;
	pinCFG.GPIO_PinNum = GPIO_PIN_1;
	pinCFG.GPIO_PinMode= INPUT_FLOATING_MODE;
	MCAL_GPIO_init(GPIOA,&pinCFG);

	//PA13 input pin
	// input mode
 //01: Floating input (reset state)
//	GPIO_pinConfig* pinCFG;
	pinCFG.GPIO_PinNum = GPIO_PIN_13;
	pinCFG.GPIO_PinMode= INPUT_FLOATING_MODE;
	MCAL_GPIO_init(GPIOA,&pinCFG);


	// PB1 is output push-pull pin
  //01: Output mode, max speed 10 MHz
   //00: General purpose output push-pull
//	GPIO_pinConfig* pinCFG;
	pinCFG.GPIO_PinNum = GPIO_PIN_1;
	pinCFG.GPIO_PinMode= OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(GPIOB,&pinCFG);

	// PB13 is output push-pull pin
	   //01: Output mode, max speed 10 MHz
  //00: General purpose output push-pull
//	GPIO_pinConfig* pinCFG;
	pinCFG.GPIO_PinNum = GPIO_PIN_13;
	pinCFG.GPIO_PinMode= OUTPUT_PUSH_PULL_MODE;
	pinCFG.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_init(GPIOB,&pinCFG);
}

int main(void)
{
	clock_init();
	GPIO_Init();

	while(1){

		if(!(MCAL_GPIO_Read_Pin(GPIOA, GPIO_PIN_1))){
			MCAL_GPIO_Toggle_Pin(GPIOB, GPIO_PIN_1);  //toggle PB1
			while(!(MCAL_GPIO_Read_Pin(GPIOA, GPIO_PIN_1)));
		}

		if((MCAL_GPIO_Read_Pin(GPIOA,GPIO_PIN_13))){
			MCAL_GPIO_Toggle_Pin(GPIOB, GPIO_PIN_13); //toggle PB1

		}

		for(int i=0 ; i<255 ; i++);

	}

}
