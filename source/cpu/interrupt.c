// #include "../drivers/asm_utils.h"

// #define PIC1            0x20    // Master   PIC
// #define PIC2            0xA0    // Slave    PIC
// #define PIC1_COMMAND    PIC1    // Command Port
// #define PIC1_DATA       (PIC1+1)// Data Port
// #define PIC2_COMMAND    PIC2
// #define PIC2_DATA       (PIC2+1)

// #define PIC_EOI         0x20    // END OF INTERRUPT command

// #define ICW1_ICW4	    0x01		// ICW4 (not) needed 
// #define ICW1_SINGLE	    0x02		// Single (cascade) mode 
// #define ICW1_INTERVAL4	0x04		// Call address interval 4 (8) 
// #define ICW1_LEVEL	    0x08		// Level triggered (edge) mode 
// #define ICW1_INIT	    0x10		// Initialization - required! 
 
// #define ICW4_8086	    0x01		// 8086/88 (MCS-80/85) mode 
// #define ICW4_AUTO	    0x02		// Auto (normal) EOI 
// #define ICW4_BUF_SLAVE	0x08		// Buffered mode/slave 
// #define ICW4_BUF_MASTER	0x0C		// Buffered mode/master 
// #define ICW4_SFNM	    0x10		// Special fully nested (not) 

// #define PIC_READ_IRR                0x0a    
// #define PIC_READ_ISR                0x0b    

// void PIC_sendEOI(unsigned char irq) {
//     if(irq >= 8)                
//         outb(PIC2_COMMAND, PIC_EOI);
//     // If the irq came from the master we only send EOI to master
//     outb(PIC1_COMMAND, PIC_EOI);
// }

// void PIC_remap(int offset1, int offset2){
//     unsigned char a1, a2;

//     a1 = inb(PIC1_DATA);
//     a2 = inb(PIC2_DATA);

//     outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
//     io_wait();
//     outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
//     io_wait();
//     outb(PIC1_DATA, offset1);
//     io_wait();
//     outb(PIC2_DATA, offset2);
//     io_wait();
//     outb(PIC1_DATA, 4);
//     io_wait();
//     outb(PIC2_DATA, 2);
//     io_wait();

//     outb(PIC1_DATA, ICW4_8086);
//     io_wait();
//     outb(PIC2_DATA, ICW4_8086);
//     io_wait();

//     outb(PIC1_DATA, a1);
//     outb(PIC2_DATA, a2);
// }

// void IRQ_set_mask(unsigned char IRQline){
//     uint16_t port;
//     uint8_t value;

//     if(IRQline < 8){
//         port = PIC1_DATA;
//     }
//     else {
//         port = PIC2_DATA;
//         IRQline -= 8;
//     }
//     value = inb(port) | (1 << IRQline);
//     outb(port, value);
// }

// void IRQ_clear_mask(unsigned char IRQline){
//     uint16_t port;
//     uint8_t value;

//     if(IRQline < 8){
//         port = PIC1_DATA;
//     }
//     else {
//         port = PIC2_DATA;
//         IRQline -= 8;
//     }
//     value = inb(port) & ~(1<<IRQline);
//     outb(port, value);
// }

// static uint16_t __pic_get_irq_reg(int ocw3){
//     outb(PIC1_COMMAND, ocw3);
//     outb(PIC2_COMMAND, ocw3);

//     return(inb(PIC2_COMMAND)<< 8) | inb(PIC1_COMMAND);
// }

// uint16_t pic_get_irr(void) {
//     return __pic_get_irq_reg(PIC_READ_IRR);
// }

// uint16_t pic_get_isr(void) {
//     return __pic_get_irq_reg(PIC_READ_ISR);
// }


// // IDT Stuff:

// struct IDT_entry{
//     unsigned short int offset_lowerbits;
//     unsigned short int selector;
//     unsigned char zero;
//     unsigned char type_attr;
//     unsigned short int offset_higherbits;
// };

// struct IDT_entry IDT[256];

// void idt_init(void) {
//     extern int load_idt();
//     extern int irq0();
//     extern int irq1();
//     extern int irq2();
//     extern int irq3();
//     extern int irq4();
//     extern int irq5();
//     extern int irq6();
//     extern int irq7();
//     extern int irq8();
//     extern int irq9();
//     extern int irq10();
//     extern int irq11();
//     extern int irq12();
//     extern int irq13();
//     extern int irq14();
//     extern int irq15();

//     unsigned long irq0_address;
//     unsigned long irq1_address;
//     unsigned long irq2_address;
//     unsigned long irq3_address;
//     unsigned long irq4_address;
//     unsigned long irq5_address;
//     unsigned long irq6_address;
//     unsigned long irq7_address;
//     unsigned long irq8_address;
//     unsigned long irq9_address;
//     unsigned long irq10_address;
//     unsigned long irq11_address;
//     unsigned long irq12_address;
//     unsigned long irq13_address;
//     unsigned long irq14_address;
//     unsigned long irq15_address;

//     unsigned long idt_address;
//     unsigned long idt_ptr[2];

//     PIC_remap(32, 40);

//     irq0_address = (unsigned long)irq0; 
// 	IDT[32].offset_lowerbits = irq0_address & 0xffff;
// 	IDT[32].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[32].zero = 0;
// 	IDT[32].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[32].offset_higherbits = (irq0_address & 0xffff0000) >> 16;
 
// 	irq1_address = (unsigned long)irq1; 
// 	IDT[33].offset_lowerbits = irq1_address & 0xffff;
// 	IDT[33].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[33].zero = 0;
// 	IDT[33].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[33].offset_higherbits = (irq1_address & 0xffff0000) >> 16;
 
// 	irq2_address = (unsigned long)irq2; 
// 	IDT[34].offset_lowerbits = irq2_address & 0xffff;
// 	IDT[34].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[34].zero = 0;
// 	IDT[34].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[34].offset_higherbits = (irq2_address & 0xffff0000) >> 16;
 
// 	irq3_address = (unsigned long)irq3; 
// 	IDT[35].offset_lowerbits = irq3_address & 0xffff;
// 	IDT[35].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[35].zero = 0;
// 	IDT[35].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[35].offset_higherbits = (irq3_address & 0xffff0000) >> 16;
 
// 	irq4_address = (unsigned long)irq4; 
// 	IDT[36].offset_lowerbits = irq4_address & 0xffff;
// 	IDT[36].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[36].zero = 0;
// 	IDT[36].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[36].offset_higherbits = (irq4_address & 0xffff0000) >> 16;
 
// 	irq5_address = (unsigned long)irq5; 
// 	IDT[37].offset_lowerbits = irq5_address & 0xffff;
// 	IDT[37].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[37].zero = 0;
// 	IDT[37].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[37].offset_higherbits = (irq5_address & 0xffff0000) >> 16;
 
// 	irq6_address = (unsigned long)irq6; 
// 	IDT[38].offset_lowerbits = irq6_address & 0xffff;
// 	IDT[38].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[38].zero = 0;
// 	IDT[38].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[38].offset_higherbits = (irq6_address & 0xffff0000) >> 16;
 
// 	irq7_address = (unsigned long)irq7; 
// 	IDT[39].offset_lowerbits = irq7_address & 0xffff;
// 	IDT[39].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[39].zero = 0;
// 	IDT[39].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[39].offset_higherbits = (irq7_address & 0xffff0000) >> 16;
 
// 	irq8_address = (unsigned long)irq8; 
// 	IDT[40].offset_lowerbits = irq8_address & 0xffff;
// 	IDT[40].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[40].zero = 0;
// 	IDT[40].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[40].offset_higherbits = (irq8_address & 0xffff0000) >> 16;
 
// 	irq9_address = (unsigned long)irq9; 
// 	IDT[41].offset_lowerbits = irq9_address & 0xffff;
// 	IDT[41].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[41].zero = 0;
// 	IDT[41].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[41].offset_higherbits = (irq9_address & 0xffff0000) >> 16;
 
// 	irq10_address = (unsigned long)irq10; 
// 	IDT[42].offset_lowerbits = irq10_address & 0xffff;
// 	IDT[42].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[42].zero = 0;
// 	IDT[42].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[42].offset_higherbits = (irq10_address & 0xffff0000) >> 16;
 
// 	irq11_address = (unsigned long)irq11; 
// 	IDT[43].offset_lowerbits = irq11_address & 0xffff;
// 	IDT[43].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[43].zero = 0;
// 	IDT[43].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[43].offset_higherbits = (irq11_address & 0xffff0000) >> 16;
 
// 	irq12_address = (unsigned long)irq12; 
// 	IDT[44].offset_lowerbits = irq12_address & 0xffff;
// 	IDT[44].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[44].zero = 0;
// 	IDT[44].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[44].offset_higherbits = (irq12_address & 0xffff0000) >> 16;
 
// 	irq13_address = (unsigned long)irq13; 
// 	IDT[45].offset_lowerbits = irq13_address & 0xffff;
// 	IDT[45].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[45].zero = 0;
// 	IDT[45].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[45].offset_higherbits = (irq13_address & 0xffff0000) >> 16;
 
// 	irq14_address = (unsigned long)irq14; 
// 	IDT[46].offset_lowerbits = irq14_address & 0xffff;
// 	IDT[46].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[46].zero = 0;
// 	IDT[46].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[46].offset_higherbits = (irq14_address & 0xffff0000) >> 16;
 
//     irq15_address = (unsigned long)irq15; 
// 	IDT[47].offset_lowerbits = irq15_address & 0xffff;
// 	IDT[47].selector = 0x08; // KERNEL_CODE_SEGMENT_OFFSET 
// 	IDT[47].zero = 0;
// 	IDT[47].type_attr = 0x8e; // INTERRUPT_GATE 
// 	IDT[47].offset_higherbits = (irq15_address & 0xffff0000) >> 16;
 
// 	// fill the IDT descriptor 
// 	idt_address = (unsigned long)IDT ;
// 	idt_ptr[0] = (sizeof (struct IDT_entry) * 256) + ((idt_address & 0xffff) << 16);
// 	idt_ptr[1] = idt_address >> 16 ;

//     load_idt(idt_ptr);
// }