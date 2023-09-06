#include <xc.h>
#include "config.h"

// functions defined in other files
void seg_DispAll(unsigned int result);

int interrupt_occur = 0; // 0 means auto mode and 1 means manual mode
int count = 0;

void __interrupt() isr(void) {
    if(PIR0bits.INTF == 1) {
        PIR0bits.INTF = 0;
        interrupt_occur = ~interrupt_occur; // interrupt occur variable opens the gate
                                                // and turn on the LED at the main.c file
    }
    if (PIR0bits.TMR0IF == 1) {
        PIR0bits.TMR0IF = 0;
        PORTAbits.RA4 = ~PORTAbits.RA4; // Toggle the motor
        count++;
        
        if (count > 99) {
            count = 0;
        }
        seg_DispAll(count);
    }
}