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
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char A3to0;
	while(1) {
		// 1) Read input
        A3to0 = PINA;
        if(A3to0 == 0x00) {
            PORTC = 0x04;
        }
        else if(A3to0 == 0x01 || A3to0 == 0x02 || A3to0 == 0x04 || A3to0 == 0x08) {
            PORTC = 0x03;
        }
        else if(A3to0 == 0x03 || A3to0 == 0x05 || A3to0 == 0x06 || A3to0 == 0x09 || A3to0 == 0x0A || A3to0 == 0x0C) {
            PORTC = 0x02;
        }
        else if(A3to0 == 0x07 || A3to0 == 0x0B || A3to0 == 0x0D || A3to0 == 0x0E) {
            PORTC = 0x01;
        }
		else if(A3to0 == 0x80 || A3to0 == 0x0F){
		   PORTC = 0x80;
		}		 
	}
	return 1;
}
