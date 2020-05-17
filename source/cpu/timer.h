#ifndef __TIMER_H
#define __TIMER_H

#include "../drivers/asm_utils.h"
#include "../cpu/isr.h"
#include "../drivers/scrn.h"
#include "../kernel/utils.h"
#include "../kernel/int_types.h"

void init_timer(uint32 freq);
uint32 getTick(void);

#endif