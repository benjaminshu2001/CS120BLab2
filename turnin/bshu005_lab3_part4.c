/*	Author: bshu005
 *  Partner(s) Name: None
 *	Lab Section: 22
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; 
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    unsigned char tempC = 0x00;
	while(1) {
        tempA = PINA;
        tempB = (PINA & 0xF0) >> 4;
        tempC = (PINA & 0x0F) << 4;
        PORTB = tempB | (PORTB & 0xF0);
        PORTC = tempC | (PORTC & 0x0F);
    }   
	return 1;
}
