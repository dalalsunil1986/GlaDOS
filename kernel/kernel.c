#include "../drivers/screen.h"
#include "./inttypes.h"
#include "./asm_utils.h"
#include "../cpu/isr.h"
#include "../drivers/keyboard_driver.h"
#include "detect_mem.h"
#include "utils.h"
#include "timer.h"
#include "mem.h"

// This function is called by the kernel_entry.asm file
void _start(void) {
    install_isr();
	enable_interrupts();
    init_vga_t();
    init_timer();
    init_keyboard();
    setForegroundColor(VGA_GREEN);
    setBackgroundColor(VGA_BLACK);
    uint32 ticks = 0;
    while(ticks < 50){
        
        char string[32];
        ticks = getTimerTicks();
        itoa(ticks, string);
        appendc(string, '\n');
        printk(string);
        
    }
    printk("test");
}