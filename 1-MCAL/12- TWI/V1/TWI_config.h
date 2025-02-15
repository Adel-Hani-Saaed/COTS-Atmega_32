/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: TWI			  *******************/
/*************** Date: 8/5/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TWI_CONFIG_H_
#define TWI_CONFIG_H_


/*
	Choose between :-
		1- PRESCALLER_BY_1
		2- PRESCALLER_BY_4
		3- PRESCALLER_BY_16
		4- PRESCALLER_BY_64
*/
#define TWI_PRESCALLER  PRESCALLER_BY_1


/*system frequency*/
#define F_CPU 8000000UL


/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
#define SCL_Clock  400000UL



#endif /* TWI_CONFIG_H_ */
