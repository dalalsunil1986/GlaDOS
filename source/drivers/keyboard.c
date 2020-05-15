#include "keyboard.h"
#include "asm_utils.h"
#include "../cpu/isr.h"
#include "scrn.h"
#include "../kernel/utils.h"

static void keyboard_callback(registers_t registers){
    // The PIC puts the scancode of the keyboard in this port:
    uint8_t scancode = inb(0x60);

    // KEYBOARD CODE GOES HERE
    char* ascii_scancode;
    itoa(scancode, ascii_scancode);
    print_string("Scancode: ");
    print_string(ascii_scancode);
    print_char('\n');
}

void init_keyboard(){
    register_interrupt_handler(IRQ1, keyboard_callback);
}