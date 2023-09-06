#include <xc.h>
#include "config.h"

// Function to initialise the ADC
void initADC(void) {
    ADREF = 0b00000000;
    ADCLK = 0b00000011;
    ADACQ = 0b00000000;
    ADCON0 = 0b10000100; // right justified
}

// ADC conversion
unsigned int adc_GetConversion(int pin) {
    
    unsigned int result;
    if (pin == 0)
        ADPCH = 0b00011000;  // RD0 as desired channel in temperature sensor
    if (pin == 1)
        ADPCH = 0b00011001;  // RD1 as desired channel in Water level sensor
    __delay_us(2);
    ADCON0bits.ADGO = 1; // Start conversion
    while(ADCON0bits.ADGO == 1); // Wait for conversion to complete
    result = ADRESH*256 + ADRESL; // Get the results
    return (result); // Return the result
}