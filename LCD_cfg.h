//author: ASMAA SOBHY
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

//RS in PORTA PIN0
//E in PORTA PIN1
//DATA PORTB
#define DataPort PORTB //choices(PORTA,PORTB,PORTC,PORTD)
#define RS_E_Port PORTA //choices(PORTA,PORTB,PORTC,PORTD)
#define RS 0
#define E  1
#define LCD_wire 8 //choices (8,4)
#define four_Wire_nibble HIGH_nibble //choices(HIGH_nibble,LOW_nibble)
#endif