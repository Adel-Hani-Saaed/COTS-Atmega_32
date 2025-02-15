/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: RTOS Stack	  *******************/
/*************** SWC: RTOS 			  *******************/
/*************** Date: 28/7/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "Timer0_interface.h"
#include "GIE_interface.h"

#include "RTOS_private.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"

/* Global Array of struct for tasks (because will uses in two functions  -->> Creat Task and Scheduler)  */
TASK_T SystemTask[RTOS_TASK_NUM]={ {(u16)NULL} };   /* All Structures = NULL  -->> first {} for Array and Second {} for element in struct and if init first element of array is NULL all array will NULL  */


void RTOS_voidStart(void)
{
	/* initialize the system */
	/*Pass the Function Scheduler to Timer ISR*/
	TIMER0_u8SetCallBackCTCMode(&RTOS_voidScheduler);
	/*Enable  Global interrupt */
	GIE_voidEnable();
	/*Start Timer CTC Mode */
	TIMER0_voidInit();

}


u8 RTOS_voidCreatTask(u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvFunctionTask)(void) , u16 Copy_FirstDelay)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	/*Check if hte required priority is empty or used before for another task*/
	if (SystemTask[Copy_u8Priority].FunctionTask == NULL)
	{
		/*Passing the atguments to array of struct each element */
		SystemTask[Copy_u8Priority].Preiodicity = Copy_u16Periodicity;
		SystemTask[Copy_u8Priority].FunctionTask = Copy_pvFunctionTask;

		/*Initialize the Task state*/
		SystemTask[Copy_u8Priority].State = RTOS_TAST_RESUMED;

		/*assign First delay*/
		SystemTask[Copy_u8Priority].FirstDelay = Copy_FirstDelay;
	}

	else
	{
		/*Priority is reserved before, don't create the task*/
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}


void RTOS_voidDeletTask	(u8 Copy_u8Priority)
{
	SystemTask[Copy_u8Priority].FunctionTask = NULL;
}


void RTOS_voidSuspendTask ( u8 Copy_u8Priority )
{

	SystemTask[Copy_u8Priority].State = RTOS_TAST_SUSPENDED;

}

void RTOS_voidResumeTask ( u8 Copy_u8Priority )
{
	SystemTask[Copy_u8Priority].State = RTOS_TAST_RESUMED;
}



/*ISR Timer*/
static void RTOS_voidScheduler (void)
{

	/*Loop on all tasks to check their preiodicity*/
	for (u8 Local_u8TaskCounter = 0 ; Local_u8TaskCounter < RTOS_TASK_NUM ; Local_u8TaskCounter++)
	{
		/*Check if Task is Resumed*/
		if (SystemTask[Local_u8TaskCounter].State == RTOS_TAST_RESUMED)
		{

			/*Check the preiodicity the Task */
			if ((SystemTask[Local_u8TaskCounter].FirstDelay) == 0  )
			{
				/*Invoke the task function*/
				if (SystemTask[Local_u8TaskCounter].FunctionTask != NULL)
				{
					/*Calling Function Task Now*/
					SystemTask[Local_u8TaskCounter].FunctionTask();

					/*Assign the first delay parameter to the periodicity minus 1*/
					SystemTask[Local_u8TaskCounter].FirstDelay = SystemTask[Local_u8TaskCounter].Preiodicity-1;
				}

				else
				{
					/*Do Nothing*/
				}
			}

			else
			{
				/*Decrement the first delay*/
				SystemTask[Local_u8TaskCounter].FirstDelay--;
			}
		}

		else
		{
			/*Task is Suspended , do nothing*/
		}
	}
}
