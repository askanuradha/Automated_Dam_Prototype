#include <xc.h>
#include "config.h"

void initSysExtInt(void) {
    INTCONbits.GIE = 0;
    PIR0bits.INTF = 0;
    INTPPS = 0x08; // Setting interrupt pin as RB0
    INTCONbits.INTEDG = 1;
    PIE0bits.INTE = 1;
    INTCONbits.GIE = 1;
}