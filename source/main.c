/*	Author: bshu005
 *  Partner(s) Name: None
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #3
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
    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    unsigned char tempC = 0x00;
    unsigned char tempD0 = 0x00;	
    unsigned char tempD1 = 0x00;
    unsigned short totalWeight = 0x0000;
	while(1) {
		// 1) Read input
		
        tempA = PINA;
        tempB = PINB;
        tempC = PINC;
        
        totalWeight = tempA + tempB + tempC;
        if(totalWeight > 140) { //if weight exceeds 140 kg, set PD0 to 1
            tempD0 = tempD0 | 0x01;
        }
        if((PINA - PINC) > 80 || (PINC - PINA) > 80) {
            tempD1 = tempD1 | 0x02;
        }  
        PORTD = (totalWeight & 0x00FC) | tempD0 | tempD1;
	}
	return 1;
}
