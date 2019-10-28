/*
 * lab12.c
 *
 *  Created on: Sep 7, 2017
 *      Author: andyhsu
 */


#include "msp.h"
#include <stdint.h>

/*
 * lab_1.c
 *
 *  Created on: Sep 6, 2017
 *      Author: anhs3970
 *
 */
void report_types(){
uint8_t size = sizeof(char);
size = sizeof(int);
size = sizeof(short);
size = sizeof(long);
size = sizeof(long int);
size = sizeof(short int);
size = sizeof(float);
size = sizeof(double);
size = sizeof(unsigned char);
size = sizeof(signed char);
size = sizeof(unsigned short);
size = sizeof(signed short);
size = sizeof(unsigned int);
size = sizeof(signed int);
size = sizeof(int8_t);
size = sizeof(uint8_t);
size = sizeof(int16_t);
size = sizeof(uint16_t);
size = sizeof(int32_t);
size = sizeof(uint32_t);
}
void report_pointer_types(){
    uint8_t size = sizeof(char*);
    size = sizeof(int*);
    size = sizeof(short*);
    size = sizeof(long*);
    size = sizeof(long int*);
    size = sizeof(short int*);
    size = sizeof(float*);
    size = sizeof(double*);
    size = sizeof(unsigned char*);
    size = sizeof(signed char*);
    size = sizeof(unsigned short*);
    size = sizeof(signed short*);
    size = sizeof(unsigned int*);
    size = sizeof(signed int*);
    size = sizeof(int8_t*);
    size = sizeof(uint8_t*);
    size = sizeof(int16_t*);
    size = sizeof(uint16_t*);
    size = sizeof(int32_t*);
    size = sizeof(uint32_t*);
}
