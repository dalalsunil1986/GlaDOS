#ifndef __SCRN_H_
#define __SCRN_H_
#include "../kernel/utils.h"

extern void cls();
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();
extern void print_char( char c);
extern void print_string( char *text);

#endif