#ifndef __SCREEN_H
#define __SCREEN_H

#include "../kernel/inttypes.h"

void cls(void);
// void settextcolor(uint8 forecolor, uint8 backcolor);
void setcolordefault(void);
void init_vga_t(void);
void printk( char *text);
// void fill_line(char c, int width);
// void create_window(int witdh, int height,int xOffset, int yOffset);
// void windowcolor(unsigned int borderFore, unsigned int borderBack,unsigned int fillFore, unsigned int fillBack);

#endif