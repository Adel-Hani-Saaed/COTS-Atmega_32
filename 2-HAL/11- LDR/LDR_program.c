/*
 * LDR_program.c
 *
 *  Created on: Mar 13, 2023
 *      Author: A-plus store
 */

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "ADC_interface.h"
#include "LDR_interfac.h"


void LDR_voidInit(void)
{
	ADC_voidInit();
}


/*The selection the Resolution please check the ADC_configration*/
u16 LDR_u16GetValue(u8 Copy_u8Channel ,u8 Copy_u8ADCResolution )
{
	u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue ;

	ADC_u16StartConversionSynch(Copy_u8Channel, &Local_u16ADCResult);

	if ( Copy_u8ADCResolution == LDR_RESOLUTION_10 )
	{
		Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * 5000UL )/1024UL);
	}

	else if (Copy_u8ADCResolution == LDR_RESOLUTION_8)
	{
		Local_u16AnalogValue = (u16)(((u32)Local_u16ADCResult * 5000UL )/256UL);
	}

	/* Convert ( V --> mV ) */
	return Local_u16AnalogValue ;


}

