/*
 * USART.h
 *
 *  Created on: Aug 14, 2023
 *      Author: ARAFA
 */

#ifndef INCLUDES_USART_H_
#define INCLUDES_USART_H_


#include <STM32F103x8.h>
//
//enum UART_IRQ_Event{
//	UART_IRQ_TXE,						/*Transmission data register Empty*/
//	UART_IRQ_Enable_TC,					/*Transmission Complete*/
//	UART_IRQ_Enable_RXNE,				/*Recieved data ready to be read*/
//	UART_IRQ_Enable_ORE,				/*Overrun error detected */
//	UART_IRQ_Enable_PE					//parity Error
//};
//UART confing struct
typedef struct {

	uint8_t USART_Mode ;						/*Specifies TX/RX Mode. This parameter must be set based on @ref USART_MODE_Define */

	uint8_t Word_Lenght;						/*Specifies the number of the data bits transmitted or recieved in a frame .
	 	 	 	 	 	 	 	 	 	 	 	 	 this parameter must be set based on @ref WordLenght define*/

	uint8_t StopBits;							/*Specifies the number of stop bits transmitted @ref StopBits define */


	uint32_t BuadRate;							/*This parameter specifies the Uart communication buad rate
	 	 	 	 	 	 	 	 	 	 	 	 	 	 This parameter must be set based on @ref BuadRate Define */

	uint8_t	 Parity ;							/*Specifies the parity mode @ref Parity_define	*/


	uint8_t HWFlowCtl;							/*Specifies whether the hardware flow control mode is enabled or disabled
	 	 	 	 	 	 	 	 	 	 	 	 	 @ref HWFlowCtrl _define*/

	uint8_t IRQEnable;							/*Enable or disable Uart IRQ TX/RX @ref IRQ_Enable_define */


	void (*P_IRQ_CallBack)(void);				/*Set the C Function which will be called once the IRQ Happen */

}UART_Config;



/********************************************************************************************************************************
 *->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> USART define Macros @ref  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *********************************************************************************************************************************/

/*@ref USART_MODE_Define*/
#define UART_Mode_RX							(uint32_t)(1<<2)
#define UART_Mode_TX							(uint32_t)(1<<3)
#define UART_Mode_RX_TX							(uint32_t)((1<<2 | 1<<3))


/*@ref WordLenght define**/
#define UART_Word_Lenght_8B						(uint32_t)(0)
#define UART_Word_Lenght_9B						(uint32_t)(1<<12)


/*@ref StopBits define*/
#define UART_StopBits_half						(uint32_t)(1<<12)
#define UART_StopBits_One						(uint32_t)(0)
#define UART_StopBits_One_half					(uint32_t)(3<<12)
#define UART_StopBits_Two						(uint32_t)(2<<12)


/*@ref BuadRate Define*/
#define UART_BuadRate_2400								2400
#define UART_BuadRate_9600								9600
#define UART_BuadRate_19200								19200
#define UART_BuadRate_57600								57600
#define UART_BuadRate_115200							115200
#define UART_BuadRate_230400							230400
#define UART_BuadRate_460800							460800
#define UART_BuadRate_921600							921600
#define UART_BuadRate_2250000							2250000
#define UART_BuadRate_4500000							4500000



/*@ref Parity_define*/
#define UART_Parity_NONE							(uint32_t)(0)
#define UART_Parity_EVEN							(uint32_t)(1<<10)
#define UART_Parity_ODD								(uint32_t)((1<<10 | 1<<9))



/*@ref HWFlowCtrl _define*/
#define UART_HWFlowCtrl_NONE						(uint32_t)(0)
#define UART_HWFlowCtrl_RTS							(uint32_t)(1<<8)
#define UART_HWFlowCtrl_CTS							(uint32_t)(1<<9)
#define UART_HWFlowCtrl_RTS_CTS						(uint32_t)((1<<8 | 1<<9))

/*@ref IRQ_Enable_define */
#define UART_IRQ_Enable_NONE						(uint32_t)(0)
#define UART_IRQ_Enable_TXE							(uint32_t)(1<<7)  /*Transmit Data register Empty*/
#define UART_IRQ_Enable_TC							(uint32_t)(1<<6) 	 /*Transmit Complete */
#define UART_IRQ_Enable_RXNE_or_ORE					(uint32_t)(1<<5) 	 /*Recieve data register not empty or overrun error detected */
#define UART_IRQ_Enable_PE							(uint32_t)(1<<8) 	 /*Parity Error */







enum polling_Mechanism{
	Disable,Enable
};



/********************************************************************************************************************************
 *->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> USART API'S  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 *********************************************************************************************************************************/
void MCAL_UART_Init(USART_typedef* USARTx, UART_Config * UARTCfg);
void MCAL_UART_DeInit(USART_typedef* USART);
void MCAL_UART_GPIO_SetPins(USART_typedef* USARTx);
void MCAL_UART_SendDate(USART_typedef* USARTx, uint16_t* pTXBuffer, enum polling_Mechanism PollingState);
void MCAL_UART_RecieveDate(USART_typedef* USARTx, uint16_t* pTXBuffer, enum polling_Mechanism PollingState);
void MCAL_UART_WAIT_TC(USART_typedef* USARTx);

#endif /* INCLUDES_USART_H_ */
