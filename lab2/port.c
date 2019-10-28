
#include "msp432p401r.h"
#include "msp432p401r_classic.h"
#include "port.h"
#include "msp.h"

void GPIO_configure() {

    //data from encoder
 /* P1->SEL0 = ???;
  P1->SEL1 = ???;
    P1->DIR = ???;
    P1->REN = ???;
    P1->OUT = ???;
    P1->IFG = ???;
    P1->IES = ???;
    P1->IE = ???;
    */

  /* Left button configure */
    P1->SEL0 &= ~BIT1;
    P1->SEL1 &= ~BIT1;
    P1->DIR &= ~BIT1;
    P1->REN |= BIT1;
    P1->OUT |= BIT1;
    P1->IFG &= ~BIT1;
    P1->IES |= BIT1;
    P1->IE = BIT1 | BIT4; //p1 and p4 interrupts enabled

    /* Right button configure */
    P1->SEL0 &= ~BIT4;
    P1->SEL1 &= ~BIT4;
    P1->DIR &= ~BIT1;
    P1->REN |= BIT4;
    P1->OUT |= BIT4;
    P1->IFG &= ~BIT4;
    P1->IES |= BIT4;


    /*Red LED configuration*/
     P2->SEL0 &= ~BIT0;
      P2->SEL1 &= ~BIT0;
        P2->DIR |= BIT0;
        P2->OUT |= BIT0;

        /*Green LED configuration*/
        P2->SEL0 &= ~BIT1;
        P2->SEL1 &= ~BIT1;
        P2->DIR |= BIT1;
        P2->OUT &= ~BIT1;


        /*Blue LED configuration*/
         P2->SEL0 &= ~BIT2;
         P2->SEL1 &= ~BIT2;
         P2->DIR |= BIT2;
         P2->OUT &= ~BIT2;


    /* Configure Latency Test Output Pin */
 /* P1->SEL0 = ???;
  P1->SEL1 = ???;
    P1->DIR = ???;
    P1->OUT = ???;
    */

  /* Enable Interrupts in the NVIC */
    //NVIC_EnableIRQ(???);
}


