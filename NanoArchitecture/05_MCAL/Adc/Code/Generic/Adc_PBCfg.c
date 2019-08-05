/*-------------------------------------------------------------------------------------------------------------------*/
/**
*    \file       Adc_PBcfg.c
*    \author     Baciu Vlad-Eusebiu
*    \brief      Implements the configuration set for the ADC registers and the configuration structure of the
*                ADC module.
*/
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Adc.h"
#include "Adc_Cfg.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Definition Of Local Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief Number of registers to be configured */
#define ADC_NUMBER_OF_REGISTERS           (9U)

/** \brief Channel 10 index in ADC2 module */
#define ADC0_CH                      (0U)

/** \brief Channel 12 index in ADC1 module */
#define ADC1_CH                      (1U)

/** \brief Channel 6 index in ADC1 module */
#define ADC2_CH                       (2U)

/** \brief Channel 14 index in ADC1 module */
#define ADC3_CH                       (3U)

/** \brief Channel 14 index in ADC1 module */
#define ADC4_CH                       (4U)

/** \brief Channel 14 index in ADC1 module */
#define ADC5_CH                      (5U)

/** \brief Channel 14 index in ADC1 module */
#define ADC6_CH                       (6U)

/** \brief Channel 14 index in ADC1 module */
#define ADC7_CH                       (7U)

/** \brief Channel 14 index in ADC1 module */
#define ADC8_CH                       (8U)

/** \brief Channel 14 index in ADC1 module */
#define ADC14_CH                       (14U)

/** \brief Channel 14 index in ADC1 module */
#define ADC15_CH                       (15U)

#define ADC_RESERVED_CHANNEL		   (0xFFU)
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

/** \brief Group configuration array */
static const Adc_GroupCfgType Adc_kat_AdcGroups[ADC_NUMBER_OF_GROUPS] =
{

	/* ADC group 0 : ADC2_CH10 - PC0 pin */
	{ ADC0_CH },
		
	/* ADC group 2 : ADC2_CH12 - PC2 pin */
	{ ADC1_CH },
		
	/* ADC group 2 : ADC2_CH6  - PA6 pin */
	{ ADC2_CH},
		
	{ ADC3_CH },
		
	/* ADC group 2 : ADC2_CH12 - PC2 pin */
	{ ADC4_CH },
		
	/* ADC group 2 : ADC2_CH6  - PA6 pin */
	{ ADC5_CH},
		
	/* ADC group 2 : ADC2_CH12 - PC2 pin */
	{ ADC6_CH },
		
	/* ADC group 2 : ADC2_CH6  - PA6 pin */
	{ ADC7_CH},
		
	/* ADC group 2 : ADC2_CH6  - PA6 pin */
	{ ADC8_CH},
	
	{ ADC_RESERVED_CHANNEL},
		
	/* ADC group 2 : ADC2_CH12 - PC2 pin */
	{ ADC_RESERVED_CHANNEL },
		
	/* ADC group 2 : ADC2_CH6  - PA6 pin */
	{ ADC_RESERVED_CHANNEL},
		
	/* ADC group 2 : ADC2_CH6  - PA6 pin */
	{ ADC_RESERVED_CHANNEL},
		
	{ ADC14_CH},
		
	/* ADC group 2 : ADC2_CH6  - PA6 pin */
	{ ADC15_CH},
	

};

/** \brief Register configuration array */
static const RegInit_Masked8BitsSingleType Adc_kat_Registers[ADC_NUMBER_OF_REGISTERS] =
{
	{
		(volatile uint8*) &ADMUX,
		
		(uint8) ~(
		REFS0
		),

		(uint8) (REFS0),
	}
	

};

/** \brief ADC register configuration array */
static const RegInit_Masked8BitsConfigType Adc_kt_Config =
{
	Adc_kat_Registers,
	ADC_NUMBER_OF_REGISTERS,

};

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                          Declaration Of Global Constants                                          */
/*-------------------------------------------------------------------------------------------------------------------*/
/** \brief ADC configuration array */
const Adc_ConfigType Adc_gkt_Cfg =
{
	Adc_kat_AdcGroups,
	&Adc_kt_Config

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