#include "screen.h"


#define WHITE_ON_BLACK 0x0F     // The default WHITE ON BLACK color scheme
#define VID_MEM_ADDR 0xB8000    // The address at the start of the video memory

uint16 csr_x = 0;               // Cursor x position
uint16 csr_y = 0;               // Cursor y position

#define SCREEN_CTRL     0x3D4   // Screen device control port
#define SCREEN_DATA     0x3D5   // Screen device data port
#define SCREEN_HEIGHT   25      // The width of the screen in chars
#define SCREEN_WIDTH    80      // The height of the screen in chars

uint8 foregroundCol, backgroundCol = 0x0;

int counter = 0;
// Print this char to the screen at pos (csr_x, csr_y)
void print_char(char c){
    volatile uint16 * vidmem = (uint16 *) VID_MEM_ADDR;
    volatile uint8 color = foregroundCol | (backgroundCol << 4);
    

    //Handle a backspace, by moving the cursor back one space
    if(c == 0x08){
        if(csr_x != 0) csr_x--;
    }

    //Handle a tab by incrementing the cursor's x
    else if(c == 0x09){
        csr_x = (csr_x + 8) & ~(8 - 1);
    }

    //returns cursor back to the margin
    else if(c == '\r'){
        csr_x = 0;
    }

    //if \n in string create a newline
    else if(c == '\n'){
        csr_x = 0;
        csr_y++;
    }

    //Any character greater than or equal to space is printable at: offset = [(y * width) + x]
    else if(c >= ' '){
        uint16 offset = (uint16)((csr_y * SCREEN_WIDTH) + csr_x);

        vidmem[offset] = (uint16)c|((uint16)color<<8);
        csr_x++;
    }

    if(csr_x>= SCREEN_WIDTH){
        csr_x = 0;
        csr_y++;
    }

    if(csr_y >= SCREEN_HEIGHT){
        csr_x = 0;
        scroll();
    }
    move_csr();

}

void scroll(void)
{
    unsigned blank;

    blank = 0x20 | (((uint16)foregroundCol | (backgroundCol << 4)) << 8);
    uint8 row = SCREEN_WIDTH * 2;
    // Copy everything on the screen minus the top most line and move it one line up;
    memcpy(VID_MEM_ADDR, VID_MEM_ADDR + row, (SCREEN_WIDTH * SCREEN_HEIGHT * 2) - row);

    // We set the bottom most line on our screen to the blanking characting
    memsetw(VID_MEM_ADDR + (SCREEN_WIDTH * (SCREEN_HEIGHT-1) *2), blank, row);
    csr_y--;

}

// Print text using the kernel print function
void printk(const char* string) {
    for(uint16 i = 0; i < strlen(string); i++){
        print_char(string[i]);
    }
}

// This will init the text based vga mode
void init_vga_t(void) {
    resetColor();
    cls();
    move_csr();
}

void cls(void){
    uint16 blank;
    blank = 0x20 | (((uint16)foregroundCol | (backgroundCol << 4)) << 8);
    
    // Sets the VID_MEM from (int)753664 to (int)753664 + (25*80) to blanks
    memsetw(VID_MEM_ADDR, blank, SCREEN_WIDTH * SCREEN_HEIGHT);

    // Reset the cursor to the 0,0 position (Top right)
    csr_x = 0;
    csr_y = 0;
    move_csr();
}

// Moves the cursor to the pos of (csr_x, csr_y)
void move_csr(void)
{
    //Finding the index in a linear chunk of memory by: Index = [(y * width) + x]
    uint16 temp = csr_y * SCREEN_WIDTH + csr_x;
    
    outb(SCREEN_CTRL, 14);
    outb(SCREEN_DATA, temp >> 8);
    outb(SCREEN_CTRL, 15);
    outb(SCREEN_DATA, temp);
}

void resetColor(void) {
    foregroundCol = VGA_GREEN;
    backgroundCol = VGA_BLACK;
}

void setForegroundColor(uint8 color){
    foregroundCol =  color;
}

void setBackgroundColor(uint8 color) {
    backgroundCol =  color;
}
void setColor(uint8 foregroundColor, uint8 backgroundColor) {
    foregroundCol =  foregroundColor;
    backgroundCol = backgroundColor;
}