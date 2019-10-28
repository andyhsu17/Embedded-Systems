/*
 * configure.c
 *
 *  Created on: Apr 21, 2018
 *      Author: andyhsu
 */
#include "msp.h"
#include "msp432p401r.h"
#include "configure.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "uart.h"

volatile char rxd;
void configure_bluetooth(){
    P2->SEL0 |= BIT2 | BIT3;
        P2->SEL1 &= ~(BIT2 | BIT3);
        //configure bluetooth EUSCI A1
        EUSCI_A1->CTLW0 |= EUSCI_A_CTLW0_SWRST; // Put eUSCI in reset
        EUSCI_A1->CTLW0 = EUSCI_A_CTLW0_SWRST | // Remain eUSCI in reset
                          EUSCI_B_CTLW0_SSEL__SMCLK;
        EUSCI_A1->CTLW0 |= BIT7;                //select frame rate parameters and clock source
        EUSCI_A1->BRW = 78;                     //set baud rate
        EUSCI_A1->MCTLW |= BIT5 | BIT0;         //set first stage modulator bit (if needed)
        EUSCI_A1->CTLW0 &= ~EUSCI_A_CTLW0_SWRST;// Initialize eUSCI

        EUSCI_A1->IFG &= ~EUSCI_A_IFG_RXIFG;    // Clear eUSCI RX interrupt flag
        //EUSCI_A1->IE |= EUSCI_A_IE_RXIE;        // Enable USCI_A1 RX interrupt
        NVIC_EnableIRQ(EUSCIA1_IRQn);           //Enable eUSCIA1 interrupt in NVIC

}




