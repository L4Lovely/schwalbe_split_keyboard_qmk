#pragma once
#include_next <mcuconf.h>
#undef RP2040_SIO_USE_UART0
#define RP2040_SIO_USE_UART0 FALSE