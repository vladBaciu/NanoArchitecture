/*-------------------------------------------------------------------------------------------------------------------*/
/**
 *    \file       Port.h
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      
 */
/*-------------------------------------------------------------------------------------------------------------------*/

#ifndef PORT_H
#define PORT_H

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Std_Types.h"
#include "RegisterInit.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                            Definition Of Global Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                          Definition Of Global Data Types                                          */
/*-------------------------------------------------------------------------------------------------------------------*/
typedef RegInit_Unmasked8BitsConfigType Port_ConfigType;
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Variables                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Constants                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
extern const Port_ConfigType Port_gkt_Config;
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Functions                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
extern void Port_Init(const Port_ConfigType* pt_PortConfig);
/*-------------------------------------------------------------------------------------------------------------------*/
#endif /* PORT_H */