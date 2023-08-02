/*
 * STM32F103x6.h
 *
 *  Created on: Jul 30, 2023
 *      Author: ARAFA
 */

#ifndef STM32F103X6_H_
#define STM32F103X6_H_

//------------------------------------------------------------------
//Includes
//------------------------------------------------------------------

#include"stdlib.h"
#include"stdint.h"


/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/


//------------------------------------------------------------------
//Base addresses for memories
//------------------------------------------------------------------

#define Flash_Memory_Base 							(0x08000000UL)
#define System_Memory_Base 							(0x1FFFF000UL)
#define Sram_Memory_Base 							(0x20000000UL)


#define Peripherals_Base 							(0x40000000UL)

#define Cortex_M3_Internal_Peripherals				(0xE0000000UL)



/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/


//------------------------------------------------------------------
//Base addresses for APB2 BUS Peripherals
//------------------------------------------------------------------
#define GPIOA_BASE 									(0x40010800)
#define GPIOB_BASE 									(0x40010C00)
#define GPIOC_BASE 									(0x40011000)
#define GPIOD_BASE									(0x40011400)
#define GPIOE_BASE 									(0x40011800)
#define GPIOF_BASE 									(0x40011C00)
#define GPIOG_BASE 									(0x40012000)

#define EXTI_BASE 									(0x40010400)


#define AFIO_BASE 									(0x40010000)

#define RCC_BASE 									(0x40021000)



/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/


//----------------------------------------------------------------
//Peripherals Registers
//----------------------------------------------------------------


//GPIO
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_typedefConfig;


//RCC
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_typedef;


//EXTI
typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_typedef;


//AFIO
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;  //0x18
	volatile uint32_t MAPR2;	//0x1C
}AFIO_typedef;




/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/



//---------------------------------------------------------------------------------
//peripherals instants
//---------------------------------------------------------------------------------


#define GPIOA 										((GPIO_typedefConfig*)GPIOA_BASE)
#define GPIOB 										((GPIO_typedefConfig*)GPIOB_BASE)
#define GPIOC 										((GPIO_typedefConfig*)GPIOC_BASE)
#define GPIOD 										((GPIO_typedefConfig*)GPIOD_BASE)
#define GPIOE 										((GPIO_typedefConfig*)GPIOE_BASE)
#define GPIOF 										((GPIO_typedefConfig*)GPIOF_BASE)
#define GPIOG 										((GPIO_typedefConfig*)GPIOG_BASE)



#define	RCC											((RCC_typedef*)RCC_BASE)

#define	EXTI										((EXTI_typedef*)EXTI_BASE)

#define AFIO										((AFIO_typedef*)AFIO_BASE)



/****************************************************************************************************/
/****************************************************************************************************/
/****************************************************************************************************/



//--------------------------------------------------------------
//clock Enable Macros
//--------------------------------------------------------------

//GPIO ENABLES
#define RCC_GPIOA_CLK_EN()							(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN()							(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN()							(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN()							(RCC->APB2ENR |= (1<<5))
#define RCC_GPIE_CLK_EN()							(RCC->APB2ENR |= (1<<6))

//AFIO ENABLE+
#define RCC_AFIO_CLK_EN()							(RCC->APB2ENR |= (1<<0))


#endif /* STM32F103X6_H_ */
