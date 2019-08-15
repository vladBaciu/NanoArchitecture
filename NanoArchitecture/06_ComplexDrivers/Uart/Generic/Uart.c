/*-------------------------------------------------------------------------------------------------------------------*/
/**
*    \file       Uart.c
*    \author     Baciu Vlad-Eusebiu
*    \brief      Implements all the functions for UART module.
*
*
*/
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Uart.h"
#include <avr/io.h>
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Definition Of Local Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
#define UART_DATA_REGISTER_EMPTY_BIT			    (1<<5)
#define UART_TX_STATUS_BIT			    (1<<6)
#define UART_RX_STATUS_BIT			    (1<<7)
#define UART_STATUS_REGISTER			(0U)
#define UART_RECEIVE_REGISTER			(1U)
#define UART_TRANSMIT_REGISTER			(1U)
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Definition Of Local Data Types                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Declaration Of Local Variables                                          */
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief  Stores the address of the selected post-build configuration. */
static Uart_GroupCfgType * Uart_pt_GroupsConfig;
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                          Declaration Of Global Variables                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Declaration Of Local Constants                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                          Declaration Of Global Constants                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Declaration Of Local Functions                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                         Implementation Of Local Functions                                         */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                         Implementation Of Global Functions                                        */
/*-------------------------------------------------------------------------------------------------------------------*/
/**
* \brief   Init the UART channels from the configuration array
* \param   pt_Config: pointer to the configuration array
* \return  -
*/
void Uart_gv_Init(const Uart_ConfigType * pt_Config)
{
	RegInit_gv_Masked8Bits(pt_Config->pt_ConfigRegisters);
	Uart_pt_GroupsConfig = (Uart_GroupCfgType*) pt_Config->pt_ConfigGroup;

}

#if(UART_TRANSMIT_API == STD_ON)
/**
* \brief   Reads the transmision register status.
* \param   t_ChannelId: index of UART channel in the configuration array
* \return  The status of transmit operation: ready or busy.
*/
Uart_TxStatusType Uart_gt_GetTransmitStatus(Uart_ChannelType t_ChannelId)
{
	Uart_TxStatusType t_ReturnValue;
	uint8 uc_StatusRegister;
	uc_StatusRegister = (uint8) *Uart_pt_GroupsConfig[t_ChannelId].pt_Registers[UART_STATUS_REGISTER];
	if((uc_StatusRegister & UART_TX_STATUS_BIT) != 0)
	{
		t_ReturnValue = UART_TX_READY;
		
	}
	else
	{
		t_ReturnValue = UART_TX_BUSY;
	}
	return t_ReturnValue;
}

/**
* \brief   Puts data in the DR register.
* \param   t_ChannelId: index of UART channel in the configuration array.
* \param   puc_TransmitAddr: buffer pointer for the data that is transmitted.
* \return  -
*/
void Uart_gv_Transmit(Uart_ChannelType t_ChannelId, uint8 * puc_TransmitAddr)
{
	  *Uart_pt_GroupsConfig[t_ChannelId].pt_Registers[UART_TRANSMIT_REGISTER] = (uint8) *puc_TransmitAddr;
 while (Uart_gt_GetTransmitStatus(t_ChannelId) == UART_TX_BUSY)
 {

 };
}
#endif


/**
* \brief   Reads the transmision register status.
* \param   t_ChannelId: index of UART channel in the configuration array
* \return  The status of transmit operation: ready or busy.
*/
Uart_DataRegisterStatusType Uart_gt_DataRegisterStatus(Uart_ChannelType t_ChannelId)
{
	Uart_TxStatusType t_ReturnValue;
	uint8 uc_StatusRegister;
	uc_StatusRegister = (uint8) *Uart_pt_GroupsConfig[t_ChannelId].pt_Registers[UART_STATUS_REGISTER];
	if((uc_StatusRegister & UART_DATA_REGISTER_EMPTY_BIT) != 0)
	{
		t_ReturnValue = UART_DATA_REG_EMPTY;
		
	}
	else
	{
		t_ReturnValue = UART_DATA_REG_NOT_EMPTY;
	}
	return t_ReturnValue;
}








#if(UART_RECEIVE_API == STD_ON)
/**
* \brief   Reads the receive register status.
* \param   t_ChannelId: index of UART channel in the configuration array
* \return  The status of receive operation: ready or busy.
*/
Uart_RxStatusType Uart_gt_GetReceiveStatus(Uart_ChannelType t_ChannelId)
{
	Uart_RxStatusType t_ReturnValue;
	uint8 uc_StatusRegister;
	uc_StatusRegister = (uint8) *Uart_pt_GroupsConfig[t_ChannelId].pt_Registers[UART_STATUS_REGISTER];
	if((uc_StatusRegister & UART_RX_STATUS_BIT) !=0)
	{
		t_ReturnValue = UART_RX_READY;
		
	}
	else
	{
		t_ReturnValue = UART_RX_NO_DATA;
	}
	return t_ReturnValue;

}

/**
* \brief   Reads data from the DR register.
* \param   t_ChannelId: index of UART channel in the configuration array.
* \param   puc_ReceiveAddr: buffer pointer where incoming data is stored.
* \return  -
*/
void Uart_gv_Receive(Uart_ChannelType t_ChannelId, uint8 * puc_ReceiveAddr)
{
	while (Uart_gt_GetReceiveStatus(t_ChannelId) == UART_RX_NO_DATA)
	{

	};
	*puc_ReceiveAddr =  (uint8) *Uart_pt_GroupsConfig[t_ChannelId].pt_Registers[UART_RECEIVE_REGISTER];
}
#endif

/**
* \brief   
* \param   
* \param   
* \return  -
*/
void Uart_gv_TransmitString_CH_0(char uc_Byte, FILE * pt_Stream)
{
	
	if (uc_Byte == '\n')
	{
			Uart_gv_TransmitString_CH_0('\r',pt_Stream);
	}
	while(Uart_gt_DataRegisterStatus(UART_TX_D_1) == UART_DATA_REG_NOT_EMPTY);
	  *Uart_pt_GroupsConfig[UART_TX_D_1].pt_Registers[UART_TRANSMIT_REGISTER] = uc_Byte;
}