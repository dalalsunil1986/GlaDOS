#include "timer.h"
#include "../drivers/screen.h"

volatile uint32 tticks = 0; // Volatile means the value can change at any moment without this variable having any code nearby that can change it

void init_timer(void) {
    register_interrupt_handler(IRQ0, (unsigned)timer_callback);
}

void timer_callback(registers_t regs){
    tticks++;
}

uint32 getTimerTicks(void) {
    return tticks;
}