/*
 * LDR_interfac.h
 *
 *  Created on: Mar 13, 2023
 *      Author: A-plus store
 */

#ifndef LDR_INTERFAC_H_
#define LDR_INTERFAC_H_


#define LDR_RESOLUTION_10		10
#define LDR_RESOLUTION_8		8


void LDR_voidInit(void);


/* Description : This Function is Get the Temperature value
 * \input :  Copy_Channel    		 	, Range : CHANNEL_A0 ~ CHANNEL_A7
 *           Copy_u8ADCResolution     	, Range : LDR_RESOLUTION_8 OR LDR_RESOLUTION_10
 *
 * Return  : Temperature value
 */
u16 LDR_u16GetValue(u8 Copy_u8Channel ,u8 Copy_u8ADCResolution );




#endif /* LDR_INTERFAC_H_ */
