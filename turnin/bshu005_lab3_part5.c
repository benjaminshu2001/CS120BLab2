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
    DDRB = 0xFE; PORTB = 0x01; 
    DDRD = 0x00; PORTD = 0xFF;
    unsigned char tempB = 0x00;
    unsigned char tempD = 0x00;
	while(1) {
        unsigned short seatWeight = (PINB & 0x01) | (PIND << 1);
        unsigned char tempB = 0x00;
        if(seatWeight >= 70) {
            tempB = tempB | 0x02;
        }   
        else if( seatWeight > 5) {
            tempB = tempB | 0x04;
        }
        PORTB = tempB & 0x06;
    }   
	return 1;
}
