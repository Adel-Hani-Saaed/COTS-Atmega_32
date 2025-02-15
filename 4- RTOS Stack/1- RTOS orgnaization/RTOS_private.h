/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: RTOS Stack	  *******************/
/*************** SWC: RTOS 			  *******************/
/*************** Date: 28/7/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

/*
	Hints :-
	1-the struct is used by me only so it is here (private.h)
	2-we will handle priority by another way so it is not here
		priority will be the index of tasks array
		we will check priority in voidScheduler
*/
typedef struct
{
	u16 Preiodicity;
	void(*FunctionTask)(void);
	u8 State;
	u16 FirstDelay;

}TASK_T;

#define RTOS_TAST_RESUMED 	    0
#define RTOS_TAST_SUSPENDED 	1


static void RTOS_voidScheduler (void);

#endif /* RTOS_PRIVATE_H_ */
