/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: TWI			  *******************/
/*************** Date: 8/5/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

/*************************************************/
/****************** Prescalers *******************/
/*************************************************/
#define PRESCALLER_BY_1    1
#define PRESCALLER_BY_4    4
#define PRESCALLER_BY_16   16
#define PRESCALLER_BY_64   64


/***************************************************************************/
/******************* Private Macros for Status Codes ***********************/
/***************************************************************************/


/******************* Status_Codes_for_Master_Transmitter_Mode **************/
#define START_ACK				0x08   	/* Start has been sent */
#define	REP_START_ACK 			0x10	/* Repeated start */
#define SLAVE_ADD_AND_WR_ACK	0x18	/* Master transmit  (slave address + Write request) ACK */
#define MSTR_WR_BYTE_ACK		0x28	/* Master transmit data ACK */


/******************* Status_Codes_for_Master_Receiver_Mode *****************/
#define SLAVE_ADD_AND_RD_ACK	0x40	/* Master transmit  (slave address + Read request) ACK */
#define MSTR_RD_BYTE_WITH_ACK	0x50	/* Master received data with ACK */
#define MSTR_RD_BYTE_WITH_NACK	0x58	/* Master received data with Not ACK */


/******************* Status Codes for Slave Receiver Mode ******************/
#define SLAVE_ADD_RCVD_WR_REQ	0x60	/* means that slave address is received with WRITE request */
#define SLAVE_DATA_RECEIVED		0x80 	/* means that a byte is received */


/******************* Status_Codes_for_Slave_Transmitter_Mode ***************/
#define SLAVE_ADD_RCVD_RD_REQ	0xA8	/* means that slave address is received with read request */
#define SLAVE_BYTE_TRANSMITTED	0xB8	/* means that the written byte is transmitted */



#endif /* TWI_PRIVATE_H_ */
