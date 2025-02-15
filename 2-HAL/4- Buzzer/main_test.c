/*
 * main_test.c
 *
 *  Created on: Feb 11, 2023
 *      Author: A-plus store
 */


#include "BIT_Math.h"
#include "STD_TYPES.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "Buzzer_interface.h"


void main()
{	//object the buzzer to selection port ,pin ,type connection
	BUZZER_T Buzz_1 ={BUZZ_PORTC,BUZZ_PIN7,BUZZ_SOURCE};

	//initialization the function Buzzer
	BUZZ_voidInit(&Buzz_1);

	while (1)
	{

		//toggle the buzzer every 1 second
		BUZZ_voidToggle(&Buzz_1);
		_delay_ms(1000);

	}
}
