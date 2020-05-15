#ifndef __SCRN_H_
#define __SCRN_H_

extern void cls();
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();
extern void print_char( char c);
extern void print_string( char *text);
extern void fill_line(char c, int width);
extern void create_window(int witdh, int height,int xOffset, int yOffset);
extern void windowcolor(unsigned int borderFore, unsigned int borderBack,unsigned int fillFore, unsigned int fillBack);

#endif