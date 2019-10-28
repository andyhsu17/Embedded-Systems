#include "msp.h"
#include "scoot.h"
#include "core_cm4.h"
#include "circbuf.h"
#include "uart.h"
#define SCB_SCR_ENABLE_SLEEPONEXIT (0x00000002)

/**
 * main.c

 */
volatile uint8_t receive;
volatile float Nadc;
volatile uint16_t zacc;
volatile uint16_t yacc;
volatile uint8_t data;
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	//GPIO_Configure();
	configure_ADC_Accelerometer();
	SCB->SCR &= ~SCB_SCR_ENABLE_SLEEPONEXIT;
	__enable_irq();

while(1)
{
    ADC14->CTL0 |= ADC14_CTL0_SC;
    __sleep();
    __no_operation();
}
}
