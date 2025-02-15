/*
 * Test_SSD_Driver.c
 *
 *  Created on: Feb 2, 2023
 *      Author: Adel_Hani
 */

#define  F_CPU 8000000UL
#include <avr/delay.h>

#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "SSD_interface.h"
#include "SW_interface.h"
#include "DIO_interface.h"


void main(void)
{
	/*Display in 7Segment in First*/
	u8 Counter=50;

	/*objects for Structure Two 7Segment Multiplexer */
	SSD_T SSD_1={SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTC,SSD_PIN0};
	SSD_T SSD_2={SSD_COMMON_CATHODE,SSD_PORTD,SSD_PORTC,SSD_PIN1};

	/*objects for Structure Two Switches */
	SW_Type SW_1={SW_PORTA,SW_PIN0,SW_INTERNAL_PULL_UP};
	SW_Type SW_2={SW_PORTA,SW_PIN2,SW_INTERNAL_PULL_UP};

//	/*Two Switches Count down and up */
//	DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
//	DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_INPUT);
//
//	/*Active internal PullUp resistance*/
//	DIO_enumSetPinValue(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
//	DIO_enumSetPinValue(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);

	/*initialized the 7Segment Function*/
	SSD_voidInit(&SSD_1);

	/*initialized the Switches Function*/
	SW_voidPinInit(&SW_1);
	SW_voidPinInit(&SW_2);

	while(1)
	{
		u8 Local_u8InputNaluePin0=SW_u8GetPressed(&SW_1);
		u8 Local_u8InputNaluePin2=SW_u8GetPressed(&SW_2);

		/*display number 5 in 7segment 2*/
		SSD_voidSetNumber(&SSD_1,(Counter/10));
		SSD_voidEnableSSD(&SSD_2);
		SSD_voidDisableSSD(&SSD_1);
		_delay_ms(10);

		/*display number 0 in 7segment 1*/
		SSD_voidSetNumber(&SSD_1,(Counter%10));
		SSD_voidEnableSSD(&SSD_1);
		SSD_voidDisableSSD(&SSD_2);
		_delay_ms(10);

//		/*Get the value switches*/
//		DIO_enumGetPinValue(DIO_PORTA,DIO_PIN0,&Local_u8InputNaluePin0);
//		DIO_enumGetPinValue(DIO_PORTA,DIO_PIN1,&Local_u8InputNaluePin1);

		if (Local_u8InputNaluePin0 == 0)
		{
			Counter++;

		}

		if (Local_u8InputNaluePin2 == 0)
		{
			Counter--;

		}

	}
}
