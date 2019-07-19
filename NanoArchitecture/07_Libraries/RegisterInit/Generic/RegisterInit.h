/*-------------------------------------------------------------------------------------------------------------------*/
/**
 *    \file       RegisterInit.h
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      
 */
/*-------------------------------------------------------------------------------------------------------------------*/

#ifndef REGISTERINIT_H
#define REGISTERINIT_H

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Std_Types.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                            Definition Of Global Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                          Definition Of Global Data Types                                          */
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief  Defines a configuration for a single 8-bits register. */
typedef struct
{
	volatile uint8* puc_Register;
	uint8 uc_Value;
} RegInit_Unmasked8BitsSingleType;

/** \brief  Defines a configuration of multiple  8-bits register. */
typedef struct
{
	const RegInit_Unmasked8BitsSingleType * kpt_Registers;
	uint16 us_NumberOfRegisters;	
	
}RegInit_Unmasked8BitsConfigType;

/** \brief  Defines a configuration for a single 16-bits register. */
typedef struct
{
	volatile uint16* pus_Register;
	uint16 us_Value;
} RegInit_Unmasked16BitsSingleType;

/** \brief  Defines a configuration of multiple  16-bits register. */
typedef struct
{
	const RegInit_Unmasked16BitsSingleType * kpt_Registers;
	uint16 us_NumberOfRegisters;	
	
}RegInit_Unmasked16BitsConfigType;

/** \brief  Defines a configuration for a single 8-bits register. */
typedef struct
{
	volatile uint8* puc_Register;
	uint8 uc_AndMask;
	uint8 uc_OrMask;
} RegInit_Masked8BitsSingleType;

/** \brief  Defines a configuration of multiple  8-bits register. */
typedef struct
{
	const RegInit_Masked8BitsSingleType * kpt_Registers;
	uint16 us_NumberOfRegisters;	
	
}RegInit_Masked8BitsConfigType;

/** \brief  Defines a configuration for a single 16-bits register. */
typedef struct
{
	volatile uint16* pus_Register;
	uint16 us_AndMask;
	uint16 us_OrMask;
} RegInit_Masked16BitsSingleType;

/** \brief  Defines a configuration of multiple  16-bits register. */
typedef struct
{
	const RegInit_Masked16BitsSingleType * kpt_Registers;
	uint16 us_NumberOfRegisters;	
	
}RegInit_Masked16BitsConfigType;
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Variables                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Constants                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Export Of Global Functions                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
extern void RegInit_gv_Unmasked8Bits(const RegInit_Unmasked8BitsConfigType* pt_Unmasked8BitsConfig);
extern void RegInit_gv_Unmasked16Bits(const RegInit_Unmasked16BitsConfigType* pt_Unmasked16BitsConfig);
extern void RegInit_gv_Masked8Bits(const RegInit_Masked8BitsConfigType* pt_Unmasked8BitsConfig);
extern void RegInit_gv_Masked16Bits(const RegInit_Masked16BitsConfigType* pt_Unmasked16BitsConfig);
/*-------------------------------------------------------------------------------------------------------------------*/
#endif /* REGISTERINIT_H*/