#include <stddef.h>
#include <stdint.h>
#include <kernel/peripheral.h>

#ifndef GPIO_H
#define GPIO_H

enum {
    // The GPIO registers base address.
    GPIO_BASE = PERIPHERAL_BASE + GPIO_OFFSET,
    // The offsets for reach register.

    // Controls actuation of pull up/down to ALL GPIO pins.
    GPPUD = (GPIO_BASE + 0x94),

    // Controls actuation of pull up/down for specific GPIO pin.
    GPPUDCLK0 = (GPIO_BASE + 0x98),
};

void gpio_led_init();

void gpio_write_led(int status);

#endif