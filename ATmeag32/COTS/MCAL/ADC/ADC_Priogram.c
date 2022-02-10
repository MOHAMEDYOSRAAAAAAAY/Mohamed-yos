/*
 * ADC_Priogram.c
 *
 *  Created on: Sep 21, 2021
 *      Author: Start1
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include"ADC_Privet.h"
#include"../DIO/DIO_Interface.h"
#include"ADC_Config.h"
#include"ADC_Interface.h"
#include"../GIE/GIE_InterFace.h"
static void(*ADC_ptr) (void)=NULL;
void ADC_Init(u8 ADC_Speed, u8 ADC_VREF,u8 ADJUSST )
{
	Set_Bit(ADCSRA,ADCSRA_ADEN);
	GIE_voidGlobalInterruptEnable();
	Set_Bit(ADCSRA,ADCSRA_ADIE);
	switch(ADJUSST)
	{
	case LEFT_ADJUSST:
		Clr_Bit(ADCSRA,ADMUX_ADLAR);break;
	case RIGHT_ADJUSST:
			Set_Bit(ADCSRA,ADMUX_ADLAR);break;
default:break; 	}


switch(ADC_Speed)
{
	case SPEED_2:	Clr_Bit(ADCSRA,ADCSRA_ADPS0);
					Clr_Bit(ADCSRA,ADCSRA_ADPS1);
					Clr_Bit(ADCSRA,ADCSRA_ADPS2);
					break;
	case SPEED_4:	Clr_Bit(ADCSRA,ADCSRA_ADPS0);
						Set_Bit(ADCSRA,ADCSRA_ADPS1);
						Clr_Bit(ADCSRA,ADCSRA_ADPS2);
						break;

	case SPEED_8:	Clr_Bit(ADCSRA,ADCSRA_ADPS0);
							Clr_Bit(ADCSRA,ADCSRA_ADPS1);
							Set_Bit(ADCSRA,ADCSRA_ADPS2);
							break;
	case SPEED_16:	Clr_Bit(ADCSRA,ADCSRA_ADPS0);
							Clr_Bit(ADCSRA,ADCSRA_ADPS1);
							Set_Bit(ADCSRA,ADCSRA_ADPS2);
							break;

	case SPEED_32:	Set_Bit(ADCSRA,ADCSRA_ADPS0);
							Clr_Bit(ADCSRA,ADCSRA_ADPS1);
							Set_Bit(ADCSRA,ADCSRA_ADPS2);
							break;
	case SPEED_64:	Clr_Bit(ADCSRA,ADCSRA_ADPS0);
							Set_Bit(ADCSRA,ADCSRA_ADPS1);
							Set_Bit(ADCSRA,ADCSRA_ADPS2);
							break;
	case SPEED_128:	Set_Bit(ADCSRA,ADCSRA_ADPS0);
							Set_Bit(ADCSRA,ADCSRA_ADPS1);
							Set_Bit(ADCSRA,ADCSRA_ADPS2);
							break;


default:break;



}
switch(ADC_VREF){
case VREF_OFF:Clr_Bit(ADMUX,ADMUX_REFS0);
              Clr_Bit(ADMUX,ADMUX_REFS1);
              break;
case VREF_EXTERNAL:Clr_Bit(ADMUX,ADMUX_REFS0);
              Set_Bit(ADMUX,ADMUX_REFS1);
              break;

case VREF_INTERNAL:Set_Bit(ADMUX,ADMUX_REFS0);
              Set_Bit(ADMUX,ADMUX_REFS1);
              break;


}
}

u16 ADC_StartConvert(u8 ADC_Channal ){
	switch(ADC_Channal){
		case ADC0:DIO_PinDirection(DIO_PORTA, DIO_PIN0,DIO_INPUT_PIN);
					Clr_Bit(ADMUX,ADMUX_MUX0);
					Clr_Bit(ADMUX,ADMUX_MUX1);
					Clr_Bit(ADMUX,ADMUX_MUX2);
					Clr_Bit(ADMUX,ADMUX_MUX3);
					Clr_Bit(ADMUX,ADMUX_MUX4);
					break;
		case ADC1:DIO_PinDirection(DIO_PORTA, DIO_PIN1,DIO_INPUT_PIN);
						Set_Bit(ADMUX,ADMUX_MUX0);
						Clr_Bit(ADMUX,ADMUX_MUX1);
						Clr_Bit(ADMUX,ADMUX_MUX2);
						Clr_Bit(ADMUX,ADMUX_MUX3);
						Clr_Bit(ADMUX,ADMUX_MUX4);
						break;
		case ADC2:DIO_PinDirection(DIO_PORTA, DIO_PIN2,DIO_INPUT_PIN);
						Clr_Bit(ADMUX,ADMUX_MUX0);
						Set_Bit(ADMUX,ADMUX_MUX1);
						Clr_Bit(ADMUX,ADMUX_MUX2);
						Clr_Bit(ADMUX,ADMUX_MUX3);
						Clr_Bit(ADMUX,ADMUX_MUX4);
						break;
		case ADC3:DIO_PinDirection(DIO_PORTA, DIO_PIN3,DIO_INPUT_PIN);
						Set_Bit(ADMUX,ADMUX_MUX0);
						Set_Bit(ADMUX,ADMUX_MUX1);
						Clr_Bit(ADMUX,ADMUX_MUX2);
						Clr_Bit(ADMUX,ADMUX_MUX3);
						Clr_Bit(ADMUX,ADMUX_MUX4);
						break;
		case ADC4:DIO_PinDirection(DIO_PORTA, DIO_PIN4,DIO_INPUT_PIN);
						Clr_Bit(ADMUX,ADMUX_MUX0);
						Clr_Bit(ADMUX,ADMUX_MUX1);
						Set_Bit(ADMUX,ADMUX_MUX2);
						Clr_Bit(ADMUX,ADMUX_MUX3);
						Clr_Bit(ADMUX,ADMUX_MUX4);
						break;
		case ADC5:DIO_PinDirection(DIO_PORTA, DIO_PIN5,DIO_INPUT_PIN);
						Set_Bit(ADMUX,ADMUX_MUX0);
						Clr_Bit(ADMUX,ADMUX_MUX1);
						Set_Bit(ADMUX,ADMUX_MUX2);
						Clr_Bit(ADMUX,ADMUX_MUX3);
						Clr_Bit(ADMUX,ADMUX_MUX4);
						break;
		case ADC6:DIO_PinDirection(DIO_PORTA, DIO_PIN6,DIO_INPUT_PIN);
						Clr_Bit(ADMUX,ADMUX_MUX0);
						Set_Bit(ADMUX,ADMUX_MUX1);
						Set_Bit(ADMUX,ADMUX_MUX2);
						Clr_Bit(ADMUX,ADMUX_MUX3);
						Clr_Bit(ADMUX,ADMUX_MUX4);
						break;
		case ADC7:DIO_PinDirection(DIO_PORTA, DIO_PIN7,DIO_INPUT_PIN);
						Set_Bit(ADMUX,ADMUX_MUX0);
						Set_Bit(ADMUX,ADMUX_MUX1);
						Set_Bit(ADMUX,ADMUX_MUX2);
						Clr_Bit(ADMUX,ADMUX_MUX3);
						Clr_Bit(ADMUX,ADMUX_MUX4);
						break;

	default:break;	}


	Set_Bit(ADCSRA,ADCSRA_ADSC);
		while(Get_Bit(ADCSRA,ADCSRA_ADSC));

	return ADC;

}

void ADC_SetCallBack( void(* ptr) (void)){
	ADC_ptr=ptr;
}


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
	if(ADC_ptr !=NULL)
	{
ADC_ptr();
	}
	else	{}
	}

