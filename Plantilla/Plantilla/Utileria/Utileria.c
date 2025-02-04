/*
 * Uutileria.c
 *
 * Created: 23/01/2025 18:02:59
 *  Author: PC
 */ 
#include "Utileria.h"

void OCHOSEGMENTOS(uint8_t VALOR, uint8_t PUERTO, uint8_t PIN){
	switch (VALOR)
	{
	case 0:
		PORTD |= 0x3F;
		PORTD &= ~(1<<PIND6);
		break;
	case 1:
		PORTD |= 0x06;
		PORTD &= ~((1<<PIND0)|(1<<PIND3)|(1<<PIND4)|(1<<PIND5)|(1<<PIND6));
		break;
	case 2:
		PORTD |= 0x5B;
		PORTD &= ~((1<<PIND2)|(1<<PIND5));
		break;	
	case 3:
		PORTD |= 0x4F;
		PORTD &= ~((1<<PIND4)|(1<<PIND5));
		break;
	case 4:
		PORTD |= 0x66;
		PORTD &= ~((1<<PIND0)|(1<<PIND3)|(1<<PIND4));
		break;
	case 5:
		PORTD |= 0x6D;
		PORTD &= ~((1<<PIND1)|(1<<PIND4));
		break;
	case 6:
		PORTD |= 0x7D;
		PORTD &= ~((1<<PIND1));
		break;
	case 7:
		PORTD |= 0x07;
		PORTD &= ~((1<<PIND3)|(1<<PIND4)|(1<<PIND5)|(1<<PIND6));
		break;
	case 8:
		PORTD |= 0x7F;
		break;
	case 9:
		PORTD |= 0x6F;
		PORTD &= ~(1<<PD6);
		break;
	default:
		PORTD &= ~(0x7F);
		break;
	}
	switch (PUERTO)
	{
	case D: 
		PORTD |= (1<<PIND7);
		break;
	case B:
		switch (PIN)
		{
		case 0:
			PORTB |= (1<<PB0);
			break;
		case 1:
			PORTB |= (1<<PB1);
			break;
		case 2:
			PORTB |= (1<<PB2);
			break;
		case 3:
			PORTB |= (1<<PB3);
			break;
		case 4:
			PORTB |= (1<<PB4);
			break;
		case 5:
			PORTB |= (1<<PB5);
			break;
		default:
			break;
		}
		break;
	case C:
		switch (PIN)
		{
			case 0:
				PORTC |= (1<<PB0);
				break;
			case 1:
				PORTC |= (1<<PB1);
				break;
			case 2:
				PORTC |= (1<<PB2);
				break;
			case 3:
				PORTC |= (1<<PB3);
				break;
			case 4:
				PORTC |= (1<<PB4);
				break;
			case 5:
				PORTC |= (1<<PB5);
				break;
			default:
				break;
		}
		break; 
	default:
		break; 
	}
	
};
	

















