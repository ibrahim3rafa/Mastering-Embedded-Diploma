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


#include <GPIO_driver.h>
#include"../MCAL/inc/STM32F103x6.h"
#include"lcd.h"
#include "keypad.h"
#include"EXTI_driver.h"


#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10

unsigned int IRQ_FLAG = 0;

void callBack_Application_Func(){
	IRQ_FLAG = 1;
	LCD_displayString("IRQ EXTI9 is happended _|-");
	wait_mss(1000);
}
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

	RCC_AFIO_CLK_EN();

}
//GPIO_pinConfig pinCFG;

/*

void GPIO_init(){

	GPIO_pinConfig Pin_Cfg ;
	Pin_Cfg.GPIO_PinNum = GPIO_PIN_8;
	Pin_Cfg.GPIO_PinMode = AF_INPUT_FLOATING_MODE;
	MCAL_GPIO_init(GPIOB, &Pin_Cfg);



}
*/


void wait_mss(uint32_t time){
	uint32_t i,j ;
	for(i=0 ; i<time ; i++){
		for(j=0 ; j<255; j++);
	}
}
unsigned char seg[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
unsigned char lcd[] = {'0','1','2','3','4','5','6','7','8','9','0'};


//void GPIO_init(){
//	GPIO_pinConfig pin_cfg;
//	pin_cfg.GPIO_PinNum = GPIO_PIN_9;
//	pin_cfg.GPIO_PinMode = AF_INPUT_FLOATING_MODE;
//	MCAL_GPIO_init(GPIOB, &pin_cfg);
//
//}
int main(void)
{
	clock_init();
//	GPIO_init();
	LCD_init();
	LCD_clearScreen();

	EXTI_pinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN=(EXTI_GPIO_Mapping_t)EXTI9PB9;
	EXTI_CFG.EXTI_Trigger = EXTI_Trigger_Mode_Rising;
	EXTI_CFG.P_EXTI_CallBack = callBack_Application_Func;
	EXTI_CFG.IRQ_State = IRQ_Enable;

	MCAL_EXTI_GPIO_Init(&EXTI_CFG);

	IRQ_FLAG = 1;

	while(1){
		if(IRQ_FLAG){
			LCD_clearScreen();
			IRQ_FLAG  = 0;
		}
	}

}
