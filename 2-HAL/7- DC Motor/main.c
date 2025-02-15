/*
 * main.c
 *
 *  Created on: Feb 18, 2023
 *      Author: A-plus store
 */

#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include <avr/delay.h>

#include "SW_interface.h"
#include "DC_Motor_interface.h"

void main(void)
{
	SW_Type SW_1 ={SW_PORTC,SW_PIN5,SW_INTERNAL_PULL_UP};
	SW_Type SW_2 ={SW_PORTC,SW_PIN4,SW_INTERNAL_PULL_UP};

	DCMOTOR_CONFIG DC_Motor = {DCMOTOR_PORTC , DCMOTOR_PIN7 , DCMOTOR_PIN6};

	SW_voidPinInit(&SW_1);
	SW_voidPinInit(&SW_2);

	DCMOTOR_voidInit(&DC_Motor);
	while(1)
	{

		u8 Local_u8Stat_1 = SW_u8GetPressed(&SW_1);
		u8 Local_u8Stat_2 = SW_u8GetPressed(&SW_2);

		if (Local_u8Stat_1 == SW_PRESSED)
		{
			DCMOTOR_uint8ControlDirection(&DC_Motor,DCMOTOR_CW);
		}

		if (Local_u8Stat_2 == SW_PRESSED)
		{
			DCMOTOR_uint8ControlDirection(&DC_Motor,DCMOTOR_CCW);
		}

		if (Local_u8Stat_1 == SW_NOT_PRESSED && Local_u8Stat_2 ==SW_NOT_PRESSED)
		{
			DCMOTOR_uint8ControlDirection(&DC_Motor,DCMOTOR_STOP);
		}
	}

}

