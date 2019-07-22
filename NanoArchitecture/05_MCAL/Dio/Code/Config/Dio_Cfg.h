/*-------------------------------------------------------------------------------------------------------------------*/
/**
 *    \file       Dio_Cfg.h
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      Defines and exports the channels and ports IDs.
 */
/*-------------------------------------------------------------------------------------------------------------------*/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Dio.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                            Definition Of Global Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief  Numbers of channels from channel configuration array */
#define DIO_NUMBER_OF_CHANNELS (30U)
/** \brief  Numbers of ports from port configuration array */
#define DIO_NUMBER_OF_PORTS    (3U)
/** \brief  Index for PORTB in configuration array */
#define DIO_PORTB			   (0U)
/** \brief  Index for PORTB in configuration array */
#define DIO_PORTC			   (1U)
/** \brief  Index for PORTB in configuration array */
#define DIO_PORTD			   (2U)
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
#endif /* DIO_CFG_H */