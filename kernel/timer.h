#ifndef __TIMER_H
#define __TIMER_H

#include "../cpu/isr.h"
#include "inttypes.h"

void init_timer(void);
void timer_callback(registers_t regs);
uint32 getTimerTicks(void);

#endif