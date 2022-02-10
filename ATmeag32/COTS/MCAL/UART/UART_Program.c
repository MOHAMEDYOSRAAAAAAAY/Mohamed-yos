#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "UART_Privet.h"
#include "UART_Interface.h"
#include "UART_Confeg.h"


void UART_Init(void)
{
UCSRC = 0b10000110;
UCSRB = 0b00011000;
Clr_Bit(UBRRL,UBRRH_URSEL);
UBRRH =(u8) 0x00;
UBRRL =(u8) 103;
Set_Bit(UCSRA,UCSRA_U2X);

}

void UART_Send( u8 Copy_localu8UARTVal)
{
while(Get_Bit(UCSRA,UCSRA_UDRE)==0);
Set_Bit(UCSRA,UCSRA_UDRE);
	UDR = Copy_localu8UARTVal;
	while(Get_Bit(UCSRA,UCSRA_TXC)==0);
	Set_Bit(UCSRA,UCSRA_TXC);
}


u8 UART_Get(void )
{while(Get_Bit(UCSRA,UCSRA_RXC)==0);
Set_Bit(UCSRA,UCSRA_RXC);
return UDR;

}
