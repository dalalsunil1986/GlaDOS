#include <stdint.h>
// Inline means it will get replaced in the function call by the compiler
// This saves on function calls making it a bit more efficient

// For more info on the inline asm see: https://wiki.osdev.org/Inline_Assembly
static inline uint8_t farpeekb(uint16_t sel, void* off) {
    uint8_t ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2),%0\n\t"
        "pop %%fs"
        : "=r" (ret) : "g" (sel), "r" (off)
    );
    return ret;
}

static inline uint16_t farpeekw(uint16_t sel, void* off) {
    uint16_t ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2),%0\n\t"
        "pop %%fs"
        : "=r" (ret) : "g" (sel), "r" (off)
    );
    return ret;
}

static inline uint32_t farpeekl(uint16_t sel, void* off) {
    uint32_t ret;
    asm("push %%fs\n\t"
        "mov %1, %%fs\n\t"
        "mov %%fs:(%2),%0\n\t"
        "pop %%fs"
        : "=r" (ret) : "g" (sel), "r" (off)
    );
    return ret;
}

static inline void farpokeb(uint16_t sel, void* off, uint8_t val){
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        : : "g"(sel),  "r" (off), "r"(val)
    );
}

static inline void farpokew(uint16_t sel, void* off, uint16_t val){
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        : : "g"(sel),  "r" (off), "r"(val)
    );
}

static inline void farpokel(uint16_t sel, void* off, uint32_t val){
    asm("push %%fs\n\t"
        "mov %0, %%fs\n\t"
        "movb %2, %%fs:(%1)\n\t"
        "pop %%fs"
        : : "g"(sel),  "r" (off), "r"(val)
    );
}


static inline void outb(uint16_t port, uint8_t val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline void outw(uint16_t port, uint16_t val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline void outl(uint16_t port, uint32_t val) {
    asm volatile("outb %0, %1" : : "a"(val), "Nd"(port));
}

static inline uint8_t inb(uint16_t port){
    uint8_t ret;
    asm volatile("inb %1, %0": "=a"(ret) : "Nd" (port));
    return ret;
}

static inline uint8_t inw(uint16_t port){
    uint16_t ret;
    asm volatile("inb %1, %0": "=a"(ret) : "Nd" (port));
    return ret;
}

static inline uint8_t inl(uint16_t port){
    uint32_t ret;
    asm volatile("inb %1, %0": "=a"(ret) : "Nd" (port));
    return ret;
}

static inline void io_wait(void)
{
    asm volatile ( "jmp 1f\n\t"
                   "1:jmp 2f\n\t"
                   "2:" );
}