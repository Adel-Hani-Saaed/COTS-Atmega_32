/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: HAL			  *******************/
/*************** SWC: DAC			  *******************/
/*************** Date: 10/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef DAC_INTERFACE_H_
#define DAC_INTERFACE_H_



#define  DAC_OUTPUTVOLT0	0
#define  DAC_OUTPUTVOLT1	1
#define  DAC_OUTPUTVOLT2	2
#define  DAC_OUTPUTVOLT3	3
#define  DAC_OUTPUTVOLT4	4
#define  DAC_OUTPUTVOLT5	5



void DAC_voidInit(u8 Copy_u8Port);


/* Description : This Function to output the analog value using DAC circuit R2R
 * \input :  Copy_u8Port    		 	, Range : DIO_PORTA ~ DIO_PORTDR
 *           Copy_u8ValueVoltage    	, Range : DAC_OUTPUTVOLT0   ~ DAC_OUTPUTVOLT5
 * Return  : nothing
 */
void DAC_voidAnalogValue(u8 Copy_u8ValueVoltage , u8 Copy_u8Port);

#endif /* DAC_INTERFACE_H_ */
