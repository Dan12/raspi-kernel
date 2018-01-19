#include <stddef.h>
#include <stdint.h>
#include <kernel/uart.h>
#include <kernel/mem.h>
#include <kernel/atag.h>
#include <kernel/kerio.h>
#include <kernel/gpu.h>
#include <kernel/interrupts.h>
#include <kernel/timer.h>
#include <kernel/process.h>
#include <kernel/gpio.h>
#include <common/stdlib.h>

void test(void) {
    int i = 0;
    while (1) {
        printf("test %d\n", i++);
        udelay(1000000);
    }
}

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    // Declare as unused
    (void) r0;
    (void) r1;
    // (void) atags;

    char buf[256];

    mem_init((atag_t *)atags);

    gpu_init(); 
    printf("GPU INITIALIZED\n");
    printf("INITIALIZING INTERRUPTS...");
    interrupts_init();
    printf("DONE\n");
    printf("INITIALIZING TIMER...");
    timer_init();
    printf("DONE\n");
    // printf("INITIALIZING SCHEDULER...");
    // process_init();
    // printf("DONE\n");

    puts("Hello, kernel World!\n");

    #ifdef HARDWARE
    int led_state = 1;
    gpio_led_init();

    //create_kernel_thread(test, "TEST", 4);

    int i = 0;
    while (1) {
        printf("main %d\n", i++);
        gpio_write_led(led_state);
        // ~.5 seconds
        udelay(500000);
        // delay(0x3F000);
        led_state = !led_state;
        // if (atags == 0x100) {
        //     break;
        // }
    }

    #else

    while (1) {
        gets(buf, 256);
        puts(buf);
        puts("\n"); 
    }

    #endif
}
