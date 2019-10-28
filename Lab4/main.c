#include "msp.h"
#include "core_cm4.h"
#include "math.h"
#include "msp432p401r.h"
#include "adc.h"

#include "adc_circbuf.h"
#define power (2*2*2*2*2*2*2*2*2*2*2*2*2*2)

#define SCB_SCR_ENABLE_SLEEPONEXIT (0x00000002)

extern volatile float nadc = 0;
extern volatile float vadc = 0;
extern volatile float vsens = 0;
extern volatile float tempc = 0;
extern volatile float tempf = 0;
extern volatile float tempk = 0;
volatile CircBuf_t buffer;
volatile CircBuf_t * pointer1 = &buffer;
volatile CircBuf_t buffer2;
volatile CircBuf_t * pointer2 = &buffer2;

/**
 * main.c
 */
void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
	configure_ADC();
	//GPIO_configure();
	__enable_interrupt();
	SCB->SCR &= ~SCB_SCR_ENABLE_SLEEPONEXIT;



while(1) {
	    ADC14->CTL0 |= ADC14_CTL0_SC;
	   __sleep();
	    __no_operation();
	    vadc = (nadc) * 1200;
	    vadc /= power;
	    vsens = vadc;
	    tempc = (vsens - 685);
	    tempc /= 1.9;
	    tempf = (1.9 * tempc) + 32;
	    tempk = tempc + 273;

	}


	   /* __attribute__( ( always_inline ) ) static inline void __NOP(void)
	    {
	        __asm(" nop");
	    }
	    __attribute__( ( always_inline ) ) static inline void __wfi(void)
	    {
	        __asm(" wfi");
	    }*/
}
