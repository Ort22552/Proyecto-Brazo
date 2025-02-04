/*
 * Plantilla.c
 *
 * Created: 10/04/2024 22:05:28
 * Author : Josue Ortiz
 */ 
/*
	------------------------------------------------------
	DEFINICIONES, INCLUDES Y VARIABLES
	------------------------------------------------------
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
//#include <avr/eeprom.h>
#include <stdlib.h>
#include <util/delay.h>
#include "Setups/SetupsMicro.h"
#include "Utileria/Utileria.h"
uint8_t Menu = 0;
uint8_t tiempo;
uint8_t Jg1=0;
uint8_t Jg2=0;

/*
	------------------------------------------------------
	DEFINICION DE FUNCIONES
	------------------------------------------------------
*/

void Setup(void);
void Jug1LED(void);
void Jug2LED(void);


/*
	------------------------------------------------------
	MAIN-LOOP
	------------------------------------------------------
*/

int main(void)
{
    cli();
	Setup();
	sei();
	
    while (1) 
    {
		
		switch (Menu)
		{
		
		
		case 4:
			OCHOSEGMENTOS(2,B,0);
			_delay_ms(10);
			PORTB &= ~(1<<PORTB0);
			Jug1LED();
			Jug2LED();
				break;
		case 3:
			OCHOSEGMENTOS(1,B,0);
			_delay_ms(10);
			PORTB &= ~(1<<PORTB0);
			Jug1LED();
			Jug2LED();
			break;
		case 2:
			OCHOSEGMENTOS(0,B,0);
			_delay_ms(5);
			PORTB &= ~(1<<PORTB1);
			Jug1LED();
			Jug2LED();
			break;
		case 1:
			OCHOSEGMENTOS(5, B, 0);
				_delay_ms(1000);
			OCHOSEGMENTOS(4, B, 0);
				_delay_ms(1000);
			OCHOSEGMENTOS(3, B, 0);
				_delay_ms(1000);
			OCHOSEGMENTOS(2, B, 0);
				_delay_ms(1000);
			OCHOSEGMENTOS(1, B, 0);
				_delay_ms(1000);
			OCHOSEGMENTOS(0, B, 0);
				_delay_ms(1000);
			Menu=2;
			Jg1=0;
			Jg2=0;
			break;
		case 0:
			OCHOSEGMENTOS(8,B,0);
			break;
		}
    }
}

/*
	------------------------------------------------------
	PROGRAMACION DE FUNCIONES
	------------------------------------------------------
*/

void Setup(void){
	//Entradas
	SetupEntrada(C,PC0); //MENU
	SetupEntrada(C,PC1); //JUGADOR 1
	SetupEntrada(C,PC2); //JUGADOR 2 
	/*SetupEntrada(B, PORTB3);
	SetupEntrada(B,PORTB4);*/
	//Salidas
	SetupSalida(Todo, D); //Led manual
	SetupSalida(Todo,B);
	/*SetupSalida(B, PORTB0);
	SetupSalida(B, PORTB1);
	SetupSalida(B, PORTB2);*/
	
	
	
	//ADC
	//SetupADC(PC4); // Base
	
	//Comunicacion
	//SetupAUART(Normal, 9600, Ninguno, 8);
	//PWM
	//SetupPWM1(FastICR, Positivo, A, 1024);
	
		//ICR1=0x138; 
	//SetupPWM2(Fast8, Positivo, A, 1024SetupPWM2(Fast8, Positivo, B, 1024);
	//TIMER
	//SetupTimer0(1024, 250);
	
}

void Jug1LED(void){
	switch (Jg1)
	{
	case 0:
		PORTD &= ~(0xFF);
		PORTB |= (1<<PORTB1);
		_delay_ms(5); 
		PORTB &= ~(1<<PORTB1);
		break;
	case 1:
		PORTD &= ~(0xFF);
		PORTD |= (1<<PORTD0);
		PORTB |= (1<<PORTB1);
		_delay_ms(5);
		PORTB &= ~(1<<PORTB1);
		break;
	case 2:
		PORTD &= ~(0xFF);
		PORTD |= ((1<<PORTD0)|(1<<PORTD1));
		PORTB |= (1<<PORTB1);
		_delay_ms(5);
		PORTB &= ~(1<<PORTB1);
		break;
	case 3:
		PORTD &= ~(0xFF);
		PORTD |= ((1<<PORTD0)|(1<<PORTD1)|(1<<PORTD2));
		PORTB |= (1<<PORTB1);
		_delay_ms(5);
		PORTB &= ~(1<<PORTB1);
		break;
	case 4:
		PORTD &= ~(0xFF);
		PORTD |= 0x0F;
		PORTB |= (1<<PORTB1);
		_delay_ms(5);
		PORTB &= ~(1<<PORTB1);
		break;
	default:
		break;		
	}
}

void Jug2LED(void){
	switch (Jg2)
	{
		case 0:
			PORTD &= ~(0xFF);
			PORTB |= (1<<PORTB2);
			_delay_ms(5);
			PORTB &= ~(1<<PORTB2);
				break;
		case 1:
			PORTD &= ~(0xFF);
			PORTD |= (1<<PORTD4);
			PORTB |= (1<<PORTB2);
			_delay_ms(5);
			PORTB &= ~(1<<PORTB2);
				break;
		case 2:
			PORTD &= ~(0xFF);
			PORTD |= ((1<<PORTD4)|(1<<PORTD5));
			PORTB |= (1<<PORTB2);
			_delay_ms(5);
			PORTB &= ~(1<<PORTB2);
				break;
		case 3:
			PORTD &= ~(0xFF);
			PORTD |= ((1<<PORTD4)|(1<<PORTD5)|(1<<PORTD6));
			PORTB |= (1<<PORTB2);
			_delay_ms(5);
			PORTB &= ~(1<<PORTB2);
				break;
		case 4:
			PORTD &= ~(0xFF);
			PORTD |= 0xF0;
			PORTB |= (1<<PORTB2);
			_delay_ms(5);
			PORTB &= ~(1<<PORTB2);
				break;
		default:
			break;
	}
}



/*
	------------------------------------------------------
	INTERRUPCIONES
	------------------------------------------------------
*/
ISR(PCINT1_vect){
	if (Menu!=2)
	{
		if ((((PINC) & (1<<PINC0)) != (1<<PINC0)))
		{
			Menu=1;
		}
	}
	if (Menu == 2){
		if (((PINC) & (1<<PINC1)) != (1<<PINC1))
		{
			Jg1++;
			if (Jg1==4)
			{	
				Jg2=0;
				Menu=3;
			}
		}
		if (((PINC) & (1<<PINC2)) != (1<<PINC2))
		{
			Jg2++;
			if (Jg2==4)
			{
				Jg1=0;
				Menu=4;
			}
		}
	}
	PCIFR|=(1<<PCIF1);
}




/*ISR(PCINT0_vect){
	Menu=1;
	PCIFR|=(1<<PCIF0);
}*/