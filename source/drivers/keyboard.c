#include "keyboard.h"

int keyPressed = 0;

static void keyboard_callback(registers_t registers){
    // The PIC puts the scancode of the keyboard in this port:
    uint8 scancode = inb(0x60);
    
    // char* ascii_scancode;
    // itoa(scancode, ascii_scancode);
    // print_string("Scancode: ");
    // print_string(ascii_scancode);
    // print_char('\n');

    keyPressed = 1;
}

// Wait for any key to be pressed;
void waitForKey(void) {
    keyPressed = 0;
    while(!keyPressed) {

    }
}

void init_keyboard(){
    register_interrupt_handler(IRQ1, keyboard_callback);
}