#ifndef __KEYBOARD_DRIVER_H
#define __KEYBOARD_DRIVER_H

#include "../cpu/isr.h"
#include "../kernel/inttypes.h"
#include "../kernel/asm_utils.h"

void init_keyboard(void);
void keyboard_callback(registers_t regs);
uint8 getKeyPressed(uint8 key);
void waitForKeyPress(void);

#endif