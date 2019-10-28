//*****************************************************************************
//
// MSP432 main.c template - Empty main
//
//****************************************************************************

#include "msp.h"
#define pause 30000
#include "lab1.h"
#include <stdint.h>


void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           // Stop watchdog timer
        unsigned int count = 0;
        unsigned int i = 0;

        uint8_t * p1in = (uint8_t*) 0x40004C00;
        uint8_t * p1SEL0 = (uint8_t*) 0x40004C0A;
        uint8_t * p1SEL1 = (uint8_t*) 0x40004C0C;
        uint8_t * p1out = (uint8_t*)0x40004C02;
        uint8_t * p1DIR = (uint8_t*)0x40004C05;
        *p1out &= 0x00;
        *p1SEL0 &= 0x00;
        *p1SEL1 &= 0x00;
        *p1DIR &= 0x00;

        int32_t var1 = 0xA274;
        var1 |= 0xC231;// set bits 0,4,5,14,15
        var1 &= 0x79FF; // clear bits 9,10,15
        var1 ^= 0x0FF0; // toggle 4,5,6,7,8,9,10,11
 report_types();
 report_pointer_types();
make_square_wave(){

}

        while (1) {                    // continuous loop
                        count++;
                        *p1out  ^= 0x01;             // Blink P1.0 LED
                        for (i = 0; i < pause; i++);    // Delay
                }




}
