#ifndef __UTILS_H
#define __UTILS_H

#include "inttypes.h"

void* memcpy(void* dest, const void* src, int count);

uint16 *memsetw(uint16 *dest, uint16 val, int count);

void itoa(int n, char str[]);
int strlen(const char *str);
void reverse(char string[]);
void appendc(char s[], char n);
void appends(char a[], char b[]);
int strcomp(char stringa[], char stringb[]);

#endif