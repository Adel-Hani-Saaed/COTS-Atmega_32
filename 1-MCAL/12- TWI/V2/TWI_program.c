/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: TWI			  *******************/
/*************** Date: 8/5/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/



#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "TWI_private.h"
#include "TWI_config.h"
#include "TWI_register.h"
#include "TWI_interface.h"


/*Pass 0 in the Copy_u8MasterAddress argument if Master will NOT be Addressed*/
void TWI_voidMasterInit(u8 Copy_u8MasterAddress)			//Pass 0 if master not addressed
{
	/*Set SCL frequency ,to 400kHz with 8Mhz system frequency*/
	/*1- Set TWBR to 2 => [0:255] */

	TWBR_REG = 2 ;

	/* Set the prescaler */
	/*2- Clear the prescaler bits (TWPS)*/
	CLR_BIT(TWSR_REG,TWSR_TWPS0);
	CLR_BIT(TWSR_REG,TWSR_TWPS1);


	/*Check if the master node will be addressed & set the Master Address */
	if(Copy_u8MasterAddress != 0)
	{
		/*Set the required address in the 7 MSB of TWAR*/
		TWAR_REG = Copy_u8MasterAddress<<1;
	}
	else
	{
		/*Do nothing*/
	}

	/*Enable Acknowledge bit*/
	SET_BIT(TWCR_REG , TWCR_TWEA);

	/*Enable TWI_Master Peripheral*/
	SET_BIT(TWCR_REG,TWCR_TWEN);

}
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{

	/*Enable Acknowledge bit*/
	SET_BIT(TWCR_REG,TWCR_TWEA);

	/*Initialize the slave address*/
	TWAR_REG = Copy_u8SlaveAddress<<1;

	/*Enable TWI_Slave*/
	SET_BIT(TWCR_REG,TWCR_TWEN);
}


void TWI_voidSendStartCondition(void)
{
	/*Send start Condition on the bus*/
	SET_BIT(TWCR_REG,TWCR_TWSTA);

	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
		the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
		must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);


}
void TWI_voidSendRepeatedStartCondition(void)
{
	/*Send start Condition on the bus*/
	SET_BIT(TWCR_REG,TWCR_TWSTA);

	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
		the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
		must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);

}


/*In register TWDR if u need Write or Read in register must be clear the first bit for Write or Set the first bit to Read */
void TWI_voidSendSlaveAddressWith_Write(u8 Copy_u8SlaveAddress)
{

	/*Set the slave address in the 7 MSB in the data register*/
	TWDR_REG = (Copy_u8SlaveAddress<<1);

	/*For (Write) must the first bit in register is 0 the request*/
	CLR_BIT(TWDR_REG,0);

	/*clear the start condition bit */
	CLR_BIT(TWCR_REG,TWCR_TWSTA);


	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
		the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
		must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);
}

void TWI_voidSendSlaveAddressWith_Read(u8 Copy_u8SlaveAddress)
{


	/*Set the slave address in the 7 MSB in the data register*/
	TWDR_REG = (Copy_u8SlaveAddress<<1);

	/*For (READ) must the first bit in register is 0 the request*/
	SET_BIT(TWDR_REG,0);

	/*clear the start condition bit */
	CLR_BIT(TWCR_REG,TWCR_TWSTA);

	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
	 the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
	 must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);
}


/*Master Transimmter*/
void TWI_voidMasterWriteDataByte(u8 Copy_u8DataByte)
{

	/*Write the data byte*/
	TWDR_REG = Copy_u8DataByte;

	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
		the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
		must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);
}

/*Master Reciver*/
u8 TWI_u8MasterReadDataByte(void)
{

	/*Clear the interrupt flag to allow the slave send the data*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR_REG,TWCR_TWINT))==0);

	/*Return Data*/
	return TWDR_REG;
}


void TWI_SlaveWriteDataByte(u8 Copy_u8DataByte)
{

	/*Write the data byte on the bus*/
	TWDR_REG = Copy_u8DataByte;

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR_REG,TWCR_TWINT))==0);

}

u8 TWI_u8SlaveReadDataByte(void)
{


	/*Check the operation status*/
	while((TWSR_REG & 0xF8) !=  SLAVE_ADD_RCVD_WR_REQ);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*Check the operation status*/
	while((TWSR_REG & 0xF8) !=  SLAVE_DATA_RECEIVED);

	return TWDR_REG;
}



void TWI_voidSendStopCondition(void)
{
	/*Generate stop condition on the bus set bit stop condition */
	SET_BIT(TWCR_REG,TWCR_TWSTO);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR_REG,TWCR_TWINT);
}

