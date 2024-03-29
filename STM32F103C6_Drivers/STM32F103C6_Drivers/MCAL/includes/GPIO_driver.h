/*
 * STM32F103C6_gpio_driver.h
 *
 *  Created on: Jul 30, 2023
 *      Author: ARAFA
 */

#ifndef STM32F103C6_GPIO_DRIVER_H_
#define STM32F103C6_GPIO_DRIVER_H_
#include <STM32F103x8.h>


//GPIO_config_struct
typedef struct{

	volatile uint16_t GPIO_PinNum;		//Specifies the GPIO Pin to be configured
										//This parameter must be set used @ref GPIO_PINS_define

	volatile uint8_t GPIO_PinMode;		//Specifies the GPIO Pin mode to be configured
										//This parameter must be set used @ref GPIO_PINS_Mode_define

	volatile uint8_t GPIO_Output_Speed; //Specifies the GPIO Output Pin speed to be configured
										//This parameter must be set used @ref GPIO_OUTPUT_PINS_Speed

}GPIO_pinConfig;

/********************************************************************************************************************************
 *->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   MACROS CONFIG  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *********************************************************************************************************************************/
//@ref GPIO_PINS_define
#define GPIO_PIN_0											((uint16_t)0x0001)   //pin 0 selected
#define GPIO_PIN_1											((uint16_t)0x0002)   //pin 1 selected
#define GPIO_PIN_2											((uint16_t)0x0004)   //pin 2 selected
#define GPIO_PIN_3											((uint16_t)0x0008)   //pin 3 selected
#define GPIO_PIN_4											((uint16_t)0x0010)   //pin 4 selected
#define GPIO_PIN_5											((uint16_t)0x0020)   //pin 5 selected
#define GPIO_PIN_6											((uint16_t)0x0040)   //pin 6 selected
#define GPIO_PIN_7											((uint16_t)0x0080)   //pin 7 selected
#define GPIO_PIN_8											((uint16_t)0x0100)   //pin 8 selected
#define GPIO_PIN_9											((uint16_t)0x0200)   //pin 9 selected
#define GPIO_PIN_10											((uint16_t)0x0400)   //pin 10 selected
#define GPIO_PIN_11											((uint16_t)0x0800)   //pin 11 selected
#define GPIO_PIN_12											((uint16_t)0x1000)   //pin 12 selected
#define GPIO_PIN_13											((uint16_t)0x2000)   //pin 13 selected
#define GPIO_PIN_14											((uint16_t)0x4000)   //pin 14 selected
#define GPIO_PIN_15											((uint16_t)0x8000)   //pin 15 selected
#define GPIO_PIN_ALL										((uint16_t)0xFFFF)   //ALL PINS selected


#define GPIO_PIN_MASK										(0X0000FFFF)		//For assert test

//@ref GPIO_PIN_STATE
//PIN SET RESET
#define GPIO_PIN_SET										(1)
#define GPIO_PIN_RESET										(0)





//@ref GPIO_return_lock_STATE
#define GPIO_PIN_LOCK_ENABLE								(1)
#define GPIO_PIN_LOCK_ERROR									(0)





//@ref GPIO_MODE_define
//PIN MODES
//In input mode (MODE[1:0]=00):
#define INPUT_ANLOG_MODE 									(0x00000000u)	 //00: Analog mode
#define INPUT_FLOATING_MODE 								(0x00000001u)	//01: Floating input (reset state)
#define INPUT_PULL_UP_MODE 									(0x00000002u)	//10: Input with pull-up
#define INPUT_PULL_DOWN_MODE 								(0x00000003u)	//11: Input pull-down
//In output mode (MODE[1:0] > 00):
#define OUTPUT_PUSH_PULL_MODE 								(0x00000004u) //0100: General purpose output push-pull
#define OUTPUT_OPEN_DRAIN_MODE 								(0x00000005u)//0101: General purpose output Open-drain
#define AF_OUTPUT_PUSH_PULL_MODE 							(0x00000006u)//0110: Alternate function output Push-pull
#define AF_OUTPUT_OPEN_DRAIN_MODE 							(0x00000007u)//0111: Alternate function output Open-drain

#define AF_INPUT_FLOATING_MODE								(0x00000008u)//1000 :Alternate function input mode


//@ref GPIO_OUTPUT_PINS_Speed
//Output Pins speed
//00: Input mode (reset state)
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz.
//11: Output mode, max speed 50

#define GPIO_SPEED_10MHZ									(0x00000001u)
#define GPIO_SPEED_2MHZ										(0x00000002u)
#define GPIO_SPEED_50MHZ									(0x00000003u)



/********************************************************************************************************************************
 *->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> GPIO API'S  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *********************************************************************************************************************************/

void MCAL_GPIO_init(GPIO_typedefConfig* GPIOx, GPIO_pinConfig* pinConfig);
void MCAL_GPIO_Deinit(GPIO_typedefConfig* GPIOx);

void MCAL_GPIO_Write_Port(GPIO_typedefConfig* GPIOx, uint16_t value);
void MCAL_GPIO_Write_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber , uint8_t value);

uint16_t MCAL_GPIO_Read_Port(GPIO_typedefConfig* GPIOx);
uint8_t MCAL_GPIO_Read_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber);

void MCAL_GPIO_Toggle_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber);

uint8_t MCAL_GPIO_Lock_Pin(GPIO_typedefConfig* GPIOx, uint16_t pinNumber);






#endif /* STM32F103C6_GPIO_DRIVER_H_ */
