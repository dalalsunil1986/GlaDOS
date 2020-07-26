#include "../kernel/utils.h"
#include "../kernel/asm_utils.h"
#include "screen.h"


#define WHITE_ON_BLACK 0x0F     // The default WHITE ON BLACK color scheme
#define VID_MEM_ADDR 0xB8000    // The address at the start of the video memory

uint16 * vidmem;
uint8 attrib = WHITE_ON_BLACK; // This doesnt work when using it in the attribute color section
uint8 csr_x = 0;        // Cursor x position
uint8 csr_y = 0;        // Cursor y position

#define SCREEN_CTRL     0x3D4   // Screen device control port
#define SCREEN_DATA     0x3D5   // Screen device data port
#define SCREEN_HEIGHT   25      // The width of the screen in chars
#define SCREEN_WIDTH    80      // The height of the screen in chars

uint8 offset;

int counter = 0;
// Print this char to the screen at pos (csr_x, csr_y)
void print_char(char c){
    vidmem = (uint16 *) VID_MEM_ADDR;
    
    switch(c){
        case ' ':
            csr_x++;
            if(++csr_x > SCREEN_WIDTH){
                csr_y++;
                csr_x = 0;
            }
            break;
        case '\n':
            csr_y++;
            csr_x=0;
            break;
        default:
            
            offset = (uint16)(csr_y * SCREEN_WIDTH + csr_x);

            vidmem[offset] = (uint16)c | (WHITE_ON_BLACK<<8);
            csr_x++;

            break;
    }
    
    if(csr_y > SCREEN_HEIGHT){
        // TODO: Implement scrolling!
    }
    move_csr();

}

// Print text using the kernel print function
void printk(char* string) {
    for(int i = 0; i < strlen(string); i++){
        print_char(string[i]);
    }
}

// This will init the text based vga mode
void init_vga_t(void) {
    cls();
    move_csr();
}

void cls(void){
    uint16 blank;

    //Sets our current color
    blank = 0x20 | (WHITE_ON_BLACK << 8);

    // Sets the VID_MEM from 0xb8000 to (25*80) to blanks
    memsetw(VID_MEM_ADDR, blank, SCREEN_WIDTH * SCREEN_HEIGHT);

    //Set the cursor back to 0,0
    csr_x = 0;
    csr_y = 0;
    move_csr();
}

// Moves the cursor to the pos of (csr_x, csr_y)
void move_csr(void)
{
    //Finding the index in a linear chunk of memory by: Index = [(y * width) + x]
    uint8 temp = csr_y * SCREEN_WIDTH + csr_x;
    
    outb(SCREEN_CTRL, 14);
    outb(SCREEN_DATA, temp >> 8);
    outb(SCREEN_CTRL, 15);
    outb(SCREEN_DATA, temp);
}

void setcolordefault(void) {
    attrib = WHITE_ON_BLACK;
}



