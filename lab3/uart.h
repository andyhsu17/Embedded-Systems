/*
 * uart.h
 *
 *  Created on: Sep 25, 2017
 *      Author: andyhsu
 */
#include "msp.h"
#include <stdint.h>
#include "msp432p401r_classic.h"
#include "msp432p401r.h"
#ifndef UART_H_
#define UART_H_

void UART_send_n(uint8_t * data, uint32_t length);
void UART_send_byte(uint8_t data);
void UART_Configure();


#endif /* UART_H_ */
