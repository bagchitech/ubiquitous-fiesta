/*
 * global.h
 *
 *  Created on: 22-Mar-2026
 *      Author: madhu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "circularbuffer.h"

extern CircularBuffer rx_buffer, tx_buffer;


/*Declaration of the states*/
typedef enum{
	STATE_OFF,
	STATE_ON,
	STATE_SLOW,
	STATE_FAST
}States;

extern volatile States current_state;

#endif /* INC_GLOBAL_H_ */
