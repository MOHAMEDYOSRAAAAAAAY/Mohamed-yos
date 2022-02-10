/*
 * KeypadProgram.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Start1
 */
#include "KeypadConfig.h"
#include"../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "util/delay.h"
static char Local_Key;
void Keypad_Init(void){
	Keypad_DDR =0b00001111;

}
char keypad_Getkey(void){
	Local_Key = '\0';
	Keypad_PORT= 0b11111110;

	if(Get_Bit(Keypad_PIN,4)==0){Local_Key ='1';}
	 if(Get_Bit(Keypad_PIN,5)==0){Local_Key ='4';}
	 if(Get_Bit(Keypad_PIN,6)==0){Local_Key ='7';}
	 if(Get_Bit(Keypad_PIN,7)==0){Local_Key ='#';}

	Keypad_PORT= 0b11111101;

	if(Get_Bit(Keypad_PIN,4)==0){Local_Key ='2';}
	 if(Get_Bit(Keypad_PIN,5)==0){Local_Key ='5';}
	 if(Get_Bit(Keypad_PIN,6)==0){Local_Key ='8';}
	 if(Get_Bit(Keypad_PIN,7)==0){Local_Key ='0';}

		Keypad_PORT= 0b11111011;
					if(Get_Bit(Keypad_PIN,4)==0){Local_Key ='3';}
			 if(Get_Bit(Keypad_PIN,5)==0){Local_Key ='6';}
			 if(Get_Bit(Keypad_PIN,6)==0){Local_Key ='9';}
			 if(Get_Bit(Keypad_PIN,7)==0){Local_Key ='*';}

			Keypad_PORT= 0b11110111;

				if(Get_Bit(Keypad_PIN,4)==0){Local_Key ='A';}
				 if(Get_Bit(Keypad_PIN,5)==0){Local_Key ='B';}
				 if(Get_Bit(Keypad_PIN,6)==0){Local_Key ='C';}
					if(Get_Bit(Keypad_PIN,7)==0){Local_Key ='D';}

return Local_Key;
								}




