//#include "asm_utils.h"
#include "scrn.c"
//#include "interrupt.h"

void write_string(int foreground, int background, const char *string )
{
    volatile char *video = (volatile char*)0xB8000;
    while( *string != 0 )
    {
        *video++ = *string++;
		// The four first bits are used for the foreground color
		// The 3 last are used for background coloring so the bit shift and then
		// applying a or to the two gives us the desired fore and background color code
        *video++ = foreground ^ (background << 4);
    }
}

//80x25

void _start(){
    init_video();
    settextcolor(15,2);
    print_char('K');
    settextcolor(2,15);
    print_string("heyy \n kaas");
    //cls();
}