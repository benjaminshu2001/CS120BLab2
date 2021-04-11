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
	DDRC = 0x0F; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char cntavail = 0;
	unsigned char A0, A1, A2, A3, A7;
	while(1) {
		// 1) Read input
		cntavail = 4;
		A0 = PINA & 0x01; //00000001 = pin 0
		A1 = PINA & 0x02; //00000010 = pin 1
		A2 = PINA & 0x04; //00000100 = pin 2
		A3 = PINA & 0x08; //00001000 = pin 3
		A7 = PINA & 0x80;
		if(A0 == 1) {
		   cntavail = cntavail - 1;
		}
		if(A1 == 1) {
		   cntavail = cntavail - 1;
		}
		if(A2 == 1) {
		   cntavail = cntavail - 1;
		}
		if(A3 == 1) {
		   cntavail = cntavail - 1;
		}
		if(cntavail == 0) {
		   A7 = PINA | 0x80;
		}
		PORTC = PORTC | A0 | A1 | A2 | A3 | A7; 
	}
	return 1;
}
