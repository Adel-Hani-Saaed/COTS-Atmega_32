/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer2		  *******************/
/*************** Date: 8/4/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


/* Description : this Function is to set the Timer2
 * \input  : nothing
 * Return  : nothing
 */
void TIMER2_voidInit();


/* Description : this Function is registration Function the Call back for CTC Mode
 * \input :  void (*Copy_pvCallBackFunc)(void)    		 ,  Pointer to function
 *  Return  : State of Function  OK or NOK
 */
u8 TIMER2_u8SetCallBackCTCMode		(void (*Copy_pvCallBackFunc)(void));


/* Description : this Function is registration Function the Call back for Normal Mode
 * \input :  void (*Copy_pvCallBackFunc)(void)    		 ,  Pointer to function
 *  Return  : State of Function  OK or NOK
 */
u8 TIMER2_u8SetCallBackOverFlowMode (void (*Copy_pvCallBackFunc)(void));



/* Description : this Function is to set the value of pre_load in register TCNT2_REG
 * \input  : Copy_u8PreloadValue       Range : 0 ~ 255
 * Return  : nothing
 */
void TIMER2_voidSetPreloadValue (u8 Copy_u8PreloadValue) ;



/* Description : this Function is to set the value of CTC Value in register OCR2
 * \input  : Copy_u8PreloadValue       Range : 0 ~ 255
 * Return  : nothing
 */
void TIMER2_voidSetCompMatchValue(u8 Copy_u8Value);



/* Description : this Function is to return the value of pre_load in register TCNT2_REG
 * \input  :  nothing
 * Return  :  Range : 0 ~ 255
 */
u8 TIMER2_u8GetTimerCounterValue (void);


#endif /* TIMER2_INTERFACE_H_ */
