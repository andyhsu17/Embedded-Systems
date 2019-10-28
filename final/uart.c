/*
 * uart.c
 *
 *  Created on: Sep 25, 2017
 *      Author: andyhsu
 */
#include "msp432p401r.h"
#include "msp.h"
#include "uart.h"
#include "stdint.h"
#include "msp432p401r_classic.h"
void UART_Configure(){
    EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST; //reset
                P1->SEL0 |= BIT2; //primary mode pins 2 and 3
                P1->SEL1 &= ~BIT2;
                P1->SEL0 |= BIT3;
                P1->SEL1 &= ~BIT3;
                EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_MODE_0;
                EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_MODE_0;
                EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_MSB;
                EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SEVENBIT; //8 bits
                EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SPB;

                UCA0IE |= EUSCI_A_IE_TXIE | EUSCI_A_IE_RXIE; // interrupt enables


                EUSCI_A0->BRW = 1; //baud rate
                UCA0IFG = 0;
                EUSCI_A0->MCTLW |= 0x00A0 | 0x0100 | EUSCI_A_MCTLW_OS16;

 EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SWRST; //initialize eusci

 EUSCI_A0->IFG = 0; //reset flags
 EUSCI_A0->IE |= BIT0;
 NVIC_EnableIRQ(EUSCIA0_IRQn);

    }


void UART_send_byte(uint8_t data){
    while(EUSCI_A0->STATW & EUSCI_A_STATW_BUSY);
    EUSCI_A0->TXBUF = data;


}
void UART_send_n(uint8_t * data, uint32_t length)
{
int i = 0;
for(i = 0; i < length; i++){
    UART_send_byte(data[i]);
}

}

