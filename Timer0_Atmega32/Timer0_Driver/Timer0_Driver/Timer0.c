/*
 * Timer0.c
 *
 * Created: 8/28/2023 10:38:56 AM
 *  Author: ARAFA
 */ 

/******************************************************************************
*                             Includes		                          *
*******************************************************************************/
#include "Timer0.h"
#include "avr/io.h"
#include "avr/interrupt.h"

/******************************************************************************
*                              Global VAR		                          *
*******************************************************************************/
Config_Struct_t* Configuration;
uint8_t g_overflow = 0;
ptr_voidfunvoid_t CallBack_OV;
ptr_voidfunvoid_t CallBack_OC;
/******************************************************************************
*                               APIS		                          *
*******************************************************************************/

E_STATUS_t Timer0_Init(Config_Struct_t* cfg){
	uint8_t retval = E_NOK;
	
	if(NULL_PTR == cfg){
		 retval = E_NOK;
	}else{
			 retval = E_OK;
		Configuration = cfg;
		if((Configuration->mode == NORMAL) && (Configuration->interrupt_mod == TOIE0)){
			TCCR0 |=Configuration->mode;
			TIMSK |= Configuration->interrupt_mod;
		}else if ((Configuration->mode == CTC) && (Configuration->interrupt_mod == OCIE0)){
			TCCR0 |= Configuration->mode;
			TIMSK |= Configuration->interrupt_mod;
		}else{
				 retval = E_NOK;
		}
		TCCR0 |= Configuration->prescaler;
	}	
	
	
	return retval;
}
E_STATUS_t Timer0_DeInit(void)
{
	uint8_t retval = E_NOK;
	
	TCCR0 |= No_CLOCK_SRC;
	return retval;
}
E_STATUS_t Timer0_SET_TCNT0(uint8_t u8_num){
	uint8_t retval = E_NOK;
	TCNT0 = u8_num;
	return retval;
}
E_STATUS_t Timer0_GET_TCNT0(ptr_uint8_t u8_num){
	uint8_t retval = E_NOK;
	*u8_num = TCNT0;
	return retval;
}
E_STATUS_t Timer0_SET_OCR0(uint8_t u8_num){
	uint8_t retval = E_NOK;
	OCR0 = u8_num;
	return retval;
}
E_STATUS_t Timer0_GET_OCR0(ptr_uint8_t u8_num){
	uint8_t retval = E_NOK;
	*u8_num = OCR0;
	return retval;
}

E_STATUS_t Timer0_SET_OVERFLOW_VALUE(uint8_t u8_num){
	uint8_t retval = E_NOK;
	g_overflow = u8_num;
	return retval;	
}
E_STATUS_t Timer0_GET_OVERFLOW_VALUE(ptr_uint8_t u8_num){
	uint8_t retval = E_NOK;
	*u8_num = g_overflow;
	return retval;	
}


void Timer0_overflow(ptr_voidfunvoid_t callback){
	CallBack_OV = callback;
}


void Timer0_overcompare(ptr_voidfunvoid_t callback){
	CallBack_OC = callback;
}


ISR(TIMER0_COMP_vect)
{
	CallBack_OC();
}

ISR(TIMER0_OVF_vect)
{
	g_overflow++;
	CallBack_OV();
}