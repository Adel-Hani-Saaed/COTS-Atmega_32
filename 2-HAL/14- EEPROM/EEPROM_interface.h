/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: EEPROM		  *******************/
/*************** Date: 21/5/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


void EEPROM_voidInit(void);

void EEPROM_voidWriteDataByte(u8 Copy_u8DataSend , u16 Copy_u16ByteAddress);

//void EEPROM_voidWriteBlockByte(u8 *Copy_pu8DataSend ,u16 Copy_u16SizeString ,u16 Copy_u16ByteAddress);


u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress);

//u8 EEPROM_u8ReadBlockByte(u8 *Copy_u8BufferData ,u16 Copy_u16SizeBuffer ,u16 Copy_u16ByteAddress);


#endif /* EEPROM_INTERFACE_H_ */
