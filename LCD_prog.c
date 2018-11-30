//author: ASMAA SOBHY
#include "LCD_types.h"
#include "LCD_priv.h"
#include "DIO_priv.h"
#include "LCD_cfg.h"
#include <util/delay.h>

void LCD_init(void){
	#if RS_E_Port== PORTA
	DDRA|=((1<<E)|(1<<RS));
	PORTA|=(1<<E);
	PORTA&=~(1<<RS);
	#elif RS_E_Port == PORTB
	DDRB|=((1<<E)|(1<<RS));
	PORTB|=(1<<E);
	PORTB&=~(1<<RS);
	#elif RS_E_Port == PORTC
	DDRC|=((1<<E)|(1<<RS));
	PORTC|=(1<<E);
	PORTC&=~(1<<RS);
	#elif RS_E_Port == PORTD
	DDRD|=((1<<E)|(1<<RS));
	PORTD|=(1<<E);
	PORTD&=~(1<<RS);
	#endif

	#if DataPort == PORTA
		#if LCD_wire ==8
		DDRA=OUTPUT;
		PORTA=0x38;
		#elif LCD_wire ==4
			#if four_Wire_nibble == HIGH_nibble
			DDRA|=((1<7)|(1<<6)|(1<<5)|(1<<4));
			#elif four_Wire_nibble == LOW_nibble
			DDRA|=((1<3)|(1<<2)|(1<<1)|(1<<0));
			#endif
		#endif
	#elif DataPort == PORTB
		#if LCD_wire ==8
		DDRB=OUTPUT;
		PORTB=0x38;
		#elif LCD_wire ==4
			#if four_Wire_nibble == HIGH_nibble
			DDRB|=((1<7)|(1<<6)|(1<<5)|(1<<4));
			#elif four_Wire_nibble == LOW_nibble
			DDRB|=((1<3)|(1<<2)|(1<<1)|(1<<0));
			#endif
		#endif
	//kmly......
	#endif

PORTB=0x01;
_delay_ms(5);
PORTB=0x02;
_delay_ms(5);
PORTB=0x0F;
_delay_us(100);
PORTB=0x14;
_delay_us(100);
}

void LCD_write(u8 DATA){
	#if RS_E_Port == PORTA
	PORTA|=(1<<RS);
	#elif RS_E_Port == PORTB
	PORTB|=(1<<RS);
	#elif RS_E_Port == PORTC
	PORTC|=(1<<RS);
	#elif RS_E_Port == PORTD
	PORTD|=(1<<RS);
	#endif
	
	#if DataPort == PORTA
	PORTA=DATA;
	#elif DataPort == PORTB
	PORTB=DATA;
	#elif DataPort == PORTC
	PORTC=DATA;
	#elif DataPort == PORTD
	PORTD=DATA;
	#endif
}