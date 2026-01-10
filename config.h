#pragma once

// #define ROWS_PER_HAND 4
// #define SPLIT_TRANSACTION_TIMEOUT 15

// #define SERIAL_DRIVER vendor
// #define SERIAL_UART_PROTOCOL_NUMBER 0
// #define SERIAL_UART_BAUD 115200

#define EE_HANDS //??
#ifndef INIT_EE_HANDS_RIGHT

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.

    //left side (usb connected master)
    // #define SERIAL_UART_TX_PIN GP16
    // #define SERIAL_UART_RX_PIN GP17
    
#define SERIAL_USART_TX_PIN GP16     // USART TX pin
#define SERIAL_USART_RX_PIN GP17     // USART RX pin

    //right side (uart connected)
    // #define SERIAL_UART_TX_PIN GP0
    // #define SERIAL_UART_RX_PIN GP1
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin


// #define SERIAL_UART_TX_PIN_SLAVE GP0
// #define SERIAL_UART_RX_PIN_SLAVE GP1
