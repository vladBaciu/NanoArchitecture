/*-------------------------------------------------------------------------------------------------------------------*/
/**
 *    \file       RegisterInit.c
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      
 *
 *              
 */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "RegisterInit.h"
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

/*
*	\brief
*	\param 
*   \return
*/
void RegInit_gv_Unmasked8Bits(const RegInit_Unmasked8BitsConfigType* pt_Unmasked8BitsConfig)
{
	uint16 uc_I;
	for(uc_I = 0; uc_I < pt_Unmasked8BitsConfig->us_NumberOfRegisters; uc_I++)
	{
		(*pt_Unmasked8BitsConfig->kpt_Registers[uc_I].puc_Register) = pt_Unmasked8BitsConfig->kpt_Registers[uc_I].uc_Value;
	}
	
}
/*
*	\brief
*	\param
*   \return
*/
void RegInit_gv_Unmasked16Bits(const RegInit_Unmasked16BitsConfigType* pt_Unmasked16BitsConfig)
{
	uint16 uc_I;
	for(uc_I = 0; uc_I < pt_Unmasked16BitsConfig->us_NumberOfRegisters; uc_I++)
	{
		(*pt_Unmasked16BitsConfig->kpt_Registers[uc_I].pus_Register) = pt_Unmasked16BitsConfig->kpt_Registers[uc_I].us_Value;
	}
	
}
/*
*	\brief
*	\param
*   \return
*/
extern void RegInit_gv_Masked8Bits(const RegInit_Masked8BitsConfigType* pt_Unmasked8BitsConfig)
{
		uint16 uc_I;
		volatile uint8 uc_RegVal;
		for(uc_I = 0; uc_I < pt_Unmasked8BitsConfig->us_NumberOfRegisters; uc_I++)
		{
			uc_RegVal = *pt_Unmasked8BitsConfig->kpt_Registers[uc_I].puc_Register;
			uc_RegVal &= pt_Unmasked8BitsConfig->kpt_Registers[uc_I].uc_AndMask;
			uc_RegVal |= pt_Unmasked8BitsConfig->kpt_Registers[uc_I].uc_OrMask;
			(*pt_Unmasked8BitsConfig->kpt_Registers[uc_I].puc_Register) = uc_RegVal;
		}
}
/*
*	\brief
*	\param
*   \return
*/
extern void RegInit_gv_Masked16Bits(const RegInit_Masked16BitsConfigType* pt_Unmasked16BitsConfig)
{
			uint16 uc_I;
			volatile uint16 uc_RegVal;
			for(uc_I = 0; uc_I < pt_Unmasked16BitsConfig->us_NumberOfRegisters; uc_I++)
			{
				uc_RegVal = *pt_Unmasked16BitsConfig->kpt_Registers[uc_I].pus_Register;
				uc_RegVal &= pt_Unmasked16BitsConfig->kpt_Registers[uc_I].us_AndMask;
				uc_RegVal |= pt_Unmasked16BitsConfig->kpt_Registers[uc_I].us_OrMask;
				(*pt_Unmasked16BitsConfig->kpt_Registers[uc_I].pus_Register) = uc_RegVal;
			}
	
}