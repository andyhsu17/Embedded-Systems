/*
 * Lab3.c
 *
 *  Created on: Sep 25, 2017
 *      Author: andyhsu
 */
#include "msp.h"
#include "lab3.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

extern volatile uint32_t countwave = 0;
extern volatile float diameter = .09988;
extern volatile float distance = 0;
extern volatile float distance1 = 0;
extern volatile float pi = 3.14159265;

void PORT1_IRQHandler(){
    if(P1->IFG & BIT6){
        countwave++;
        P1->OUT ^= BIT0;
        P1->IFG &= ~BIT6;

    distance = pi * diameter;
    distance /= 14;
    distance1 = distance * countwave;
    val = 0;
    }
}
// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}
