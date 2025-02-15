/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layers: MCAL		  *******************/
/*************** SWC: SPI			  *******************/
/*************** Date: 27/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "SPI_private.h"
#include "SPI_config.h"
#include "SPI_register.h"
#include "SPI_interface.h"


/*Global variable to carry the Transmit Data*/
static u8 * SPI_pu8TData = NULL ;

/*Global variable to carry the Receive Data*/
static u8 * SPI_pu8RData = NULL ;

/*Global variable to carry the buffer size*/
static u8 SPI_u8BufferSize;

/*Global pointer to function to carry the notification function called by ISR*/
static void (* SPI_pvCallBackNotificationFunc)(void)= NULL;

/*Global flag for the SPI Busy State*/
static u8 SPI_u8State= SPI_IDEL ;

/*Global variable to indicate for the current Data index of the buffer*/
static u8 SPI_u8Index;



void SPI_voidInit(void)
{
	/*Master & Slave Select and config the Pins in Micro*/
#if SPI_MASTER_SLAVE_SELECT == SPI_MASTER

	SET_BIT(SPCR_REG , SPCR_MSTR) ;

	/*SCK  Pin 7 in PortB*/
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);

	/*MISO Pin 6 in PortB  must is  input*/
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_INPUT);

	/*MOSI Pin 5 in PortB  must output is master */
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);

	/*SS   Pin 7 in PortB  must is  input pull up or Vcc */
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_INPUT);
	DIO_enumSetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);


#elif SPI_MASTER_SLAVE_SELECT == SPI_SLAVE

	CLR_BIT(SPCR_REG , SPCR_MSTR) ;

	/*SCK Pin 7 in PortB*/
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_INPUT);

	/*MISO Pin 6 in PortB  must is  input*/
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);

	/*MOSI Pin 5 in PortB  must input is slave */
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN5, DIO_INPUT);

	/*SS   Pin 7 in PortB  must is input */
	DIO_enumSetPinDirection(DIO_PORTB, DIO_PIN4, DIO_INPUT);

#else
#error "wrong SPI_MASTER_SLAVE_SELECT config"
#endif


	/*Data Order ( LSB & MSB )  first*/
#if SPI_DATA_ORDER == SPI_DATA_LSB_FIRST
	SET_BIT(SPCR_REG , SPCR_DORD) ;
#elif SPI_DATA_ORDER == SPI_DATA_MSP_FIRST
	CLR_BIT(SPCR_REG , SPCR_DORD) ;
#else
#error "wrong SPI_DATA_ORDER config"
#endif


	/*Clock Polarity ( Rising & Falling Leading Edge )*/
#if SPI_CLOCK_POLARITY == SPI_RISING_LEADING_FALLING_TRAILING
	CLR_BIT(SPCR_REG , SPCR_CPOL) ;
#elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
	SET_BIT(SPCR_REG , SPCR_CPOL) ;
#else
#error "wrong SPI_CLOCK_POLARITY config"
#endif

	/*Clock Phase ( Setup & Sample )*/
#if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING
	CLR_BIT(SPCR_REG , SPCR_CPHA) ;

#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
	SET_BIT(SPCR_REG , SPCR_CPHA) ;
#else
#error "wrong SPI_CLOCK_PHASE config"
#endif

	/*Clock Rate Selection*/
#if SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_2
	CLR_BIT(SPCR_REG , SPCR_SPR0) ;
	CLR_BIT(SPCR_REG , SPCR_SPR1) ;
	SET_BIT(SPSR_REG , SPSR_SPI2X) ;
#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_4
	CLR_BIT(SPCR_REG  , SPCR_SPR0) ;
	CLR_BIT(SPCR_REG  , SPCR_SPR1) ;
	CLR_BIT(SPSR_REG  , SPSR_SPI2X) ;
#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_8
	SET_BIT(SPCR_REG , SPCR_SPR0) ;
	CLR_BIT(SPCR_REG , SPCR_SPR1) ;
	SET_BIT(SPSR_REG , SPSR_SPI2X) ;
#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_16
	SET_BIT(SPCR_REG , SPCR_SPR0) ;
	CLR_BIT(SPCR_REG , SPCR_SPR1) ;
	CLR_BIT(SPSR_REG , SPSR_SPI2X) ;
#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_32
	CLR_BIT(SPCR_REG , SPCR_SPR0) ;
	SET_BIT(SPCR_REG , SPCR_SPR1) ;
	SET_BIT(SPSR_REG , SPSR_SPI2X) ;
#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_64
	CLR_BIT(SPCR_REG , SPCR_SPR0) ;
	SET_BIT(SPCR_REG , SPCR_SPR1) ;
	CLR_BIT(SPSR_REG , SPSR_SPI2X) ;
#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_128
	SET_BIT(SPCR_REG , SPCR_SPR0) ;
	SET_BIT(SPCR_REG , SPCR_SPR1) ;
	CLR_BIT(SPSR_REG , SPSR_SPI2X) ;
#else
#error "wrong SPI_CLOCK_RATE config"
#endif

	/*SPI Interrupt Enable PIE*/
#if SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_DISABLE
	CLR_BIT(SPCR_REG , SPCR_SPIE) ;
#elif SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_ENABLE
	SET_BIT(SPCR_REG , SPCR_SPIE) ;
#else
#error "wrong SPI_INTERRUPT_ENABLE_MODE config"
#endif

	/*SPI Enable Peripheral*/
#if SPI_ENABLE_MODE == SPI_DISABLE
	CLR_BIT(SPCR_REG , SPCR_SPE) ;
#elif SPI_ENABLE_MODE == SPI_ENABLE
	SET_BIT(SPCR_REG , SPCR_SPE) ;
#else
#error "wrong SPI_ENABLE_MODE config"
#endif

}


u8 SPI_u8TranceiveChar (u8 Copy_u8TransmittedData , u8 *Copy_pu8RecivedData)
{
	u8 Local_u8ErrorState = STD_TYPES_OK ;
	u32 Local_u32TimeoutCounter = 0 ;

	if (SPI_u8State == SPI_IDEL)
	{
		/*make spi busy until finshed function*/
		SPI_u8State = SPI_BUSY ;

		/*Send data*/
		SPDR_REG = Copy_u8TransmittedData ;

		/*Wait (busy waiting ) until transfer complete or Time out */
		while (((GET_BIT(SPSR_REG , SPSR_SPIF)) == 0) && (Local_u32TimeoutCounter < SPI_u32TIMEOUT))
		{
			Local_u32TimeoutCounter++ ;
		}
		/*If time out is finished*/
		if (Local_u32TimeoutCounter == SPI_u32TIMEOUT)
		{
			/*return the timer out error*/
			Local_u8ErrorState = STD_TIMEOUT_STATE ;
		}
		else
		{
			/*recived data*/
			*Copy_pu8RecivedData = SPDR_REG ;
		}
		/*make Spi idel to used function again*/
		SPI_u8State = SPI_IDEL ;
	}

	/*if spi busy return error state function busy*/
	else
	{
		Local_u8ErrorState = BUSY_FUNC ;
	}

	return Local_u8ErrorState ;
}


u8 SPI_u8BufferTranceiverSynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8Counter = 0 ;

	/* Hint: any function input is pointer must be Check it Not equal Null Pointer (if Not equal null is meaning the pointer have string)*/
	if ((Copy_u8RData != NULL) && (Copy_u8RData != NULL))
	{
		while(Local_u8Counter < Copy_u8BufferSize)
		{
			/*Array Trans data & Array to storge Return */
			SPI_u8TranceiveChar(Copy_u8TData[Local_u8Counter], &Copy_u8RData[Local_u8Counter]);
			Local_u8Counter++;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}



u8 SPI_u8BufferTranceiverAsynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize , void(*Copy_PvNotificationFunction)(void))
{
	u8 Local_ErrorState = STD_TYPES_OK;

	if (SPI_u8State == SPI_IDEL)
	{
		/* Hint: any function input is pointer must be Check it Not equal Null Pointer (if Not equal null is meaning the pointer have string)*/
		if ( (Copy_u8TData != NULL) && (Copy_u8RData != NULL) && (Copy_PvNotificationFunction !=NULL) )
		{
			/*Make Spi is now Busy
			 * Hint: this function non_reentrant  and  i put State in first line to avoid the corruption data
			 * because not assign the Buffer and if interrupt call function the Busy state save function
			 * */
			SPI_u8State = SPI_BUSY;

			/*Assign the SPI data globally*/
			SPI_pu8TData = Copy_u8TData ;
			SPI_pu8RData = Copy_u8RData ;
			SPI_u8BufferSize = Copy_u8BufferSize ;
			Copy_PvNotificationFunction = SPI_pvCallBackNotificationFunc ;

			/*Initialize current  index equal 0*/
			SPI_u8Index = 0;

			/*Transmit first Data  */
			SPDR_REG = SPI_pu8TData[SPI_u8Index] ;

			/*SPI Interrupt Enable*/
			SET_BIT(SPCR_REG , SPCR_SPIE) ;
		}
		else
		{
			Local_ErrorState = STD_TYPES_NOK;
		}
	}

	else
	{
		Local_ErrorState = BUSY_FUNC;
	}

	return Local_ErrorState;
}


void __vector_12 (void)	__attribute__ ((signal)) ;
void __vector_12 (void)
{
	/*Receive Data First Char*/
	SPI_pu8RData[SPI_u8Index] = SPDR_REG ;

	/*Increment Data index of the buffer*/
	SPI_u8Index++ ;


	/*Buffer Complete*/
	if (SPI_u8Index == SPI_u8BufferSize)
	{
		/*SPI is now IDLE*/
		SPI_u8State = SPI_IDEL ;

		/*SPI Interrupt Disable*/
		CLR_BIT(SPCR_REG , SPCR_SPIE) ;

		/*Call Notification Function*/
		SPI_pvCallBackNotificationFunc();
	}

	/*Buffer not Complete*/
	else
	{
		/*Transmit next Data*/
		SPDR_REG = SPI_pu8TData[SPI_u8Index] ;
	}
}



