/*
 * SetupsMicro.c
 *
 * Created: 10/04/2024 23:45:59
 *  Author: PC
 */ 
#include "SetupsMicro.h"

void SetupEntrada(uint8_t PuertoEntrada, uint8_t PinEntrada){
	if (PuertoEntrada == Todo)
	{
		switch (PinEntrada)
		{
			case B:
			DDRB = 0;
			PORTB = 0xFF;
			PCICR |= (1<<PCIE0);
			PCMSK0 |= 0xFF;
			break;
			case C:
			DDRC = 0;
			PORTC = 0xFF;
			PCICR |= (1<<PCIE1);
			PCMSK1 |= 0xFF;
			break;
			case D:
			DDRD = 0;
			PORTD = 0xFF;
			PCICR |= (1<<PCIE2);
			PCMSK2 |= 0xFF;
			break;
			default: break;
		}
	}
	else if (PuertoEntrada == B)
	{
		PCICR |= (1<<PCIE0);
		switch (PinEntrada) {
			case PINB0:
				DDRB &= ~(1<<PINB0);
				PORTB |= (1<<PINB0);
				PCMSK0 |= (1<<PCINT0);
				break;
			case PINB1:
				DDRB &= ~(1<<PINB1);
				PORTB |= (1<<PINB1);
				PCMSK0 |= (1<<PCINT1);
				break;
			case PINB2:
				DDRB &= ~(1<<PINB2);
				PORTB |= (1<<PINB2);
				PCMSK0 |= (1<<PCINT2);
				break;
			case PINB3:
				DDRB &= ~(1<<PINB3);
				PORTB |= (1<<PINB3);
				PCMSK0 |= (1<<PCINT3);
				break;
			case PINB4:
				DDRB &= ~(1<<PINB4);
				PORTB |= (1<<PINB4);
				PCMSK0 |= (1<<PCINT4);
				break;
			case PINB5:
				DDRB &= ~(1<<PINB5);
				PORTB |= (1<<PORTB5);
				PCMSK0 |= (1<<PCINT5);
				break;
			default:
				break;
		}
	}
	else if (PuertoEntrada == C)
	{
		PCICR |= (1<<PCIE1);
		switch (PinEntrada) {
			case PC0:
			DDRC &= ~(1<<PC0);
			PORTC |= (1<<PC0);
			PCMSK1 |= (1<<PCINT8);
			break;
			case PC1:
			DDRC &= ~(1<<PC1);
			PORTC |= (1<<PC1);
			PCMSK1 |= (1<<PCINT9);
			break;
			case PC2:
			DDRC &= ~(1<<PC2);
			PORTC |= (1<<PC2);
			PCMSK1 |= (1<<PCINT10);
			break;
			case PC3:
			DDRC &= ~(1<<PC3);
			PORTC |= (1<<PC3);
			PCMSK1 |= (1<<PCINT11);
			break;
			case PC4:
			DDRC &= ~(1<<PC4);
			PORTC |= (1<<PC4);
			PCMSK1 |= (1<<PCINT12);
			break;
			case PC5:
			DDRC &= ~(1<<PC5);
			PORTC |= (1<<PC5);
			PCMSK1 |= (1<<PCINT13);
			break;
			default: break;
		}
	}
	else if (PuertoEntrada == D)
	{
		PCICR |= (1<<PCIE2);
		switch (PinEntrada) {
			case PD0:
			DDRD &= ~(1<<PD0);
			PORTD |= (1<<PD0);
			PCMSK2 |= (1<<PCINT16);
			break;
			case PD1:
			DDRD &= ~(1<<PD1);
			PORTD |= (1<<PD1);
			PCMSK2 |= (1<<PCINT17);
			break;
			case PD2:
			DDRD &= ~(1<<PD2);
			PORTD |= (1<<PD2);
			PCMSK2 |= (1<<PCINT18);
			break;
			case PD3:
			DDRD &= ~(1<<PD3);
			PORTD |= (1<<PD3);
			PCMSK2 |= (1<<PCINT19);
			break;
			case PD4:
			DDRD &= ~(1<<PD4);
			PORTD |= (1<<PD4);
			PCMSK2 |= (1<<PCINT20);
			break;
			case PD5:
			DDRD &= ~(1<<PD5);
			PORTD |= (1<<PD5);
			PCMSK2 |= (1<<PCINT21);
			break;
			case PD6:
			DDRD &= ~(1<<PD6);
			PORTD |= (1<<PD6);
			PCMSK2 |= (1<<PCINT22);
			break;
			case PD7:
			DDRD &= ~(1<<PD7);
			PORTD |= (1<<PD7);
			PCMSK2 |= (1<<PCINT23);
			break;
			default: break;
		}
	}
}

void SetupSalida(uint8_t PuertoSalida ,uint8_t PinSalida){
	if (PuertoSalida == Todo)
	{
		switch (PinSalida)
		{
			case B:
			DDRB = 0xFF;
			PORTB = 0;
			break;
			case C:
			DDRC = 0xFF;
			PORTC = 0;
			break;
			case D:
			DDRD = 0xFF;
			PORTD = 0;
			break;
			default: break;
		}
	}
	else if (PuertoSalida == B)
	{
		switch (PinSalida) {
			case PINB0:
			DDRB |= (1<<PINB0);
			PORTB &= ~(1<<PINB0);
			break;
			case PINB1:
			DDRB |= (1<<PINB1);
			PORTB &= ~(1<<PINB1);
			break;
			case PINB2:
			DDRB |= (1<<PINB2);
			PORTB &= ~(1<<PINB2);
			break;
			case PINB3:
			DDRB |= (1<<PINB3);
			PORTB &= ~(1<<PINB3);
			break;
			case PINB4:
			DDRB |= (1<<PINB4);
			PORTB &= ~(1<<PINB4);
			break;
			case PINB5:
			DDRB |= (1<<PINB5);
			PORTB &= ~(1<<PINB5);
			break;
			default:break;
		}
	}
	else if (PuertoSalida == C)
	{
		switch (PinSalida) {
			case PC0:
			DDRC |= (1<<PC0);
			PORTC &= ~(1<<PC0);
			break;
			case PC1:
			DDRC |= (1<<PC1);
			PORTC &= ~(1<<PC1);
			break;
			case PC2:
			DDRC |= (1<<PC2);
			PORTC &= ~(1<<PC2);
			break;
			case PC3:
			DDRC |= (1<<PC3);
			PORTC &= ~(1<<PC3);
			break;
			case PC4:
			DDRC |= (1<<PC4);
			PORTC &= ~(1<<PC4);
			break;
			case PC5:
			DDRC |= (1<<PC5);
			PORTC &= ~(1<<PC5);
			break;
			default:break;
		}
	}
	else if (PuertoSalida == D)
	{
		switch (PinSalida) {
			case PD0:
			DDRD |= (1<<PD0);
			PORTD &= ~(1<<PD0);
			break;
			case PD1:
			DDRD |= (1<<PD1);
			PORTD &= ~(1<<PD1);
			break;
			case PD2:
			DDRD |= (1<<PD2);
			PORTD &= ~(1<<PD2);
			break;
			case PD3:
			DDRD |= (1<<PD3);
			PORTD &= ~(1<<PD3);
			break;
			case PD4:
			DDRD |= (1<<PD4);
			PORTD &= ~(1<<PD4);
			break;
			case PD5:
			DDRD |= (1<<PD5);
			PORTD &= ~(1<<PD5);
			break;
			case PD6:
			DDRD |= (1<<PD6);
			PORTD &= ~(1<<PD6);
			break;
			case PD7:
			DDRD |= (1<<PD7);
			PORTD &= ~(1<<PD7);
			break;
			default:break;
		}
	}
}

void SetupTimer0(uint16_t Prescaler0, uint8_t Desvordamiento0 ){
	switch (Prescaler0)
	{
		case 0:
		TCCR0B |= (1<<CS00);
		break;
		case 8:
		TCCR0B |= (1<<CS01);
		break;
		case 64:
		TCCR0B |= (1<<CS00)|(1<<CS01);
		break;
		case 256:
		TCCR0B |= (1<<CS02);
		break;
		case 1024:
		TCCR0B |= (1<<CS00)|(1<<CS02);
		break;
	}
	
	TCNT0 = Desvordamiento0;
	
	TIMSK0 |= (1<<TOIE0);
}

void SetupTimer1(uint16_t Prescaler1, uint16_t Desvordamiento1){
	switch (Prescaler1)
	{
		case 0:
		TCCR1B |= (1<<CS10);
		break;
		case 8:
		TCCR1B |= (1<<CS11);
		break;
		case 64:
		TCCR1B |= (1<<CS10)|(1<<CS11);
		break;
		case 256:
		TCCR1B |= (1<<CS12);
		break;
		case 1024:
		TCCR1B |= (1<<CS10)|(1<<CS12);
		break;
	}
	
	TCNT0 = Desvordamiento1;
	
	TIMSK1 |= (1<<TOIE1);
}

void SetupTimer2(uint16_t Prescaler2, uint8_t Desvordamiento2, uint8_t Cristal){
	switch (Prescaler2)
	{
		case 0:
		TCCR2B |= (1<<CS20);
		break;
		case 8:
		TCCR2B |= (1<<CS21);
		break;
		case 64:
		TCCR2B |= (1<<CS20)|(1<<CS21);
		break;
		case 256:
		TCCR2B |= (1<<CS22);
		break;
		case 1024:
		TCCR2B |= (1<<CS20)|(1<<CS22);
		break;
	}
	
	TCNT2 = Desvordamiento2;
	
	TIMSK2 |= (1<<TOIE2);
	
	if (Cristal == Externo)
	{
		ASSR |= (1<<AS2);
	}
	if (Cristal == Interno)
	{
		ASSR &= ~(1<<AS2);
	}
}

void SetupADC(uint8_t PinADC){
	switch (PinADC)
	{
		case PC0 :
		DIDR0 |= (1<<ADC0D);
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		break;
		case PC1 :
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX0);
		DIDR0 |= (1<<ADC1D);
		break;
		case PC2 :
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX1);
		DIDR0 |= (1<<ADC2D);
		break;
		case PC3 :
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX0)|(1<<MUX1);
		DIDR0 |= (1<<ADC3D);
		break;
		case PC4 :
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2);
		DIDR0 |= (1<<ADC4D);
		break;
		case PC5 :
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2)|(1<<MUX0);
		DIDR0 |= (1<<ADC5D);
		break;
		case PC6 :
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2)|(1<<MUX1);
		break;
		case PC7 :
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2)|(1<<MUX1)|(1<<MUX0);
		break;
	}
	//JUSTIFICACION IZQUIERDA
	ADMUX |= (1<<ADLAR);
	//REFERENCIA INTERNA
	ADMUX |= (1<<REFS0);
	// HABILITAR INTERRUPCION
	ADCSRA |= (1<<ADIE);
	//PRESCALER 128
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	//HABILITAR
	ADCSRA |= (1<<ADEN);
}

void SetupPWM0(uint8_t ModoPWM0, uint8_t Sentido0, uint8_t SaidaPMW0, uint16_t PrescalerPWM0){
	
}

void SetupPWM1(uint8_t ModoPWM1, uint8_t Sentido1, uint8_t SaidaPMW1, uint16_t PrescalerPWM1){
	//MODOS
	switch (ModoPWM1)
	{
		case Phase8:
			TCCR1A|=(1<<WGM10);
			break;
		case Phase9:
			TCCR1A|=(1<<WGM11);
			break;
		case Phase10:
			TCCR1A|=(1<<WGM10)|(1<<WGM11);
			break;
		case PhaseICR:
			TCCR1B|=(1<<WGM13);
			break;
		case PhaseOCR:
			TCCR1B|=(1<<WGM13);
			TCCR1A |=(1<<WGM12);
			break;
		case Fast8:
			TCCR1B|=(1<<WGM12);
			TCCR1A|=(1<<WGM10);
			break;
		case Fast9:
			TCCR1B|=(1<<WGM12);
			TCCR1A|=(1<<WGM11);
			break;
		case Fast10:
			TCCR1B|=(1<<WGM12);
			TCCR1A|=(1<<WGM10)|(1<<WGM11);
			break;
		case FastICR:
			TCCR1B|=(1<<WGM13)|(1<<WGM12);
			TCCR1A|=(1<<WGM11);
			break;
		case FastOCR:
			TCCR1B|=(1<<WGM13)|(1<<WGM12);
			TCCR1A|=(1<<WGM11)|(1<<WGM10);
			break;
		default:
			break;
	}
	// SENTIDO Y SALIDA
	if ((ModoPWM1==Fast8)|(ModoPWM1==Fast9)|(ModoPWM1==Fast10)|(ModoPWM1==FastICR)|(ModoPWM1==FastOCR))
	{
		switch (SaidaPMW1)
		{
			case A:
				switch (Sentido1)
				{
					case Positivo:
						TCCR1A|=(1<<COM1A1);
						break;
					case Invertido:
						TCCR1A|=(1<<COM1A1)|(1<<COM1A0);
						break;
					default:
						break;
				}
				DDRB |= (1<<PINB1);
				PORTB &= (~(1<<PINB1));
				//TIMSK1 |= (1<<OCIE1A);
				break;
			case B:
				switch (Sentido1)
				{
					case Positivo:
						TCCR1A|=(1<<COM1B1);
						break;
					case Invertido:
						TCCR1A|=(1<<COM1B1)|(1<<COM1B0);
						break;
				}
				DDRB |= (1<<PINB2);
				PORTB &= (~(1<<PINB2));
				//TIMSK1 |= (1<<OCIE1B);
				break;
			default:
				break;
		}
	}
	// PRESCALER
	switch (PrescalerPWM1)
	{
		case 0:
			TCCR1B |= (1<<CS10);
			break;
		case 8:
			TCCR1B |= (1<<CS11);
			break;
		case 64:
			TCCR1B |= (1<<CS10)|(1<<CS11);
			break;
		case 256:
			TCCR1B |= (1<<CS12);
			break;
		case 1024:
			TCCR1B |= (1<<CS10)|(1<<CS12);
			break;
		default:
			break;
	}
	//TIMSK1 |= (1<<TOIE1);
}

void SetupPWM2(uint8_t ModoPWM2, uint8_t Sentido2, uint8_t SaidaPMW2, uint16_t PrescalerPWM2){
	//MODOS
	switch (ModoPWM2)
	{
		case Phase8:
		TCCR2A|=(1<<WGM20);
		break;
		case PhaseOCR:
		TCCR2B|=(1<<WGM20);
		TCCR2A |=(1<<WGM22);
		break;
		case Fast8:
		TCCR2A|=(1<<WGM20)|(1<<WGM21);
		break;
		case FastOCR:
		TCCR2B|=(1<<WGM22);
		TCCR2A|=(1<<WGM21)|(1<<WGM20);
		break;
	}
	// SENTIDO Y SALIDA
	if ((ModoPWM2==Fast8)|(ModoPWM2==Fast9)|(ModoPWM2==Fast10)|(ModoPWM2==FastICR)|(ModoPWM2==FastOCR))
	{
		switch (SaidaPMW2)
		{
			case A:
			switch (Sentido2)
			{
				case Positivo:
				TCCR2A|=(1<<COM2A1);
				break;
				case Invertido:
				TCCR2A|=(1<<COM2A1)|(1<<COM2A0);
				break;
			}
			DDRB |= (1<<PINB3);
			PORTB &= (~(1<<PINB3));
			//TIMSK2 |= (1<<OCIE2A);
			break;
			case B:
			switch (Sentido2)
			{
				case Positivo:
				TCCR2A|=(1<<COM2B1);
				break;
				case Invertido:
				TCCR2A|=(1<<COM2B1)|(1<<COM2B0);
				break;
			}
			DDRD |= (1<<PD3);
			PORTD &= (~(1<<PD3));
			//TIMSK2 |= (1<<OCIE2B);
			break;
		}
	}
	// PRESCALER
	switch (PrescalerPWM2)
	{
		case 0:
		TCCR2B |= (1<<CS20);
		break;
		case 8:
		TCCR2B |= (1<<CS21);
		break;
		case 32:
		TCCR2B |= (1<<CS20)|(1<<CS21);
		break;
		case 64:
		TCCR2B |= (1<<CS22);
		break;
		case 128:
		TCCR2B |= (1<<CS22)|(1<<CS20);
		break;
		case 256:
		TCCR2B |= (1<<CS22)|(1<<CS21);
		break;
		case 1024:
		TCCR2B |= (1<<CS20)|(1<<CS22)|(1<<CS21);
		break;
	}
	//TIMSK2 |= (1<<TOIE2);
}

void SetupAUART(uint16_t ModoUART, uint16_t FrecuencaUART, uint8_t Paridad, uint8_t Largo){
	UCSR0B |= (1<<RXCIE0)|(1<<TXEN0)|(1<<RXEN0);
	switch (ModoUART)
	{
	case Normal:
		switch (FrecuencaUART)
		{
		case 2400:
			UBRR0 = 416; 
			break;
		case 4800:
			UBRR0 = 207;
			break;
		case 9600:
			UBRR0 = 103;
			break;
		case 14400:
			UBRR0 = 68;
			break;
		}
		UCSR0A &= ~(1<<U2X0);
		break;
	case Turbo:
		switch (FrecuencaUART)
		{
		case 2400:
			UBRR0 = 832;
			break;
		case 4800:
			UBRR0 = 416;
			break;
		case 9600:
			UBRR0 = 207;
			break;
		case 14400:
			UBRR0 = 138;
			break;
		}
		UCSR0A |= (1<<U2X0);
		break;
	}
	switch (Paridad)
	{
	case Par:
		UCSR0C |= (1<<UPM01);
		break;
	case Impar:
		UCSR0C |= (1<<UPM01)|(1<<UPM00);
		break;
	case Ninguno:
		UCSR0C &= ~((1<<UPM01)|(1<<UPM00));
		break;
	}
	switch (Largo)
	{
	case 7:
	UCSR0C |= (1<<UCSZ01);
		break;
	case 8:
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
		break;
	}
}