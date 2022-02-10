#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
/************************INCLUDE TIMER****************/
//Don't forget TO define the time in the main
//Timer 0 only
#include"Timer_Interface.h"
#include"Timer_Privet.h"
#include"Timer_Config.h"
static void (* Glopal_PTR)(void)= NULL;
void TIMER_Init(void)

{

#if TIMER0_INTERRUPT_ENABLE == ENABLE
	Set_Bit(TIMSK,TIMSK_TIOE0);
#elif TIMER0_INTERRUPT_ENABLE == DESABLE
	Clr_Bit(TIMSK,TIMSK_TOIE0);
#else
#error "TIMER0_INTERRUPT_ENABLE Cnfigration ERROR"
#endif

#if TIMER0_MODE == NORMAL
	TCNR0 &=MODE_MASK;
#elif TIMER0_MODE == FAST_PWM
	TCCR0 &=MODE_MASK
			TCCR0 |=FAST_PWM;
#elif TIMER0_MODE == CTC
	TCCR0 &=MODE_MASK
			TCCR0 |=CTC;
#elif TIMER0_MODE == PHASE_CORRECT_PWM
	TCCR0 &=MODE_MASK
			TCCR0 |= PHASE_CORRECT_PWM;
#else
 #error "TIMER0_MODE Cnfigration ERROR"
#endif

#if TIMER0_ENABLE == ENABLE
	TCNR0 &=PRESCALLER_MASK ;
	TCNR0 |=TIMER_PRESCALLER ;
#elif TIMER0_ENABLE == DESABLE
	TCCR0&=PRESCALLER_MASK ;


#else
# error "TIMER0_ENABLE Cnfigration ERROR"
#endif
}
void TIMER_SetCallBack(void (* PTR) (void) ){

	Glopal_PTR= PTR;
}
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	Set_Bit(TIFR,TIFR_TOv0);
	if (Glopal_PTR!=0){
		Glopal_PTR();
	}
	else
	{}
}

