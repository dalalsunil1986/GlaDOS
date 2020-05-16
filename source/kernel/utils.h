#ifndef __UTILS_H
#define __UTILS_H

void* memcpy(void* dest, const void* src, int count);

unsigned short *memsetw(unsigned short *dest, unsigned char val, int count);

void itoa(int n, char str[]);
int strlen(const char *str);
void reverse(char string[]);
void appendc(char s[], char n);
void appends(char a[], char b[]);
int strcomp(char stringa[], char stringb[]);

#endif