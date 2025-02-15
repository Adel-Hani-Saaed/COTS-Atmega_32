/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: TWI			  *******************/
/*************** Date: 8/5/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartConditionError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,
	SlaveWriteByteError,
	SlaveReadByteError,

}TWI_ErrStatus;


/*Pass 0 in the Copy_u8MasterAddress argument if Master will NOT be Addressed*/
void TWI_voidMasterInit(u8 Copy_u8MasterAddress);		//Pass 0 if master not addressed

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStartCondition(void);

TWI_ErrStatus TWI_SendSlaveAddressWith_Write(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWith_Read(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

TWI_ErrStatus TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_SlaveReadDataByte(u8 *Copy_pu8DataByte);

void TWI_voidSendStopCondition(void);


#endif /* TWI_INTERFACE_H_ */
