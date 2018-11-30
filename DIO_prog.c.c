//author: ASMAA SOBHY
#include "types.h"
#include "priv.h"
#include "cfg.h"
#include "bitop.h"
void PinDir(u8 PortNum,u8 PinNum,u8 Value){
	switch(PortNum){
		
		case 'a':
		case 'A':
		switch(Value){
		case 'i':
		case 'I':
			Clear_Bit(DDRA,PinNum);
		break;
		case 'o':
		case 'O':
			Set_Bit(DDRA,PinNum);
		break;
	    }
	    break;

		case 'b':
		case 'B':
		switch(Value){
		case 'i':
		case 'I'
			Clear_Bit(DDRB,PinNum);
		break;
		case 'o':
		case 'O':
			Set_Bit(DDRB,PinNum);
		break;
		}
		break;


		case 'c':
		case 'C':
		switch(Value){	
		case 'i':
		case 'I':
			Clear_Bit(DDRC,PinNum);
		break;
		case 'o':
		case 'O':
			Set_Bit(DDRC,PinNum);
		break;
		}
		break;	

		case 'd':
		case 'D':
		switch(Value){	
		case 'i':
		case 'I':
			Clear_Bit(DDRD,PinNum);
		break;
		case 'o':
		case 'O':
			Set_Bit(DDRD,PinNum);
		break;
		}
		break;
	}

}

void WritePin(u8 PortNum,u8 PinNum,u8 Value){
	switch(PortNum){
		case 'a':
		case 'A':
			switch(Value){
				case 0:
					Clear_Bit(PORTA,PinNum);
					break;
				case 1:
					Set_Bit(PORTA,PinNum);
					break;
			}
		break;

		case 'b':
		case 'B':
			switch(Value){
				case 0:
					Clear_Bit(PORTB,PinNum);
				break;
				case 1:
					Set_Bit(PORTB,PinNum);
				break;
			}
		break;

		case 'c':
		case 'C':
			switch(Value){
				case 0:
				Clear_Bit(PORTC,PinNum);
				break;
				case 1:
				Set_Bit(PORTC,PinNum);
				break;
				}
		break;

		case 'd':
		case 'D':
			switch(Value){
				case 0:
				Clear_Bit(PORTD,PinNum);
				break;
				case 1:
				Set_Bit(PORTD,PinNum);
				break;
			}
		break;

	}
}

void ReadPin(u8 PortNum,u8 PinNum,u8 *Value){
	switch(PortNum){
		case 'a':
		case 'A':
			*Value=Get_Bit(PINA,PinNum);
		break;

		case 'b':
		case 'B':
			*Value=Get_Bit(PINB,PinNum);
		break;

		case 'c':
		case 'C':
			*Value=Get_Bit(PINC,PinNum);
		break;

		case 'd':
		case 'D':
			*Value=Get_Bit(PIND,PinNum);
		break;

	}
}
void PullUp(u8 PortNum,u8 PinNum){
	switch(PortNum){
		case 'a':
		case 'A':
			if (Get_Bit(DDRA,PinNum)==0)
			{
				Set_Bit(PORTA,PinNum);
			}
			else{#warning invalid pin}
		break;

		case 'b':
		case 'B':
			if (Get_Bit(DDRB,PinNum)==0)
			{
				Set_Bit(PORTB,PinNum);
			}
			else{#warning invalid pin}
		break;

		case 'c':
		case 'C':
			if (Get_Bit(DDRC,PinNum)==0)
			{
				Set_Bit(PORTC,PinNum);
			}
			else{#warning invalid pin}
		break;

		case 'd':
		case 'D':
			if (Get_Bit(DDRAD,PinNum)==0)
			{
				Set_Bit(PORTD,PinNum);
			}
			else{#warning invalid pin}
		break;
	}
}