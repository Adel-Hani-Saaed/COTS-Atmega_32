/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layers: MCAL		  *******************/
/*************** SWC: SPI			  *******************/
/*************** Date: 27/4/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


/*Select Master/Slave
 * 		Choose between
 * 			1. SPI_MASTER
 * 			2. SPI_SLAVE
 */
#define SPI_MASTER_SLAVE_SELECT			SPI_MASTER


/*Set Clock Rate Divide
 * 		Choose between
 * 			1. SPI_FREQ_DIVIDED_BY_2
 * 			2. SPI_FREQ_DIVIDED_BY_4
 * 			3. SPI_FREQ_DIVIDED_BY_8
 * 			4. SPI_FREQ_DIVIDED_BY_16
 * 			5. SPI_FREQ_DIVIDED_BY_32
 * 			6. SPI_FREQ_DIVIDED_BY_64
 * 			7. SPI_FREQ_DIVIDED_BY_128
 */
#define SPI_CLOCK_RATE					SPI_FREQ_DIVIDED_BY_32


/*Set SPI Enable
 * 		Choose between
 *			 1. SPI_DISABLE
 * 			 2. SPI_ENABLE
 */
#define SPI_ENABLE_MODE					SPI_ENABLE


/*Set Data Order
 * 		Choose between
 * 			1. SPI_DATA_LSB_FIRST
 * 			2. SPI_DATA_MSP_FIRST
 */
#define SPI_DATA_ORDER					SPI_DATA_MSP_FIRST


/*Set Clock Polarity
 * 		Choose between
 * 			1. SPI_RISING_LEADING_FALLING_TRAILING
 * 			2. SPI_FALLING_LEADING_RISING_TRAILING
 */
#define SPI_CLOCK_POLARITY				SPI_RISING_LEADING_FALLING_TRAILING


/*Set Clock Phase
 * 		Choose between
 * 			1. SPI_SAMPLE_LEADING_SETUP_TRAILING
 * 			2. SPI_SETUP_LEADING_SAMPLE_TRAILING
 */
#define SPI_CLOCK_PHASE					SPI_SAMPLE_LEADING_SETUP_TRAILING


/*Set SPI Interrupt Enable
 * 		Choose between
 * 			1. SPI_INTERRUPT_DISABLE
 * 			2. SPI_INTERRUPT_ENABLE
 */
#define SPI_INTERRUPT_ENABLE_MODE		SPI_INTERRUPT_DISABLE


/*Set Timeout for your functions*/
#define SPI_u32TIMEOUT					10000UL

#endif /* SPI_CONFIG_H_ */
