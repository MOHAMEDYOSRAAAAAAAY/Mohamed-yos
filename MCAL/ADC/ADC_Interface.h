/*
 * ADC_Interface.h
 *
 *  Created on: Sep 21, 2021
 *      Author: Start1
 */

#ifndef MCAL_ADC_INTERFACE_H_
#define MCAL_ADC_INTERFACE_H_
#include "../LIB/STD_TYPES.h"
#define ADMUX_REFS1 7
#define ADMUX_REFS0 6
#define ADMUX_ADLAR 5
#define ADMUX_MUX4 4
#define ADMUX_MUX3 3
#define ADMUX_MUX2 2
#define ADMUX_MUX1 1
#define ADMUX_MUX0 0
/////////////////////////////
#define ADCSRA_ADEN 7 //Enable PIN
#define ADCSRA_ADSC 6 //Start the converting
#define ADCSRA_ADSTE 5 //1 for the auto trigger
#define ADCSRA_ADIF 4//Interrupt flag
#define ADCSRA_ADIE 3//Interrupt Enable
#define ADCSRA_ADPS2 2
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS0 0
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7
#define SPEED_2 0
#define SPEED_4 1
#define SPEED_8 2
#define SPEED_16 3
#define SPEED_32 4
#define SPEED_64 5
#define SPEED_128 6
#define PRESCALE_128 7
void ADC_Init(u8 ADC_Speed, u8 ADC_VREF,u8 ADJUSST );
#define VREF_OFF 0
void ADC_SetCallBack( void(* ptr) (void));
u16 ADC_StartConvert(u8 ADC_Channal );
#define LEFT_ADJUSST 0
#define RIGHT_ADJUSST 1
#define VREF_EXTERNAL 1
#define VREF_INTERNAL 2

#endif /* MCAL_ADC_INTERFACE_H_ */
