/*
 * scoot.h
 *
 *  Created on: Nov 1, 2017
 *      Author: andyhsu
 */
#include "msp.h"
#include <stdint.h>
#include "msp432p401r_classic.h"
#include "msp432p401r.h"
#ifndef SCOOT_H_
#define SCOOT_H_
//void GPIO_Configure();
void reverse();
void ftoa(float n, char * res, int afterpoint);
int8_t itoa();
void configure_ADC_Accelerometer();


#endif /* SCOOT_H_ */
