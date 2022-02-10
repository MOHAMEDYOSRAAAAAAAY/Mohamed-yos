/*
 * Attiny_85_Main.c
 *
 *  Created on: Sep 16, 2021
 *      Author: Start1
 */

#include"MCAL/AT85_DIO/AT85_DIO_Interface.h"


#include "util/delay.h"
int main(){
	pinMode(PIN0,INPUT);
	pinMode(PIN1,OUTPUT);
	digitalWrite(PIN0, HIGH);
	while(1){
if(digitalRead(PIN0)==0){
	digitalWrite(PIN1, HIGH);

}else{digitalWrite(PIN1, LOW);

}
	}
}


