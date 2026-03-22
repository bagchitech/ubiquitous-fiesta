/*
 * uart.h
 *
 *  Created on: 22-Mar-2026
 *      Author: madhu
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32h7xx_hal.h"
#include "circularbuffer.h"
#include "global.h"

extern UART_HandleTypeDef huart1;

/*Initialize the UART*/
void uart_init(UART_HandleTypeDef *huart1);


/*Send data through the UART*/
void uart_send(uint8_t data);

void uart_send_string(const char *str);

/*Receive data through the UART*/
int uart_read(uint8_t *data);


#endif /* INC_UART_H_ */
