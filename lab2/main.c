#include "msp.h"
#include <stdint.h>
#include "msp432p401r.h"
#include "msp432p401r_classic.h"
#include "port.h"


void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // disable watchdog

  GPIO_configure();  //configure button 1 & 2

 /* <CONFIGURE_TIMER>
  <ENBALE_GLOBAL_INTERRUPTS>
*/
	//while (1);

}

void PORT1_IRQHandler()
{

}

/*void ISR-FUNCTION-TIMER()
{

}
*/

/*void timer_a0_config(){
    TIMER_A0->R = ???;         // Reset count
    TIMER_A0->CTL = ???;       // SMCLK, Up mode
    TIMER_A0->CCR[0] = ???;    // Value to count to
    TIMER_A0->CCTL[0] = ???;   // TACCR0 interrupt enabled

     Enable Interrupts in the NVIC
	  NVIC_EnableIRQ(???);
}
*/
