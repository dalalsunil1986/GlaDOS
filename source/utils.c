// Inline means it will get replaced in the function call by the compiler
// This saves on function calls making it a bit more efficient
static inline uint32_t farpeekl(uint16_t sel, void* off) {
    uint32_t ret;
    asm("push %%fs\n\t"
        "mov %l, %%fs\n\t"
        "mov %%fs:(%2),%0\n\t"
        "pop %%fs"
        : "=r" (ret) : "g" (sel), "r" (off)
    );
    return ret;
}