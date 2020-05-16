#ifndef __KEYBOARD_H
#define __KEYBOARD_H
#include "../kernel/int_types.h"
#include "asm_utils.h"
#include "../cpu/isr.h"
#include "scrn.h"
#include "../kernel/utils.h"


void init_keyboard();
void waitForKey(void);

#endif