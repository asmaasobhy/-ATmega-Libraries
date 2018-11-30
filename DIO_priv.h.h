//author: ASMAA SOBHY
#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_   //header file guard

#define PORTA *((volatile u8 *)0x1B)
#define DDRA *((volatile u8 *)0x1A)
#define PINA *((volatile u8 *)0x19)

#define PORTB *((volatile u8 *)0x18)
#define DDRB *((volatile u8 *)0x17)
#define PINB *((volatile u8 *)0x16)

#define PORTC *((volatile u8 *)0x15)
#define DDRC *((volatile u8 *)0x14)
#define PINC *((volatile u8 *)0x13)

#define PORTD *((volatile u8 *)0x12)
#define DDRD *((volatile u8 *)0x11)
#define PIND *((volatile u8 *)0x10)

#define INPUT 0x00

#define OUTPUT 0xFF

#endif