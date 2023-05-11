/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Eng Arafa
 * @brief          : Main program body
 ******************************************************************************
 *
 ******************************************************************************
 */
#include <stdio.h>
#include<stdlib.h>
#include "Platform_Types.h"
#define 	RCC_BASE			0X40021000
#define 	GPIOA_BASE			0X40010800

#define 	APB2ENR				*(vuint32*)(RCC_BASE+0X18)
#define		CRH					*(vuint32*)(GPIOA_BASE+0X04)
#define 	ODR					*(vuint32*)(GPIOA_BASE+0X0C)
//BIT FIELDS
#define RCC_IOPAEN 				(1<<2)
#define GPIOA13					(1UL<<13)

typedef union {
	vuint32 		all_fields;
		struct{
		vuint32 	reserved : 13;
		vuint32		p_13:1;
	}pin;
}R_ODR;

volatile R_ODR*  R_ODR_PTR = (volatile R_ODR*)(GPIOA_BASE+0X0C);
unsigned char g_variables[3] = {1,2,3};
unsigned char const_variables[3] = {1,2,3};
volatile unsigned char bss_var[3] ;

void *_sbrk(int incr){
	static unsigned char* heap_ptr = NULL;
	unsigned char* prev_heap_ptr = NULL;
	extern unsigned int _E_BSS ;
	extern unsigned int _heap_End ;

	// first intialze 
	if(heap_ptr == NULL)
		heap_ptr = (unsigned char*)&_E_BSS;

	prev_heap_ptr = heap_ptr;

//protect stack

	if((heap_ptr + incr) > (&_heap_End))
		return (void*) NULL;

	//booking inc size 

	heap_ptr += incr;

	return (void*) prev_heap_ptr;
}
int main(void)
{
	int* p = (int*)malloc(4);
	APB2ENR |= RCC_IOPAEN;
	CRH &= 0XFF0FFFFF;
	CRH |= 0X00200000;
	int i;
    /* Loop forever */
	while(1){
	R_ODR_PTR->pin.p_13 = 1;
	for(i = 0; i<5000; i++);
	R_ODR_PTR->pin.p_13 = 0;
	for(i = 0; i<5000; i++);
	}
	free(p);
}
