/*
 * main.c
 *
 *  Created on: Feb 16, 2023
 *      Author: A-plus store
 */

#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include "avr/delay.h"

#include "CLCD_interface.h"
#include "Keypad_interface.h"


void main (void)
{
	u8 Local_u8Char;

	CLCD_voidInit();
	KPD_voidInit();

	while(1)
	{
		Local_u8Char=KPD_u8GetPressedKey();

		if (Local_u8Char == 0xff )
		{
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendString("wrong");
			CLCD_voidClearLCD();
		}

		else{
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendData(Local_u8Char);
		}
	}
}
