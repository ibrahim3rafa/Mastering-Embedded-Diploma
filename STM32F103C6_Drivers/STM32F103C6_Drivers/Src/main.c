/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//
////#define SPI_ACT_AS_Master
//#define SPI_ACT_AS_Slave



#include "../MCAL/includes/GPIO_driver.h"
#include<STM32F103x8.h>
#include"../MCAL/includes/EXTI_driver.h"
#include"USART.h"
#include"RCC.h"
#include"SPI.h"
#include"I2C.h"
#include"I2C_EEPROM_SLAVE.h"

//
//unsigned int IRQ_FLAG = 0;
//unsigned char  ch;
//void ARAFA_CallBack(void){
//#ifdef	SPI_ACT_AS_Master
//	MCAL_UART_RecieveDate(USART1, &ch, Disable);
//	MCAL_UART_SendDate(USART1, &ch, Enable);
//
//	//send to spi
//	MCAL_GPIO_Write_Pin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
//	MCAL_SPI_TX_RX(SPI1, &ch, En);
//	MCAL_GPIO_Write_Pin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
//
//#endif
//}

void clock_init(void){
	//	Bit 2 IOPAEN: IO port A clock enable
	//	Set and cleared by software.
	//	0: IO port A clock disabled
	//	1: IO port A clock enabled

	RCC_GPIOA_CLK_EN();


	//	Bit 3 IOPBEN: IO port B clock enable
	//	Set and cleared by software.
	//	0: IO port B clock disabled
	//	1: IO port B clock enabled
	RCC_GPIOB_CLK_EN();

	RCC_AFIO_CLK_EN();

	RCC_USART1_CLK_Enable();



}

//
//void Arafa_SPI1_IRQHandler(struct SPI_Interrupt_source irq_src){
//#ifdef	SPI_ACT_AS_Slave
//	if(irq_src.RXNE){
//
//		ch = 0xf;
//		MCAL_SPI_TX_RX(SPI1, &ch, dis);
//		MCAL_UART_SendDate(USART1, &ch, Enable);
//
//	}
//#endif
//}


int main(void)
{

	clock_init();

//
//	GPIO_pinConfig pinConfiguration;
//
//
//
//
//
//	//>>>>>>>>>>>UART INit<<<<<<<<<<<<<<<<<<
//	UART_Config uartcfg;
//
//	uartcfg.BuadRate = UART_BuadRate_115200;
//	uartcfg.HWFlowCtl = UART_HWFlowCtrl_NONE;
//	uartcfg.IRQEnable = UART_IRQ_Enable_RXNE_or_ORE ;
//	uartcfg.P_IRQ_CallBack = ARAFA_CallBack;
//	uartcfg.Parity = UART_Parity_NONE;
//	uartcfg.Word_Lenght = UART_Word_Lenght_8B;
//	uartcfg.StopBits = UART_StopBits_One;
//	uartcfg.USART_Mode = UART_Mode_RX_TX;
//
//	MCAL_UART_Init(USART1, &uartcfg);
//	MCAL_UART_GPIO_SetPins(USART1);
//
//
//	//>>>>>>>>>>>SPI INit<<<<<<<<<<<<<<<<<<
//	SPI_Config spi_cfg;
//	spi_cfg.Clock_Phase = SPI_CLOCK_PHASE_SECOND_CLK_FIRST_CAPTURE_EDGE;
//	spi_cfg.Clock_Polarity = SPI_CLOCK_POLARITY_HIGH_IDLE;
//	spi_cfg.Communication_Mode = SPI_Two_Direction_2Lines;
//	spi_cfg.Data_Size = SPI_8BIT_DATA_FRAME;
//	spi_cfg.Frame_Format = SPI_Frame_Format_MSB_First;
//	//assume pclk2 is 8mhz
//	spi_cfg.Buadrate_Prescaler = SPI_BUADRATE_PRESCALER_8;
//
//#ifdef	SPI_ACT_AS_Master
//	//assume pclk2 is 8mhz
//	spi_cfg.Device_Mode = SPI_Device_Mode_Master;
//	spi_cfg.IRQ_En = SPI_IRQ_NONE;
//	spi_cfg.NSS = SPI_INTERNAL_SLAVE_SELECT_ENABLED;
//	spi_cfg.P_IRQ_CallBack = NULL;
//
//
//	//config PA4 as by gpio to slave select
//	pinConfiguration.GPIO_PinNum = GPIO_PIN_4;
//	pinConfiguration.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
//	pinConfiguration.GPIO_PinMode = OUTPUT_PUSH_PULL_MODE;
//	MCAL_GPIO_init(GPIOA, &pinConfiguration);
//
//	MCAL_GPIO_Write_Pin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
//#endif
//
//
//#ifdef SPI_ACT_AS_Slave
//
//	spi_cfg.Device_Mode = SPI_Device_Mode_Slave;
//	spi_cfg.IRQ_En = SPI_IRQ_RXNEIE;
//	spi_cfg.NSS = SPI_NSS_HW_SLAVE;
//	spi_cfg.P_IRQ_CallBack = Arafa_SPI1_IRQHandler;
//
//#endif
//
//	MCAL_SPI_Init(SPI1, &spi_cfg);

	//	MCAL_SPI_GPIO_Set_Pins(SPI1);


	//Test case 1
	unsigned char ch1[] = {0x1 , 0x2, 0x3, 0x4, 0x5, 0x6 , 0x7};
	unsigned char ch2[7] = {0};

	EEPROM_Init();
	EEPROM_WRITE_NBytes(0xAF, ch1, 7);		//write
	EEPROM_READ_NBytes(0xAF, ch2, 7);		//read

	//Test case 2
	ch1[0] = 0xA;
	ch1[1] = 0xB;
	ch1[2] = 0xC;
	ch1[3] = 0xD;
	EEPROM_WRITE_NBytes(0xFFF, ch1, 4);		//write
	EEPROM_READ_NBytes(0xFFF, ch2, 4);		//read

	while(1){


	}
}
