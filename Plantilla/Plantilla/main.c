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
#include <avr/eeprom.h>
#include <stdlib.h>
//#include <util/delay.h>
#include "Setups/SetupsMicro.h"
#define	Manual 0
#define Nube 1
#define Leer 2

const uint8_t Tabla[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
uint8_t TurnoPOT = 0; 
uint8_t POTBASE = 0; 
uint8_t POTBASEP = 0; 
uint8_t POT1 = 0; 
uint8_t POT1P = 0; 
uint8_t POT2 = 0; 
uint8_t POT2P = 0; 
uint8_t POTGARRA = 0; 
uint8_t POTGARRAP = 0; 
uint8_t Modo = 0;
uint8_t TurnoNube = 0;
uint8_t BotonNube = 0;
volatile uint8_t comodini=0;
char comodinc=0;
volatile uint8_t Potencimetro=0;
volatile uint8_t PotencimetroC=0;
volatile uint8_t PotencimetroD=0;
volatile uint8_t PotencimetroU=0;


/*
	------------------------------------------------------
	DEFINICION DE FUNCIONES
	------------------------------------------------------
*/

void Setup(void);
void Luzmenu(void);
void MandarP(char Letra);
void Actualizarnube(uint8_t emodo, uint8_t epotb ,uint8_t epot1 ,uint8_t epot2 ,uint8_t epotg , uint8_t ebotonnube, uint8_t ecambio);
void EEPROMP(uint8_t accion, uint8_t posicion);
uint8_t Traductor(uint8_t valor);


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
	//PORTB = 0xFF;
    while (1) 
    {
		Luzmenu();
		/*OCR1A=(POTBASE/6);
		OCR1B = (POT1/6);
		OCR2B = (POT2/6);
		OCR2A = (POTGARRA/6);*/
		OCR1A = 12.5+(POTBASE/10);
		OCR1B = 12.5+ (POT1/10);
		OCR2A = 12.5+(POT2/10);
		OCR2B = 12.5 +(POTGARRA/10);
/*		switch (TurnoPOT)
		{
			case 1:
			OCR1A = 12.5+(POTBASE/10);
			break;
			case 2:
			OCR1B = 12.5+ (POT1/15);
			break;
			case 0:
			OCR2B = 10 +(POT2/15);
			break;
			case 3:
			OCR2A = 12.5+(POTGARRA/30);
			break;
		}
		*/
    }
}

/*
	------------------------------------------------------
	PROGRAMACION DE FUNCIONES
	------------------------------------------------------
*/

void Setup(void){
	//Entradas
	SetupEntrada(C,PC0); //Posición 1
	SetupEntrada(C,PC1); //Posición 2
	SetupEntrada(C,PC2); //Posición 3
	SetupEntrada(C,PC3); //Posición 4
	SetupEntrada(B,PB5); //Modo
	//Salidas
	SetupSalida(B, PINB4); //Led manual
	SetupSalida(B, PINB0); //Led nube
	SetupSalida(D, PD4); //Led leer
	//ADC
	SetupADC(PC4); // Base
	SetupADC(PC5); // Servo 1
	SetupADC(PC6); // Servo 2
	SetupADC(PC7); // Garra
	//Comunicacion
	SetupAUART(Normal, 9600, Ninguno, 8);
	//PWM
	SetupPWM1(FastICR, Positivo, A, 1024);
	SetupPWM1(FastICR, Positivo, B, 1024); 
		ICR1=0x138; 
	SetupPWM2(Fast8, Positivo, A, 1024);
	SetupPWM2(Fast8, Positivo, B, 1024);
	//TIMER
	SetupTimer0(1024, 250);
	
}

void Luzmenu(void){
	switch(Modo)
	{
		case 0:
			PORTB |=(1<<PORTB4);
			PORTB &=(~(1<<PORTB0));
			PORTD &=(~(1<<PORTD4));
			break;
		case 1:
			PORTB &=(~(1<<PORTB4));
			PORTB |=(1<<PORTB0);
			PORTD &=(~(1<<PORTD4));
			break;
		case 2:
			PORTB &=(~(1<<PORTB4));
			PORTB &=(~(1<<PORTB0));
			PORTD |=(1<<PORTD4);
			break;
		default:
			break;
	}
}

void MandarP(char Letra){
	while(!(UCSR0A & (1<<UDRE0)));
		UDR0 = Letra;
}

void Actualizarnube(uint8_t emodo, uint8_t epotb ,uint8_t epot1 ,uint8_t epot2 ,uint8_t epotg , uint8_t ebotonnube, uint8_t ecambio){
	//mandar emodo
	MandarP(Tabla[emodo]);
	//mandar epotb
	Potencimetro = epotb;
	PotencimetroC = (Potencimetro/100) ;
	PotencimetroD = ((Potencimetro-(PotencimetroC*100))/10);
	PotencimetroU = (Potencimetro-((PotencimetroC*100)+(PotencimetroD*10)));
	MandarP(Tabla[PotencimetroC]);
	MandarP(Tabla[PotencimetroD]);
	MandarP(Tabla[PotencimetroU]);
	//mandar epot1
	Potencimetro = epot1;
	PotencimetroC = (Potencimetro/100) ;
	PotencimetroD = ((Potencimetro-(PotencimetroC*100))/10);
	PotencimetroU = (Potencimetro-((PotencimetroC*100)+(PotencimetroD*10)));
	MandarP(Tabla[PotencimetroC]);
	MandarP(Tabla[PotencimetroD]);
	MandarP(Tabla[PotencimetroU]);
	//mandar epot2
	Potencimetro = epot2;
	PotencimetroC = (Potencimetro/100) ;
	PotencimetroD = ((Potencimetro-(PotencimetroC*100))/10);
	PotencimetroU = (Potencimetro-((PotencimetroC*100)+(PotencimetroD*10)));
	MandarP(Tabla[PotencimetroC]);
	MandarP(Tabla[PotencimetroD]);
	MandarP(Tabla[PotencimetroU]);
	//mandar epotg
	Potencimetro = epotg;
	PotencimetroC = (Potencimetro/100) ;
	PotencimetroD = ((Potencimetro-(PotencimetroC*100))/10);
	PotencimetroU = (Potencimetro-((PotencimetroC*100)+(PotencimetroD*10)));
	MandarP(Tabla[PotencimetroC]);
	MandarP(Tabla[PotencimetroD]);
	MandarP(Tabla[PotencimetroU]);
	//mandar ebotonnube	(Boton de posicion)
	MandarP(Tabla[ebotonnube]);
	//Mandar ecambio (qué variable cambió)
	MandarP(Tabla[ecambio]);
}

void EEPROMP(uint8_t accion, uint8_t posicion){
	cli();
	switch (accion)
	{
	case Leer:
		switch (posicion)
		{
		case 1:
			POTBASE=eeprom_read_byte((uint8_t*)0);
			POT1=eeprom_read_byte((uint8_t*)1);
			POT2=eeprom_read_byte((uint8_t*)2);
			POTGARRA=eeprom_read_byte((uint8_t*)3);
			break;
		case 2:
			POTBASE=eeprom_read_byte((uint8_t*)4);
			POT1=eeprom_read_byte((uint8_t*)5);
			POT2=eeprom_read_byte((uint8_t*)6);
			POTGARRA=eeprom_read_byte((uint8_t*)7);
			break;
		case 3:
			POTBASE=eeprom_read_byte((uint8_t*)8);
			POT1=eeprom_read_byte((uint8_t*)9);
			POT2=eeprom_read_byte((uint8_t*)10);
			POTGARRA=eeprom_read_byte((uint8_t*)11);
			break;
		case 4:
			POTBASE=eeprom_read_byte((uint8_t*)12);
			POT1=eeprom_read_byte((uint8_t*)13);
			POT2=eeprom_read_byte((uint8_t*)14);
			POTGARRA=eeprom_read_byte((uint8_t*)15);
			break;
		default:
		
			break;	
		}
		break;
	case Manual:
		switch (posicion)
		{
		case 1:
			eeprom_write_byte((uint8_t*)0,  POTBASE);
			eeprom_write_byte((uint8_t*)1,  POT1);
			eeprom_write_byte((uint8_t*)2,  POT2);
			eeprom_write_byte((uint8_t*)3,  POTGARRA);
			break;
		case 2:
			eeprom_write_byte((uint8_t*)4,  POTBASE);
			eeprom_write_byte((uint8_t*)5,  POT1);
			eeprom_write_byte((uint8_t*)6,  POT2);
			eeprom_write_byte((uint8_t*)7,  POTGARRA);
			break;
		case 3:
			eeprom_write_byte((uint8_t*)8,  POTBASE);
			eeprom_write_byte((uint8_t*)9,  POT1);
			eeprom_write_byte((uint8_t*)10, POT2);
			eeprom_write_byte((uint8_t*)11, POTGARRA);
			break;
		case 4:
			eeprom_write_byte((uint8_t*)12, POTBASE);
			eeprom_write_byte((uint8_t*)13, POT1);
			eeprom_write_byte((uint8_t*)14, POT2);
			eeprom_write_byte((uint8_t*)15, POTGARRA);
			break;
		default:
		
			break;
		}
		break;
	case Nube:
		switch (posicion)
		{
			case 1:
				eeprom_write_byte((uint8_t*)0,  POTBASE);
				eeprom_write_byte((uint8_t*)1,  POT1);
				eeprom_write_byte((uint8_t*)2,  POT2);
				eeprom_write_byte((uint8_t*)3,  POTGARRA);
				break;
			case 2:
				eeprom_write_byte((uint8_t*)4,  POTBASE);
				eeprom_write_byte((uint8_t*)5,  POT1);
				eeprom_write_byte((uint8_t*)6,  POT2);
				eeprom_write_byte((uint8_t*)7,  POTGARRA);
				break;
			case 3:
				eeprom_write_byte((uint8_t*)8,  POTBASE);
				eeprom_write_byte((uint8_t*)9,  POT1);
				eeprom_write_byte((uint8_t*)10, POT2);
				eeprom_write_byte((uint8_t*)11, POTGARRA);
				break;
			case 4:
				eeprom_write_byte((uint8_t*)12, POTBASE);
				eeprom_write_byte((uint8_t*)13, POT1);
				eeprom_write_byte((uint8_t*)14, POT2);
				eeprom_write_byte((uint8_t*)15, POTGARRA);
				break;
			default:
			
			break;
		}
		break;
	default:
		break;
	}
	sei();
}

uint8_t Traductor(uint8_t valor){
	uint8_t exe = 0;
	switch (valor)
	{
	case 48:
		exe=0;
		break;
	case 49:
		exe=1;
		break;
	case 50:
		exe=2;
		break;
	case 51:
		exe=3;
		break;
	case 52:
		exe=4;
		break;	
	case 53:
		exe=5;
		break;
	case 54:
		exe=6;
		break;
	case 55:
		exe=7;
		break;
	case 56:
		exe=8;
		break;
	case 57:
		exe=9;
		break;
	}
	return exe;
}

/*
	------------------------------------------------------
	INTERRUPCIONES
	------------------------------------------------------
*/
ISR(PCINT1_vect){
	if ((Modo==Leer)|(Modo==Manual)) //Modo leer o modo manual
	{
		if (((PINC) & (1<<PINC0)) != (1<<PINC0)) //PC0 está activado
		{
			//Leer o escribir posicion 1
			BotonNube=1;
			EEPROMP(Modo,BotonNube);
			Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA,BotonNube, 5);
		}
		else if (((PINC) & (1<<PINC1)) != (1<<PINC1)) //PC1 está activado
		{
			//Leer o escribir posicion 2
			BotonNube=2;
			EEPROMP(Modo,BotonNube);
			Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA,BotonNube, 5);
		}
		else if (((PINC) & (1<<PINC2)) != (1<<PINC2)) //PC2 está activado
		{
			//Leer o escribir posicion 3
			BotonNube=3;
			EEPROMP(Modo,BotonNube);
			Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA,BotonNube, 5);
		}
		else if (((PINC) & (1<<PINC3)) != (1<<PINC3)) //PC3 está activado 
		{
			//Leer o escribir posicion 4
			BotonNube=4;
			EEPROMP(Modo,BotonNube);
			Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA,BotonNube, 5);
		}
	}
	//apagar inerrupcion
	
	PCIFR|=(1<<PCIF1);
}

ISR(PCINT0_vect){
	if (((PINB) & (1<<PINB5)) != (1<<PINB5))
	{
		Modo++;
		if (Modo==3)
		{
			Modo=0;
		}
		BotonNube=0;
		Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA, BotonNube, 0);
	}
	PCIFR|=(1<<PCIF0);
}

ISR(TIMER0_OVF_vect){
 if (Modo==Manual)  //Modo manual
 {
	switch (TurnoPOT)
	{
	case 0:
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2);
		TurnoPOT=1;
		break;
	case 1:
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2)|(1<<MUX0);
		TurnoPOT=2;
		break;
	case 2:
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2)|(1<<MUX1);
		TurnoPOT=3;
		break;
	case 3:
		ADMUX &= ~((1<<MUX0)|(1<<MUX1)|(1<<MUX2));
		ADMUX|=(1<<MUX2)|(1<<MUX1)|(1<<MUX0);
		TurnoPOT=0;
		break;
	 }
	 ADCSRA |= (1<<ADSC);
 }
 TCNT0=250;
 TIFR0|=(1<<TOV0);
}

ISR(ADC_vect){
	switch (TurnoPOT)
	{
		case 1:
			POTBASEP = POTBASE;
			POTBASE = ADCH;
			if((POTBASE/5)!=(POTBASEP/5)){
				Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA, BotonNube, 1);
			}
			break;
		case 2:
			POT1P=POT1;
			POT1 = ADCH;
			if((POT1/5)!=(POT1P/5)){
				Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA, BotonNube, 2);
			}
			break;
		case 3:
			POT2P=POT2;
			POT2 = ADCH;
			if((POT2P/5)!=(POT2/5)){
				Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA, BotonNube, 3);
			}
			break;
		case 0:
			POTGARRAP=POTGARRA;
			POTGARRA = ADCH;
			if((POTGARRA/5)!=(POTGARRAP/5)){
				Actualizarnube(Modo, POTBASE, POT1, POT2, POTGARRA, BotonNube, 4);
			}
			break;
	}
	ADCSRA |= (1<<ADIF);
}

ISR(USART_RX_vect){
	if (Modo==Nube)
	{
		switch (TurnoNube)
		{
		case 0:
			comodini=UDR0;
			Modo=Traductor(comodini);
			TurnoNube++;
			break;
		case 1:
			comodini=UDR0;
			PotencimetroC=Traductor(comodini);
			TurnoNube++;
			break;
		case 2:
			comodini=UDR0;
			PotencimetroD=Traductor(comodini);
			TurnoNube++;
			break;
		case 3:
			comodini=UDR0;			
			PotencimetroU=Traductor(comodini);
			POTBASE=(PotencimetroC*100)+(PotencimetroD*10)+(PotencimetroU);
			TurnoNube++;
			break;
		case 4:
			comodini=UDR0;			
			PotencimetroC=Traductor(comodini);
			TurnoNube++;
			break;
		case 5:
			comodini=UDR0;
			PotencimetroD=Traductor(comodini);;
			TurnoNube++;
			break;
		case 6:
			comodini=UDR0;
			PotencimetroU=Traductor(comodini);
			POT1=(PotencimetroC*100)+(PotencimetroD*10)+(PotencimetroU);
			TurnoNube++;
			break;
		case 7:
			comodini=UDR0;
			PotencimetroC=Traductor(comodini);
			TurnoNube++;
			break;
		case 8:
			comodini=UDR0;
			PotencimetroD=Traductor(comodini);
			TurnoNube++;
			break;
		case 9:
			comodini=UDR0;
			PotencimetroU=Traductor(comodini);
			POT2=(PotencimetroC*100)+(PotencimetroD*10)+(PotencimetroU);
			TurnoNube++;
			break;
		case 10:
			comodini=UDR0;
			PotencimetroC=Traductor(comodini);
			TurnoNube++;
			break;
		case 11:
			comodini=UDR0;
			PotencimetroD=Traductor(comodini);
			TurnoNube++;
			break;
		case 12:
			comodini=UDR0;
			PotencimetroU=Traductor(comodini);
			POTGARRA=(PotencimetroC*100)+(PotencimetroD*10)+(PotencimetroU);
			TurnoNube++;
			break;
		case 13:
			comodini=UDR0;
			BotonNube=Traductor(comodini);
			EEPROMP(Modo,BotonNube);
			TurnoNube=0;
			
			break;
		default:
			break;
		}
	}
	if (Modo==Leer)
	{
		switch (TurnoNube)
		{
		case 0:
			comodini=UDR0;
			Modo=Traductor(comodini);
			TurnoNube++;
			break;
		case 13:
			comodini=UDR0;
			BotonNube=Traductor(comodini);
			EEPROMP(Modo,BotonNube);
			break;
		default:
			TurnoNube++;
			break;
		}
	}
	if (Modo==Manual)
	{	
		comodini=UDR0;
	}
}