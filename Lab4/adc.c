/*
 * adc.c
 *
 *  Created on: Oct 11, 2017
 *      Author: andyhsu
 */
#include "msp.h"
#include "msp432p401r.h"
#include "adc.h"
extern volatile float nadc;
extern volatile float vadc;
extern volatile float vsens;
extern volatile float tempc;
extern volatile float tempf;
extern volatile float tempk;

void configure_ADC(){
    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY); // if busy, wait
    REF_A->CTL0 = REF_A_CTL0_VSEL_0 | REF_A_CTL0_ON; //reference v of 1.2v
    REF_A->CTL0 &= ~REF_A_CTL0_TCOFF; // turn on temp sensor
    ADC14->CTL0 &= ~ADC14_CTL0_ENC; // disable adc

    ADC14->CTL0 |= ADC14_CTL0_SHT0_5 | ADC14_CTL0_ON | ADC14_CTL0_SHP; //pulse sample mode, ADC14SC trigger, ADC on
    //temp sample period > 30us
    ADC14->CTL1 |= ADC14_CTL1_TCMAP; //temp sensor channel select 1
    ADC14->MCTL[0] = ADC14_MCTLN_INCH_22 | ADC14_MCTLN_VRSEL_1; // temperature analog input to MEM0/MCTL0, 3.3Vref
    ADC14->CTL0 |= ADC14_CTL0_ENC; //enable conversions
    ADC14->IER0 = ADC14_IER0_IE0; // enable interrupts

    while(!(REF_A->CTL0 & REF_A_CTL0_GENRDY));//wait for ref generator to settle
    ADC14->CTL0 |= ADC14_CTL0_ENC;// enable conversions
    NVIC_EnableIRQ(ADC14_IRQn); //global enable interrupts in NVIC

}

void ADC14_IRQHandler()
{

    if(ADC14->IFGR0 & ADC14_IFGR0_IFG0)
    {
        nadc = (float) ADC14->MEM[0];
    }
}
