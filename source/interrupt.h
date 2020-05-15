#include "asm_utils.h"

#define PIC1            0x20    // Master   PIC
#define PIC2            0xA0    // Slave    PIC
#define PIC1_COMMAND    PIC1    // Command Port
#define PIC1_DATA       (PIC1+1)// Data Port
#define PIC2_COMMAND    PIC2
#define PIC2_DATA       (PIC2+1)

void PIC_sendEOI(unsigned char irq);

#define PIC_EOI         0x20    // END OF INTERRUPT command

#define ICW1_ICW4	    0x01		// ICW4 (not) needed 
#define ICW1_SINGLE	    0x02		// Single (cascade) mode 
#define ICW1_INTERVAL4	0x04		// Call address interval 4 (8) 
#define ICW1_LEVEL	    0x08		// Level triggered (edge) mode 
#define ICW1_INIT	    0x10		// Initialization - required! 
 
#define ICW4_8086	    0x01		// 8086/88 (MCS-80/85) mode 
#define ICW4_AUTO	    0x02		// Auto (normal) EOI 
#define ICW4_BUF_SLAVE	0x08		// Buffered mode/slave 
#define ICW4_BUF_MASTER	0x0C		// Buffered mode/master 
#define ICW4_SFNM	    0x10		// Special fully nested (not) 

void PIC_remap(int offset1, int offset2);
void IRQ_set_mask(unsigned char IRQline);
void IRQ_clear_mask(unsigned char IRQline);

#define PIC_READ_IRR                0x0a    
#define PIC_READ_ISR                0x0b    

struct IDT_entry{
    unsigned short int offset_lowerbits;
    unsigned short int selector;
    unsigned char zero;
    unsigned char type_attr;
    unsigned short int offset_higherbits;
};

struct IDT_entry IDT[256];

void idt_init(void);