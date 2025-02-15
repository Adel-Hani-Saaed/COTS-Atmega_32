/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer2		  *******************/
/*************** Date: 8/4/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_


#define TCCR2_REG 			*((volatile u8*)0X45)		/*Timer/Counter control register*/

#define TCCR2_FOC2			7							/*Force Output compare*/
#define TCCR2_WGM20			6							/*Wave for generation mode  BIT_1*/
#define	TCCR2_COM21			5 							/*Compare match output mode BIT_1*/
#define	TCCR2_COM20			4							/*Compare match output mode BIT_2*/
#define TCCR2_WGM21			3							/*Wave for generation mode  BIT_2*/
#define TCCR2_CS22			2							/*Clock Selection Bit_3*/
#define TCCR2_CS21			1							/*Clock Selection Bit_2*/
#define TCCR2_CS20			0							/*Clock Selection Bit_1*/


#define TCNT2_REG			*((volatile u8*)0X44)		/*Timer/Counter 2 register (overflow) */

#define OCR2_REG			*((volatile u8*)0X43)		/*Output compare 2 match Register*/

#define TIMSK_REG			*((volatile u8*)0x59)		/*Timer/Counter 2 interrupt mask register*/

#define TIMSK_OCIE2			7							/*Timer/Counter 2 CTC Mode interrupt Enable Bit*/
#define TIMSK_TOIE2			6							/*Timer/Counter 2 Overflow Mode interrupt Enable Bit*/




#endif /* TIMER2_REGISTER_H_ */
