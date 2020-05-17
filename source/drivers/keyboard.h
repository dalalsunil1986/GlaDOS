#ifndef __KEYBOARD_H
#define __KEYBOARD_H
#include "../kernel/int_types.h"
#include "asm_utils.h"
#include "../cpu/isr.h"
#include "scrn.h"
#include "../kernel/utils.h"
#include "scancodes.h"


void init_keyboard();
void waitForKey(void);
//int scancodeToChar(uint8 s, char* charVal);
int getKeyPressed(uint8 key);

#endif