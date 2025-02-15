/*
 * Ultrasonic_progeram.c
 *
 *  Created on: Apr 9, 2023
 *      Author: A-plus store
 */

#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CUP 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "GIE_interface.h"
#include "Timer1_interface.h"
#include "Ultrasonic_interface.h"


static volatile u16 Global_u16ReadingICU1 ,Global_u16ReadingICU2, Global_16Flags_ICU  ;

static void ICU_CallBackFunction();


void Ultrasonic_voidInit(u8 Copy_u8TriggerPort , u8 Copy_u8TriggerPin)
{
	/*Set Trigger Pin Direction output*/
	DIO_enumSetPinDirection(Copy_u8TriggerPort, Copy_u8TriggerPin, DIO_OUTPUT);
	/*Set echo Pin Direction input (ICP)*/
	DIO_enumSetPinDirection(DIO_PORTD, DIO_PIN6, DIO_INPUT);


	/* if need ultrasonic only in this timer  than -> config file Selected normal mode
	 * if need ultrasonic with anything(Servo) in this timer  than -> config file Selected FastPWM top OCR1A and Connect the servo in OCR1B as 0 to 180 angle
	 *  */
	TIMER1_voidInit();

	/*Set call back get reading the ICU for ultrasonic*/
	ICU_u8SetCallBackRegisterICU(&ICU_CallBackFunction);

}

u16 Ultrasonic_u16GetDistance(u8 Copy_u8TriggerPort , u8 Copy_u8TriggerPin)
{
	u16 Local_u8Distance = 0;
	u16 Local_u16TimerCal = 0;

	Global_16Flags_ICU = 0;

	/*Set Timer from Zero*/
	TIMER1_voidSetPreloadValue(0);

	/*Set the trigger High -> 10 microsecond -> Low*/
	DIO_enumSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, DIO_HIGH);
	_delay_us(10);
	DIO_enumSetPinValue(Copy_u8TriggerPort, Copy_u8TriggerPin, DIO_LOW);

	/*After the 8 Pulses the RX Ultrasonic generated the Pulse for Kown the Timer (Recived & Transsmit)  */
	ICU_u8SetTriggerEdge(ICU_RISING_EDGE);

	/*Set the interrupt ISR ICU*/
	ICU_voidEnableInterrupt();

	/*Waiting until the flag return 0 */
	while(Global_16Flags_ICU < 2);

	/*Timer Pulse for Kown the Timer (Recived & Transsmit) */
	Local_u16TimerCal = (Global_u16ReadingICU2 - Global_u16ReadingICU1) ;

	/*Disrance = Velocity * (Timer/2)  -> Velocity = 343000 Cm/S   */
	Local_u8Distance = (Local_u16TimerCal / 58);

	/*Disable the interrupt until not reading come again*/
	ICU_voidDisableInterrupt();

	return Local_u8Distance;

}



static void ICU_CallBackFunction()
{
	if(Global_16Flags_ICU == 0)
	{
		/*Get reading Rasing Edge*/
		Global_u16ReadingICU1 = ICU_u16GetReadingInputCaptureUnit();

		Global_16Flags_ICU = 1;

		/*Convert the Trigger*/
		ICU_u8SetTriggerEdge(ICU_FALLING_EDGE);
	}

	else if(Global_16Flags_ICU == 1)
	{
		/*Get the Timer Totally*/
		Global_u16ReadingICU2 = ICU_u16GetReadingInputCaptureUnit();

		Global_16Flags_ICU = 2;

		/*again retune the Trigger for new reading*/
		ICU_u8SetTriggerEdge(ICU_RISING_EDGE);

		ICU_voidDisableInterrupt();
	}
}



