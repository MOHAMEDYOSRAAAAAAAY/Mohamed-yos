#include "SSD_Privet.h"
#include "SSD_Config.h"
#include <avr/io.h>


int SSD_Arr_1[10] = {
	 0b00111111,//0
	 0b00000110,//1
	 0b01011011,//2
	 0b01001111,//3
	 0b01100110,//4
	 0b01101101,//5
     0b01111101,//6
	 0b00000111,//7
	 0b01111111,//8
	 0b01101111 //9
};
int SSD_Arr_2[10] = {
	 0b10111111,//0
	 0b10000110,//1
	 0b11011011,//2
	 0b11001111,//3
	 0b11100110,//4
	 0b11101101,//5
     0b11111101,//6
	 0b10000111,//7
	 0b11111111,//8
	 0b11101111 //9
};
void SSD_INIT(void){
	SSD_DDR =0xff;
}
void SSD_Num_Diss(int n){
#if SSD_TYPE ==	COM_CATHOD
	int x=0,y=0;
	for( y = 0;y<10;y++){
	for( x = 0;x<10;x++){
		for(int c=0; c<100;c++){
	SSD_PORT = SSD_Arr_1[x];
	SSD_PORT = SSD_Arr_2[y];}}}
#elif 	SSD_TYPE ==	COM_ANOD
	int x=0,y=0;
		for( y = 0;y<10;y++){
		for( x = 0;x<10;x++){
			for(long int c=0; c<150000;c++){
		SSD_PORT = ~SSD_Arr_1[x];
		SSD_PORT = 0xff;
		SSD_PORT = ~SSD_Arr_2[y];
		SSD_PORT = 0xff;}}}
#endif
}
