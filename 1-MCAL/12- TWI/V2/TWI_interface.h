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



/*Pass 0 in the Copy_u8MasterAddress argument if Master will NOT be Addressed*/
void TWI_voidMasterInit(u8 Copy_u8MasterAddress);		//Pass 0 if master not addressed

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);

void TWI_voidSendStartCondition(void);

void TWI_voidSendRepeatedStartCondition(void);

void TWI_voidSendSlaveAddressWith_Write(u8 Copy_u8SlaveAddress);

void TWI_voidSendSlaveAddressWith_Read(u8 Copy_u8SlaveAddress);

void TWI_voidMasterWriteDataByte(u8 Copy_u8DataByte);

u8 TWI_u8MasterReadDataByte(void);

void TWI_voidSendStopCondition(void);




void TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);
u8 TWI_u8SlaveReadDataByte(void);


#endif /* TWI_INTERFACE_H_ */
