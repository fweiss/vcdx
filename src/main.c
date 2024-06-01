#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"
#include "string.h"

#define UART_PORT_NUM      UART_NUM_2
#define UART_BAUD_RATE     115200
#define UART_TX_PIN        17
#define UART_RX_PIN        16

void app_main(void) {
    // Configure UART parameters
    uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    // Install UART driver
    uart_driver_install(UART_PORT_NUM, 1024 * 2, 0, 0, NULL, 0);
    uart_param_config(UART_PORT_NUM, &uart_config);
    uart_set_pin(UART_PORT_NUM, UART_TX_PIN, UART_RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    // String to be sent to UART
    // only "Yuyintianxia" is spoken
    // none of the English words are spoken
    
    // const char *data = "Hello, UART!\n";
    // const char data[] = {0xAA, 0x00, 0x00, 0xAB};
    // const char data[] = {0xFD, 0x00, 0x01, 0x21}; // status
    const char data[] = {0xFD,    0x00, 0x0A,   0x01, 0x03,    0x87, 0x5B, 0xF3, 0x97, 0x29, 0x59, 0x0B, 0x4E}; // Yuyintianxia
    // const char data[] = {0xFD,    0x00, 13,   0x01, 0x04,    'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D'};
    // const char data[] = {0xFD,    0x00, 17,   0x01, 0x03,    '[', 'h', '2', ']', 'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D'};
    // const char data[] = {0xFD,    0x00, 20,   0x01, 0x03,    0x00, 0x5b, 0x00, 0x67, 0x00, 0x32, 0x00, 0x5d,    0x00, 0x68, 0x00, 0x65, 0x00, 0x6c, 0x00, 0x6c, 0x00, 0x6f};

    while (1) {
        // Send data
        uart_write_bytes(UART_PORT_NUM, data, sizeof(data));
        vTaskDelay(4000 / portTICK_PERIOD_MS); // Wait for 1 second
    }
}
