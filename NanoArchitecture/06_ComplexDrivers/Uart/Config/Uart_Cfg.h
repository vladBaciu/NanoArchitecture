
/*-------------------------------------------------------------------------------------------------------------------*/
/**
 *    \file       Uart_Cfg.h
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      Defines  API macros and UART channels.
 */
/*-------------------------------------------------------------------------------------------------------------------*/

#ifndef UART_CFG_H
#define UART_CFG_H

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Uart.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                            Definition Of Global Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
#define UART_TRANSMIT_API                    (STD_ON)

#define UART_RECEIVE_API                     (STD_ON)

#define UART_FCPU							 (1U)

#define UART_BAUD_RATE						 (1U)

#define UART_UBRR_REGISTER					 (UART_FCPU/16/UART_BAUD_RATE-1)

#define UART_UBBRH_REGISTER					 (UART_UBRR_REGISTER>>8)

#define UART_ENABLE_RX						 (1<<RXEN0)

#define UART_ENABLE_TX						 (1<<TXEN0)

#define UART_NO_BITS						 (1<<USBS0)

#define UART_STOP_BITS						 (3<<UCSZ00)
	
#define UART_RX_INTERRUPT					 (1<<RXCIE0)
	
#define UART_TX_D_1							 (0U)
	
#define UART_RX_D_0							 (1U)
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                          Definition Of Global Data Types                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Variables                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Constants                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Functions                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
#endif /* UART_CFG_H */