/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer2		  *******************/
/*************** Date: 8/4/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_


#define TIMER2_PRESCALER_MASK					     0b11111000 /* This Value also could use for bit masking */

#define TIMER2_NO_CLOCK_SOURCE                        0
#define TIMER2_NO_PRESCALER_FACTOR                    1
#define TIMER2_DIVISION_FACTOR_8                      2
#define TIMER2_DIVISION_FACTOR_32                     3
#define TIMER2_DIVISION_FACTOR_64                     4
#define TIMER2_DIVISION_FACTOR_128                    5
#define TIMER2_DIVISION_FACTOR_256                    6
#define TIMER2_DIVISION_FACTOR_1024                   7

/*Fast PWM*/
#define TIMER2_OC_DISCONNECTED     					  1
#define TIMER2_CLR_ON_CTC_SET_ON_TOP				  2
#define TIMER2_SET_ON_CTC_CLR_ON_TOP				  3

/*Phase Correct*/
#define TIMER2_OC_DISCONNECTED     					 					 1
#define TIMER2_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON			 2
#define TIMER2_CLR_ON_CTC_COUNTING_DWON_SET_ON_CTC_COUNTING_UP							         3

#define DISABLE						                  0
#define ENABLE						                  1

#define TIMER2_NORMAL_MODE						      0
#define TIMER2_PWM_PHASE_CORRECT_MODE			      1
#define TIMER2_CTC_MODE							      2
#define TIMER2_FAST_PWM_MODE						  3

#define TIMER2_OC2_DISCONNECTED					      0
#define TIMER2_OC2_TOGGEL					          1
#define TIMER2_OC2_LOW							      2
#define TIMER2_OC2_HIGH							      3


#endif /* TIMER2_PRIVATE_H_ */
