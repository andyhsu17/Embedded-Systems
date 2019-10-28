/*
 * adc.c
 *
 *  Created on: Dec 4, 2017
 *      Author: andyhsu
 */

#include "adc.h"
#include "msp.h"
#include "msp432p401r.h"
#include "msp432p401r_classic.h"
#include "core_cm4.h"

extern volatile float Nadc1, Nadc2, Nadc5;
extern volatile int convert1, convert2, convert3;

//temperature
void configureADC()
{
    P4->SEL0 |= (BIT4);
    P4->SEL1 |= (BIT4); // Configure ADC input pin 4.4 A9
    P4->DIR &= ~(BIT4); // input mode
    P4->SEL0 |= (BIT5);
    P4->SEL1 |= (BIT5); // Configure ADC input pin 4.5 A8
    P4->DIR &= ~(BIT5); // input mode
    P5->SEL0 |= (BIT0);
    P5->SEL1 |= (BIT0); // Configure ADC input pin 5.0 A5
    P4->DIR &= ~(BIT0);

    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY); //IF ref genearator busy, wait
    ADC14->CTL0 &= ~ADC14_CTL0_ENC; //Disable ADC to configure

    REF_A->CTL0 = REF_A_CTL0_VSEL_3 | REF_A_CTL0_ON; //reference v of 2.5v

    ADC14->CTL0 |= ADC14_CTL0_SSEL__SMCLK; //select SMCLK
    ADC14->CTL0 |= ADC14_CTL0_SHP | ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON |ADC14_CTL0_CONSEQ_1;
    //sample and hold pulse mode, 96 samples/period, ADCON, Sequence of channels
    ADC14->CTL0 |= ADC14_CTL0_MSC;//multiple conversions,

    ADC14->CTL1 |= ADC14_CTL1_RES_3;//14 bit resolution

    ADC14->MCTL[0] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_9; // analog A9
    ADC14->MCTL[1] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_8; // analog A8
    ADC14->MCTL[4] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_5; // analog A5
    //ADC14->MCTL[4] = ADC14_MCTLN_EOS;
    ADC14->IER0 |= ADC14_IER0_IE0|ADC14_IER0_IE1|ADC14_IER0_IE4; // enable interrupt in bit 0, 1, 4

    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY)); // wait for ref gen to settle
    ADC14->CTL0 |= ADC14_CTL0_ENC; //enable ADC again
    NVIC_EnableIRQ(ADC14_IRQn);
}


//carbon monoxide
void configureADC2()
{
    P4->SEL0 |= (BIT5);
    P4->SEL1 |= (BIT5); // Configure ADC input pin 4.5 A8
    P4->DIR &= ~(BIT5); // input mode

    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY); //IF ref genearator busy, wait
    ADC14->CTL0 &= ~ADC14_CTL0_ENC; //Disable ADC to configure

    REF_A->CTL0 = REF_A_CTL0_VSEL_3 | REF_A_CTL0_ON; //reference v of 2.5v, reference Voltage enable

    //ADC14->CTL0 |= ADC14_CTL0_SSEL__SMCLK; //select SMCLK
    ADC14->CTL0 |= ADC14_CTL0_SHP | ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON |ADC14_CTL0_CONSEQ_0;
    //sample and hold pulse mode, 96 samples/period, ADCON, Sequence of channels
    //ADC14->CTL0 |= ADC14_CTL0_MSC;//multiple conversions,

    ADC14->CTL1 |= ADC14_CTL1_RES_3;//14 bit resolution

    ADC14->MCTL[1] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_8|ADC14_MCTLN_INCH_5|ADC14_MCTLN_INCH_9;// analog A8
    ADC14->IER0 |= ADC14_IER0_IE1; // enable interrupt in bit 0

    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY)); // wait for ref gen to settle
    ADC14->CTL0 |= ADC14_CTL0_ENC; //enable ADC again
    NVIC_EnableIRQ(ADC14_IRQn);
}

/*hydrogen
void configureADC3()
{
    P4->SEL0 |= (BIT6);
    P4->SEL1 |= (BIT6); // Configure ADC input pin 4.6 A7
    P4->DIR &= ~(BIT6); // input mode

    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY); //IF ref genearator busy, wait
    ADC14->CTL0 &= ~ADC14_CTL0_ENC; //Disable ADC to configure

    REF_A->CTL0 = REF_A_CTL0_VSEL_3 | REF_A_CTL0_ON; //reference v of 2.5v

    //ADC14->CTL0 |= ADC14_CTL0_SSEL__SMCLK; //select SMCLK
    ADC14->CTL0 |= ADC14_CTL0_SHP | ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON |ADC14_CTL0_CONSEQ_1;
    //sample and hold pulse mode, 96 samples/period, ADCON, Sequence of channels
    ADC14->CTL0 |= ADC14_CTL0_MSC;//multiple conversions,

    ADC14->CTL1 |= ADC14_CTL1_RES_3;//14 bit resolution

    ADC14->MCTL[2] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_7; //Voltage reference 3.3V, analog A7
    ADC14->IER0 |= ADC14_IER0_IE0; // enable interrupt in bit 0

    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY)); // wait for ref gen to settle
    ADC14->CTL0 |= ADC14_CTL0_ENC; //enable ADC again
    NVIC_EnableIRQ(ADC14_IRQn);
}
*/
/*
//methane
void configureADC4()
{
    P4->SEL0 |= (BIT7);
    P4->SEL1 |= (BIT7); // Configure ADC input pin 4.7 A6
    P4->DIR &= ~(BIT7); // input mode

    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY); //IF ref genearator busy, wait
    ADC14->CTL0 &= ~ADC14_CTL0_ENC; //Disable ADC to configure

    REF_A->CTL0 = REF_A_CTL0_VSEL_3 | REF_A_CTL0_ON; //reference v of 2.5v

    //ADC14->CTL0 |= ADC14_CTL0_SSEL__SMCLK; //select SMCLK
    ADC14->CTL0 |= ADC14_CTL0_SHP | ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON |ADC14_CTL0_CONSEQ_1;
    //sample and hold pulse mode, 96 samples/period, ADCON, Sequence of channels
    ADC14->CTL0 |= ADC14_CTL0_MSC;//multiple conversions,

    ADC14->CTL1 |= ADC14_CTL1_RES_3;//14 bit resolution

    ADC14->MCTL[3] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_6; //Voltage reference 3.3V, analog A6
    ADC14->IER0 |= ADC14_IER0_IE0; // enable interrupt in bit 0

    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY)); // wait for ref gen to settle
    ADC14->CTL0 |= ADC14_CTL0_ENC; //enable ADC again
    NVIC_EnableIRQ(ADC14_IRQn);
}
*/


//lpg
void configureADC5()
{
    P5->SEL0 |= (BIT0);
    P5->SEL1 |= (BIT0); // Configure ADC input pin 5.0 A5
    P5->DIR &= ~(BIT0); // input mode

    REF_A->CTL0 = REF_A_CTL0_VSEL_3 | REF_A_CTL0_ON; //reference v of 2.5v

    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY); //IF ref genearator busy, wait
    ADC14->CTL0 &= ~ADC14_CTL0_ENC; //Disable ADC to configure



    //ADC14->CTL0 |= ADC14_CTL0_SSEL__SMCLK; //select SMCLK
    ADC14->CTL0 |= ADC14_CTL0_SHP | ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON |ADC14_CTL0_CONSEQ_0;
    //sample and hold pulse mode, 96 samples/period, ADCON, Sequence of channels
   // ADC14->CTL0 |= ADC14_CTL0_MSC;//multiple conversions,

    ADC14->CTL1 |= ADC14_CTL1_RES_3;//14 bit resolution

    ADC14->MCTL[4] = ADC14_MCTLN_VRSEL_0 | ADC14_MCTLN_INCH_5; // analog A7
    ADC14->MCTL[4] = ADC14_MCTLN_EOS; //end of sequence, for last conversion
    ADC14->IER0 |= ADC14_IER0_IE4; // enable interrupt in bit 0

    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY)); // wait for ref gen to settle
    ADC14->CTL0 |= ADC14_CTL0_ENC; //enable ADC again
    NVIC_EnableIRQ(ADC14_IRQn);
}


void ADC14_IRQHandler()
{
    __disable_irq();
    if(ADC14->IFGR0 & ADC14_IFGR0_IFG0)
    {
        Nadc1 = ADC14->MEM[0];
        convert1 = 1;
    }

   if(ADC14->IFGR0 & ADC14_IFGR0_IFG1)
    {
        Nadc2 = ADC14->MEM[1];
        convert2 = 1;
    }
    if(ADC14->IFGR0 & ADC14_IFGR0_IFG4)
    {
        Nadc5 = ADC14->MEM[4];
        convert3 = 1;

    }
    __enable_irq();

}
