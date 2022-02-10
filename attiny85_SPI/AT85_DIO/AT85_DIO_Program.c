/*
 * AT85_DIO_Program.c
 *
 *  Created on: Sep 19, 2021
 *      Author: Start1
 */
#include "BIT_MATH.h"
#include "AT85_DIO_Privet.h"
#include "AT85_DIO_Config.h"
#include "AT85_DIO_Interface.h"
void pinMode(u8 PinNum, u8 Mode)
{switch(Mode){
case OUTPUT: Set_Bit(DDRB,PinNum);break;
case INPUT: Clr_Bit(DDRB,PinNum);break;
default :break;
}}
void digitalWrite(u8 PinNum, u8 value){switch(value){
case HIGH: Set_Bit(PORTB,PinNum);break;
case LOW: Clr_Bit(PORTB,PinNum);break;
default :break;
}}

void setPort(u8 value ){
	PORTB= value;
}
void setPortDirection(u8 direction ){
	switch(direction){
case OUTPUT:DDRB=0xff ;break;
case INPUT: DDRB=0x00 ;break;
default :break;
}}
u8 digitalRead(u8 PinNum){
return Get_Bit(PINB,PinNum);
}
void TogPin(u8 pinNum){

	Tog_Bit(PORTB,pinNum);



}
