/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: DAC			  *******************/
/*************** Date: 10/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"


void DAC_voidInit(u8 Copy_u8Port)
{
	/*Direction the Port must Be is Output*/
	DIO_enumSetPortDirection(Copy_u8Port, DIO_PORT_OUTPUT);

}




void DAC_voidAnalogValue(u8 Copy_u8ValueVoltage , u8 Copy_u8Port)
{

	/*Convert the value form 0 to 5  to the  0 to 255 digital value*/
	DIO_enumSetPortValue(Copy_u8Port, (Copy_u8ValueVoltage*51));
}
