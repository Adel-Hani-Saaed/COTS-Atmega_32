/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer2		  *******************/
/*************** Date: 8/4/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_

/* 	Set Timer2 Waveform Generation Mode
 * 				Choose between
 * 					1. TIMER2_NORMAL_MODE
 * 					2. TIMER2_CTC_MODE
 * 					3. TIMER2_FAST_PWM_MODE
 *			 		4. TIMER2_PWM_PHASE_CORRECT_MODE
 */
#define TIMER2_WAVEFORM_GENERATION_MODE		TIMER2_PWM_PHASE_CORRECT_MODE


/*Set the Required Pre_scaler
				Choose between
					1- TIMER2_NO_CLOCK_SOURCE
					2- TIMER2_NO_PRESCALER_FACTOR
					3- TIMER2_DIVISION_FACTOR_8
					4- TIMER2_DIVISION_FACTOR_32
					5- TIMER2_DIVISION_FACTOR_64
					6- TIMER2_DIVISION_FACTOR_128
					7- TIMER2_DIVISION_FACTOR_256
					8- TIMER2_DIVISION_FACTOR_1024
 */
#define TIMER2_PRESCALER					TIMER2_DIVISION_FACTOR_64






#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_NORMAL_MODE

/*Set the Required Pre_load on TIMER2 Normal Mode*/
#define TIMER2_PRELOAD_VAL					192

/*Set Timer2 Overflow Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER2_OVERFLOW_INTERRUPT			DISABLE




#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_CTC_MODE

/*Set the Required Compare Match Value on TIMER2 CTC Mode*/
#define TIMER2_CTC_VAL						125

/*Set Compare Match Output Mode
 * Choose between
 * 1. TIMER2_OC2_DISCONNECTED
 * 2. TIMER2_OC2_TOGGEL
 * 3. TIMER2_OC2_LOW
 * 4. TIMER2_OC2_HIGH
 */
#define TIMER2_OC2_MODE						TIMER2_OC2_DISCONNECTED

/*Set Timer2 CTC Interrupt
 * Choose between
 * 1. DISABLE
 * 2. ENABLE
 */
#define TIMER2_CTC_INTERRUPT				ENABLE



#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_PWM_PHASE_CORRECT_MODE

		/*Set the Required Compare Match Value on TIMER2 CTC Mode*/
		#define TIMER2_CTC_VAL						0

		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER2_OC_DISCONNECTED
		 * 2. TIMER2_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON    (Non_Interval)
		 * 3. TIMER2_CLR_ON_CTC_COUNTING_DWON_SET_ON_CTC_COUNTING_UP    (Interval)
		 */
		#define TIMER2_CTC_PWM_MODE   	TIMER2_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON


#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_FAST_PWM_MODE

		/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
		#define TIMER2_CTC_VAL						0

		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER2_OC_DISCONNECTED
		 * 2. TIMER2_CLR_ON_CTC_SET_ON_TOP		(Non_Interval)
		 * 3. TIMER2_SET_ON_CTC_CLR_ON_TOP		(Interval)
		 */
		#define TIMER2_CTC_PWM_MODE						TIMER2_SET_ON_CTC_CLR_ON_TOP

	#else
		#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"


#endif


#endif /* TIMER2_CONFIG_H_ */
