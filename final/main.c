#include "msp.h"
#include <math.h>
//#include "ti/devices/msp432p4xx/inc/msp.h"
#include <stdint.h>
#define SCB_SCR_ENABLE_SLEEPONEXIT (0x00000002)
#include "core_cm4.h"
//#include "configure.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
//#include "bme280_defs.h"
//#include "bme280.h"
#include "msp432p401r.h"
#include "msp432p401r_classic.h"
#include "adc.h"

/**
 * main.c
 */

volatile float Nadc1, Nadc2, Nadc5;



uint8_t RXData[5] = {0};
uint8_t RXDataPointer=0;
volatile int count=0;
volatile char rxd;
int num1=0;
int len=3;
volatile int status;
uint8_t reg_addr=0xFA;
uint8_t dev_id=0x77;
uint16_t i;

volatile float vadc, vadc2, vadc5;
float tempc;
float temp;
float coppm;
//float methaneppm;
//float hydrogenppm;
float lpgppm;
volatile int convert1, convert2, convert3;

void main(void)
{

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	configureADC();

	__enable_irq();


	while(1)
	{
	    ADC14->CTL0 |= ADC14_CTL0_SC|ADC14_CTL0_ENC; // sampling&conversion start
	    __sleep();// wait til conversion finishes
	    //__disable_irq();
	    __no_operation(); // breakpoint
	    for(i = 0; i < 3000; i++);

//temperature conversion

if(convert1)
{

	    vadc = Nadc1 * 3300 / (2<<13);
	    //for (i = 30000; i > 0; i--); // wait for sensor to settle
	    temp = (1777.3 - vadc);
	    temp *= 4;
	    temp *= .00347;
	    temp += (10.888 * 10.888);
	    temp = sqrt(temp);
	    temp = 10.888 - temp;
	    temp /= (2 * -.00347);
	    temp += 30;
	    temp *= 1.8;
	    temp += 32;
	    convert1 = 0;
}


//carbon monoxide ppm conversion
if(convert2)
{
	    vadc2 = Nadc2 * 3300 / (2<<13);
	   // for (i = 30000; i > 0; i--); // wait for sensor to settle
	    if (vadc2 < 700)
	    {
	        coppm = 0;
	    }

	    else
	    {

	    coppm = .2368 * vadc2;
	    coppm -= 565.789;
	    }
	    convert2 = 0;

}


/*hydrogen
	    vadc3 = Nadc3 * 3300 / (2<<13);
	    for (i = 30000; i > 0; i--); // wait for sensor to settle
	    if (vadc3 < 1500)
	    {
	        hydrogenppm = 0;
	    }
	    else{
	    hydrogenppm = vadc3 - 1400;
	    }
*/


/*methane
	    vadc4 = Nadc4 * 3300 / (2<<13);
	    for (i = 30000; i > 0; i--); // wait for sensor to settle
	    if (vadc4 < 1500)
	    {
	        methaneppm = 0;
	    }
	    else
	    {
	    methaneppm = vadc4 * 4.1739;
	    methaneppm -= 5443.478;
	    }
*/
if(convert3)
{
//Liquified petroleum gas sensor
	    vadc5 = Nadc5 * 3300 / (2<<13);
	   // for (i = 30000; i > 0; i--); // wait for sensor to settle
	    if (vadc5 < 700)
	    {
	        lpgppm = 0;
	    }
	    else
	    {
	    lpgppm = vadc5 * 3.607;
	    lpgppm -= 5732.14;
	    }
	    convert3 = 0;
}
__enable_irq();
__no_operation();

}
}



	            // Don't wake up on exit from ISR
	           // SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;

	            // Ensures SLEEPONEXIT takes effect immediately
	          //  __DSB();

	          /*  // Arbitrary delay before transmitting the next byte
	            for (i = 5000; i > 0; i--);

	            // Ensure stop condition got sent
	            while (EUSCI_B0->CTLW0 & EUSCI_B_CTLW0_TXSTP);

	            // I2C start condition
	            EUSCI_B0->CTLW0 |= EUSCI_B_CTLW0_TXSTT;

	            // Go to LPM0
	            __sleep();
	            __no_operation();                   // for debug
	            */




	/*void TA0_0_IRQHandler()
	{
	    TIMER_A0->R &= 0;         // Reset count
	    TA0CCTL0 &= ~CCIFG;     //Clear interrupt
	    //uart_putchar_n("a",1);

	}

	void PORT2_IRQHandler()
	{
	    if(P2->IFG==BIT3){
	        count++;
	        P2->IFG &= ~BIT3;
	    }
	    P2->IFG &= 0x00;
	}
	void EUSCIA3_IRQHandler(void){
	    if(UCA3IFG&UCRXIFG){    //Rx interrupts
	        UCA3IFG &= ~UCRXIFG;    //clear flag
	        rxd=EUSCI_A3->RXBUF;
	        //CB_Add_Item(&buf,rxd);  //add item to buffer
	        uart_putchar0(rxd);    //Echo to terminal
	    }
	    else if(!(UCA3IFG&UCTXIFG)){       //Tx Interrupts
	        UCA3IFG &= ~UCTXIFG;        //clear flag
	    }
	}

	void EUSCIA0_IRQHandler(void){
	    if(UCA0IFG&UCRXIFG){    //Rx interrupts
	        UCA0IFG &= ~UCRXIFG;    //clear flag
	        rxd=EUSCI_A0->RXBUF;
	        //uart_putchar(rxd);    //part 10 (Echo)
	    }
	    else if(!(UCA0IFG&UCTXIFG)){       //Tx Interrupts
	        UCA0IFG &= ~UCTXIFG;        //clear flag
	    }
	}





	// I2C interrupt service routine
	void EUSCIB1_IRQHandler(void)
	{
	    if (EUSCI_B1->IFG & EUSCI_B_IFG_NACKIFG)
	    {
	        //reset flag
	        EUSCI_B1->IFG &= ~ EUSCI_B_IFG_NACKIFG;

	        // I2C start condition
	        EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTT;
	    }

	    if (EUSCI_B1->IFG & EUSCI_B_IFG_RXIFG0)
	    {
	        //reset flag
	        EUSCI_B1->IFG &= ~ EUSCI_B_IFG_RXIFG0;

	        // Get RX data
	        RXData[RXDataPointer++] = EUSCI_B1->RXBUF;

	        if (RXDataPointer > sizeof(RXData))
	        {
	            RXDataPointer = 0;
	        }

	        // Wake up on exit from ISR
	        SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;

	        // Ensures SLEEPONEXIT takes effect immediately
	        __DSB();
	    }
	    if (EUSCI_B1->IFG & EUSCI_B_IFG_BCNTIFG)
	    {
	        EUSCI_B1->IFG &= ~ EUSCI_B_IFG_BCNTIFG;
	    }
}
	void uart_putchar3(uint8_t tx_data){
	    while(!(UCA3IFG&UCTXIFG));
	    EUSCI_A3->TXBUF = tx_data;
	}

	void uart_putchar0(uint8_t tx_data){
	    while(!(UCA0IFG&UCTXIFG));
	    EUSCI_A0->TXBUF = tx_data;
	}

	void uart_putchar_n(uint8_t* data, uint32_t length){
	    int k=1;
	    while(k<=length){
	    uart_putchar3(*data);
	    data++;
	    k++;
	    }
	}
	*/



