// PIN MAP
// RA3 = minimum level LED
// RA5 = medium level LED
// RA1 = red LED in maximum LED (it is toggling)
// RA2 = Buzzer
// RA4 = Motor
// RD7-RD4 = LCD module data lines
// RE1 = RS in LCD
// RE0 = E in LCD
// RB0 = manual operation push button
// RD2, RD3 = seven seg selection bits
// RC0-RC6 = seven seg data lines
// RD0 = Potentiometer/ Temp sensor
// RD1 = Potentiometer/ water level sensor


#include <xc.h>
#include "config.h"

// Function Declarations:
// - Defined in this file:
void initSysPins(void);
// - Defined in other file(s):
void initLCD(void);
void lcdWriteDspData(char x);
void lcdCtrl_SetPos(char row, char col);
void initADC(void);
unsigned int adc_GetConversion(int pin);
void on_dsp_0(int temp);
void on_dsp_1(int water_level);
void initSysExtInt(void);
void initSysTimer0(void);

extern int interrupt_occur;
extern count;

#define minimum_level 250
#define maximum_level 750

void main(void) {
    
    char message1[] = "Temp:";
    char message2[] = "Water:";
    
    unsigned int i;
    
    initSysPins();
    initLCD();
    initADC(); // initialize the ADC
    initSysExtInt(); // initialize the external interrupt
    initSysTimer0(); // initialize the timer 0 interrupt
    
    lcdCtrl_SetPos(1, 1);
    for(i = 0; message1[i]!=0; i++) {
        lcdWriteDspData(message1[i]);
    }
    
    lcdCtrl_SetPos(2, 1);
    for(i = 0; message2[i]!=0; i++) {
        lcdWriteDspData(message2[i]);
    }
    
    while (1) {
        unsigned int temp = adc_GetConversion(0); // Getting Temperature value, It connected to RD0
        on_dsp_0(temp);

        unsigned int water_level = adc_GetConversion(1); // Getting water level, It connected to RD1
        on_dsp_1(water_level);

        if (interrupt_occur == 0) {
            // setting level LEDs
            if (water_level < minimum_level) {
                PORTAbits.RA3 = 1; // turn on red led
                PORTAbits.RA1 = 0; // turn off red led
                PORTAbits.RA2 = 0; // turn off buzzer
                PORTAbits.RA4 = 0; // turn off motor
                PORTAbits.RA5 = 0; // turn off green led
                PIE0bits.TMR0IE = 0; // prevent the timer 0 interrupt
                count = 0;
            } else if (minimum_level <= water_level && water_level <= maximum_level) {
                PORTAbits.RA5 = 1; // turn on green led
                PORTAbits.RA1 = 0; // turn off red led
                PORTAbits.RA2 = 0; // turn off buzzer
                PORTAbits.RA4 = 0; // turn off motor
                PORTAbits.RA3 = 0; // turn off red led
                PIE0bits.TMR0IE = 0; // prevent the timer 0 interrupt
                count = 0;
            } else if (maximum_level < water_level) {
                PORTAbits.RA1 = ~PORTAbits.RA1; // toggle red led
                PORTAbits.RA2 = ~PORTAbits.RA2; // toggle buzzer
                PIE0bits.TMR0IE = 1; // enable the timer 0 interrupt
                PORTAbits.RA5 = 0; // turn off green led
                PORTAbits.RA3 = 0; // turn off red led
                __delay_ms(400);
            }
        } else {
            PORTAbits.RA1 = ~PORTAbits.RA1; // toggle red led
            PORTAbits.RA2 = ~PORTAbits.RA2; // toggle buzzer
            PORTAbits.RA4 = 1; // turn on motor
            PORTAbits.RA5 = 0; // turn off green led
            PORTAbits.RA3 = 0; // turn off red led
            PIE0bits.TMR0IE = 0; // prevent the timer 0 interrupt
            count = 0;
            __delay_ms(400);
        }
    }
}
void initSysPins(void) {
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    ANSELC = 0b00000000;
    ANSELD = 0b00000011;
    ANSELE = 0b11110000;
    TRISA = 0b00000000;
    TRISB = 0b11111111;
    TRISC = 0b00000000;
    TRISD = 0b00000011;
    TRISE = 0b11111100;
}
