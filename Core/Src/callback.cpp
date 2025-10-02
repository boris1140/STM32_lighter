//
// Created by zbxboris on 10/2/2025.
//
#include "main.h"
#include "string.h"
#include "usart.h"

extern uint8_t rx_msg[4];
extern uint8_t tx_msg[4];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart) {
    if (huart == &huart1) {
        memcpy(tx_msg, rx_msg, 4);
        HAL_UART_Transmit_IT(&huart1, tx_msg, 4);
        HAL_UART_Receive_IT(&huart1, rx_msg, 4);
    }
}