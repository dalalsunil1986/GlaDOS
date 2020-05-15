#include "../drivers/asm_utils.h"
#include "../drivers/scrn.h"

//80x25

/* Commands */
// cls(); 																clears screen
// settextcolor(unsigned char forecolor, unsigned char backcolor);		Set foreground and background color
// init_video(); 														Sets our text-mode VGA pointer, then clears the screen
// print_char(unsigned char c);											Write a single charater to screen
// print_string(unsigned char *text);									Write multiple charater to screen

void _start(){
	init_video();
	settextcolor(2,0);
	print_string("                        _____ _      ______ _____ _____          \n");
	print_string("                       |  __ \\ |     |  _  \\  _  /  ___|         \n");
	print_string("               ______  | |  \\/ | __ _| | | | | | \\ `--.   ______ \n");
	print_string("              |______| | | __| |/ _` | | | | | | |`--. \\ |______|\n");
	print_string("                       | |_\\ \\ | (_| | |/ /\\ \\_/ /\\__/ /         \n");
	print_string("                        \\____/_|\\__,_|___/  \\___/\\____/          \n");

	
}
