#include "msp.h"


/**
 * main.c
 */
void foo(uint8_t * ptr_a, uint32_t * ptr_b){
    *ptr_a += 2;
    (*(uint8_t *)(ptr_b))++;
    ptr_b++;
}

int main(){

    //creating memory
	uint8_t memory[8] = {0x44, 0x10, 0x42, 0x32, 0x40, 0xFF, 0x67, 0xFF};

	//initializing pointers 1 and 2 to addresses
	uint32_t * ptr1 = (uint32_t *)(&memory[0]);
	uint8_t * ptr2 = (uint8_t *)(&memory[2]);
	(*(uint8_t *)(ptr1)) >>= 1;
	ptr2++;
	*ptr1 += 512;

	//call foo with two pointers
	foo(((uint8_t*)(&memory[5])), ptr1);
	ptr1++;
	*ptr1 -= 4;
	ptr2 += 2;
	(*ptr2)++;
	--*ptr1;
	return 0;
}
