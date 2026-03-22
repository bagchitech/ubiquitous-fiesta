/*
 * uart.c
 *
 *  Created on: 22-Mar-2026
 *      Author: madhu
 */

#include "uart.h"
#include "circularbuffer.h"
#include "global.h"

UART_HandleTypeDef huart1;
extern CircularBuffer tx_buffer;
extern CircularBuffer rx_buffer;

static uint8_t rx_byte;
static uint8_t tx_byte;

/* Initialize UART interrupt reception */
void uart_init(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_IT(huart, &rx_byte, 1);
}

/* Send single byte */
void uart_send(uint8_t data)
{
	cb_push(&tx_buffer, data);

	/* Start transmission if idle */
	if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TXE))
	{
		if (cb_pop(&tx_buffer, &tx_byte) == 0)
		{
			HAL_UART_Transmit_IT(&huart1, &tx_byte, 1);
		}
	}
}

/* Send string */
void uart_send_string(const char *str)
{
	while (*str)
	{
		uart_send((uint8_t)(*str));
		str++;
	}
}

/* RX complete callback */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)
	{
		cb_push(&rx_buffer, rx_byte);
		HAL_UART_Receive_IT(huart, &rx_byte, 1);
	}
}

/* TX complete callback */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)
	{
		if (cb_pop(&tx_buffer, &tx_byte) == 0)
		{
			HAL_UART_Transmit_IT(&huart1, &tx_byte, 1);
		}
	}
}

