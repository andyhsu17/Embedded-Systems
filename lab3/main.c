#include "msp.h"
//#include "cmsis_css.h"
#include "uart.h"
#include "circbuf.h"
#include "lab3.h"
/**
 * main.c

 */
CircBuf_t buffer;
CircBuf_t * pointer1 = &buffer;

extern volatile uint32_t countwave = 0;
extern volatile float diameter = .09988;
extern volatile float distance = 0;
extern volatile float distance1 = 0;
extern volatile float pi = 3.14159265;
extern volatile uint8_t val = 1;

void main(void)
{

	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	UART_Configure();
	uint16_t length1 = 256;
	//uint8_t send;
	CB_initialize_buffer(pointer1, length1);
	char str[20];
while(val){

//CB_clear_buffer(pointer1);
    ftoa(distance1, str, 4);
    UART_send_byte(str);
CB_add_item_to_buffer(distance1);

}
UART_send_n(pointer1, 256);


	/*EUSCI_A0->CTLW0 |= EUSCI_A_CTLW0_SWRST;
	P4->SEL0 |= BIT4; //configure UART pins to primary
	P4->SEL1 &= ~BIT4;
	P4->DIR |= BIT4;
	EUSCI_A0->CTLW0 &= ~EUSCI_A_CTLW0_SWRST;
*/

  /*  while(1){

    UART_send_n("why not zoidberg?", 17);

}
    NVIC_EnableIRQ(EUSCIA0_IRQn);

    __attribute__( ( always_inline ) ) static inline void __NOP(void)
    {
        __asm("  nop");
    }
    __attribute__( ( always_inline ) ) static inline void __wfi(void)
    {
        __asm("  wfi");
    }
    */

}
