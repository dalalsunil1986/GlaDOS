#include "timer.h"
#include "../drivers/screen.h"

uint32 timer_ticks;

void init_timer(void) {
    timer_ticks = 0;
    register_interrupt_handler(IRQ0, timer_callback);
}

void timer_callback(registers_t regs){
    timer_ticks+=1;
}

uint32 getTimerTicks(void) {
    return timer_ticks;
}