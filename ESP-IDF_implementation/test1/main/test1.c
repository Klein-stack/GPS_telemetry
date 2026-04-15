#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

const int ring_buffer_size = (1024*2);
QueueHandle_t queue_handler;

uart_driver_install(UART_NUM_1, ring_buffer_size, ring_buffer_size, 10, &queue_handler, 0);

uart_config_t uart_configurs = {
    .baud_rate = 115200,
    .data_bits = UART_DATA_8_BITS,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .parity = UART_PARITY_DISABLE
};

uint8_t data[128];
uart_read_bytes(UART_NUM_1 );
