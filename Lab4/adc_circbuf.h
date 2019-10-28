/*
 * adc_circbuf.h

 *
 *  Created on: Oct 11, 2017
 *      Author: andyhsu
 */
#include "msp.h"
#include <stdint.h>
#include "msp432p401r_classic.h"
#include "msp432p401r.h"

#ifndef ADC_CIRCBUF_H_
#define ADC_CIRCBUF_H_
typedef struct
{
    uint8_t * buffer;
    volatile uint8_t * head;
    volatile uint8_t * tail;
    volatile uint16_t num_items;
    volatile uint16_t length;

}CircBuf_t;

typedef enum
{
    CB_FULL = 1,
    CB_NOT_FULL = 0,
    CB_EMPTY = 1,
    CB_NOT_EMPTY = 0,
    CB_ERROR = 0,
    CB_Success = 1,
}CB_Status;

CB_Status CB_initialize_buffer(CircBuf_t ** buf, int16_t length);
CB_Status CB_add_item_to_buffer(CircBuf_t * buf, uint8_t item);
CB_Status CB_delete_buffer(CircBuf_t * buf);
CB_Status CB_clear_buffer(CircBuf_t * buf);
uint8_t remove_item_from_buffer(CircBuf_t * buf);
//int8_t CB_is_buffer_empty(CircBuf_t * buf);
//int8_t CB_is_buffer_full(CircBuf_t * buf);
CB_Status peak_in_buffer(CircBuf_t * buf);

#endif /* ADC_CIRCBUF_H_ */
