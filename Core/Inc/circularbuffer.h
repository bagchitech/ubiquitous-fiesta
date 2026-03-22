/*
 * circularbuffer.h
 *
 *  Created on: 22-Mar-2026
 *      Author: madhu
 */

#ifndef INC_CIRCULARBUFFER_H_
#define INC_CIRCULARBUFFER_H_

#include<stdint.h>
#define BUFFER_LEN 128

/*Circular Buffer Definition*/
typedef struct{
	uint8_t data[BUFFER_LEN];
	volatile uint8_t head;
	volatile uint8_t tail;
}CircularBuffer;

/*Circular Buffer Initialization*/
void cb_init(CircularBuffer *cb);

/*Circular Buffer Write*/
int cb_push(CircularBuffer *cb, uint8_t data);

/*Circular Buffer Read*/
int cb_pop(CircularBuffer *cb, uint8_t *data);

#endif /* INC_CIRCULARBUFFER_H_ */
