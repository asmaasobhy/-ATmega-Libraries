//author: ASMAA SOBHY
#include "ADC_types.h"
#include "ADC_priv.h"
#include "ADC_cfg.h"


void ADC_init(void){
	ADCSRA|=(1<<ADEN);
	#if ADC_Prescaler == CK_2
	ADCSRA|=(1<<ADPS0);
	#elif ADC_Prescaler == CK_4
	ADCSRA|=(1<<ADPS1);
	#elif ADC_Prescaler == CK_8
	ADCSRA|=((1<<ADPS0)|(1<<ADPS1));
	#elif ADC_Prescaler == CK_16
	ADCSRA|=(1<<ADPS2);
	#elif ADC_Prescaler == CK_32
	ADCSRA|=((1<<ADPS0)|(1<<ADPS2));
	#elif ADC_Prescaler == CK_64
	ADCSRA|=((1<<ADPS1)|(1<<ADPS2));
	#elif ADC_Prescaler == CK_128
	ADCSRA|=((1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2));
	#endif

	#if RefVolt == AVCC
	ADMUX|=(1<<REFS0);
	#elif RefVolt == AREF
	ADMUX&=~(REFS0);
	ADMUX&=~(REFS1);
	#elif RefVolt == INTERNAL
	ADMUX|=((1<<REFS0)|(1<<REFS1));
	#endif

	ADMUX|=(1<<ADLAR); //left justified
}

u8 AnalogRead(u8 PinNum){
	switch(PinNum){
		case 0:
			ADMUX&=~(1<<MUX0);
			ADMUX&=~(1<<MUX1);
			ADMUX&=~(1<<MUX2);
			break;
		case 1:
			ADMUX|=(1<<MUX0);
			ADMUX&=~(1<<MUX1);
			ADMUX&=~(1<<MUX2);
			break;
		case 2:
			ADMUX|=(1<<MUX1);
			ADMUX&=~(1<<MUX0);
			ADMUX&=~(1<<MUX2);
			break;
		case 3:
			ADMUX|=((1<<MUX0)|(1<<MUX1));
			ADMUX&=~(1<<MUX2);
			break;
		case 4:
			ADMUX|=(1<<MUX2);
			ADMUX&=~(1<<MUX0);
			ADMUX&=~(1<<MUX1);
			break;
		case 5:
			ADMUX|=((1<<MUX0)|(1<<MUX2));
			break;
		case 6:
			ADMUX|=((1<<MUX1)|(1<<MUX2));
			ADMUX&=~(1<<MUX0);
			break;
		case 7:
			ADMUX|=((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
			break;
		}
		
ADCSRA|=(1<<ADSC);
while(!(ADCSRA&=(1<<ADIF)));
return ADCH;
}