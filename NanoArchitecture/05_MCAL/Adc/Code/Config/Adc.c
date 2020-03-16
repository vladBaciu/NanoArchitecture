/*-------------------------------------------------------------------------------------------------------------------*/
/**
 *    \file       Adc.c
 *    \author     Baciu Vlad-Eusebiu
 *    \brief      Implements the ADC interfaces: SetupResultBuffer,StartGroupConversion,GetGroupStatus.
 */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                                     Inclusions                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/
#include "Adc.h"
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                             Definition Of Local Macros                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
#define ADC_CLEAR_CHANNEL_VALUE (0x00)
#define ADC_CHANNEL_MASK		(0x07)
#define ADC_ADMUX_MASK			(0xF8)
#define ADC_START_CONVERSION	(ADSC)
/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Definition Of Local Data Types                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------------*/
/*                                           Declaration Of Local Variables                                          */
/*-------------------------------------------------------------------------------------------------------------------*/

/** \brief  Array that holds the addresses of the data buffers */
static uint8* Adc_apul_AdressBuffer[ADC_NUMBER_OF_GROUPS];

/** \brief  Stores the address of the selected post-build configuration. */
static Adc_GroupCfgType *Adc_pt_GroupsConfig;

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
 * \brief   Init all the registers from the configuration array.
 * \param   ConfigPtr: pointer to the configuration array.
 * \return  -
 */
void Adc_Init(const Adc_ConfigType* ConfigPtr)
{
   RegInit_gv_Masked8Bits(ConfigPtr->pt_ConfigRegisters);

   Adc_pt_GroupsConfig = (Adc_GroupCfgType *) ConfigPtr->pt_ConfigGroup;

}

/**
 * \brief    Sets the start bit in CR2 register in order to start the channel conversion.
 * \param    Group: number of group from array group configuration.
 * \return   -
 */
void Adc_StartGroupConversion(Adc_GroupType Group)
{
	
	Adc_GroupType t_Channel = (Adc_GroupType) (Adc_pt_GroupsConfig[Group].t_Channel & ADC_CHANNEL_MASK);
	*Adc_pt_GroupsConfig[Group].pt_MuxRegister = (ADC_ADMUX_MASK & *Adc_pt_GroupsConfig[Group].pt_MuxRegister) | t_Channel;
	*Adc_pt_GroupsConfig[Group].pt_StartRegister |= (1<<ADC_START_CONVERSION);
	
}

/**
 * \brief   Shows the status of the ADC conversion.
 * \param   Group: number of group from array group configuration.
 * \return  Status of the conversion (BUSY,COMPLETED,IDLE).
 */
Adc_StatusType Adc_GetGroupStatus(Adc_GroupType Group)
{
  
   return 0;
}

/**
 * \brief   Stores the address of the buffer in the resultBuffer array.
 * \param   Group: number of group from array group configuration.
 *          DataBufferPtr: buffer address.
 * \return  Status of the operation (E_OK or E_NOT_OK).
 */
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group, const Adc_ValueGroupType* DataBufferPtr)
{
   /* Variable that holds the return value */
   Std_ReturnType t_ReturnValue;


   t_ReturnValue = E_OK;

   return t_ReturnValue;
}