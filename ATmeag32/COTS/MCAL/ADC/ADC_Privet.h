/*
 * ADC_Privet.h
 *
 *  Created on: Sep 21, 2021
 *      Author: Start1
 */

#ifndef MCAL_ADC_ADC_PRIVET_H_
#define MCAL_ADC_ADC_PRIVET_H_
#define ADMUX (*((volatile u8 *)(0x27)))
#define ADCSRA (*((volatile u8 *)(0x26)))
#define ADC (*((volatile u16 *)(0x24)))
#define NULL (void *)0
#endif /* MCAL_ADC_ADC_PRIVET_H_ */
