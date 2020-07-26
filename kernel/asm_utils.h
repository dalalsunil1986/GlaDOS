#ifndef __ASM_UTILS_H
#define __ASM_UTILS_H
#include "../kernel/inttypes.h"
// Inline means it will get replaced in the function call by the compiler
// This saves on function calls making it a bit more efficient

// For more info on the inline asm see: https://wiki.osdev.org/Inline_Assembly
static inline uint8 farpeekb(uint16 sel, void* off) {
    uint8 ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2),%0\n\t"
        "pop %%fs"
        : "=r" (ret) : "g" (sel), "r" (off)
    );
    return ret;
}

static inline uint16 farpeekw(uint16 sel, void* off) {
    uint16 ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2),%0\n\t"
        "pop %%fs"
        : "=r" (ret) : "g" (sel), "r" (off)
    );
    return ret;
}

static inline uint32 farpeekl(uint16 sel, void* off) {
    uint32 ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2),%0\n\t"
        "pop %%fs"
        : "=r" (ret) : "g" (sel), "r" (off)
    );
    return ret;
}

static inline void farpokeb(uint16 sel, void* off, uint8 val){
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        : : "g"(sel),  "r" (off), "r"(val)
    );
}

static inline void farpokew(uint16 sel, void* off, uint16 val){
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        : : "g"(sel),  "r" (off), "r"(val)
    );
}

static inline void farpokel(uint16 sel, void* off, uint32 val){
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        : : "g"(sel),  "r" (off), "r"(val)
    );
}


static inline void outb(uint16 port, uint8 val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline void outw(uint16 port, uint16 val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline void outl(uint16 port, uint32 val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline uint8 inb(uint16 port){
    uint8 ret;
    asm volatile("inb %1, %0": "=a"(ret) : "Nd" (port));
    return ret;
}

static inline uint8 inw(uint16 port){
    uint16 ret;
    asm volatile("inb %1, %0": "=a"(ret) : "Nd" (port));
    return ret;
}

static inline uint8 inl(uint16 port){
    uint32 ret;
    asm volatile("inb %1, %0": "=a"(ret) : "Nd" (port));
    return ret;
}

static inline void io_wait(void)
{
    asm volatile ( "jmp 1f\n\t"
                   "1:jmp 2f\n\t"
                   "2:" );
}

static inline void enable_interrupts(void) {
    asm volatile("sti");
}

static inline void disable_interrupts(void) {
    asm volatile("cli");
}

#endif