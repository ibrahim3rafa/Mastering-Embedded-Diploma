/*
 * STM32F103C6_EXTI_driver.c
 *
 *  Created on: Aug 4, 2023
 *      Author: ARAFA
 */


#include <STM32F103x8.h>
#include "../includes/EXTI_driver.h"

#include "../includes/GPIO_driver.h"


void (*GP_EXTI_CallBack[15])(void);

#define AFIO_EXTI_Position_Mapping(x)  		(       (x==GPIOA)?PAx_PIN:\
													(x==GPIOB)?PBx_PIN:\
													(x==GPIOC)?PCx_PIN:\
													(x==GPIOD)?PDx_PIN:0      )


void NVIC_Enable(uint16_t IRQ){
	switch(IRQ){
	case EXTI0:
		NVIC_EXTI0_IRQ_Enable;
		break;
	case EXTI1:
		NVIC_EXTI1_IRQ_Enable;
		break;
	case EXTI2:
		NVIC_EXTI2_IRQ_Enable;
		break;
	case EXTI3:
		NVIC_EXTI3_IRQ_Enable;
		break;
	case EXTI4:
		NVIC_EXTI4_IRQ_Enable;
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_EXTI9_5_IRQ_Enable;
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_EXTI15_10_IRQ_Enable;
		break;

	}
}

void NVIC_Disable(uint16_t IRQ){
	switch(IRQ){
	case EXTI0:
		NVIC_EXTI0_IRQ_Disable;
		break;
	case EXTI1:
		NVIC_EXTI1_IRQ_Disable;
		break;
	case EXTI2:
		NVIC_EXTI2_IRQ_Disable;
		break;
	case EXTI3:
		NVIC_EXTI3_IRQ_Disable;
		break;
	case EXTI4:
		NVIC_EXTI4_IRQ_Disable;
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_EXTI9_5_IRQ_Disable;
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_EXTI15_10_IRQ_Disable;
		break;

	}
}
void Update_EXTI_GPIO(EXTI_pinConfig_t* EXTI_CFG){

	//UPDATE pin configuration as input floating
	GPIO_pinConfig PIN_CFG;
	PIN_CFG.GPIO_PinNum = EXTI_CFG->EXTI_PIN.EXTI_pinNumber;
	PIN_CFG.GPIO_PinMode = AF_INPUT_FLOATING_MODE;
	MCAL_GPIO_init(EXTI_CFG->EXTI_PIN.GPIOx, &PIN_CFG);

	//UPDATE EXTI Interrupt Configuration Register settings (AFIO)

	uint8_t EXTI_AFIO_Index =  (EXTI_CFG->EXTI_PIN.EXTI_line) / 4;

	uint8_t EXTI_AFIO_position =  (EXTI_CFG->EXTI_PIN.EXTI_line % 4)*4;

	AFIO->EXTICR1[EXTI_AFIO_Index] &= ~(0xF<<EXTI_AFIO_position);

	AFIO->EXTICR1[EXTI_AFIO_Index]  |= ((AFIO_EXTI_Position_Mapping(EXTI_CFG->EXTI_PIN.GPIOx)&0xF)<<EXTI_AFIO_position);

	//UPDATE Trigger Mode
	EXTI->RTSR &= ~(1<<EXTI_CFG->EXTI_PIN.EXTI_line) ;
	EXTI->FTSR &= ~(1<<EXTI_CFG->EXTI_PIN.EXTI_line) ;

	if(EXTI_CFG->EXTI_Trigger == EXTI_Trigger_Mode_Rising){
		EXTI->RTSR |= (1<<EXTI_CFG->EXTI_PIN.EXTI_line) ;
	}else if (EXTI_CFG->EXTI_Trigger == EXTI_Trigger_Mode_Falling){
		EXTI->FTSR |= (1<<EXTI_CFG->EXTI_PIN.EXTI_line) ;

	}else if(EXTI_CFG->EXTI_Trigger == EXTI_Trigger_Mode_RS_FA) {   //Falling and Rising
		EXTI->RTSR |= (1<<EXTI_CFG->EXTI_PIN.EXTI_line) ;
		EXTI->FTSR |= (1<<EXTI_CFG->EXTI_PIN.EXTI_line) ;
	}



	//Update GP
	GP_EXTI_CallBack[EXTI_CFG->EXTI_PIN.EXTI_line] = EXTI_CFG->P_EXTI_CallBack;

	//UPDATE IRQ_State
	if(EXTI_CFG->IRQ_State == IRQ_Enable){
		EXTI->IMR |= (1<<EXTI_CFG->EXTI_PIN.EXTI_line);
		NVIC_Enable(EXTI_CFG->EXTI_PIN.EXTI_line);

	}else if(EXTI_CFG->IRQ_State == IRQ_Disable){
		EXTI->EMR &= ~(1<<EXTI_CFG->EXTI_PIN.EXTI_line);
		NVIC_Disable(EXTI_CFG->EXTI_PIN.EXTI_line);
	}

}







/********************************************************************************************************************************
 *->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> EXTI API'S  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *********************************************************************************************************************************/




/*************************************************************************************
 * @Fn							-MCAL_EXTI_GPIO_Init
 * @Brief						-Configure settings required to generate interrupt
 * @Param [in]					-EXTI_CFG: select (EXTIx, GPIOy , GPIO_PIN_x , EXTIx_IRQ) x-->[1-15] && y[A,B,C,D]
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_EXTI_GPIO_Init(EXTI_pinConfig_t* EXTI_CFG){

	Update_EXTI_GPIO(EXTI_CFG);
}


/*************************************************************************************
 * @Fn							-MCAL_EXTI_GPIO_DeInit
 * @Brief						-Configure settings required to Reset
 * @Param [in]					-EXTI_CFG: select (EXTIx, GPIOy , GPIO_PIN_x , EXTIx_IRQ) x-->[1-15] && y[A,B,C,D]
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_EXTI_GPIO_DeInit(void){
	/*	Reset all EXTI_REGISTERS */
	EXTI->IMR   =	 0x00000000;
	EXTI->EMR   = 	 0x00000000;
	EXTI->RTSR  = 	 0x00000000;
	EXTI->FTSR  =	 0x00000000;
	EXTI->SWIER =	 0x00000000;
	EXTI->PR    = 	 0xFFFFFFFF;

	/*	Reset all NVIC Registers*/

	NVIC_EXTI0_IRQ_Disable ;
	NVIC_EXTI1_IRQ_Disable ;
	NVIC_EXTI2_IRQ_Disable ;
	NVIC_EXTI3_IRQ_Disable ;
	NVIC_EXTI4_IRQ_Disable ;
	NVIC_EXTI9_5_IRQ_Disable ;
	NVIC_EXTI15_10_IRQ_Disable ;

}



/*************************************************************************************
 * @Fn							-MCAL_EXTI_GPIO_Update
 * @Brief						-Configure Updated settings required to generate interrupt
 * @Param [in]					-EXTI_CFG: select (EXTIx, GPIOy , GPIO_PIN_x , EXTIx_IRQ) x-->[1-15] && y[A,B,C,D]
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_EXTI_GPIO_Update(EXTI_pinConfig_t* EXTI_CFG)
{
	Update_EXTI_GPIO(EXTI_CFG);
}














/* EXTI Line0 interrupt                             */
void EXTI0_IRQHandler(){
	EXTI->PR |= (1<<EXTI0); 		//Clear Pending register
	GP_EXTI_CallBack[0]() ;			//Call function in application layer
}


/* EXTI Line1interrupt                             */
void EXTI1_IRQHandler(){
	EXTI->PR |= (1<<EXTI1); 		//Clear Pending register
	GP_EXTI_CallBack[1]() ;			//Call function in application layer
}

/* EXTI Line2 interrupt                             */
void EXTI2_IRQHandler(){
	EXTI->PR |= (1<<EXTI2); 		//Clear Pending register
	GP_EXTI_CallBack[2]() ;			//Call function in application layer
}

/* EXTI Line3 interrupt                             */
void EXTI3_IRQHandler(){
	EXTI->PR |= (1<<EXTI3); 		//Clear Pending register
	GP_EXTI_CallBack[3]() ;			//Call function in application layer
}

/* EXTI Line4 interrupt                             */
void EXTI4_IRQHandler(){
	EXTI->PR |= (1<<EXTI4); 		//Clear Pending register
	GP_EXTI_CallBack[4]() ;			//Call function in application layer
}

/* EXTI Line[9:5] interrupts                        */
void EXTI9_5_IRQHandler(){

	if(EXTI->PR & (1<<5)){
	EXTI->PR |= (1<<EXTI5); 		//Clear Pending register
	GP_EXTI_CallBack[5]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<6)){
	EXTI->PR |= (1<<EXTI6); 		//Clear Pending register
	GP_EXTI_CallBack[6]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<7)){
	EXTI->PR |= (1<<EXTI7); 		//Clear Pending register
	GP_EXTI_CallBack[7]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<8)){
	EXTI->PR |= (1<<EXTI8); 		//Clear Pending register
	GP_EXTI_CallBack[8]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<9)){
	EXTI->PR |= (1<<EXTI9); 		//Clear Pending register
	GP_EXTI_CallBack[9]() ;			//Call function in application layer
	}

}
/* EXTI Line[15:10] interrupts                      */
void EXTI15_10_IRQHandler(){

	if(EXTI->PR & (1<<10)){
	EXTI->PR |= (1<<EXTI10); 		//Clear Pending register
	GP_EXTI_CallBack[10]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<11)){
	EXTI->PR |= (1<<EXTI11); 		//Clear Pending register
	GP_EXTI_CallBack[11]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<12)){
	EXTI->PR |= (1<<EXTI12); 		//Clear Pending register
	GP_EXTI_CallBack[12]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<13)){
	EXTI->PR |= (1<<EXTI13); 		//Clear Pending register
	GP_EXTI_CallBack[13]() ;			//Call function in application layer
	}

	if(EXTI->PR & (1<<14)){
	EXTI->PR |= (1<<EXTI14); 		//Clear Pending register
	GP_EXTI_CallBack[14]() ;			//Call function in application layer
	}
	if(EXTI->PR & (1<<15)){
	EXTI->PR |= (1<<EXTI15); 		//Clear Pending register
	GP_EXTI_CallBack[15]() ;			//Call function in application layer
	}
}
