//
// Created by zbxboris on 10/2/2025.
//

#include "gpio.h"
#include "tim.h"

uint32_t brightness = 0;
uint32_t count = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    brightness = (brightness + 500) % __HAL_TIM_GET_AUTORELOAD(&htim5);
    __HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_3, brightness);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim == &htim5) {
        count++;
    }
}
