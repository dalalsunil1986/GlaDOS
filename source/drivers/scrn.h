#ifndef __SCRN_H_
#define __SCRN_H_

void cls();
void settextcolor(unsigned char forecolor, unsigned char backcolor);
void init_video();
void print_char( char c);
void print_string( char *text);
void fill_line(char c, int width);
void create_window(int witdh, int height,int xOffset, int yOffset);
void windowcolor(unsigned int borderFore, unsigned int borderBack,unsigned int fillFore, unsigned int fillBack);

#endif