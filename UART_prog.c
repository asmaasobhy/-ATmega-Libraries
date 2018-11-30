//author: ASMAA SOBHY
#include "UART_types.h"
#include "UART_priv.h"
#include "UART_cfg.h"

void UART_init(void){
	if (Calc_UBRR1 <= 4095)
	{
		UBRRL=Calc_UBRR1;
		UBRRH=(Calc_UBRR1>>8);
	}
	else{
		UCSRA|=(1<<U2X);
		UBRRL=Calc_UBRR2;
		UBRRH=(Calc_UBRR2>>8);
	}
	UCSRB|=((1<<TXEN)|(1<<RXEN));
	UCSRC|=(1<<URSEL);
	UCSRC|=((1<<UCSZ0)|(1<<UCSZ1));
	
}

void UART_transmit(u8 DATA){
	while(!(UCSRA&=(1<<UDRE)){};
	UDR=DATA;
}

u8 UART_recieve(void){
	while(!(UCSRA&=(1<<RXC)){};
	return UDR;


}