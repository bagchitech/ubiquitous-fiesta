/*
 * global.c
 *
 *  Created on: 22-Mar-2026
 *      Author: madhu
 */


#include "global.h"

CircularBuffer rx_buffer;
CircularBuffer tx_buffer;

volatile States current_state = STATE_OFF;
