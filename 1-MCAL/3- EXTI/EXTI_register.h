/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: EXTI			  *******************/
/*************** Date: 27/2/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/****************************** Private Macros For EXTI Registers****************************/

#define GICR_REG 			*((volatile u8*)0x5B) 		 /*General interrupt control register(PIE)*/
#define GICR_INT1		    7							 /*INT1 PIE*/
#define GICR_INT0 			6 						 	 /*INT0 PIE*/
#define GICR_INT2 			5 						 	 /*INT2 PIE*/




#define GIFR_REG 			*((volatile u8*)0x5A)		 /*General interrupt Flag(auto_clearing) register*/


/**********************************************************************************************/
/********* The MCU Control Register contains control bits for interrupt sense control *********/
/**************************** and general MCU functions. **************************************/
/**********************************************************************************************/
#define MCUCR_REG 		    *((volatile u8*)0x55) 		/* MCU control register*/

/***********************************************************************************************/
/************** These Two Bits defines the condition will generate interrupt request ***********/
/****************************** The INT0 is BIT_control number 1 and 0 *************************/
/*********************************** 0 0 ---> For Low Level ************************************/
/*********************************** 0 1 ---> For Any Logical(ON Change) ***********************/
/*********************************** 1 0 ---> For Falling Edge *********************************/
/*********************************** 1 1 ---> For Rising Edge **********************************/
/***********************************************************************************************/
#define MCUCR_ISC00 		0 					    	/*Int0 sense control bit 0*/
#define MCUCR_ISC01			1 						    /*Int0 sense control bit 1*/

/***********************************************************************************************/
/************** These Two Bits defines the condition will generate interrupt request ***********/
/****************************** The INT1 is BIT_control number 2 and 3 *************************/
/*********************************** 0 0 ---> For Low Level ************************************/
/*********************************** 0 1 ---> For Any Logical(ON Change) ***********************/
/*********************************** 1 0 ---> For Falling Edge *********************************/
/*********************************** 1 1 ---> For Rising Edge **********************************/
/***********************************************************************************************/
#define MCUCR_ISC11			3 							/*Int1 sense control bit 1*/
#define MCUCR_ISC10 		2 							/*Int1 sense control bit 0*/



#define MCUCSR_REG 			*((volatile u8*)0x54)	    /*MCU control and status register for INT2 */
/**********************************************************************************************/
/************** This Bit defines the condition will generate interrupt request ****************/
/***************************** The INT2 is BIT_control number 6 *******************************/
/*********************************** 0 ---> For Falling Edge **********************************/
/*********************************** 1 ---> For Rising Edge ***********************************/
/**********************************************************************************************/
#define MCUCSR_ISC2 		6 							/*INT 2 sense control bit */





#endif /* EXTI_REGISTER_H_ */
