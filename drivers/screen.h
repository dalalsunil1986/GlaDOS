#ifndef __SCREEN_H
#define __SCREEN_H

#include "../kernel/inttypes.h"
#include "../kernel/utils.h"
#include "../kernel/asm_utils.h"
#include "../kernel/mem.h"

void cls(void);
void setforegroundcolor(uint8 color);
void resetcolor(void);
void init_vga_t(void);
void printk(char *text);
void scroll(void);
void move_csr(void);
// void fill_line(char c, int width);
// void create_window(int witdh, int height,int xOffset, int yOffset);
// void windowcolor(unsigned int borderFore, unsigned int borderBack,unsigned int fillFore, unsigned int fillBack);


// COLORS:
#define VGA_BLACK   0x0
#define VGA_BLUE    0x1
#define VGA_GREEN   0x2
#define VGA_CYAN    0x3
#define VGA_RED     0x4
#define VGA_MAGENTA 0x5
#define VGA_BROWN   0x6
#define VGA_LGRAY   0x7
#define VGA_DGRAY   0x8
#define VGA_LBLUE   0x9
#define VGA_LGREEN  0xA
#define VGA_LCYAN   0xB
#define VGA_LRED    0xC
#define VGA_PINK    0xD
#define VGA_YELLOW  0xE
#define VGA_WHITE   0xF

#endif