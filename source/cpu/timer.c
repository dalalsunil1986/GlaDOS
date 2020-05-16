#include "timer.h"

uint32 tick = 0;

void timer_callback(registers_t regs) {
    tick++;
    // char tickInASCII[256];
    // itoa(tick, tickInASCII);
    // print_string(tickInASCII);
    // print_char('\n');
}

uint32 getTick() {
    return tick;
}

void init_timer(uint32 freq) {
    register_interrupt_handler(IRQ0, timer_callback);

    // 1.19... MHz hardware clock signal: 
    uint32 devisor = 1193180 / freq;
    uint8 low = (uint8)(devisor & 0xFF);
    uint8 high = (uint8)((devisor >> 8) & 0xFF);

    outb(0x43, 0x36);
    outb(0x40, low);
    outb(0x40, high);
}