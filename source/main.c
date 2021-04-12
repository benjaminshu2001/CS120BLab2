/*	Author: bshu005
 *  Partner(s) Name: None
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #4
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
    DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0x00; PORTC = 0xFF;
    DDRD = 0xFF; PORTD = 0x00; //Port D = output, initialize ports as 0
    unsigned char tempA, tempB, tempC, tempD;	
    unsigned short totalWeight = 0x0000;
    unsigned char cutTotal = 0x00;
	while(1) {
		// 1) Read input
		tempA = PINA;
        tempB = PINB;
        tempC = PINC;
        totalWeight = tempA + tempB + tempC;
        if(totalWeight > 140) { //if weight exceeds 140 kg, set PD0 to 1 1100 0100 1100 0001
            tempD = 0x01;
        }
        if((PINA - PINC) > 80 || (PINC - PINA) > 80) {
            tempD = tempD | 0x02;
        }

        PORTD = ((totalWeight >> 2) & 0xFC)  | tempD;   
	}
	return 1;
}
