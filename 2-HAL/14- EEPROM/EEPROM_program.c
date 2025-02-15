/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: EEPROM		  *******************/
/*************** Date: 21/5/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#include "BIT_Math.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#include "TWI_interface.h"

#include "EEPROM_private.h"
#include "EEPROM_config.h"
#include "EEPROM_interface.h"

void EEPROM_voidInit(void)
{
	TWI_voidMasterInit(0);
}


void EEPROM_voidWriteDataByte(u8 Copy_u8DataSend , u16 Copy_u16ByteAddress)
{
	/*Start condition TWI*/
	TWI_voidSendStartCondition();

	/*Send the address with Write and Block of Memory*/
	TWI_voidSendSlaveAddressWith_Write((EEPROM_FIXED_FOUR_BIT_ADDRESS | (EEPROM_A2_PIN_VALUE <<2 ) | ( Copy_u16ByteAddress >> 8 )));

	/*Send the address of Block*/
	TWI_voidMasterWriteDataByte( (u8)Copy_u16ByteAddress);

	/*Send the data to slave*/
	TWI_SlaveWriteDataByte(Copy_u8DataSend);

	/*Stop condition TWI communcatoin*/
	TWI_voidSendStopCondition();

	/*Time to one cycle Write in EEPROM*/
	_delay_ms(10);
}

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress)
{
	u8 Lcoal_u8DataReturn;

	/*Start condition TWI*/
	TWI_voidSendStartCondition();

	/*Send the address with Write and Block of Memory*/
	TWI_voidSendSlaveAddressWith_Write((EEPROM_FIXED_FOUR_BIT_ADDRESS | (EEPROM_A2_PIN_VALUE <<2 ) | ( Copy_u16ByteAddress >> 8 )));

	/*Send the address of Block*/
	TWI_voidMasterWriteDataByte( (u8)Copy_u16ByteAddress);

	/*Send Repeated Start*/
	TWI_voidSendRepeatedStartCondition();

	/*Send the address with Read and Block of Memory*/
	TWI_voidSendSlaveAddressWith_Read((EEPROM_FIXED_FOUR_BIT_ADDRESS | (EEPROM_A2_PIN_VALUE <<2 ) | ( Copy_u16ByteAddress >> 8 )));


	/*Send the data to slave*/
	Lcoal_u8DataReturn = TWI_u8MasterReadDataByte();

	/*Stop condition TWI communcatoin*/
	TWI_voidSendStopCondition();

	/*Retuen Data Recived*/
	return Lcoal_u8DataReturn;
}

//
//
//
//void EEPROM_voidWriteBlockByte(u8 *Copy_pu8DataSend ,u16 Copy_u16SizeString ,u16 Copy_u16ByteAddress)
//{
//
//}
//
//
//
//
//u8 EEPROM_u8ReadBlockByte(u8 *Copy_u8BufferData ,u16 Copy_u16SizeBuffer ,u16 Copy_u16ByteAddress)
//{
//
//}

