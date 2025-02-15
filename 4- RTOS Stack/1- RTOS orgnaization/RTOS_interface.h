/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: RTOS Stack	  *******************/
/*************** SWC: RTOS 			  *******************/
/*************** Date: 28/7/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_


void RTOS_voidStart			(void);

u8 RTOS_voidCreatTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvFunctionTask)(void) , u16 Copy_FirstDelay);

void RTOS_voidSuspendTask	( u8 Copy_u8Priority );

void RTOS_voidResumeTask 	( u8 Copy_u8Priority );

void RTOS_voidDeletTask		(u8 Copy_u8Priority);


#endif /* RTOS_INTERFACE_H_ */
