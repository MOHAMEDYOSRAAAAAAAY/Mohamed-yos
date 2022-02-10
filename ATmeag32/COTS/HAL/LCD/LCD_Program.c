/*
 * LCD_Program.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Start1
 */

#include<avr/io.h>
#include<util/delay.h>
void LCD_Init(void){
_delay_ms(50);
LCD_SendCom(0b00110000);
_delay_ms(1);
LCD_SendCom(0b00001000);
_delay_ms(1);
LCD_SendCom(0b00000001);
_delay_ms(3);
LCD_SendCom(0b00000111);
}

void LCD_SendCom(int data){
PORTB = 0b00000000;
	PORTA = data;
	PORTB= 0b00000100;
	_delay_ms(1);
	PORTB= 0b00000000;
	_delay_ms(1);
}
void LCD_SendCom(int Char){
PORTB = 0b00000001;
	PORTA = Char;
	PORTB= 0b00000101;
	_delay_ms(1);
	PORTB= 0b00000001;
	_delay_ms(1);
}
