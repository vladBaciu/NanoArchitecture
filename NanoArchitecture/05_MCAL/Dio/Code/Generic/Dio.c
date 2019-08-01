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
	uint8 uc_Mask = Dio_gkat_ChannelCfg[ChannelId].us_Mask;
	Dio_LevelType t_ReturnValue = 0;
	Dio_PortLevelType t_PortValue = (Dio_PortLevelType) *Dio_gkat_PortAdressRead[Dio_gkat_ChannelCfg[ChannelId].t_Port].pt_Registers;
	if ((uc_Mask & t_PortValue) == uc_Mask)
	{
		t_ReturnValue = STD_HIGH;
	}
	else
	{
		t_ReturnValue = STD_LOW;
	}
	return t_ReturnValue;
}

/**
* \brief      Writes data in ODR register for a specific channel.
* \param      ChannelId: channel index from channel configuration array.
* \param      Level: specifies the value to be written (STD_LOW or STD_HIGH).
* \return     -
*/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	uint8 uc_Mask = Dio_gkat_ChannelCfg[ChannelId].us_Mask;
	Dio_PortType t_PortNumber = Dio_gkat_ChannelCfg[ChannelId].t_Port;

	if (Level == STD_HIGH)
	{
		*(Dio_gkat_PortAdressWrite[t_PortNumber].pt_Registers) |= uc_Mask;
	}
	else
	{
		*(Dio_gkat_PortAdressWrite[t_PortNumber].pt_Registers) &= ~(uc_Mask);
	}
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