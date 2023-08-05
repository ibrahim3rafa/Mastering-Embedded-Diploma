/*
 * STM32F103C_EXTI_driver.h
 *
 *  Created on: Aug 4, 2023
 *      Author: ARAFA
 */

#ifndef INC_EXTI_DRIVER_H_
#define INC_EXTI_DRIVER_H_

#include <GPIO_driver.h>
#include"STM32F103x6.h"




/********************************************************************************************************************************
 *->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   STRUCTS CONFIG  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *********************************************************************************************************************************/

//EXTI_config_struct

typedef struct {
	uint16_t EXTI_line ;   								/*specifies the EXTI input line number From EXTI0-EXTI15
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 you can know that form @EXTI_define_ref*/

	GPIO_typedefConfig* GPIOx; 							/*specifies the EXTI input port from PORTA -- PORTD
	 	 	 	 	 	 	 	 							you can know that form @GPIO_define_ref at STM32F103x6.h file */

	uint16_t EXTI_pinNumber;								/*specifies the EXTI input pin number from PA0 -- PD0--> you allowed to choose only GPIO.PIN0 form everyport
	 	 	 	 	 	 	 	 							you can know that form //@ref GPIO_PINS_define at GPIO.h file */

	uint16_t EXTIx_IRQ; 								/*specifies the EXTIx IRQ  number From EXTI0_IRQ-->EXTI15_IRQ
	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 you can know that form @EXTIx_IRQ_define_ref*/

}EXTI_GPIO_Mapping_t;



/*EXTI_Pin_config_struct */
typedef struct{

	EXTI_GPIO_Mapping_t EXTI_PIN;						/*specifies the EXTI pin configuration (EXTI_line,EXTI_PORT_EXTI_PIN,EXTI_IRQ_NUMBER)
	 	 	 	 	 	 	 	 							you can know that form //@ref EXTI_PIN*/

	uint16_t EXTI_Trigger;								/*specifies the EXTI TRIGGER mode which(Rising,Falling,RS&FA)
															You can know that from @EXTI_Trigger_Mode*/

	uint8_t	IRQ_State ;								/*	Specifies the state of IRQ ENAble or Disable
															you can Know the state from @EXTI_IRQ_State_Mode */

	void (*P_EXTI_CallBack)();						/*	specifies the EXTI callBack function which will be called from application program
															You can use it at ISR*/

}EXTI_pinConfig_t;


/********************************************************************************************************************************
 *->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   MACROS CONFIG  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *********************************************************************************************************************************/


/*EXTI_define_ref*/
#define EXTI0	 				0
#define EXTI1 					1
#define EXTI2 					2
#define EXTI3 					3
#define EXTI4 					4
#define EXTI5 					5
#define EXTI6 					6
#define EXTI7 					7
#define EXTI8 					8
#define EXTI9 					9
#define EXTI10 					10
#define EXTI11 					11
#define EXTI12					12
#define EXTI13					13
#define EXTI14					14
#define EXTI15					15




/*@EXTIx_IRQ_define_ref*/
#define EXTI0_IRQ				6
#define EXTI1_IRQ				7
#define EXTI2_IRQ				8
#define EXTI3_IRQ				9
#define EXTI4_IRQ				10
#define EXTI5_IRQ				23
#define EXTI6_IRQ				23
#define EXTI7_IRQ				23
#define EXTI8_IRQ				23
#define EXTI9_IRQ				23
#define EXTI10_IRQ				40
#define EXTI11_IRQ				40
#define EXTI12_IRQ				40
#define EXTI13_IRQ				40
#define EXTI14_IRQ				40
#define EXTI15_IRQ				40




/*@ref EXTI_PIN*/
//EXTI0
#define EXTI0PA0				(EXTI_GPIO_Mapping_t){EXTI0,GPIOA,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PB0				(EXTI_GPIO_Mapping_t){EXTI0,GPIOB,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PC0				(EXTI_GPIO_Mapping_t){EXTI0,GPIOC,GPIO_PIN_0,EXTI0_IRQ}
#define EXTI0PD0				(EXTI_GPIO_Mapping_t){EXTI0,GPIOD,GPIO_PIN_0,EXTI0_IRQ}

//EXTI1
#define EXTI1PA1				(EXTI_GPIO_Mapping_t){EXTI1,GPIOA,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PB1				(EXTI_GPIO_Mapping_t){EXTI1,GPIOB,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PC1				(EXTI_GPIO_Mapping_t){EXTI1,GPIOC,GPIO_PIN_1,EXTI1_IRQ}
#define EXTI1PD1				(EXTI_GPIO_Mapping_t){EXTI1,GPIOD,GPIO_PIN_1,EXTI1_IRQ}


//EXTI2
#define EXTI2PA2				(EXTI_GPIO_Mapping_t){EXTI2,GPIOA,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PB2				(EXTI_GPIO_Mapping_t){EXTI2,GPIOB,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PC2				(EXTI_GPIO_Mapping_t){EXTI2,GPIOC,GPIO_PIN_2,EXTI2_IRQ}
#define EXTI2PD2				(EXTI_GPIO_Mapping_t){EXTI2,GPIOD,GPIO_PIN_2,EXTI2_IRQ}


//EXTI3
#define EXTI3PA3				(EXTI_GPIO_Mapping_t){EXTI3,GPIOA,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PB3				(EXTI_GPIO_Mapping_t){EXTI3,GPIOB,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PC3				(EXTI_GPIO_Mapping_t){EXTI3,GPIOC,GPIO_PIN_3,EXTI3_IRQ}
#define EXTI3PD3				(EXTI_GPIO_Mapping_t){EXTI3,GPIOD,GPIO_PIN_3,EXTI3_IRQ}


//EXTI4
#define EXTI4PA4				(EXTI_GPIO_Mapping_t){EXTI4,GPIOA,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PB4				(EXTI_GPIO_Mapping_t){EXTI4,GPIOB,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PC4				(EXTI_GPIO_Mapping_t){EXTI4,GPIOC,GPIO_PIN_4,EXTI4_IRQ}
#define EXTI4PD4				(EXTI_GPIO_Mapping_t){EXTI4,GPIOD,GPIO_PIN_4,EXTI4_IRQ}


//EXTI5
#define EXTI5PA5				(EXTI_GPIO_Mapping_t){EXTI5,GPIOA,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PB5				(EXTI_GPIO_Mapping_t){EXTI5,GPIOB,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PC5				(EXTI_GPIO_Mapping_t){EXTI5,GPIOC,GPIO_PIN_5,EXTI5_IRQ}
#define EXTI5PD5				(EXTI_GPIO_Mapping_t){EXTI5,GPIOD,GPIO_PIN_5,EXTI5_IRQ}


//EXTI6
#define EXTI6PA6				(EXTI_GPIO_Mapping_t){EXTI6,GPIOA,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PB6				(EXTI_GPIO_Mapping_t){EXTI6,GPIOB,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PC6				(EXTI_GPIO_Mapping_t){EXTI6,GPIOC,GPIO_PIN_6,EXTI6_IRQ}
#define EXTI6PD6				(EXTI_GPIO_Mapping_t){EXTI6,GPIOD,GPIO_PIN_6,EXTI6_IRQ}


//EXTI7
#define EXTI7PA7				(EXTI_GPIO_Mapping_t){EXTI7,GPIOA,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PB7				(EXTI_GPIO_Mapping_t){EXTI7,GPIOB,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PC7				(EXTI_GPIO_Mapping_t){EXTI7,GPIOC,GPIO_PIN_7,EXTI7_IRQ}
#define EXTI7PD7				(EXTI_GPIO_Mapping_t){EXTI7,GPIOD,GPIO_PIN_7,EXTI7_IRQ}


//EXTI8
#define EXTI8PA8				(EXTI_GPIO_Mapping_t){EXTI8,GPIOA,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PB8				(EXTI_GPIO_Mapping_t){EXTI8,GPIOB,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PC8				(EXTI_GPIO_Mapping_t){EXTI8,GPIOC,GPIO_PIN_8,EXTI8_IRQ}
#define EXTI8PD8				(EXTI_GPIO_Mapping_t){EXTI8,GPIOD,GPIO_PIN_8,EXTI8_IRQ}


//EXTI9
#define EXTI9PA9				(EXTI_GPIO_Mapping_t){EXTI9,GPIOA,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PB9				(EXTI_GPIO_Mapping_t){EXTI9,GPIOB,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PC9				(EXTI_GPIO_Mapping_t){EXTI9,GPIOC,GPIO_PIN_9,EXTI9_IRQ}
#define EXTI9PD9				(EXTI_GPIO_Mapping_t){EXTI9,GPIOD,GPIO_PIN_9,EXTI9_IRQ}


//EXTI10
#define EXTI10PA10				(EXTI_GPIO_Mapping_t){EXTI10,GPIOA,GPIO_PIN_10,EXTI10IRQ}
#define EXTI10PB10				(EXTI_GPIO_Mapping_t){EXTI10,GPIOB,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10PC10				(EXTI_GPIO_Mapping_t){EXTI10,GPIOC,GPIO_PIN_10,EXTI10_IRQ}
#define EXTI10PD10				(EXTI_GPIO_Mapping_t){EXTI10,GPIOD,GPIO_PIN_10,EXTI10_IRQ}


//EXTI11
#define EXTI11PA11				(EXTI_GPIO_Mapping_t){EXTI11,GPIOA,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11PB11				(EXTI_GPIO_Mapping_t){EXTI11,GPIOB,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11PC11				(EXTI_GPIO_Mapping_t){EXTI11,GPIOC,GPIO_PIN_11,EXTI11_IRQ}
#define EXTI11PD11				(EXTI_GPIO_Mapping_t){EXTI11,GPIOD,GPIO_PIN_11,EXTI11_IRQ}


//EXTI12
#define EXTI12PA12				(EXTI_GPIO_Mapping_t){EXTI12,GPIOA,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12PB12				(EXTI_GPIO_Mapping_t){EXTI12,GPIOB,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12PC12				(EXTI_GPIO_Mapping_t){EXTI12,GPIOC,GPIO_PIN_12,EXTI12_IRQ}
#define EXTI12PD12				(EXTI_GPIO_Mapping_t){EXTI12,GPIOD,GPIO_PIN_12,EXTI12_IRQ}


//EXTI13
#define EXTI13PA13				(EXTI_GPIO_Mapping_t){EXTI13,GPIOA,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13PB13				(EXTI_GPIO_Mapping_t){EXTI13,GPIOB,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13PC13				(EXTI_GPIO_Mapping_t){EXTI13,GPIOC,GPIO_PIN_13,EXTI13_IRQ}
#define EXTI13PD13				(EXTI_GPIO_Mapping_t){EXTI13,GPIOD,GPIO_PIN_13,EXTI13_IRQ}


//EXTI14
#define EXTI14PA14				(EXTI_GPIO_Mapping_t){EXTI14,GPIOA,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14PB14				(EXTI_GPIO_Mapping_t){EXTI14,GPIOB,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14PC14				(EXTI_GPIO_Mapping_t){EXTI14,GPIOC,GPIO_PIN_14,EXTI14_IRQ}
#define EXTI14PD14				(EXTI_GPIO_Mapping_t){EXTI14,GPIOD,GPIO_PIN_14,EXTI14_IRQ}


//EXTI15
#define EXTI15PA15				(EXTI_GPIO_Mapping_t){EXTI15,GPIOA,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15PB15				(EXTI_GPIO_Mapping_t){EXTI15,GPIOB,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15PC15				(EXTI_GPIO_Mapping_t){EXTI15,GPIOC,GPIO_PIN_15,EXTI15_IRQ}
#define EXTI15PD15				(EXTI_GPIO_Mapping_t){EXTI15,GPIOD,GPIO_PIN_15,EXTI15_IRQ}



/*@EXTI_Trigger_Mode*/
#define EXTI_Trigger_Mode_Rising  					(0)
#define EXTI_Trigger_Mode_Falling 					(1)
#define EXTI_Trigger_Mode_RS_FA						(2)		//	Trigger rising and falling edge




/*NVIC Registers Enable /Disable*/
#define NVIC_EXTI0_IRQ_Enable						(NVIC_ISER0 |= (1<<EXTI0_IRQ))
#define NVIC_EXTI1_IRQ_Enable						(NVIC_ISER0 |= (1<<EXTI1_IRQ))
#define NVIC_EXTI2_IRQ_Enable						(NVIC_ISER0 |= (1<<EXTI2_IRQ))
#define NVIC_EXTI3_IRQ_Enable						(NVIC_ISER0 |= (1<<EXTI3_IRQ))
#define NVIC_EXTI4_IRQ_Enable						(NVIC_ISER0 |= (1<<EXTI4_IRQ))
#define NVIC_EXTI9_5_IRQ_Enable						(NVIC_ISER0 |= (1<<EXTI9_IRQ))  //as EXTI from 5_9 take the same pin (pin 23)
#define NVIC_EXTI15_10_IRQ_Enable					(NVIC_ISER1 |= (1<<8))			//as EXTI from 10-->15 take the same pin (pin 8)


#define NVIC_EXTI0_IRQ_Disable						(NVIC_ICER0 |=  (1<<EXTI0_IRQ))
#define NVIC_EXTI1_IRQ_Disable						(NVIC_ICER0 |= (1<<EXTI1_IRQ))
#define NVIC_EXTI2_IRQ_Disable						(NVIC_ICER0 |= (1<<EXTI2_IRQ))
#define NVIC_EXTI3_IRQ_Disable						(NVIC_ICER0 |= (1<<EXTI3_IRQ))
#define NVIC_EXTI4_IRQ_Disable						(NVIC_ICER0 |= (1<<EXTI4_IRQ))
#define NVIC_EXTI9_5_IRQ_Disable					(NVIC_ICER0 |= (1<<EXTI9_IRQ))  	//as EXTI from 5_9 take the same pin (pin 23)
#define NVIC_EXTI15_10_IRQ_Disable					(NVIC_ICER1 |= (1<<8))				//as EXTI from 10-->15 take the same pin (pin 8)


//@ref_EXTIx[3:0]_define
//EXTERNAL interrupt line Mapping
//to select the source input for EXTIx external interrupt

#define PAx_PIN										(0)
#define PBx_PIN										(1)
#define PCx_PIN										(2)
#define PDx_PIN										(3)




/*@EXTI_IRQ_State_Mode */
#define IRQ_Enable									(1)
#define IRQ_Disable									(0)

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
void MCAL_EXTI_GPIO_Init(EXTI_pinConfig_t* EXTI_CFG);


/*************************************************************************************
 * @Fn							-MCAL_EXTI_GPIO_DeInit
 * @Brief						-Configure settings required to Reset
 * @Param [in]					-EXTI_CFG: select (EXTIx, GPIOy , GPIO_PIN_x , EXTIx_IRQ) x-->[1-15] && y[A,B,C,D]
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_EXTI_GPIO_DeInit(void);


/*************************************************************************************
 * @Fn							-MCAL_EXTI_GPIO_Update
 * @Brief						-Configure Updated settings required to generate interrupt
 * @Param [in]					-EXTI_CFG: select (EXTIx, GPIOy , GPIO_PIN_x , EXTIx_IRQ) x-->[1-15] && y[A,B,C,D]
 * @Note						-stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 								But LQFP48 package has only GPIO A,B part of C,D exported as PINS from the MCU
 *
 */
void MCAL_EXTI_GPIO_Update(EXTI_pinConfig_t* EXTI_CFG);

#endif /* INC_EXTI_DRIVER_H_ */
