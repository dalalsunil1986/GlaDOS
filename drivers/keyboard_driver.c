#include "keyboard_driver.h"

#define NUM_KEYS 88
uint8 keys[NUM_KEYS];
uint8 keyPressed = 0;

void init_keyboard(void){
    register_interrupt_handler(IRQ1, keyboard_callback);
}

void keyboard_callback(registers_t regs) {
    uint8 scancode = inb(0x60);     // The PIC puts the scancode on this port
    if(scancode <= 0x80){           
        keyPressed = 1;
        keys[scancode - 0x80] = 0;  // This is an keyup event
    }
    else {
        keys[scancode] = 1; 
    }
}

void waitForKeyPress(void) {
    while(!keyPressed){
        // Do nothing while there is no key pressed..
    }
    keyPressed = 0;
}

uint8 getKeyPressed(uint8 key) {
    // TODO: Make sure this key is in the array
    return keys[key];
}
