#include "utils.h"

void* memcpy(void* dest, const void* src, int count)
{
    unsigned char* destC = (unsigned char*)dest;
    unsigned char* srcC = (unsigned char*)src;
    int i;
    for (i = 0; i < count; i++)
        destC[i] = srcC[i];
    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned char val, int count){
    int i;
    for (i = 0; i < count; i++)
        dest[i] = val;
    return dest;
}

void itoa(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';
}