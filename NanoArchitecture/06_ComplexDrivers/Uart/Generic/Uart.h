    
/*-------------------------------------------------------------------------------------------------------------------*/
/**
 *    \file       Uart.h
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      Declares UART functions, exports the array configuration and define global data types.
 */
/*-------------------------------------------------------------------------------------------------------------------*/

#ifndef UART_H
#define UART_H

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "RegisterInit.h"
#include "Uart_Cfg.h"

#include <avr/io.h>
#include <stdio.h>

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                            Definition Of Global Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
#define NUMBER_OF_UART_REGISTERS (10U)
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                          Definition Of Global Data Types                                          */
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Status types for transmit process */
typedef enum
{
   UART_TX_BUSY,
   UART_TX_READY
} Uart_TxStatusType;

/** \brief Status types for receive process */
typedef enum
{
   UART_RX_NO_DATA,
   UART_RX_READY
} Uart_RxStatusType;

/** \brief Status types for data register  */
typedef enum
{
	UART_DATA_REG_EMPTY,
	UART_DATA_REG_NOT_EMPTY
} Uart_DataRegisterStatusType;

/** \brief Uart channel type */
typedef uint8 Uart_ChannelType;

/** \brief Channel config type */
typedef struct
{
   Uart_ChannelType t_Channel;
   volatile uint8  *pt_Registers[NUMBER_OF_UART_REGISTERS];
} Uart_GroupCfgType;

typedef struct
{
   const Uart_GroupCfgType *pt_ConfigGroup;
   const RegInit_Masked8BitsConfigType* pt_ConfigRegisters;
} Uart_ConfigType;
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Variables                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Constants                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
extern const Uart_ConfigType Uart_gkt_Cfg;
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Functions                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
extern void Uart_gv_Init(const Uart_ConfigType * pt_Config);
extern Uart_TxStatusType Uart_gt_GetTransmitStatus(Uart_ChannelType t_ChannelId);
extern Uart_RxStatusType Uart_gt_GetReceiveStatus(Uart_ChannelType t_ChannelId);
extern Uart_DataRegisterStatusType Uart_gt_DataRegisterStatus(Uart_ChannelType t_ChannelId);
extern void Uart_gv_Transmit(Uart_ChannelType t_ChannelId, uint8 * puc_TransmitAddr);
extern void Uart_gv_Receive(Uart_ChannelType t_ChannelId, uint8 * puc_ReceiveAddr);

extern void Uart_gv_TransmitString_CH_0(char uc_Byte , FILE * pt_Stream);

/*-------------------------------------------------------------------------------------------------------------------*/



#endif /* UART_H */