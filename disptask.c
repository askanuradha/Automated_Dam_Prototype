#include <xc.h>
#include "config.h"

// - Defined in other file(s):
void lcdCtrl_SetPos(unsigned char row, unsigned char col);
void lcdWriteDspData(char x);

void on_dsp_0(int temp) {    
    char temp_dig2 = temp/100;
    char temp_dig1 = (temp/10)%10;
    char temp_dig0 = temp%10;

    // displaying the temperature
    lcdCtrl_SetPos(1, 9);
    lcdWriteDspData(temp_dig2+0x30);
    lcdWriteDspData(temp_dig1+0x30);
    lcdWriteDspData(temp_dig0+0x30);
}

void on_dsp_1(int water_level) {    
    // setting water level digits to show
    char water_dig2 = water_level/100;
    char water_dig1 = (water_level/10)%10;
    char water_dig0 = water_level%10;

    // displaying the water level
    lcdCtrl_SetPos(2, 9);
    lcdWriteDspData(water_dig2+0x30);
    lcdWriteDspData(water_dig1+0x30);
    lcdWriteDspData(water_dig0+0x30);
}
