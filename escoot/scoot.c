/*
 * scoot.c
 *
 *  Created on: Nov 1, 2017
 *      Author: andyhsu
 */
#include "msp.h"
#include "scoot.h"
#include "circbuf.h"
#include <stdint.h>
#include <stdio.h>
#include "msp432p401r.h"
#include "msp432p401r_classic.h"

extern volatile float Nadc;
extern volatile uint16_t yacc;
extern volatile uint16_t zacc;

/*void GPIOConfigure(){

  P1->SEL0 &= ~BIT6;
  P1->SEL1 &= ~BIT6;
  P1->DIR &= ~BIT6;
  P1->REN |= BIT6;
  P1->OUT &= ~BIT6;
  P1->IES &= ~BIT6;
  P1->IFG &= ~BIT6;
  P1->IE |= BIT6;
}*/
void configure_ADC_Accelerometer()
{
    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY);
    ADC14->CTL0 &= ~ADC14_CTL0_ENC; //DISABLE ADC
    REF_A->CTL0 |= REF_A_CTL0_VSEL_0 | REF_A_CTL0_ON;
    ADC14->CTL0 |= ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON | ADC14_CTL0_SHP | ADC14_CTL0_CONSEQ_1;
    ADC14->CTL1 |= ADC14_CTL1_CH0MAP | ADC14_CTL1_CH1MAP | ADC14_CTL1_CH2MAP | ADC14_CTL1_RES_3;
    ADC14->MCTL[0] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_14;
    ADC14->MCTL[1] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_13;
    ADC14->MCTL[2] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_11 | ADC14_MCTLN_EOS;
    ADC14->IER0 |= ADC14_IER0_IE0;
    ADC14->CLRIFGR0 = 0;
    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY));
    ADC14->CTL0 |= ADC14_CTL0_ENC;
    NVIC_EnableIRQ(ADC14_IRQn);
}
void ADC14_IRQHandler()
{
    if(ADC14->IFGR0 & ADC14_IFGR0_IFG0)
    {
        Nadc = ADC14->MEM[0];
       yacc = ADC14->MEM[1];
       //zacc = ADC14->MEM[2];
    }
}

/*

void reverse(char s[], int strlength)
{
    int i, j;
    char c;

    for(i = 0, j = strlength - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void ftoa(float n, char * res, int afterpoint)
{
    //extract integer
    int ipart = (int)n;
    //extract floating part
    float fpart = n - (float)ipart;
    //convert integer to string
    int pos = itoa(ipart, res);

    //check for display
    if(afterpoint != 0)
    {
        res[pos] = '.';
        int temp = 1;
        int i = 0;
        for(i = 0; i < afterpoint; i++)
        {
            temp *= 10;
        }
        fpart = fpart * temp;
        if(fpart < 0)
        {
            fpart = abs(fpart);
        }
        itoa((int)fpart, res + pos + 1);
    }
}

int8_t itoa(int n, char s[])
{
    int i, sign;
    if((sign = n) < 0)
        n = -n;
    i = 0;
    do{
        s[i++] = n % 10 + '0';
    }
    while((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
    return i;
}


*/
