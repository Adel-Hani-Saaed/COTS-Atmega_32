/*
 * main.c
 *
 *  Created on: Feb 12, 2023
 *      Author: A-plus store
 */


#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include "avr/delay.h"

#include "CLCD_interface.h"


u8 Pattern[8]=
		{
		0b00001111,
		0b00001000,
		0b00001000,
		0b00001000,
		0b00011111,
		0b00000000,
		0b00000000,
		0b00000000,
		};

void main(void)
{
	//u8 shift , i ;

	CLCD_voidInit();

	/*Print Special */
	//CLCD_voidSpecialCharacter(Pattern,0,1,0);


	/*print interger number */
	CLCD_voidPrintINTNumber(410);

	/*Try the function X,Y*/
//	CLCD_voidGoToXY(1,15);
//	CLCD_voidSendString("Gamal ahmed :)");

	/*Try the function*/
//	CLCD_voidSendStringIndex_16("ADEL HANI");
//	CLCD_voidSendCommand(CLCD_JUMPSECONDLINE_P0);
//	CLCD_voidSendStringIndex_16("ADEL HANI");

	while (1)
	{
			/*Rolling Right and Left */
//		  shift = 15;	/* Number of time shifts count=15 */
//				while(1)
//				{
//					for( i=0;i<shift;i++)
//					{
//						CLCD_voidSendCommand(0x1c);/* shift entire display right */
//						_delay_ms(300);
//					}
//					shift=30;/* number of time shifts 30 */
//
//					for(i=0;i<30;i++)
//					{
//						CLCD_voidSendCommand(0x18);/* shift entire display left */
//						_delay_ms(300);
//					}
//				}

	}
}
