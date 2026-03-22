/*
 * uart.c
 *
 *  Created on: 22-Mar-2026
 *      Author: madhu
 */

#include "uart.h"

/*Initialize the UART peripheral*/
UART_HandleTypeDef huart1;

void uart_init(UART_HandleTypeDef *huart){
	//The clock is already configured by the HAL generated code
	HAL_UART_Receive_IT(huart, (uint8_t[]){0}, 1); // Starting the UART RX
}

/*Transmit Data*/

void uart_send(uint8_t data){
	cb_push(&tx_buffer, data);

	    // start transmission if idle
	    if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TXE))
	    {
	        uint8_t d;
	        if (cb_pop(&tx_buffer, &d) == 0)
	        {
	            HAL_UART_Transmit_IT(&huart1, &d, 1);
	        }
	    }
}
/*Read Data*/

int uart_read(uint8_t *data)
{
    return cb_pop(&rx_buffer, data);
}

/* Receive Callback Function Redefined*/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    uint8_t byte = huart->Instance->RDR;
    cb_push(&rx_buffer, byte);

    // restart interrupt for next byte
    HAL_UART_Receive_IT(huart, &byte, 1);
}

/*Transmit Callback Function Redefined*/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    uint8_t byte;
    if (cb_pop(&tx_buffer, &byte) == 0)
    {
        HAL_UART_Transmit_IT(huart, &byte, 1);
    }
}
