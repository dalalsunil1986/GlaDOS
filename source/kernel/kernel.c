#include "../drivers/asm_utils.h"
#include "../drivers/scrn.h"
#include "../cpu/isr.h"
#include "../drivers/keyboard.h"
#include "../cpu/timer.h"

#define _WITDH 80
#define _HEIGHT 25
//80x25

/* Commands */
// cls(); 																clears screen
// settextcolor(unsigned char forecolor, unsigned char backcolor);		Set foreground and background color
// init_video(); 														Sets our text-mode VGA pointer, then clears the screen
// print_char(unsigned char c);											Write a single charater to screen
// print_string(unsigned char *text);									Write multiple charater to screen
// fill_line(char c, int width)											Overwrites anything on current line with chosen symbol

void _start(){
	install_isr();

	// this functions enables the interrupts needed for keyboard input asm sti
	enable_interrupts();

	init_keyboard();
	init_timer((uint32)50);

	init_video();
	settextcolor(14,0);
	print_string("Booted GlaDOS successfully!\n");
	print_string("                        _____ _      ______ _____ _____          \n");
	print_string("                       |  __ \\ |     |  _  \\  _  /  ___|         \n");
	print_string("               ______  | |  \\/ | __ _| | | | | | \\ `--.   ______ \n");
	print_string("              |______| | | __| |/ _` | | | | | | |`--. \\ |______|\n");
	print_string("                       | |_\\ \\ | (_| | |/ /\\ \\_/ /\\__/ /         \n");
	print_string("                        \\____/_|\\__,_|___/  \\___/\\____/          \n");
	fill_line('=',_WITDH);
	waitForKey();
	cls();
	windowcolor(14,0,14,0);
	create_window(45,_HEIGHT - 1,1,0);
	create_window(31,12,47,0);

}
