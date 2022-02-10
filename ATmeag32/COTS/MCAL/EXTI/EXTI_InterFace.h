/*
 * EXTI_EnterFace.h
 *
 *  Created on: Sep 15, 2021
 *      Author: Start1
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#include "STD_TYPES.h"
void INT0_SetCallBack(void (*PTR0)(void));
void EXTI_voidINT0Status(unsigned char );
void EXTI_voidINT0SenseControll (unsigned char);
void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT1Status (u8 Copy_u8InterruptStatus);
void INT1_SetCallBack(void (*PTR1)(void));
void EXTI_voidINT1SenseControll (u8 Copy_u8ControllStatus);
void INT2_SetCallBack(void (*PTR2)(void));
void EXTI_voidINT2SenseControll (u8 Copy_u8ControllStatus);
void EXTI_voidINT2Status (u8 Copy_u8InterruptStatus);
void EXTI_voidINT2Init(void);
#define INT0_ENABLE 1
#define INT0_DISABLE 0
#define RISING 0
#define FALLING 1
#define LOW_LEVEL 2
#define ON_CHANGE 3


#define MCUCSR_JTD 7
#define MCUCSR_ISC2 6
#define MCUCSR_JTRF 4
#define MCUCSR_WDRF 3
#define MCUCSR_BORF 2
#define MCUCSR_EXTRF 1
#define MCUCSR_PORF 0


#define MCUCR_SE 7
#define MCUCR_SM2 6
#define MCUCR_SM1 5
#define MCUCR_SM0 4
#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0

#define GICR_INT1 7
#define GICR_INT0 6
#define GICR_INT2 5
#define GICR_IVSEL 1
#define GICR_IVCE 0



#define GIFR_INTF1 7
#define GIFR_INTF0 6
#define GIFR_INTF2 5
#define INT2_ENABLE 1
#define INT2_DISABLE 0
#define INT1_ENABLE 1
#define INT1_DISABLE 0
#define INT0_ENABLE 1
#define INT0_DISABLE 0
#define RISING 0
#define FALLING 1
#define LOW_LEVEL 2
#define ON_CHANGE 3




#endif /* EXTI_INTERFACE_H_ */
