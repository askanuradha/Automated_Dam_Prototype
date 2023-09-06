#include <xc.h>
#include "config.h"

void initSysTimer0(void) { // TIMER0: 8 bit timer with 2998272 (~3s) us (this time value gets for its near to 3s and it completely divided by Npre = 16384)
                           // TIMER1: 16bit timer with 400ms interval
    INTCONbits.GIE = 0;
    T0CON0 = 0b10000000;
    T0CON1 = 0b01001110; // Npre = 16384
    TMR0H = 182;
    
    // for TMR1 // for buzzer and LED
    //TMR1H = 0x3C;
    //TMR1L = 0xB0;
    //T1CON = 0b00110010; // not enables the timer 1
    //T1CLK = 0b00000001;
    //INTCONbits.PEIE = 1;
    //PIE4.TMR1IE = 1;
            
    PIR0bits.TMR0IF = 0;
    PIE0bits.TMR0IE = 0; // not enables the timer 0 and it enables in main file after water level goes high
    INTCONbits.GIE = 1;
}