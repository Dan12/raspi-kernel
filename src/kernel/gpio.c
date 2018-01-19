#include <kernel/gpio.h>

void gpio_led_init() {
	// init the led select function
	*(volatile uint32_t *) (GPIO_BASE + 0x10) = 1 << 21;
}

void gpio_write_led(int status) {
    // pin 15 wired to the ACT led (green)
	uint32_t ledNum = 1 << 15;
	if(status) {
		// turn on
		*(volatile uint32_t *) (GPIO_BASE + 0x20) = ledNum;
	} else {
		//clear
		*(volatile uint32_t *) (GPIO_BASE + 0x2C) = ledNum;
	}
}