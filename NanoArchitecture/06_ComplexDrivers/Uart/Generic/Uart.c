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
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Definition Of Local Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

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
  

}
#endif

#if(UART_RECEIVE_API == STD_ON)
/**
 * \brief   Reads the receive register status.
 * \param   t_ChannelId: index of UART channel in the configuration array
 * \return  The status of receive operation: ready or busy.
 */
Uart_RxStatusType Uart_gt_GetReceiveStatus(Uart_ChannelType t_ChannelId)
{
   Uart_TxStatusType t_ReturnValue;
   
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
 
}
#endif