#include <stdint.h>
// Read a 8,16 or 32 bit value at a given memory location using another segment than the c segement
inline uint8_t farpeekb(uint16_t sel, void* off);
inline uint16_t farpeekw(uint16_t sel, void* off);
inline uint32_t farpeekl(uint16_t sel, void* off);

// Write a 8,16 or 32 bit value to given memory location using another segment than the c segement
inline void farpokeb(uint16_t sel, void* off, uint8_t val);
inline void farpokew(uint16_t sel, void* off, uint16_t val);
inline void farpokel(uint16_t sel, void* off, uint32_t val);

// Sends a 8,16 or 32-bit value on a I/O location
inline void outb(uint16_t port, uint8_t val);
inline void outw(uint16_t port, uint16_t val);
inline void outl(uint16_t port, uint32_t val);

// Reads a 8,16 or 32 bit value from a I/O location
inline uint8_t inb(uint16_t port);
inline uint16_t inw(uint16_t port);
inline uint32_t inl(uint16_t port);

// Forces the cpu to wait for the completion of a I/O command
inline void io_wait(void);