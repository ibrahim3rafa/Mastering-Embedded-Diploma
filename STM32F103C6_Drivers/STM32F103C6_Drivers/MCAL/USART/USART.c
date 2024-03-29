/*
 * USART.c
 *
 *  Created on: Aug 14, 2023
 *      Author: ARAFA
 */


#include"USART.h"
#include"RCC.h"
#include"EXTI_driver.h"

//Generic ptr to be used in funcs
UART_Config * GP_UART_Config = NULL;



/**================================================================
 * @Fn					- MCAL_UART_Init
 * @brief 				- Initializes UART (Supported feature : ASYNCHRONOUS only)
 * @param [in] 			- USARTx: where x can be (1..3) depending on the device used
 * @param [in] 			- UARTCfg: All the UART configurations
 * @retval 				- None
 * Note					- The driver supports Asynchronous mode & HSI clock 8 Mhz
 */

void MCAL_UART_Init(USART_typedef* USARTx, UART_Config * UARTCfg){
	GP_UART_Config = UARTCfg;    //Backup

	uint32_t BRR,PCLCK;

	//Enable clock
	if(USARTx == USART1){
		RCC_USART1_CLK_Enable();
	}else if (USARTx == USART2){
		RCC_USART2_CLK_Enable();
	}else if(USARTx == USART3){
		RCC_USART3_CLK_Enable();
	}

	//Enable usart UE bit in USART_CR1
	USARTx->CR1 |= (1<<13);

	//programin M Bit in USART_CR1
	USARTx->CR1 |= UARTCfg->Word_Lenght;

	//stop Bits
	USARTx->CR2 |= UARTCfg->StopBits;

	//select desired buadrate
	if(USARTx == USART1){
		PCLCK = MCAL_RCC_GetPCLK2_CLCKFreq();
	}else if (USARTx == USART2){
		PCLCK = MCAL_RCC_GetPCLK1_CLCKFreq();
	}
	BRR = UART_BRR_Register(PCLCK,UARTCfg->BuadRate);
	USARTx->BRR = BRR;

	//select desired stop bit
	USARTx->CR2 |= UARTCfg->StopBits;

	//Select Parity bit
	USARTx->CR1 |= UARTCfg->Parity;

	//Select HWFlow CTRl
	USARTx->CR3 |= UARTCfg->HWFlowCtl;

	//select TX/Rx MOde
	USARTx->CR1 |= UARTCfg->USART_Mode;

	//select between interrupt and polling
	if(UARTCfg->IRQEnable != UART_IRQ_Enable_NONE){

		USARTx->CR1 |= UARTCfg->IRQEnable;

		if(USARTx == USART1){
			NVIC_USART1_IRQ_Enable;
		}else if (USARTx == USART2){
			NVIC_USART2_IRQ_Enable;
		}else if(USARTx == USART3){
			NVIC_USART3_IRQ_Enable;
		}
	}
}



/**================================================================
 * @Fn					- MCAL_UART_DeInit
 * @brief 				- DeInitializes UART (Supported feature : ASYNCHRONOUS only)
 * @param [in] 			- USARTx: where x can be (1..3) depending on the device used
 * @retval 				- None
 * Note					- Resets the USART module using RCC Reset registers
 */

void MCAL_UART_DeInit(USART_typedef* USARTx){
	if(USARTx == USART1){
		RCC_USART1_CLK_Disable();
		NVIC_USART1_IRQ_Disable;

	}else if (USARTx == USART2){
		RCC_USART2_CLK_Disable();
		NVIC_USART2_IRQ_Disable;

	}else if(USARTx == USART3){
		RCC_USART3_CLK_Disable();
		NVIC_USART3_IRQ_Disable;
	}
}


/**================================================================
 * @Fn					- MCAL_UART_GPIO_SetPins
 * @brief 				- Initializes GPIO pins
 * @param [in] 			- USARTx: where x can be (1..3) depending on the device used
 * @retval 				- None
 * Note					- should enable the corresponding AFIO & GPIO in RCC clock
 * 						  based on the recommended settings in data sheet
 */
void MCAL_UART_GPIO_SetPins(USART_typedef* USARTx){
	GPIO_pinConfig PINCfg;

	if(USARTx == USART1){

		//PA9-->Tx
		PINCfg.GPIO_PinNum = GPIO_PIN_9;
		PINCfg.GPIO_PinMode = AF_OUTPUT_PUSH_PULL_MODE;
		PINCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_init(GPIOA, &PINCfg);

		//PA10--->RX
		PINCfg.GPIO_PinNum = GPIO_PIN_10;
		PINCfg.GPIO_PinMode = AF_INPUT_FLOATING_MODE;
		MCAL_GPIO_init(GPIOA, &PINCfg);

		if(GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_CTS || GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS_CTS ){

			//PA11---> CTS
			PINCfg.GPIO_PinNum = GPIO_PIN_11;
			PINCfg.GPIO_PinMode = INPUT_FLOATING_MODE;
			MCAL_GPIO_init(GPIOA, &PINCfg);

		}else if(GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS || GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS_CTS){

			//PA12-->RTS
			PINCfg.GPIO_PinNum = GPIO_PIN_12;
			PINCfg.GPIO_PinMode = AF_OUTPUT_PUSH_PULL_MODE;
			PINCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOA, &PINCfg);
		}

	}else if (USARTx == USART2){

		//PA2-->Tx
		PINCfg.GPIO_PinNum = GPIO_PIN_2;
		PINCfg.GPIO_PinMode = AF_OUTPUT_PUSH_PULL_MODE;
		PINCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_init(GPIOA, &PINCfg);

		//PA3--->RX
		PINCfg.GPIO_PinNum = GPIO_PIN_3;
		PINCfg.GPIO_PinMode = AF_INPUT_FLOATING_MODE;
		MCAL_GPIO_init(GPIOA, &PINCfg);

		if(GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_CTS || GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS_CTS ){

			//PA0---> CTS
			PINCfg.GPIO_PinNum = GPIO_PIN_0;
			PINCfg.GPIO_PinMode = INPUT_FLOATING_MODE;
			MCAL_GPIO_init(GPIOA, &PINCfg);

		}else if(GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS || GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS_CTS){

			//PA1-->RTS
			PINCfg.GPIO_PinNum = GPIO_PIN_1;
			PINCfg.GPIO_PinMode = AF_OUTPUT_PUSH_PULL_MODE;
			PINCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOA, &PINCfg);
		}

	}else if(USARTx == USART3){

		//PB10-->Tx
		PINCfg.GPIO_PinNum = GPIO_PIN_10;
		PINCfg.GPIO_PinMode = AF_OUTPUT_PUSH_PULL_MODE;
		PINCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_init(GPIOB, &PINCfg);

		//PB11--->RX
		PINCfg.GPIO_PinNum = GPIO_PIN_11;
		PINCfg.GPIO_PinMode = AF_INPUT_FLOATING_MODE;
		MCAL_GPIO_init(GPIOB, &PINCfg);

		if(GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_CTS || GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS_CTS ){

			//PB13---> CTS
			PINCfg.GPIO_PinNum = GPIO_PIN_13;
			PINCfg.GPIO_PinMode = INPUT_FLOATING_MODE;
			MCAL_GPIO_init(GPIOB, &PINCfg);

		}else if(GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS || GP_UART_Config->HWFlowCtl == UART_HWFlowCtrl_RTS_CTS){

			//PB14-->RTS
			PINCfg.GPIO_PinNum = GPIO_PIN_14;
			PINCfg.GPIO_PinMode = AF_OUTPUT_PUSH_PULL_MODE;
			PINCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_init(GPIOB, &PINCfg);
		}

	}
}



/**================================================================
 * @Fn					- MCAL_UART_SendData
 * @brief 				- Send buffer on UART
 * @param [in] 			- USARTx: where x can be (1..3) depending on the device used
 * @param [in] 			- pTxBuffer: buffer
 * @param [in]			- PollingEn: Enable polling or not
 * @retval 				- None
 * Note					- When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
							the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
							because it is replaced by the parity.
							When receiving with the parity enabled, the value read in the MSB bit is the received parity bit.
 */
void MCAL_UART_SendDate(USART_typedef* USARTx, uint16_t* pTXBuffer, enum polling_Mechanism PollingState){

	//wait till TXE is set
	if(PollingState == Enable){
		while(!(USARTx->SR & 1<<7));
	}

	//check the word lenght
	if(GP_UART_Config ->Word_Lenght == UART_Word_Lenght_8B){
		USARTx->DR = (*pTXBuffer & (uint8_t)0xFF);
	}else{
		USARTx->DR = (*pTXBuffer & (uint16_t)0x01FF);
	}
}



/**================================================================
 * @Fn					- MCAL_UART_ReceiveData
 * @brief 				- Send buffer on UART
 * @param [in] 			- USARTx: where x can be (1..3) depending on the device used
 * @param [in] 			- pRxBuffer: buffer
 * @param [in]			- PollingEn: Enable polling or not
 * @retval 				- None
 * Note					- When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
							the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
							because it is replaced by the parity.
							When receiving with the parity enabled, the value read in the MSB bit is the received parity bit.
 */

void MCAL_UART_RecieveDate(USART_typedef* USARTx, uint16_t* pTXBuffer, enum polling_Mechanism PollingState){

	//wait till recieve not empty RXNE
	if(PollingState == Enable){
		while(!(USARTx->SR & (1<<5)));
	}

	//check the word lenght
	if(GP_UART_Config->Word_Lenght == UART_Word_Lenght_8B){

		if (GP_UART_Config->Parity == UART_Parity_NONE){
			*pTXBuffer = (USARTx->DR & (uint8_t)0xFF);

		}else{
			*pTXBuffer = (USARTx->DR & (uint8_t)0x7F);
		}

	}else{


		if (GP_UART_Config->Parity == UART_Parity_NONE){
			*pTXBuffer = (USARTx->DR & (uint16_t)0x1FF);

		}else{
			*pTXBuffer = (USARTx->DR & (uint8_t)0xFF);
		}

	}
}



/**================================================================
 * @Fn					- MCAL_UART_WAIT_TC
 * @brief 				- Waits until the last buffer is sent
 * @param [in] 			- USARTx: where x can be (1..3) depending on the device used
 * @retval 				- None
 * Note					- None
 */
void MCAL_UART_WAIT_TC(USART_typedef* USARTx){

	//wait till TC Flag is set
	while(!(USARTx->SR & 1<<6));

}







//ISR HANDELER
	void USART1_IRQHandler(void){
		GP_UART_Config->P_IRQ_CallBack();
	}

	void USART2_IRQHandler(void){
			GP_UART_Config->P_IRQ_CallBack();
		}

	void USART3_IRQHandler(void){
			GP_UART_Config->P_IRQ_CallBack();
		}
