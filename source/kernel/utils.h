#ifndef __UTILS_H
#define __UTILS_H

void* memcpy(void* dest, const void* src, int count);

unsigned short *memsetw(unsigned short *dest, unsigned char val, int count);

void itoa(int n, char str[]);

#endif