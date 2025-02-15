/********************************************************/
/********************************************************/
/*************** Author: Adel_Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: Timer2		  *******************/
/*************** Date: 8/4/2023 	  *******************/
/*************** Version: 1.00		  *******************/
/********************************************************/
/********************************************************/


#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "Timer2_interface.h"
#include "Timer2_private.h"  				//Hint: must include the file private before file configuration
#include "Timer2_config.h"
#include "Timer2_register.h"


static void (*Timer2_pvCallBackFuncCTCMode)(void) = NULL;
static void (*Timer2_pvCallBackFuncOverFlowMode)(void) = NULL;


void TIMER2_voidInit()
{
	/*Set Configurable Modes*/
#if TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_NORMAL_MODE

	/*Initialize Waveform Generation Mode as Normal Mode*/
	CLR_BIT(TCCR2_REG, TCCR2_WGM20);
	CLR_BIT(TCCR2_REG, TCCR2_WGM21);

	/*Set value PreLoad*/
	TCNT2_REG = TIMER2_PRELOAD_VAL;

	/*Timer2 Overflow Interrupt Enable*/
#if TIMER2_OVERFLOW_INTERRUPT == DISABLE

	CLR_BIT(TIMSK_REG , TIMSK_TOIE2);

#elif TIMER2_OVERFLOW_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_TOIE2);

#else
#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
#endif


#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_CTC_MODE

	/*Initialize Waveform Generation Mode as CTC Mode*/
	CLR_BIT(TCCR2_REG , TCCR2_WGM20) ;
	SET_BIT(TCCR2_REG , TCCR2_WGM21) ;

	/*Set the Required CTC Value*/
	OCR2_REG = TIMER2_CTC_VAL ;

	/*Timer2 Compare Match Interrupt Enable*/
#if TIMER0_CTC_INTERRUPT == DISABLE
	CLR_BIT(TIMSK_REG , TIMSK_OCIE2) ;

#elif TIMER0_CTC_INTERRUPT == ENABLE
	SET_BIT(TIMSK_REG , TIMSK_OCIE2) ;

#else
#error "Wrong TIMER0_OVERFLOW_INTERRUPT Config"
#endif


#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_FAST_PWM_MODE

	/*Initialize Waveform Generation Mode as Fast PWM Mode*/
	SET_BIT(TCCR2_REG , TCCR2_WGM20) ;
	SET_BIT(TCCR2_REG , TCCR2_WGM21) ;

	/*Set CTC Fast PWM MODE*/
#if TIMER2_CTC_PWM_MODE == TIMER2_OC_DISCONNECTED
	CLR_BIT(TCCR2_REG , TCCR2_COM20) ;
	CLR_BIT(TCCR2_REG , TCCR2_COM21) ;
#elif TIMER2_CTC_PWM_MODE == TIMER2_CLR_ON_CTC_SET_ON_TOP
	CLR_BIT(TCCR2_REG , TCCR2_COM20) ;
	SET_BIT(TCCR2_REG , TCCR2_COM21) ;
#elif TIMER2_CTC_PWM_MODE == TIMER2_SET_ON_CTC_CLR_ON_TOP
	SET_BIT(TCCR2_REG , TCCR2_COM20) ;
	SET_BIT(TCCR2_REG , TCCR2_COM21) ;
#else
#error "Wrong TIMER0_CTC_PWM_MODE Config"
#endif

	/*Set the Required CTC Value*/
	OCR2_REG = TIMER2_CTC_VAL;

#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER2_PWM_PHASE_CORRECT_MODE

	/*Initialize Waveform Generation Mode as Phase Correct PWM Mode*/
	SET_BIT(TCCR2_REG , TCCR2_WGM20) ;
	CLR_BIT(TCCR2_REG , TCCR2_WGM21) ;

	/*Set CTC Fast PWM MODE*/
#if TIMER2_CTC_PWM_MODE == TIMER2_OC_DISCONNECTED
	CLR_BIT(TCCR2_REG , TCCR2_COM20) ;
	CLR_BIT(TCCR2_REG , TCCR2_COM21) ;
#elif TIMER2_CTC_PWM_MODE == TIMER2_CLR_ON_CTC_COUNTING_UP_SET_ON_CTC_COUNTING_DWON
	CLR_BIT(TCCR2_REG , TCCR2_COM20) ;
	SET_BIT(TCCR2_REG , TCCR2_COM21) ;
#elif TIMER2_CTC_PWM_MODE == TIMER2_CLR_ON_CTC_COUNTING_DWON_SET_ON_CTC_COUNTING_UP
	SET_BIT(TCCR2_REG , TCCR2_COM20) ;
	SET_BIT(TCCR2_REG , TCCR2_COM21) ;
#else
#error "Wrong TIMER0_CTC_PWM_MODE Config"
#endif

	/*Set the Required CTC Value*/
	OCR2_REG = TIMER2_CTC_VAL;


#else
	#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"

#endif

	/*Set the Required Pre_scaler*/
	TCCR2_REG &= TIMER2_PRESCALER_MASK ;
	TCCR2_REG |= TIMER2_PRESCALER ;
}

void TIMER2_voidSetPreloadValue (u8 Copy_u8PreloadValue)
{
	TCNT2_REG = Copy_u8PreloadValue;
}

void TIMER2_voidSetCompMatchValue(u8 Copy_u8CTCValue)
{
	OCR2_REG = Copy_u8CTCValue;
}



u8 TIMER2_u8GetTimerCounterValue (void)
{
	return TCNT2_REG;
}




u8 TIMER2_u8SetCallBackCTCMode(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		Timer2_pvCallBackFuncCTCMode = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;

	}

	return Local_u8ErrorState;
}


/*TIMER2 CTC Mode ISR*/
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if (Timer2_pvCallBackFuncCTCMode != NULL)
	{
		Timer2_pvCallBackFuncCTCMode();
	}
}



u8 TIMER2_u8SetCallBackOverFlowMode(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if (Copy_pvCallBackFunc != NULL)
	{
		Timer2_pvCallBackFuncOverFlowMode = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;

	}

	return Local_u8ErrorState;
}

/*TIMER2 Normal Mode ISR*/
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if (Timer2_pvCallBackFuncOverFlowMode != NULL)
	{
		Timer2_pvCallBackFuncOverFlowMode();
	}
}
