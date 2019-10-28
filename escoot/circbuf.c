/*
 * circbuf.c
 *
 *  Created on: Nov 1, 2017
 *      Author: andyhsu
 */


/*
 * adc_circbuf.c
 *
 *  Created on: Oct 11, 2017
 *      Author: andyhsu
 */
#include "circbuf.h"
#include "msp.h"
#include <stdlib.h>
CB_Status CB_initialize_buffer(CircBuf_t ** buf, int16_t length)
{
    if(length > 256 || length < 0)
    {
        return CB_ERROR;
    }
    uint8_t * buf2 = (uint8_t *)malloc(length * sizeof(uint8_t));
    (*buf)->buffer = buf2;
    (*buf)->head = buf2;
    (*buf)->tail = buf2;
    (*buf)->length = length;
    (*buf)->num_items = 0;

    return CB_EMPTY;
}

CB_Status CB_add_item_to_buffer(CircBuf_t * buf, uint8_t item)
{
    if(buf->num_items == (buf->length))
    {
        return CB_FULL;
    }
    if(buf->head == buf->buffer + buf->length)
    {
        buf->head = buf->buffer - 1;
        *buf->head = item;
        buf->head++;
        buf->num_items++;
        return CB_Success;
    }

    *buf->head = item;
    buf->head++;
    buf->num_items++;
    return CB_Success;
}
uint8_t remove_item_from_buffer(CircBuf_t * buf)
{
    if(buf->num_items == 0)
    {
        return CB_EMPTY;
    }
    if(buf->tail == buf->buffer + buf->length)
    {
        uint8_t temp = *buf->tail;
        buf->tail = buf->buffer;
        buf->num_items--;
    }
    uint8_t temp = *buf->tail;
    buf->tail++;
    buf->num_items--;
    return temp;
}

    CB_Status CB_delete_buffer(CircBuf_t * buf)
    {
        free(buf);
        return CB_Success;
    }

    CB_Status CB_clear_buffer(CircBuf_t * buf)
    {
        unsigned int i = 0;
        while(i < buf->length)
        {
            buf->head = buf->buffer + i;
            *buf->head = 0;
            i++;
        }
        buf->head = buf->buffer;
        buf->tail = buf->buffer;
        buf->num_items = 0;
        return CB_Success;
    }

    CB_Status peak_in_buffer(CircBuf_t * buf)
    {
        volatile uint8_t * original_tail;
        uint8_t temp;
        original_tail = buf->tail;

        if(!buf)
        {
            return CB_ERROR;
        }
        while(buf->tail != buf->head)
        {
            temp = *buf->tail;
            UART_send_byte(temp);
            buf->tail++;
        }
        buf->tail = original_tail;

    }


