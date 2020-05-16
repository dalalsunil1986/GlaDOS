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

void reverse(char string[]) {
    int c, i, j;
    for(i=0, j = strlen(string) - 1; i<j;i++,j--){
        c=string[i];
        string[i] = string[j];
        string[j] = c;
    }
}

int strlen(const char *str)
{
    int count = 0;
    while(*str!='\0'){
        count++;
        str++;
    }
    return count;
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

    reverse(str);
}