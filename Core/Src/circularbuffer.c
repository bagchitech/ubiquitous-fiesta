/*
 * circularbuffer.cpp
 *
 *  Created on: 22-Mar-2026
 *      Author: madhu
 */

#include "circularbuffer.h"

/*Initialize the Circular Buffer */

void cb_init(CircularBuffer *cb){
	cb->head = 0;
	cb->tail = 0;
}

/* Write into the circular buffer*/

int cb_push(CircularBuffer *cb, uint8_t data){
	uint8_t next = (cb->head+1) % BUFFER_LEN;

	if(next == cb->tail){
		return -1; //Buffer is full
	}

	cb->data[cb->head] =  data;
	cb->head = next;
	return 0; //SUCCESS


}

/*Read from the Circular Buffer*/

int cb_pop(CircularBuffer *cb, uint8_t *data){
	if(cb->tail == cb->head){
		return -1; //Buffer is Empty
	}
	*data = cb->data[cb->tail];
	cb->tail = (cb->tail+1) % BUFFER_LEN;
	return 0; //Success
}
