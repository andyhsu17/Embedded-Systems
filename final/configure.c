#include "msp.h"
#include "stdio.h"
#include "stdlib.h"
#include "core_cm4.h"
//#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
/* Standard Includes */
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
//#include "bme280.h"

//#define SLAVE_ADDRESS_1     0x48
/* I2C Configuration Parameter */
/*
const eUSCI_I2C_MasterConfig i2cMasterConf =
{
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        3000000,                                // SMCLK = 3MHz
        EUSCI_B_I2C_SET_DATA_RATE_100KBPS,      // Desired I2C Clock of 100khz
        0,                                      // No Auto Stop
        EUSCI_B_I2C_NO_AUTO_STOP                // No Auto Stop
};
const eUSCI_SPI_SlaveConfig spiSlaveConfig =
{ EUSCI_B_SPI_MSB_FIRST,
        EUSCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT,
        EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH,
        EUSCI_B_SPI_3PIN
        };
const eUSCI_SPI_MasterConfig spiMasterConfig =
{ EUSCI_B_SPI_CLOCKSOURCE_SMCLK, 12000000, 1000000,
        EUSCI_B_SPI_MSB_FIRST,
        EUSCI_B_SPI_PHASE_DATA_CAPTURED_ONFIRST_CHANGED_ON_NEXT,
        EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH, EUSCI_B_SPI_3PIN };
*/
//void SPI_Configure(){
    /* Configure CLK, MOSI & MISO for SPI0 (EUSCI_B1) */
/*    MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1,
            GPIO_PIN5 | GPIO_PIN6, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
            GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
    MAP_SPI_initMaster(EUSCI_B1_BASE, &spiMasterConfig);*/
        /* Enable the SPI module */
//        MAP_SPI_enableModule(EUSCI_B1_BASE);
//}

//void I2C_Configure(){
    /* Initializing I2C Master on EUSCIB1  at 400Khz */
  /*      MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P6,    //select pin, set to primary mode: I2C
        GPIO_PIN4 | GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);
        MAP_I2C_initMaster(EUSCI_B1_BASE, &i2cMasterConf);
        MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, 0x48);*/
        /* eUSCI I2C Slave Configuration */
 /*           MAP_I2C_initSlave(EUSCI_B1_BASE, SLAVE_ADDRESS_1, EUSCI_B_I2C_OWN_ADDRESS_OFFSET0,
                    EUSCI_B_I2C_OWN_ADDRESS_ENABLE);
        MAP_I2C_setMode(EUSCI_B1_BASE, EUSCI_B_I2C_RECEIVE_MODE);   //set to receive mode
        MAP_I2C_enableModule(EUSCI_B1_BASE);        //enable channel
        MAP_Interrupt_enableInterrupt(INT_EUSCIB1);
}
*/
/*
void I2C_Configure(){

        // Configure USCI_B0 for I2C mode
        EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_SWRST; // Software reset enabled
        P6->SEL0 |= BIT4 | BIT5;                // I2C pins to USCI_B0
        P6->SEL1 &= ~(BIT4|BIT5);
        EUSCI_B1->CTLW0 = EUSCI_B_CTLW0_SWRST | // Remain eUSCI in reset mode
                EUSCI_B_CTLW0_MODE_3 |          // I2C mode
                EUSCI_B_CTLW0_MST |             // Master mode
                EUSCI_B_CTLW0_SYNC |            // Sync mode
                EUSCI_B_CTLW0_SSEL__SMCLK;      // SMCLK
        EUSCI_B1->CTLW1 |= EUSCI_B_CTLW1_ASTP_0;// No automatic stop
        EUSCI_B1->BRW = 30;                     // baudrate = SMCLK / 10 = 300kHz
        //EUSCI_B1->TBCNT = 0x0009;               // number of bytes to be received
        EUSCI_B1->I2CSA = 0x5B;               // Slave address when SDO connected to VDDIO
        EUSCI_B1->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;// Release eUSCI from reset

        EUSCI_B1->IE |=
                //EUSCI_B_IE_RXIE0 |       // Enable receive interrupt
                EUSCI_B_IE_NACKIE;
       //         | EUSCI_B_IE_TXIE0;
                            // Enable NACK interrupt
                //EUSCI_B_IE_BCNTIE;              // Enable byte counter interrupt
        NVIC_EnableIRQ(EUSCIB1_IRQn);
}
/*
void BME_Init(){
    struct bme280_dev dev;

    int8_t rslt;
    rslt = BME280_OK;

    dev.dev_id = BME280_I2C_ADDR_SEC;   //connect to VDDIO mode, slave address 0x77
    dev.intf = BME280_I2C_INTF;
    dev.read = user_i2c_read;
    dev.write = user_i2c_write;
    //dev.delay_ms = user_delay_ms;

    rslt = bme280_init(&dev);
}
*/
//void I2C_

/*void UART_Configure(){
    P9->SEL0    |= (BIT6|BIT7);
    P9->SEL1    &= ~(BIT6|BIT7);
    EUSCI_A3->CTLW0 |= 0x0001;  //put eUSCI in reset
    EUSCI_A3->CTLW0 |= UCSSEL_2;    //select clock sourse SMCLK
    EUSCI_A3->BRW   = 0x1A;    //set baud rate close to 9600
    EUSCI_A3->CTLW0 &=0xFFFE;   //Initialize eUSCI

    UCA3IE  |=((UCRXIE)|(UCRXIE));
    NVIC_EnableIRQ(EUSCIA3_IRQn);

    P1->SEL0    |= (BIT2|BIT3);
    P1->SEL1    &= ~(BIT2|BIT3);
    EUSCI_A0->CTLW0 |= 0x0001;  //put eUSCI in reset
    EUSCI_A0->CTLW0 |= UCSSEL_2;    //select clock sourse SMCLK
    EUSCI_A0->BRW   = 0x1A;    //set baud rate close to 9600
    EUSCI_A0->CTLW0 &=0xFFFE;   //Initialize eUSCI

    UCA0IE  |=((UCRXIE)|(UCRXIE));
    NVIC_EnableIRQ(EUSCIA0_IRQn);
}

void timer_a0_config(){
    TIMER_A0->R &= 0;         // Reset count
    TIMER_A0->CTL = TASSEL_2|MC_1|TACLR|ID_3;       // SMCLK, Up mode 3Mhz
    TIMER_A0->CCR[0] = 18590;    // Value to count to for 0.05s
    TIMER_A0->CCTL[0] = CCIE;   // TACCR0 interrupt enabled
    /* Enable Interrupts in the NVIC */
     // NVIC_EnableIRQ(TA0_0_IRQn);
//}
/*
void GPIO_configure() {
    //data from encoder pin2.3 J4.34
    P2->SEL0 &= ~BIT3;
    P2->SEL1 &= ~BIT3;
    P2->DIR &= ~BIT3;
    P2->REN |= BIT3;        //pull up
    P2->OUT |= BIT3; //pull up selected
    P2->IFG &= 0x00;
    P2->IES |= BIT3;
    P2->IE |= BIT3;
    // Left button configure
/*      P1->SEL0 &= 0xFD;         //1.1 to general I/O
      P1->SEL1 &= 0xFD;
      P1->DIR &= ~BIT1;        //Direction to input
      P1->REN |= 0x02;        //Enable Pull-up or Pull-Down
      P1->OUT |= 0x02;        //Select Pull-up
      P1->IFG &= 0x00;        //No interrupt is pending
      P1->IES |= 0x02;        //Flag High to Low transition
      P1->IE |= 0x02;         //Enable port interrupt

    // Right button configure
      P1->SEL0 &= 0xEF;
      P1->SEL1 &= 0xEF;
      P1->DIR &= ~BIT4;
      P1->REN |= 0x10;
      P1->OUT |= 0x10;
      P1->IFG &= 0x00;
      P1->IES |= 0x10;
      P1->IE |= 0x10;
*/
    /*
      P2->SEL0 &= ~BIT0;    //LED 2.0
      P2->SEL1 &= ~BIT0;
      P2->DIR |= BIT0;
      P2->OUT &= ~BIT0;

    P1->SEL0 &= BIT0;   //LED 1.0
    P1->SEL1 &= BIT0;
    P1->DIR |= BIT0;
    P1->OUT &= ~BIT0;


    // Enable Interrupts in the NVIC
     NVIC_EnableIRQ(PORT1_IRQn);
     NVIC_EnableIRQ(PORT2_IRQn);
}
/*
void configure_ADC(){
    P6SEL0 |= BIT0|BIT1;
    P6SEL1 |= 0;
    P4SEL0 |= (BIT0 | BIT2| BIT4);
    P4SEL1 |= BIT2|BIT4;
    while(REF_A->CTL0 & REF_A_CTL0_GENBUSY);
    REF_A->CTL0=REF_A_CTL0_VSEL_0 | REF_A_CTL0_ON;  //Vref 1.2V
    REF_A->CTL0 &= ~REF_A_CTL0_TCOFF;

    ADC14->CTL0&= ~ADC14_CTL0_ENC;//Disable ADC
    //Configure ADC - Pulse sample mode; ADC14SC register
    //ADC on , temperature sample period >30us
    ADC14->CTL0|=ADC14_CTL0_SHT0_5|ADC14_CTL0_ON|ADC14_CTL0_SHP|ADC14_CTL0_CONSEQ_1;
    ADC14->CTL1|=ADC14_CTL1_RES_3|ADC14_CTL1_TCMAP ;     //Conf internal temp sensor channel, set resolution
    //ADC14->MCTL[0]|=ADC14_MCTLN_VRSEL_0|ADC14_MCTLN_INCH_14;    //x Map Temp analog channel to MEM0/MCTL0, set 0-3.3 ref
    ADC14->MCTL[1]|=ADC14_MCTLN_VRSEL_0|ADC14_MCTLN_INCH_13;    //y Map Temp analog channel to MEM1/MCTL1, set 0-3.3 ref
   // ADC14->MCTL[2]|=ADC14_MCTLN_VRSEL_0|ADC14_MCTLN_INCH_11;    //z Map Temp analog channel to MEM2/MCTL2, set 0-3.3 ref
   // ADC14->MCTL[0]|=ADC14_MCTLN_VRSEL_0|ADC14_MCTLN_INCH_15;  // joystick x
   // ADC14->MCTL[1]|=ADC14_MCTLN_VRSEL_0|ADC14_MCTLN_INCH_9;  // joystick y
    ADC14->IER0|=ADC14_IER0_IE1;   //Enable MCTL0/MEM0 Interrupts

    while(!(REF_A->CTL0&REF_A_CTL0_GENRDY));
    ADC14->CTL0|=ADC14_CTL0_ENC;  //Enable conversions
    NVIC_EnableIRQ(ADC14_IRQn);
}
/*
void RTC_configure(){
    // Configure RTC
        RTCCTL0_H = RTCKEY_H ;                 // Unlock RTC key protected registers
        RTCCTL0_L |= RTCTEVIE ;
        RTCCTL0_L &= ~(RTCTEVIFG);
        RTCCTL1 = RTCBCD | RTCHOLD ;
        // RTC enable, BCD mode, RTC hold
        // enable RTC read ready interrupt
        // enable RTC time event interrupt

        RTCYEAR = 0x2017;                         // Year = 0x2010
        RTCMON = 0x11;                             // Month = 0x04 = April
        RTCDAY = 0x27;                            // Day = 0x05 = 5th
        RTCDOW = 0x01;                            // Day of week = 0x01 = Monday
        RTCHOUR = 0x10;                           // Hour = 0x10
        RTCMIN = 0x32;                            // Minute = 0x32
        RTCSEC = 0x45;                            // Seconds = 0x45

        RTCADOWDAY = 0x2;                         // RTC Day of week alarm = 0x2
        RTCADAY = 0x20;                           // RTC Day Alarm = 0x20
        RTCAHOUR = 0x10;                          // RTC Hour Alarm
        RTCAMIN = 0x23;                           // RTC Minute Alarm

        RTCCTL1 &= ~(RTCHOLD);                    // Start RTC calendar mode

        RTCCTL0_H = 0;                            // Lock the RTC registers

        /* Enable all SRAM bank retentions prior to going to LPM3 (Deep-sleep) */

/*
        SYSCTL->SRAM_BANKRET |= SYSCTL_SRAM_BANKRET_BNK7_RET;
        __enable_interrupt();
        NVIC_EnableIRQ(RTC_C_IRQn);
        SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;        // Sleep on exit from ISR
}
*/
