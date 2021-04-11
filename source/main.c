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
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char tempA = 0x00;
    unsigned char tempB = 0x00;
    unsigned char count = 0;
	while(1) {
		// 1) Read input
		tempA = PINA;
        tempB = PINB;
        count = 0;
        if((tempA & 0x01) == 0x01) {
            count = count + 1;
        }
        if((tempA & 0x02) == 0x02) {
            count = count + 1;
        }
        if((tempA & 0x04) == 0x04) {
            count = count + 1;
        }
        if((tempA & 0x08) == 0x08) {
            count = count + 1;
        }
        if((tempA & 0x10) == 0x10) {
            count = count + 1;
        }
        if((tempA & 0x20) == 0x20) {
            count = count + 1;
        }
        if((tempA & 0x40) == 0x40) {
            count = count + 1;
        }
        if((tempA & 0x80) == 0x80) {
            count = count + 1;
        }
        if((tempB & 0x01) == 0x01) {
            count = count + 1;
        }
        if((tempB & 0x02) == 0x02) {
            count = count + 1;
        }
        if((tempB & 0x04) == 0x04) {
            count = count + 1;
        }
        if((tempB & 0x08) == 0x08) {
            count = count + 1;
        }
        if((tempB & 0x10) == 0x10) {
            count = count + 1;
        }
        if((tempB & 0x20) == 0x20) {
            count = count + 1;
        }
        if((tempB & 0x40) == 0x40) {
            count = count + 1;
        }
        if((tempB & 0x80) == 0x80) {
            count = count + 1;
        }
        PORTC = count;   
        
	}
	return 1;
}
