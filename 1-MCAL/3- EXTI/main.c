/*
 * main.c
 *
 *  Created on: Feb 27, 2023
 *      Author: A-plus store
 */

#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"

void Function_Interrupt(void);

void main(void)
{
	/*LEd is output*/
	DIO_enumSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
	/*Pull_up Pin to the interrupt not nassesary the Pul up to Actived the interrupt */
	DIO_enumSetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
	DIO_enumSetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);

	/*Enable PIE and GIE interrupt Falling edge */
	EXTI_voidINT2Init();
	EXTI_voidINT1Init();
	GIE_voidEnable();

	/*Pass the pointer pointed the function (&Name_Func (Masra_c)) OR ( Name_Funct only  )*/
	EXTI_u8ExtISetCallBackINT2(&Function_Interrupt);

	EXTI_u8ExtISetCallBackINT1(&Function_Interrupt);

	while(1)
	{

	}
}

void Function_Interrupt(void)
{
	DIO_enumTogglePinValue(DIO_PORTA,DIO_PIN3);
}





///*without driver */
///*
//void main (void)
//{
//	/*Led Ouput*/
//	DDRA=0xff;
//	/*pull up Pin 2 is INT0 interrupt*/
//	PORTD=1<<2;
//	/*Falling Edge*/
//	MCUCR=0x02;
//	/*Enable interrupt 0*/
//	GICR=(1<<INT0);
//	/*Global interrupt enable*/
//	SREG=(1<<SREG_I);
//
//
//	while(1);
//}
//
////Equal ISR
//void __vector_1 (void) __attribute__((signal));
//void __vector_1 (void)
//{
//	PORTA ^=s(1<<3);
//
//}
//
//ISR(INT0_vect)
//{
//
//	PORTA ^=(1<<3);
//
//}
