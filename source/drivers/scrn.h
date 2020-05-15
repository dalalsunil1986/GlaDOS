#ifndef __SCRN_H_
#define __SCRN_H_

extern void cls();
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();
extern void print_char(unsigned char c);
extern void print_string(unsigned char *text);

#endif