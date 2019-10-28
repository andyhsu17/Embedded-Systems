/*
 * circbuf.c
 *
 *  Created on: Sep 25, 2017
 *      Author: andyhsu
 */
#include "circbuf.h"
#include "msp.h"

CB_Status CB_initialize_buffer(CircBuf_t ** buf, uint32_t length){
    if (length > 256){
        return CB_ERROR;
    }
    (*buf)->buffer = (uint8_t *) malloc(length);
    (*buf)->head = (*buf)->buffer;
    (*buf)->tail = (*buf)->buffer;
    (*buf)->length = length;
    (*buf)->num_items = 0;

    return CB_EMPTY;
    }
CB_Status CB_clear_buffer(CircBuf_t * buf){
if(!buf) return CB_ERROR;
*buf->head = 0;
*buf->tail = 0;
return CB_Success;
}
CB_Status CB_delete_buffer(CircBuf_t * buf){
free(buf);
}
int8_t CB_is_buffer_full(CircBuf_t * buf){
    if(!buf || buf->num_items > buf->length - 1){
        return CB_ERROR;
    }
    if((buf->num_items == buf->length - 1) && (buf->head == buf->tail)){
        return CB_FULL;
    }
    else{
        return 0;
    }
}

int8_t CB_is_buffer_empty(CircBuf_t * buf){
    if(!buf){
        return CB_ERROR;
    }
if((buf->num_items == 0) && (buf->head == buf->tail)){
    return CB_EMPTY;
}
else if(buf->num_items){
    return 0;
}
}


CB_Status CB_add_item_to_buffer(CircBuf_t * buf, uint8_t item){
    if(!buf || !buf->head || !buf->tail) return CB_ERROR;
    if(buf->num_items == (buf->length - 1)) return CB_FULL;

    *buf->head = item;
    *buf->head++;
    buf->num_items++;

    return CB_Success;
}

uint8_t remove_item_from_buffer(CircBuf_t * buf){
    if (buf->num_items == 0) return CB_EMPTY;
    uint8_t temp = *buf->tail;
    buf->tail++;
    buf->num_items--;

    return temp;
}

