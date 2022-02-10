/*
 * main.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Start1
 */
#include "UART/UART_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"
#include "Keypad2/Keypad_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
static u8 SPEED;

int main()
{

	char Local_Key ;
	int NoteNumb = 20;
	int note ;

	DIO_PortDirection(DIO_PORTA, DIO_OUTPUT_PORT);
	DIO_PortDirection(DIO_PORTC, DIO_OUTPUT_PORT);
	DIO_PinDirection(DIO_PORTA,DIO_PIN0, DIO_INPUT_PIN);

	Keypad_Init();
	UART_Init();
	ADC_Init(SPEED_128,VREF_EXTERNAL, LEFT_ADJUSST );
	while(1)
	{Local_Key =	keypad_Getkey();

	note = ADC_StartConvert(ADC1);
	if (note >=0 && note<=4){
		NoteNumb =24;
	}
	if (note >=4 && note<=8){
		NoteNumb =36;
	}

	if (note >=8 && note<=16){
		NoteNumb =48;
	}
	if (note >=24 && note<=32){
		NoteNumb =60;
	}
	if (note >=32 && note<=46){
		NoteNumb =72;
	}if (note >=46 && note<=64){
		NoteNumb =84;
	}DIO_SetPort(DIO_PORTC, ADC_StartConvert(ADC1));

	if (Local_Key != '\0')
	{SPEED =  (ADC_StartConvert(ADC0));
	if (SPEED>=127){
		SPEED =127 ;
	}

	UART_Send(0b10010000);
	switch (Local_Key)
	{case '1' : UART_Send(0 + NoteNumb);break;
	case '2' : UART_Send(1 + NoteNumb);break;
	case '3' : UART_Send(2 + NoteNumb);break;
	case '4' : UART_Send(3 + NoteNumb);break;
	case '5' : UART_Send(4 + NoteNumb);break;
	case '6' : UART_Send(5 + NoteNumb);break;
	case '7' : UART_Send(6 + NoteNumb);break;
	case '8' : UART_Send(7 + NoteNumb);break;
	case '9' : UART_Send(8 + NoteNumb);break;
	case 'A' : UART_Send(9 + NoteNumb);break;
	case 'B' : UART_Send(10 + NoteNumb);break;
	case 'C' : UART_Send(11 + NoteNumb);break;
	case 'D' : UART_Send(12 + NoteNumb);break;
	case '*' : UART_Send(13 + NoteNumb);break;
	case '0' : UART_Send(14 + NoteNumb);break;
	case '#' : UART_Send(15 + NoteNumb);break;
	default :break;


	}
	UART_Send(SPEED);
	while(keypad_Getkey()!= '\0');
	UART_Send(0b10000000);
	switch (Local_Key)
	{case '1' : UART_Send(0 + NoteNumb);break;
	case '2' : UART_Send(1 + NoteNumb);break;
	case '3' : UART_Send(2 + NoteNumb);break;
	case '4' : UART_Send(3 + NoteNumb);break;
	case '5' : UART_Send(4 + NoteNumb);break;
	case '6' : UART_Send(5 + NoteNumb);break;
	case '7' : UART_Send(6 + NoteNumb);break;
	case '8' : UART_Send(7 + NoteNumb);break;
	case '9' : UART_Send(8 + NoteNumb);break;
	case 'A' : UART_Send(9 + NoteNumb);break;
	case 'B' : UART_Send(10 + NoteNumb);break;
	case 'C' : UART_Send(11 + NoteNumb);break;
	case 'D' : UART_Send(12 + NoteNumb);break;
	case '*' : UART_Send(13 + NoteNumb);break;
	case '0' : UART_Send(14 + NoteNumb);break;
	case '#' : UART_Send(15 + NoteNumb);break;
	default :break;





	}UART_Send(50);
	}
	}
}
