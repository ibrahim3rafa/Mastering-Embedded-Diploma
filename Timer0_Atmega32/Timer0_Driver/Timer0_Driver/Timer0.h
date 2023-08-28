/*
 * Timer0.h
 *
 * Created: 8/28/2023 9:49:24 AM
 *  Author: ARAFA
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "Utils.h"

/******************************************************************************
*                               TYPEDEF_ENUMS			                          *
*******************************************************************************/
typedef enum{
 Normal = 0x80,
 OCT = 0x88
}Mode_t;

typedef enum {
	No_CLOCK_SRC,
	NO_PRESCALER,
	CLK8,
	CLK64,
	CLK256,
	CLK1024,
	EXT_CLK_FALL,
	EXT_CLK,RIS

}Clock_Select_t;

typedef enum {
	NORMAL,
	PWM_PHASE_CORRECT,
	CTC=0x02,
	FAST_PWM
}Wave_Generation_Mode_t;


typedef enum {
	Disconnected_OC0,
	TOG_OC0,
	CLEAR_OC0,
	SET_OC0
}Compare_Match_Output_Mode_t;

typedef enum{
	TOIE0 = 0x01,
	OCIE0 = 0x02,
}Interrupt_Mode_t;


typedef enum {
	TOV0,
	OCF0,
}Interrupt_Flag_t;

typedef struct {
	Mode_t mode;
	Clock_Select_t prescaler;
	Interrupt_Mode_t interrupt_mod;
	
}Config_Struct_t;



typedef enum {
 E_OK,
 E_NOK	
}E_STATUS_t;

/******************************************************************************
*                               APIS									      *
*******************************************************************************/

E_STATUS_t Timer0_Init(Config_Struct_t* cfg);
E_STATUS_t Timer0_DeInit(void);
E_STATUS_t Timer0_SET_TCNT0(uint8_t u8_num);
E_STATUS_t Timer0_GET_TCNT0(ptr_uint8_t u8_num);
E_STATUS_t Timer0_SET_OCR0(uint8_t u8_num);
E_STATUS_t Timer0_GET_OCR0(ptr_uint8_t u8_num);
E_STATUS_t Timer0_SET_OVERFLOW_VALUE(uint8_t u8_num);
E_STATUS_t Timer0_GET_OVERFLOW_VALUE(ptr_uint8_t u8_num);

#endif /* TIMER0_H_ */