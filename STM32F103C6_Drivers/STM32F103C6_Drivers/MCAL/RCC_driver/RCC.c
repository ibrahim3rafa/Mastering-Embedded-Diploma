/*
 * RCC.c
 *
 *  Created on: Aug 14, 2023
 *      Author: ARAFA
 */

#include"RCC.h"




//Bits 7:4 HPRE[3:0]: AHB prescaler
//Set and cleared by software to control AHB clock division factor.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512

const uint8_t AHBPrescaler[16U] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0, 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};

//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16
const uint8_t APBPrescaler[8U] = {0 , 0 , 0 , 0 , 1 , 2 , 3 , 4};

uint32_t MCAL_RCC_GetSYS_CLCKFreq(void){
	switch((RCC->CFGR >> 2) & 0b11){
	case 0 :
		return HSI_RC_Clock;
			break;
	case 1 :
		return HSE_Clock;
			break;
	case 2 :
		return 16000000;
		break;
	}
}


//: AHB prescaler
//Set and cleared by software to control AHB clock division factor.
uint32_t MCAL_RCC_GetHCLK_CLCKFreq(void){
	return (MCAL_RCC_GetSYS_CLCKFreq() >> AHBPrescaler[((RCC->CFGR >> 4) & 0xF)] );
}



//Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
uint32_t MCAL_RCC_GetPCLK1_CLCKFreq(void){
	return ( MCAL_RCC_GetHCLK_CLCKFreq() >> APBPrescaler[((RCC->CFGR>>8) & 0b111) ] );
}



//PPRE2[2:0]: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
uint32_t MCAL_RCC_GetPCLK2_CLCKFreq(void){
	return ( MCAL_RCC_GetHCLK_CLCKFreq() >> APBPrescaler[((RCC->CFGR>>11) & 0b111) ] );
}

