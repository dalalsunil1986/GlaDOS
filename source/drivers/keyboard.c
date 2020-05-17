#include "keyboard.h"
#define KEYS_LENGTH 88
int keyPressed = 0;

int keys[KEYS_LENGTH];

static void keyboard_callback(registers_t registers){
    // The PIC puts the scancode of the keyboard in this port:
    uint8 scancode = inb(0x60);
    

    // char scancodeChar[10];
    // itoa(scancode, scancodeChar);
    // appendc(scancodeChar, '\n');
    // print_string(scancodeChar);

    keys[scancode] = 1;
    if(scancode <= 0x80){
        keys[scancode - 0x80] = 0;
    }

    keyPressed = 1;
}

int getKeyPressed(uint8 key) {
    if (key > KEYS_LENGTH){
        return 0;
    }
    else {
        return keys[key];
    }
}

// Wait for any key to be pressed;
void waitForKey(void) {
    keyPressed = 0;
    while(!keyPressed) {
	// Do nothing while there is no key pressed yet
    }
}

void init_keyboard(){
    register_interrupt_handler(IRQ1, keyboard_callback);
}

// Returns 0 if the scancode was a keydown, returns 1 if the scancode was a keyup
// int scancodeToChar(uint8 scancode, char* charVal) {

//     char returnChar = ' ';   
//     int returnInt = 0;

//     switch(scancode){
//         case 0x2:
// 	        returnChar = '1';
//             break;
//         case 0x3:
// 	        returnChar = '2';
//             break;
//         case 0x4:
// 	        returnChar = '3';
//             break;
//         case 0x5:
// 	        returnChar = '4';
//             break;
//         case 0x6:
// 	        returnChar = '5';
//             break;
//         case 0x7:
// 	        returnChar = '6';
//             break;
//         case 0x8:
// 	        returnChar = '7';
//             break;
//         case 0x9:
// 	        returnChar = '8';
//             break;
//         case 0xA:
// 	        returnChar = '9';
//             break;
//         case 0xB:
// 	        returnChar = '0';
//             break;
//         case 0xC:
// 	        returnChar = '-';
//             break;
//         case 0xD:
// 	        returnChar = '=';
//             break;
//         case 0xE:
// 	        returnChar = '\b';
//             break;
//         case 0xF:
// 	        returnChar = '\t';
//             break;
//         case 0x10:
// 	        returnChar = 'q';
//             break;
//         case 0x11:
// 	        returnChar = 'w';
//             break;
//         case 0x12:
// 	        returnChar = 'e';
//             break;
//         case 0x13:
// 	        returnChar = 'r';
//             break;
//         case 0x14:
// 	        returnChar = 't';
//             break;
//         case 0x15:
// 	        returnChar = 'y';
//             break;
//         case 0x16:
// 	        returnChar = 'u';
//             break;
//         case 0x17:
// 	        returnChar = 'i';
//             break;
//         case 0x18:
// 	        returnChar = 'o';
//             break;
//         case 0x19:
// 	        returnChar = 'p';
//             break;
//         case 0x1A:
// 	        returnChar = '[';
//             break;
//         case 0x1B:
// 	        returnChar = ']';
//             break;
//         case 0x1C:
// 	        returnChar = '\n';
//             break;
//         case 0x1E:
// 	        returnChar = 'a';
//             break;
//         case 0x1F:
// 	        returnChar = 's';
//             break;
//         case 0x20:
// 	        returnChar = 'd';
//             break;
//         case 0x21:
// 	        returnChar = 'f';
//             break;
//         case 0x22:
// 	        returnChar = 'g';
//             break;
//         case 0x23:
// 	        returnChar = 'h';
//             break;
//         case 0x24:
// 	        returnChar = 'j';
//             break;
//         case 0x25:
// 	        returnChar = 'k';
//             break;
//         case 0x26:
// 	        returnChar = 'l';
//             break;
//         case 0x27:
// 	        returnChar = ';';
//             break;
//         case 0x28:
// 	        returnChar = '\'';
//             break;
//         case 0x29:
// 	        returnChar = '`';
//             break;
//         case 0x2B:
// 	        returnChar = '\\';
//             break;
//         case 0x2C:
// 	        returnChar = 'z';
//             break;
//         case 0x2D:
// 	        returnChar = 'x';
//             break;
//         case 0x2E:
// 	        returnChar = 'c';
//             break;
//         case 0x2F:
// 	        returnChar = 'v';
//             break;
//         case 0x30:
// 	        returnChar = 'b';
//             break;
//         case 0x31:
// 	        returnChar ='n';
//             break;
//         case 0x32:
// 	        returnChar ='m';
//             break;
//         case 0x33:
// 	        returnChar =',';
//             break;
//         case 0x34:
// 	        returnChar ='.';
//             break;
//         case 0x35:
// 	        returnChar ='/';
//             break;
//         case 0x37:
// 	        returnChar ='*';
//             break;
//         case 0x39:
// 	        returnChar =' ';
//             break;
//         default: 
//             if(scancode <= 0x39 + 0x80){
//                 // Keyup event
//                 returnInt = 1;
//             }
//             break;
//     }

//     // Is this char a letter?
//     if(returnChar <= 0x7A && returnChar >= 0x61) {
//         // Is the shift key pressed?
//         if (getKeyPressed(KEY_LEFTSHIFT) || getKeyPressed(KEY_RIGHTSHIFT)){
//             // If both cases are true than we substract 0x20 from the char code to get the uppercase variant
//             returnChar -= 0x20;
//         }
//     }
//     *charVal = returnChar;
//     return returnInt;
// }
