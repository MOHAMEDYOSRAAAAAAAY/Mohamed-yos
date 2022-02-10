#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

#define DIV_BY_0 		0
#define DIV_BY_1 		1
#define DIV_BY_8 		2
#define DIV_BY_64 		3
#define DIV_BY_256 		4
#define DIV_BY_1024		5
#define FALLING_EDGE	6
#define RISING_EDGE 	7

#define NORMAL 				0
#define FAST_PWM 			1
#define CTC 				2
#define PHASE_CORRECT_PWM 	3
void TIMER_Init(void);
void TIMER_SetCallBack (void (*PTR)(void));
#endif
