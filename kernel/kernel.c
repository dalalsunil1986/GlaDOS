#include "../drivers/screen.h"
#include "./inttypes.h"
#include "./asm_utils.h"
#include "../cpu/isr.h"



// This function is called by the kernel_entry.asm file
void _start(void) {
    install_isr();
	enable_interrupts();
    init_vga_t();
    printk("je moeder\n");
    printk("test123");
    //cls();

}