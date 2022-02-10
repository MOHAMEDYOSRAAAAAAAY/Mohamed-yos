#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "EXTI_InterFace.h"
#include "EXTI_Privet.h"
#include "EXTI_Config.h"
#include "../GIE/GIE_InterFace.h"

//static void(*Global_ptr[3]) (void)={NULL,NULL,NULL};

static void(*Global_ptr0) (void)=NULL;
static void(*Global_ptr1) (void)=NULL;
static void(*Global_ptr2) (void)=NULL;
void EXTI_voidINT0Init(void)
{
	
#if INT0_STATUS ==EXTI_ENABLE
	Set_Bit(GICR, GICR_INT0);
#elif INT0_STATUS ==EXTI_DISABLE
Clr_Bit(GICR, GICR_INT0);
#else
	
#error "Error INT0"
#endif
}

void EXTI_voidINT1Init(void)
{

#if INT1_STATUS ==EXTI_ENABLE
	Set_Bit(GICR, GICR_INT1);
#elif INT1_STATUS ==EXTI_DISABLE
Clr_Bit(GICR, GICR_INT1);
#else

#error "Error INT1"
#endif
}
void EXTI_voidINT2Init(void)
{

#if INT2_STATUS ==EXTI_ENABLE
	Set_Bit(GICR, GICR_INT2);
#elif INT2_STATUS ==EXTI_DISABLE
Clr_Bit(GICR, GICR_INT2);
#else

#error "Error INT2"
#endif
}
void EXTI_voidINT0Status (u8 Copy_u8InterruptStatus)
{
	switch (Copy_u8InterruptStatus)
	{

		case INT0_ENABLE :Set_Bit(GICR, GICR_INT0);break;
		case INT0_DISABLE :Clr_Bit(GICR, GICR_INT0);break;

		default :break;
	}
}
void EXTI_voidINT1Status (u8 Copy_u8InterruptStatus)
{
	switch (Copy_u8InterruptStatus)
	{

		case INT1_ENABLE :Set_Bit(GICR, GICR_INT1);break;
		case INT1_DISABLE :Clr_Bit(GICR, GICR_INT1);break;

		default :break;
	}
}
void EXTI_voidINT2Status (u8 Copy_u8InterruptStatus)
{
	switch (Copy_u8InterruptStatus)
	{

		case INT2_ENABLE :Set_Bit(GICR, GICR_INT2);break;
		case INT2_DISABLE :Clr_Bit(GICR, GICR_INT2);break;

		default :break;
	}
}
	void INT0_SetCallBack(void (*PTR0)(void))
	{

	//	Global_ptr[0] =PTR;
		Global_ptr0 =PTR0;
	}
	void INT1_SetCallBack(void (*PTR1)(void))
		{

		//	Global_ptr[1] =PTR;
			Global_ptr1 =PTR1;
		}
	void INT2_SetCallBack(void (*PTR2)(void))
		{

		//	Global_ptr[2] =PTR;
			Global_ptr2 =PTR2;
		}
void EXTI_voidINT0SenseControll (u8 Copy_u8ControllStatus)/////////////////////////POST
{
	switch (Copy_u8ControllStatus)
	{
		case RISING :Set_Bit(MCUCR,MCUCR_ISC01 );
			         Set_Bit(MCUCR,MCUCR_ISC00);break;
		case FALLING :Set_Bit(MCUCR,MCUCR_ISC01);
						Clr_Bit(MCUCR,MCUCR_ISC00);break;
		case LOW_LEVEL :Clr_Bit(MCUCR,MCUCR_ISC01);
						Clr_Bit(MCUCR,MCUCR_ISC00);break;
		case ON_CHANGE :Clr_Bit(MCUCR,MCUCR_ISC01);
						Set_Bit(MCUCR,MCUCR_ISC00);break;

		default :break;
	}
}
void EXTI_voidINT1SenseControll (u8 Copy_u8ControllStatus)/////////////////////////POST
	{
		switch (Copy_u8ControllStatus)
		{
			case RISING :Set_Bit(MCUCR,MCUCR_ISC11 );
				         Set_Bit(MCUCR,MCUCR_ISC10);break;
			case FALLING :Set_Bit(MCUCR,MCUCR_ISC11);
							Clr_Bit(MCUCR,MCUCR_ISC10);break;
			case LOW_LEVEL :Clr_Bit(MCUCR,MCUCR_ISC11);
							Clr_Bit(MCUCR,MCUCR_ISC10);break;
			case ON_CHANGE :Clr_Bit(MCUCR,MCUCR_ISC11);
							Set_Bit(MCUCR,MCUCR_ISC10);break;

			default :break;
		}
	}
		void EXTI_voidINT2SenseControll (u8 Copy_u8ControllStatus)/////////////////////////POST
			{
				switch (Copy_u8ControllStatus)
				{
					case RISING :Set_Bit(MCUCSR,MCUCSR_ISC2 );
						        break;
					case FALLING :
									Clr_Bit(MCUCSR,MCUCSR_ISC2);break;

					default :break;
				}




}
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(Global_ptr0 !=NULL)
	{
		//Global_ptr[0]();
		Global_ptr0();
	}
	else{
		}
	}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(Global_ptr1 !=NULL)
	{
Global_ptr1();
	}
	else{
		}
	}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(Global_ptr2 !=NULL)
	{

Global_ptr2();
	}
	else{
		}
	}

	

