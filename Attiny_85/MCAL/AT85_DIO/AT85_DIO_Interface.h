/*
 * AT85_DIO_Interface.h
 *
 *  Created on: Sep 19, 2021
 *      Author: Start1
 */
#include "STD_TYPES.h"

#ifndef AT85_DIO_INTERFACE_H_
#define AT85_DIO_INTERFACE_H_
#define INPUT 0
#define OUTPUT 1
#define LOW 0
#define HIGH 1
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5

void pinMode(u8 PinNum, u8 Mode);
void digitalWrite(u8 PinNum, u8 value);
void setPort(u8 value );
u8 digitalRead(u8 PinNum);
void setPortDirection(u8 direction );
void TogPin(u8 pinNum);




#endif /* AT85_DIO_INTERFACE_H_ */
