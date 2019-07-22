/**
 *    \file       Dio.c
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      Implements the interfaces of DIO module.
 */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Dio.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Definition Of Local Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Definition Of Local Data Types                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Declaration Of Local Variables                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

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
 * \brief      Read a bit from a GPIOx IDR register. That bit represents the state of the selected channel.
 * \param      ChannelId: index of the channel from channel configuration array.
 * \return     The state of the channel (STD_HIGH or STD_LOW).
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
return 1;
}

/**
 * \brief      Writes data in ODR register for a specific channel.
 * \param      ChannelId: channel index from channel configuration array.
 * \param      Level: specifies the value to be written (STD_LOW or STD_HIGH).
 * \return     -
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{

}

/**
 * \brief      Reads the entire  port register.
 * \param      PortId: the index of the port in the list of ports.
 * \return     Returns the state of the channels.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	return (Dio_PortLevelType) *Dio_gkat_PortAdressRead[PortId].pt_Registers;
}

/**
 * \brief      Writes the  port register.
 * \param      PortId: the index of the port in the list of ports.
 * \param      Level:  the state for every channel in the port.
 * \return     -
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	uint8 uc_PortValue;
	uc_PortValue = Dio_ReadPort(PortId); 
	uc_PortValue = Level & uc_PortValue; 
	uc_PortValue = Level | uc_PortValue; 
	
	
	*Dio_gkat_PortAdressWrite[PortId].pt_Registers = uc_PortValue;
}