/*-------------------------------------------------------------------------------------------------------------------*/
/**
*    \file       Dio_Lcfg.c
*    \author     Baciu Vlad-Eusebiu
*    \brief      Defines the configuration for every DIO channel and PORT.
*/
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Dio.h"
#include "Dio_Cfg.h"
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
/** \brief  Port configuration array. */
const Dio_PortCfgType Dio_gkat_PortAdressWrite[DIO_NUMBER_OF_PORTS] =
{
	{(volatile uint8 *) &PORTB},
	{(volatile uint8 *) &PORTC},
	{(volatile uint8 *) &PORTD},
	
};
const Dio_PortCfgType Dio_gkat_PortAdressRead[DIO_NUMBER_OF_PORTS] =
{
	{(volatile uint8 *) &PINB},
	{(volatile uint8 *) &PINC},
	{(volatile uint8 *) &PIND},
	
};

/** \brief  Channel configuration array. */
const Dio_ChannelCfgType Dio_gkat_ChannelCfg[DIO_NUMBER_OF_CHANNELS] =
{
	{ (uint8) PORTB0, DIO_PORTB },
	{ (uint8) PORTB1, DIO_PORTB },
	{ (uint8) PORTB2, DIO_PORTB },
	{ (uint8) PORTB3, DIO_PORTB },
	
	{ (uint8) PORTC0, DIO_PORTC },
	{ (uint8) PORTC1, DIO_PORTC },
	{ (uint8) PORTC2, DIO_PORTC },
	{ (uint8) PORTC3, DIO_PORTC },
	
	{ (uint8) PORTD0, DIO_PORTD },
	{ (uint8) PORTD1, DIO_PORTD },
	{ (uint8) PORTD2, DIO_PORTD },
	{ (uint8) PORTD3, DIO_PORTD },
	
	{ (uint8) PORTB4, DIO_PORTB },
	{ (uint8) PORTB5, DIO_PORTB },
	{ (uint8) PORTB6, DIO_PORTB },
	{ (uint8) PORTB7, DIO_PORTB },
	
	{ (uint8) PORTC4, DIO_PORTC },
	{ (uint8) PORTC5, DIO_PORTC },
	{ (uint8) PORTC6, DIO_PORTC },
	{ (uint8) PORTC7, DIO_PORTC },
	
	{ (uint8) PORTD4, DIO_PORTD },
	{ (uint8) PORTD5, DIO_PORTD },
	{ (uint8) PORTD6, DIO_PORTD },
	{ (uint8) PORTD7, DIO_PORTD },
	
};
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Declaration Of Local Functions                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                         Implementation Of Local Functions                                         */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                         Implementation Of Global Functions                                        */
/*-------------------------------------------------------------------------------------------------------------------*/