
 /*
 * lab1.h
 *
 *  Created on: Sep 6, 2017
 *      Author: anhs3970
 */

#ifndef LAB1_H_
#define LAB1_H_
#define bit0 0x40004C00
#define bit1 0x40004C0A
#define bit2 0x40004C0C
#define bit3 0x40004C02
#define bit4 0x40004C05


 unsigned int count = 0;
    unsigned int i = 0;

	uint8_t * p1in = (uint8_t*)bit0;
	uint8_t * p1SEL0 = (uint8_t*)bit1;
	uint8_t * p1SEL1 = (uint8_t*)bit2;
	uint8_t * p1out = (uint8_t*)bit3;
	uint8_t * p1DIR = (uint8_t*)bit4;

	void report_types();
	void report_pointer_types();


#endif /* LAB1_H_ */
