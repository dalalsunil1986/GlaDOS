#include <stdint.h>
// Read a 8,16 or 32 bit value at a given memory location using another segment than the c segement
static inline uint8_t farpeekl(uint16_t sel, void* off);
static inline uint16_t farpeekl(uint16_t sel, void* off);
static inline uint32_t farpeekl(uint16_t sel, void* off);

// Write a 8,16 or 32 bit value to given memory location using another segment than the c segement
static inline void farpokeb(uint16_t sel, void* off, uint8_t val);
static inline void farpokew(uint16_t sel, void* off, uint16_t val);
static inline void farpokel(uint16_t sel, void* off, uint32_t val);

// Sends a 8,16 or 32-bit value on a I/O location
static inline void outb(uint16_t port, uint8_t val);
static inline void outw(uint16_t port, uint16_t val);
static inline void outl(uint16_t port, uint32_t val);

// Reads a 8,16 or 32 bit value from a I/O location
static inline uint8_t inb(uint16_t port);
static inline uint16_t inw(uint16_t port);
static inline uint32_t inl(uint16_t port);