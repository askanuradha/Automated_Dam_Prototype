#include <xc.h>
#include "config.h"

const unsigned char segTable[] = {
    0b11000000,
    0b11111001,
    0b10100100,
    0b10110000,
    0b10011001,
    0b10010010,
    0b10000010,
    0b11111000,
    0b10000000,
    0b10010000,
    0b11111111
};

void seg_DispAll(unsigned int result) {
    int dig0, dig1;
    
    dig0 = result%10;
    dig1 = (result/10)%10;
    
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 0;
    PORTC = segTable[dig0];
    __delay_ms(5);
    PORTC = segTable[10];
    
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 1;
    PORTC = segTable[dig1];
    __delay_ms(5);
    PORTC = segTable[10];
}