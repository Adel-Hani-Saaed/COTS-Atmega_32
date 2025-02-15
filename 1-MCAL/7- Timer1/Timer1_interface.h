/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer1		  *******************/
/*************** Date: 31/3/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

/*****************************************/
/************* For ICU *******************/
/*****************************************/
#define ICU_FALLING_EDGE	0
#define ICU_RISING_EDGE		1


/* Description : this Function is to set the Timer1
 * \input  : nothing
 * Return  : nothing
 */
void TIMER1_voidInit(void);


/* Description : this Function is registration Function the Call back for Normal Mode
 * \input :  void (*Copy_pvCallBackFunc)(void)    		 ,  Pointer to function
 *  Return  : State of Function  OK or NOK
 */
u8 TIMER1_u8SetCallBackOverFlowMode (void (*Copy_pvCallBackFunc)(void));


/* Description : this Function is registration Function the Call back for CTC Mode Channel A
 * \input :  void (*Copy_pvCallBackFunc)(void)    		 ,  Pointer to function
 *  Return  : State of Function  OK or NOK
 */
u8 TIMER1_u8SetCallBackCTCModeChannel_A		(void (*Copy_pvCallBackFunc)(void));

/* Description : this Function is registration Function the Call back for CTC Mode Channel B
 * \input :  void (*Copy_pvCallBackFunc)(void)    		 ,  Pointer to function
 *  Return  : State of Function  OK or NOK
 */
u8 TIMER1_u8SetCallBackCTCModeChannel_B		(void (*Copy_pvCallBackFunc)(void));


/* Description : this Function is to set the value of pre_load in register TCNT0_REG
 * \input  : Copy_u16PreloadValue       Range : 0 ~ 65536
 * Return  : nothing
 */
void TIMER1_voidSetPreloadValue (u16 Copy_u16PreloadValue) ;



/* Description : this Function is to set the value of TOP in register ICR
 * \input  : Copy_u16PreloadValue       Range : 0 ~ 65536
 * Return  : nothing
 */
void TIMER1_voidSetICR1 (u16 Copy_u16ICR1) ;


u16 TIMER1_u16GetTimerCounterValue (void);


/* Description : this Function is to set the value of CTC Value in register OCR1A & OCR1B
 * \input  : Copy_u16PreloadValue       Range : 0 ~ 65536
 * Return  : nothing
 */
void TIMER1_voidSetValueCompMatchChannel_A (u16 Copy_u16CTCA);
void TIMER1_voidSetValueCompMatchChannel_B (u16 Copy_u16CTCB);


/*****************************************/
/************* For ICU *******************/
/*****************************************/
void ICU_voidInit(void);
u8 ICU_u8SetTriggerEdge(u8 Copy_u8Edge);
void ICU_voidEnableInterrupt(void);
void ICU_voidDisableInterrupt(void);
u16 ICU_u16GetReadingInputCaptureUnit(void);
u8 ICU_u8SetCallBackRegisterICU(void(*Copy_pvCallBackFunc)(void));






#endif /* TIMER1_INTERFACE_H_ */
