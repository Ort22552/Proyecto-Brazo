/*
 * Utileria.h
 *
 * Created: 23/01/2025 18:02:30
 *  Author: Josue Ortiz
 */ 


#ifndef	UTILERIA_H_
#define UTILERIA_H_
/*
	DEFINICIONES E INCLUDES BASE
*/

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>

/*
	DEFINICIONES DE VARIABLES
*/
#define D 3
#define C 2
#define B 1

/*
	FUNCIONES
*/

void OCHOSEGMENTOS(uint8_t VALOR, uint8_t PUERTO, uint8_t PINES);

#endif /* UTILERIA_H_ */