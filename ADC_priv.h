//author: ASMAA SOBHY
#ifndef ADC_PRIV_H
#define ADC_PRIV_H

#define ADCL   *((volatile u8 *)0x78)
#define ADCH   *((volatile u8 *)0x79)

#define ADCSRA *((volatile u8 *)0x7A)
#define ADPS0    0
#define ADPS1    1
#define ADPS2    2
#define ADIE     3
#define ADIF     4
#define ADATE    5
#define ADSC     6
#define ADEN     7

#define ADMUX  *((volatile u8 *)0x7C)
#define MUX0     0
#define MUX1     1
#define MUX2     2
#define MUX3     3
#define MUX4     4
#define ADLAR    5
#define REFS0    6
#define REFS1    7

#define AVCC     0
#define AREF     1
#define INTERNAL 2

#define CLK_2    0
#define CLK_4    1
#define CLK_8    2
#define CLK_16   3
#define CLK_32   4
#define CLK_64   5
#define CLK_128  6

#endif