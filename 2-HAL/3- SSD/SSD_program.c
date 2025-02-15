/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: SSD			  *******************/
/*************** Date: 28/1/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"


static u8 SegArr[]={0b10111111,   /* 0 */
		0b10000110,   /* 1 */
		0b11011011,   /* 2 */
		0b11001111,   /* 3 */
		0b11100110,   /* 4 */
		0b11101101,   /* 5 */
		0b11111101,   /* 6 */
		0b10000111,   /* 7 */
		0b11111111,   /* 8 */
		0b11101111,   /* 9 */
		0b11110111,   /* A */P
		0b11111100,   /* B */
		0b10111001,   /* C */
		0b11011110,   /* D */
		0b11111001,   /* E */
		0b11110001,   /* F */
};


void SSD_voidInit(SSD_T *SSD_structConfig )
{

		DIO_enumSetPortDirection(SSD_structConfig->Port,SSD_PORT_OUTPUT);

}

void SSD_voidSetNumber (SSD_T *SSD_structConfig , u8 Copy_u8Number)
{
	if(SSD_structConfig->Conn_T == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPortValue(SSD_structConfig->Port,SegArr[Copy_u8Number]);
	}
	else if(SSD_structConfig->Conn_T == SSD_COMMON_ANODE)
	{
		DIO_enumSetPortValue(SSD_structConfig->Port,~(SegArr[Copy_u8Number]));
	}
}

void SSD_voidEnableSSD ( SSD_T *SSD_structConfig )
{
	if(SSD_structConfig->Conn_T == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPinDirection(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_OUTPUT);
		DIO_enumSetPinValue(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_LOW);
	}
	else if(SSD_structConfig->Conn_T == SSD_COMMON_ANODE)
	{
		DIO_enumSetPinDirection(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_OUTPUT);
		DIO_enumSetPinValue(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_HIGH);
	}
}
void SSD_voidDisableSSD ( SSD_T *SSD_structConfig )
{
	if(SSD_structConfig->Conn_T == SSD_COMMON_CATHODE)
	{
		DIO_enumSetPinDirection(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_OUTPUT);
		DIO_enumSetPinValue(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_HIGH);
	}
	else if(SSD_structConfig->Conn_T == SSD_COMMON_ANODE)
	{
		DIO_enumSetPinDirection(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_OUTPUT);
		DIO_enumSetPinValue(SSD_structConfig->Enable_Port,SSD_structConfig->Enable_Pin,SSD_PIN_LOW);
	}

}



