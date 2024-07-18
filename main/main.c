#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUTTON_PIN 4
#define LED_PIN 5

void app_main(void)
{
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);

    while (1) {
        if (gpio_get_level(BUTTON_PIN) == 0) {
            gpio_set_level(LED_PIN, 1);  // ถ้ากดสวิตช์ LED ติด
        } else {
            gpio_set_level(LED_PIN, 0);  // ถ้าปล่อยสวิตช์ LED ดับ
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);  // รอสักครู่
    }
}
