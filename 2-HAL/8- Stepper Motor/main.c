/*
 * main.c
 *
 *  Created on: Feb 20, 2023
 *      Author: A-plus store
 */




#include "BIT_Math.h"
#include "STD_TYPES.h"
#define F_CPU 8000000UL
#include "util/delay.h"

#include "Stepper_interface.h"


void main(void)
{
	STEPPER_voidInit();

	while(1)
	{
		STEPPER_voidTurnOn(STEPPER_FULL_STEP,STEPPER_CLOCK_WISE,10,360);
		STEPPER_voidTurnOff();
		_delay_ms(2000);
		STEPPER_voidTurnOn(STEPPER_HALF_STEP,STEPPER_ANTI_CLOCK_WISE,2,360);
		STEPPER_voidTurnOff();
		_delay_ms(2000);

	}

}
