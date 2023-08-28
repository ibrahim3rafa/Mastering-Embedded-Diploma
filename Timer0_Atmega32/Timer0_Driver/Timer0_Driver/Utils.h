/*
 * Utils.h
 *
 * Created: 8/28/2023 9:40:55 AM
 *  Author: ARAFA
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(PORT,BIT)						  (PORT |= (1 << BIT))
#define RESET_BIT(PORT,BIT)						  (PORT &= ~(1 << BIT))
#define TOG_BIT(PORT,BIT)						  (PORT ^= (1 << BIT))
#define GET_BIT(PORT,BIT)						  (PORT & (1 << BIT))

#define  NULL_PTR								  ((void*)0)

/******************************************************************************
*                               TYPEDEFS			                          *
*******************************************************************************/
typedef unsigned char uint8_t;
typedef char sint8_t;
typedef int sint32_t;

typedef unsigned char*  ptr_uint8_t;	
typedef char* ptr_sint8_t;

typedef void(*ptr_voidfunvoid_t)(void);



#endif /* UTILS_H_ */