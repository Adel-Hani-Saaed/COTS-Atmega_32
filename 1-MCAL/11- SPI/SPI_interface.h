/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layers: MCAL		  *******************/
/*************** SWC: SPI			  *******************/
/*************** Date: 27/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/* Description : this Function is to  Init the SPI
 * \input : nothing
 * Return  : nothing
 */
void SPI_voidInit(void);


/* Description : this Function is to Send and Received Char
 * \input :  Copy_u8TransmittedData    		 , Range :  'Char' or any Ascii Data
 *           *Copy_pu8RecivedData     		 , Range : 	Pointer stored data
 * Return  : ErrorStatus
 */
u8 SPI_u8TranceiveChar (u8 Copy_u8TransmittedData , u8 *Copy_pu8RecivedData);

/* Description : this Function is to Send and Received String Synchronous Function
 * \input :  *Copy_u8TData    				 , Range :  String (Array of Char)
 *           *Copy_u8RData     		 		 , Range :  Array to Stored the Data Received
 *           Copy_u8BufferSize				 , Range :  Number of Size String
 * Return  : ErrorStatus
 */
u8 SPI_u8BufferTranceiverSynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize) ;


/* Description : this Function is to Send and Received String ASynchronous Function
 * \input :  *Copy_u8TData    				 , Range :  String (Array of Char)
 *           *Copy_u8RData     		 		 , Range :  Array to Stored the Data Received
 *           Copy_u8BufferSize				 , Range :  Number of Size String
 *           void(*NotificationFuncn)(void)  , Range :  Function to pointer to Notification the Send or Recived is Finished
 * Return  : ErrorStatus
 */
u8 SPI_u8BufferTranceiverAsynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize , void(*Copy_PvNotificationFunction)(void));

#endif /* SPI_INTERFACE_H_ */
