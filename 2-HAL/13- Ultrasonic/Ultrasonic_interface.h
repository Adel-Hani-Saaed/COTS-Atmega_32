/*
 * Ultrasonic_interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: A-plus store
 */

#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_


void Ultrasonic_voidInit(u8 Copy_u8TriggerPort , u8 Copy_u8TriggerPin);

u16 Ultrasonic_u16GetDistance(u8 Copy_u8TriggerPort , u8 Copy_u8TriggerPin);



#endif /* ULTRASONIC_INTERFACE_H_ */
