#include "keyboard.h"

int keyPressed = 0;



static void keyboard_callback(registers_t registers){
    // The PIC puts the scancode of the keyboard in this port:
    uint8 scancode = inb(0x60);

    char* ascii_scancode;
    itoa(scancode, ascii_scancode);
    print_string("Scancode: ");
    print_string(ascii_scancode);
    print_char('\n');

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

char scancodeToChar(uint8 scancode) {
    switch(scancode){
        case 0x2:
	        return '1';
        case 0x3:
	        return '2';
        case 0x4:
	        return '3';
        case 0x5:
	        return '4';
        case 0x6:
	        return '5';
        case 0x7:
	        return '6';
        case 0x8:
	        return '7';
        case 0x9:
	        return '8';
        case 0xA:
	        return '9';
        case 0xB:
	        return '0';
        case 0xC:
	        return '-';
        case 0xD:
	        return '=';
        case 0xE:
	        return '\b';
        case 0xF:
	        return '\t';
        case 0x10:
	        return 'Q';
        case 0x11:
	        return 'W';
        case 0x12:
	        return 'E';
        case 0x13:
	        return 'R';
        case 0x14:
	        return 'T';
        case 0x15:
	        return 'Y';
        case 0x16:
	        return 'U';
        case 0x17:
	        return 'I';
        case 0x18:
	        return 'O';
        case 0x19:
	        return 'P';
        case 0x1A:
	        return '[';
        case 0x1B:
	        return ']';
        case 0x1C:
	        return '\n';
        case 0x1E:
	        return 'A';
        case 0x1F:
	        return 'S';
        case 0x20:
	        return 'D';
        case 0x21:
	        return 'F';
        case 0x22:
	        return 'G';
        case 0x23:
	        return 'H';
        case 0x24:
	        return 'J';
        case 0x25:
	        return 'K';
        case 0x26:
	        return 'L';
        case 0x27:
	        return ';';
        case 0x28:
	        return '\'';
        case 0x29:
	        return '`';
        case 0x2B:
	        return '\\';
        case 0x2C:
	        return 'Z';
        case 0x2D:
	        return 'X';
        case 0x2E:
	        return 'C';
        case 0x2F:
	        return 'V';
        case 0x30:
	        return 'B';
        case 0x31:
	        return 'N';
        case 0x32:
	        return 'M';
        case 0x33:
	        return ',';
        case 0x34:
	        return '.';
        case 0x35:
	        return '/';
        case 0x37:
	        return '*';
        case 0x39:
	        return ' ';
    }
}