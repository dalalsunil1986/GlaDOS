#include "../drivers/screen.h"
#include "./inttypes.h"
#include "./asm_utils.h"
#include "../cpu/isr.h"
#include "detect_mem.h"
#include "utils.h"
#include "timer.h"
#include "mem.h"

// This function is called by the kernel_entry.asm file
void _start(void) {
    install_isr();
	enable_interrupts();
    init_vga_t();
    init_timer();

    printk("Default color\n");
    setforegroundcolor(VGA_DGRAY);
}