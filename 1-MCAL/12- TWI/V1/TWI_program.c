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

	TWBR_REG=(u8) ( (( F_CPU / SCL_Clock) - 16) / (2 * TWI_PRESCALLER) );

	/* Set the prescaler */
	/*2- Clear the prescaler bits (TWPS)*/
#if   TWI_PRESCALLER == PRESCALLER_BY_1

	TWSR_REG = 0;

#elif TWI_PRESCALLER == PRESCALLER_BY_4

	TWSR_REG=1;

#elif TWI_PRESCALLER == PRESCALLER_BY_16

	TWSR_REG=2;

#elif TWI_PRESCALLER == PRESCALLER_BY_64

	TWSR_REG=3;

#else
#error "Wrong TWI_TWI_PRESCALLER Config"
#endif

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



TWI_ErrStatus TWI_SendStartCondition(void)
{
	/*variable to the return status Error */
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Send start Condition on the bus*/
	SET_BIT(TWCR_REG,TWCR_TWSTA);

	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
		the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
		must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);

	/*Check the Status of code is correct or no if no return Error that mean the data not drop in bus */
	/*used Bit masking because we interested the Bits MSB 5*/
	if ((TWSR_REG & 0xF8) != START_ACK)
	{
		Local_ErrStatus = StartConditionError;
	}
	else
	{
		/*DO nothing :)*/
	}

	/*must be in the next step in frame(Send slave address) to clear the bit Start Condintion in Register TWCR Bit TWSTA*/

	return Local_ErrStatus;

}
TWI_ErrStatus TWI_SendRepeatedStartCondition(void)
{
	/*variable to the return status Error */
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Send start Condition on the bus*/
	SET_BIT(TWCR_REG,TWCR_TWSTA);

	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
		the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
		must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);

	/*Check the Status of code is correct or no if no return Error that mean the data not drop in bus */
	/*used Bit masking because we interested the Bits MSB 5*/
	if ((TWSR_REG & 0xF8) != REP_START_ACK)
	{
		Local_ErrStatus = RepeatedStartConditionError;
	}
	else
	{
		/*DO nothing :)*/
	}

	/*must be in the next step in frame(Send slave address) to clear the bit start in Register TWCR Bit TWSTA*/
	return Local_ErrStatus;
}


/*In register TWDR if u need Write or Read in register must be clear the first bit for Write or Set the first bit to Read */
TWI_ErrStatus TWI_SendSlaveAddressWith_Write(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

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

	/*Check the Status of code is correct or no if no return Error that mean the data not drop in bus */
	/*used Bit masking because we interested the Bits MSB 5*/
	if ((TWSR_REG & 0xF8) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrStatus = SlaveAddressWithWriteError;
	}
	else
	{
		/*DO nothing :)*/
	}

	return Local_ErrStatus;

}
TWI_ErrStatus TWI_SendSlaveAddressWith_Read(u8 Copy_u8SlaveAddress)
{

	TWI_ErrStatus Local_ErrStatus = NoError;

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

	/*Check the Status of code is correct or no if no return Error that mean the data not drop in bus */
	/*used Bit masking because we interested the Bits MSB 5*/
	if ((TWSR_REG & 0xf8) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrStatus = SlaveAddressWithReadError;
	}
	else
	{
		/*DO nothing :)*/
	}

	return Local_ErrStatus;

}


/*Master Transimmter*/
TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_ErrStatus = NoError;

	/*Write the data byte*/
	TWDR_REG = Copy_u8DataByte;

	/*clear the interrupt flag (TWINT)to start the previous operation  */
	/*DataSheet Page 175:::Also note that clearing this flag starts the operation of the TWI, so all accesses to
		the TWI Address Register (TWAR), TWI Status Register (TWSR), and TWI Data Register(TWDR)
		must be complete before clearing this flag.*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait for the interrupt flag is raised again and  the previous operation is complete */
	while ((GET_BIT(TWCR_REG,TWCR_TWINT)) == 0);

	/*Check the Status of code is correct or no if no return Error that mean the data not drop in bus */
	/*used Bit masking because we interested the Bits MSB 5*/
	if ((TWSR_REG & 0xf8) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrStatus = MasterWriteByteError;
	}
	else
	{
		/*DO nothing :)*/
	}

	return Local_ErrStatus;

}

/*Master Reciver*/
TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Local_Error= NoError;

	/*Clear the interrupt flag to allow the slave send the data*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR_REG,TWCR_TWINT))==0);

	/*Check the operation status*/
	if((TWSR_REG & 0xF8) !=  MSTR_RD_BYTE_WITH_ACK)
	{
		Local_Error = MasterReadByteError;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte = TWDR_REG;
	}

	return Local_Error;
}


TWI_ErrStatus TWI_SlaveWriteDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Local_Error= NoError;

	/*Write the data byte on the bus*/
	TWDR_REG = Copy_u8DataByte;

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR_REG,TWCR_TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR_REG,TWCR_TWINT))==0);

	/*Check the operation status*/
	if((TWSR_REG & 0xF8) !=  SLAVE_BYTE_TRANSMITTED)
	{
		Local_Error = SlaveWriteByteError;
	}
	else
	{
		/*Do nothing*/
	}

	return Local_Error;
}

TWI_ErrStatus TWI_SlaveReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Local_Error= NoError;

	/*Check the operation status*/
	if((TWSR_REG & 0xF8) !=  SLAVE_ADD_RCVD_WR_REQ)
	{
		Local_Error = SlaveReadByteError;
	}

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR_REG,TWCR_TWINT);
	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(TWCR_REG,TWCR_TWINT))==0);



	/*Check the operation status*/
	if((TWSR_REG & 0xF8) !=  SLAVE_DATA_RECEIVED)
	{
		Local_Error = SlaveReadByteError;
	}
	else
	{
		/*Read the received data*/
		*Copy_pu8DataByte = TWDR_REG;
	}

	return Local_Error;
}



void TWI_voidSendStopCondition(void)
{
	/*Generate stop condition on the bus set bit stop condition */
	SET_BIT(TWCR_REG,TWCR_TWSTO);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(TWCR_REG,TWCR_TWINT);
}

