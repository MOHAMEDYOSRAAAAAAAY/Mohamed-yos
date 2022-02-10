#ifndef _TIMER_PRIVET_H_
#define _TIMER_PRIVET_H_
 
 #define TCNT0 (*((volatile u8 *)(0x52)))
 #define TCNR0 (*((volatile u8 *)(0x53)))
 #define OCR0 (*((volatile u8 *)(0x5C)))
 #define TIMSK (*((volatile u8 *)(0x59)))
 #define TIFR (*((volatile u8 *)(0x58)))

#define TCNR0_WGM01 3
#define TCNR0_COM00 4
#define TCNR0_COM01 5
#define TCNR0_WGM00 6
#define TCNR0_FOC0 7
#define TCNR0_CS02 2
#define TCNR0_CS01 1
#define TCNR0_CS00 0


#define TIMSK_TIOE0 0
#define TIMSK_OCIE0 1

#define TIFR_TOv0 0
#define TIFR_OCF0 1

#define ENABLE 1
#define DESABLE 0
#define PRESCALLER_MASK 0b11111000
#define MODE_MASK 0b10110111
#define NULL (void *)0
#endif

