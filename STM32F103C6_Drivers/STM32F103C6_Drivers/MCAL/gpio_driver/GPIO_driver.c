/*
 * STM32F103C6_gpio_driver.c
 *
 *  Created on: Jul 30, 2023
 *      Author: ARAFA
 */
#include <STM32F103x8.h>
#include <STM32F103x8.h>
#include "../includes/GPIO_driver.h"


uint16_t GPIO_CRLH_PIN_POSITION(uint16_t pinNumber){
	switch(pinNumber){
	case GPIO_PIN_0 :
		return 0;
		break;
	case GPIO_PIN_1 :
		return 4;
		break;
	case GPIO_PIN_2 :
		return 8;
		break;
	case GPIO_PIN_3 :
		return 12;
		break;
	case GPIO_PIN_4 :
		return 16;
		break;
	case GPIO_PIN_5 :
		return 20;
		break;
	case GPIO_PIN_6 :
		return 24;
		break;
	case GPIO_PIN_7 :
		return 28;
	case GPIO_PIN_8 :
		return 0;
		break;
	case GPIO_PIN_9 :
		return 4;
		break;
	case GPIO_PIN_10 :
		return 8;
		break;
	case GPIO_PIN_11 :
		return 12;
		break;
	case GPIO_PIN_12 :
		return 16;
		break;
	case GPIO_PIN_13 :
		return 20;
		break;
	case GPIO_PIN_14 :
		return 24;
		break;
	case GPIO_PIN_15 :
		return 28;

	}

	return 0;
}





/*************************************************************************************
 * @Fn							-MCAL_GPIO_init
 * @Brief						-Initialize the GPIOx Piny according to the specified parameters in the pinconfig
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @Param [in] 					-pinConfig : pointer to GPIO_pinConfig struct that contains information about specefied
 * 								GPIO pin
 * @retval						-none
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_GPIO_init(GPIO_typedefConfig* GPIOx, GPIO_pinConfig* pinConfig){

	//port configuration register low (pins from 0 >> 7 )	GPIOx_CRL
	//port configuration register high (pins from 8 >> 15 )	GPIOx_CRH
	volatile uint32_t * configRegister = NULL;
	uint8_t Pin_Conf = 0;

	configRegister = (pinConfig->GPIO_PinNum)<GPIO_PIN_8 ? &GPIOx->CRL : &GPIOx->CRH;

	//Clear CNFx[1:0] and MODEx[1:0]
	(*configRegister) &= ~(0xf<<GPIO_CRLH_PIN_POSITION(pinConfig->GPIO_PinNum));

	// if pin is output
	if(pinConfig->GPIO_PinMode == OUTPUT_OPEN_DRAIN_MODE || pinConfig->GPIO_PinMode == OUTPUT_PUSH_PULL_MODE || pinConfig->GPIO_PinMode == AF_OUTPUT_OPEN_DRAIN_MODE || pinConfig->GPIO_PinMode == AF_OUTPUT_PUSH_PULL_MODE){

		//configure pin CNF and MODE
		Pin_Conf = (((pinConfig->GPIO_PinMode-4) << 2) | ((pinConfig->GPIO_Output_Speed )& 0x0f));

	}else{	//if pin is input
		if (pinConfig -> GPIO_PinMode == INPUT_ANLOG_MODE || pinConfig->GPIO_PinMode == INPUT_FLOATING_MODE){
			Pin_Conf = ((pinConfig->GPIO_PinMode<<2) | 0x00) & 0x0f;
		}else if (pinConfig -> GPIO_PinMode == AF_INPUT_FLOATING_MODE){ //Input Floating
			Pin_Conf = ((INPUT_FLOATING_MODE<<2) | 0x00) & 0x0f;
		}else{		//Input PU PD
			Pin_Conf = ((pinConfig->GPIO_PinMode<<2) | 0x00) & 0x0f;

			if(pinConfig->GPIO_PinMode == INPUT_PULL_UP_MODE){
				GPIOx->ODR |= pinConfig->GPIO_PinNum;
			}else{
				GPIOx->ODR &= ~(pinConfig->GPIO_PinNum);
			}

		}
	}
	//write on the register
	(*configRegister) |= (Pin_Conf<<GPIO_CRLH_PIN_POSITION(pinConfig->GPIO_PinNum));
}







/*************************************************************************************
 * @Fn							-MCAL_GPIO_Deinit
 * @Brief						-reset all the gpio registers
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @retval						-none
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */

void MCAL_GPIO_Deinit(GPIO_typedefConfig* GPIOx){

	//Reset all regs.
	GPIOx->BRR = 0x00000000;
	GPIOx->BSRR =0x00000000;
	GPIOx->CRH =0x44444444;
	GPIOx->CRL = 0x44444444;
	GPIOx->IDR =0x0;
	GPIOx->LCKR =0x00000000;
	GPIOx->ODR =0x00000000;


	//using RCC_APB2RSTR

	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2);	//bit 2 : GPIOA reset
		RCC->APB2RSTR &= ~(1<<2);
	}else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= (1<<3);	//bit 3 : GPIOB reset
		RCC->APB2RSTR &= ~(1<<3);
	}else if(GPIOx == GPIOC){
		RCC->APB2RSTR |= (1<<4);	//bit 4 : GPIOC reset
		RCC->APB2RSTR &= ~(1<<4);
	}else if(GPIOx == GPIOD){
		RCC->APB2RSTR |= (1<<5);	//bit 5 : GPIOD reset
		RCC->APB2RSTR &= ~(1<<5);
	}else if(GPIOx == GPIOE){
		RCC->APB2RSTR |= (1<<6);	//bit 6 : GPIOE reset
		RCC->APB2RSTR &= ~(1<<6);
	}

}







/*************************************************************************************
 * @Fn							-MCAL_GPIO_Write_Port
 * @Brief						-write on all the port pins
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @Param [in]					-value: The value which will be written on the port
 * @retval						-none
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_GPIO_Write_Port(GPIO_typedefConfig* GPIOx, uint16_t value){
	GPIOx->ODR = (uint32_t)value;
}








/*************************************************************************************
 * @Fn							-MCAL_GPIO_Write_Pin
 * @Brief						-write on specific pin on specific port
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @Param [in]					-PinNumber: The number of pin on the port
 * @Param [in]					-value: The value which will be written on the pin
 * @retval						-none
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_GPIO_Write_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber , uint8_t value){

	/* The first way to set or reset pin
	if(value == 0){
		GPIOx->ODR = ~pinNumber;

	}else{
		GPIOx->ODR = pinNumber;
	}
	 */

	/*The second way to set or reset pin
	 * using BRR----BSRR
	 */

	if(value == GPIO_PIN_RESET){
		GPIOx->BRR = pinNumber;   		//reset pin by write 1 on BRy
	}else{
		GPIOx->BSRR = pinNumber;			//reser pin by write 1 on BSRRy
	}

}








/*************************************************************************************
 * @Fn							-MCAL_GPIO_Read_Port
 * @Brief						-READ all the port pins
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @retval						-The value was read from the port
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
uint16_t MCAL_GPIO_Read_Port(GPIO_typedefConfig* GPIOx){
	return (uint16_t)(GPIOx -> IDR);
}







/*************************************************************************************
 * @Fn							-MCAL_GPIO_Read_Pin
 * @Brief						-Read specific pin on specific port
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @Param [in]					-pinNumber : The number of pin to be read
 * @retval						-The value was read from the pin
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
uint8_t MCAL_GPIO_Read_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber){
/*	uint8_t pin_val ;
	pin_val = (uint8_t) (GPIOx->IDR & pinNumber);*/
	return (uint8_t) (GPIOx->IDR & pinNumber);
}







/*************************************************************************************
 * @Fn							-MCAL_GPIO_Toggle_Pin
 * @Brief						-Toggle specific pin on specific port
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @Param [in]					-pinNumber : The number of pin to be Toggled
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_GPIO_Toggle_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber){
	GPIOx->ODR ^= pinNumber;
}










/*************************************************************************************
 * @Fn							-MCAL_GPIO_Lock_Pin
 * @Brief						-Lock specific pin on specific port
 * @Param [in]					-GPIOx: where x can be (A---E depending on device mode) to select the GPIO Peripherals
 * @Param [in]					-pinNumber : The number of pin to be Locked
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
uint8_t MCAL_GPIO_Lock_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber){
//	Bit 16 LCKK[16]: Lock key
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock.
//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
//	These bits are read write but can only be written when the LCKK bit is 0.
//	0: Port configuration not locked
//	1: Port configuration locked.

	//SET LCKK[16]
	volatile uint32_t temp = 1<<16;

	//SET pin LCKy
	temp |= pinNumber;

	//write 1
	GPIOx->LCKR = temp;

	//write 0
	GPIOx->LCKR = pinNumber;

	//write 1
	GPIOx->LCKR = temp;


	//READ 0
	temp = GPIOx->LCKR;


	//Read 1 for confirmation
	if((uint32_t)(GPIOx->LCKR & 1<<16)){
		return GPIO_PIN_LOCK_ENABLE;
	}else{
		return GPIO_PIN_LOCK_ERROR;
	}


}



