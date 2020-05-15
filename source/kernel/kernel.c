#include "asm_utils.h"

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
void clear_screen(int color) {
	char* mem = (char*)0xb8000;
	for (unsigned int row = 0; row < 25; row++){
		for (unsigned int col = 0; col < 80; col++){
			*mem++ = ' ';
			*mem++ = color;
		}
	}
}

void _start(){
	io_wait();
	clear_screen(0);
	write_string(2,5, "Je moeder");

}