/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: SSD			  *******************/
/*************** Date: 28/1/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/********************************************************/
/******************* Public Macros **********************/
/********************************************************/

// Type 7Segment
#define SSD_COMMON_CATHODE  1
#define SSD_COMMON_ANODE    0

//  SSD Port Macros
#define SSD_PORTA    0
#define SSD_PORTB    1
#define SSD_PORTC    2
#define SSD_PORTD    3

//  SSD Pin Macros
#define SSD_PIN0     0
#define SSD_PIN1     1
#define SSD_PIN2     2
#define SSD_PIN3     3
#define SSD_PIN4     4
#define SSD_PIN5     5
#define SSD_PIN6     6
#define SSD_PIN7     7

//  SSD direction
#define SSD_PIN_OUTPUT   1
#define SSD_PIN_INPUT    0

//  SSD State
#define SSD_PIN_HIGH   1
#define SSD_PIN_LOW	   0

// Port SSD Direction
#define SSD_PORT_OUTPUT		 0xff
#define SSD_PORT_INPUT 		 0x00

//  Port SSD State
#define SSD_PORT_HIGH   	 0xff
#define SSD_PORT_LOW	     0x00

typedef struct{
	u8 Conn_T		;	// SSD_COMMON_CATHODE or SSD_COMMON_ANODE
	u8 Port         ;   // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 Enable_Port  ;   // SSD_PORTA or SSD_PORTB or SSD_PORTC or SSD_PORTD
	u8 Enable_Pin   ;   // SSD_PIN0 , SSD_PIN1 ,SSD_PIN2 , SSD_PIN3 , SSD_PIN4 , SSD_PIN5 , SSD_PIN6 , SSD_PIN7
}SSD_T;


void SSD_voidInit(SSD_T *SSD_structConfig );
void SSD_voidSetNumber (SSD_T *SSD_structConfig , u8 Copy_u8Number);
void SSD_voidEnableSSD ( SSD_T *SSD_structConfig );
void SSD_voidDisableSSD ( SSD_T *SSD_structConfig );


#endif
