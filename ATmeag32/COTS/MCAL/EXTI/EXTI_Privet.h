/*
 * EXTI_Privet.h
 *
 *  Created on: Sep 15, 2021
 *      Author: Start1
 */

#ifndef EXTI_PRIVET_H_
#define EXTI_PRIVET_H_


#define EXTI_ENABLE 1
#define EXTI_DISABLE 0
 #define NULL (void *)0
#define MCUCR (*((volatile u8 *)(0x55)))
#define MCUCSR (*((volatile u8 *)(0x54)))
#define GICR (*((volatile u8 *)(0x5B)))
#define GIFR (*((volatile u8 *)(0x5A)))


#endif /* EXTI_PRIVET_H_ */
