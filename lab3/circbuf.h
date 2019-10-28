/*
 * circbuf.h
 *
 *  Created on: Sep 25, 2017
 *      Author: andyhsu
 */
#include "msp.h"
#include <stdint.h>
#include "msp432p401r.h"
#include "msp432p401r_classic.h"
#ifndef CIRCBUF_H_
#define CIRCBUF_H_

typedef struct{
    uint8_t * buffer;
    volatile uint8_t * head;
    volatile uint8_t * tail;
    volatile uint8_t num_items;
    volatile uint16_t length;
}CircBuf_t;

typedef enum{
    CB_FULL = 1,
    CB_EMPTY = 0,
    CB_ERROR,
    CB_Success,
}CB_Status;

CB_Status CB_initialize_buffer(CircBuf_t ** buf, uint32_t length);
CB_Status CB_add_item_to_buffer(CircBuf_t * buf, uint8_t item);
uint8_t remove_item_from_buffer(CircBuf_t * buf);
#endif /* CIRCBUF_H_ */
