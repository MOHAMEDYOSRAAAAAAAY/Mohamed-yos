#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "GIE_InterFace.h"
#include "GIE_Privet.h"
#include "GIE_Config.h"
void GIE_voidGlobalInterruptEnable(void){
	Set_Bit(SREG,SREG_I);
}
void GIE_voidGlobalInterruptDisable(void){
	Clr_Bit(SREG,SREG_I);
}
