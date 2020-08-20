#ifndef __UTILS_H
#define __UTILS_H

#include "inttypes.h"

void* memcpy(void* dest, const void* src, int count);

uint16 *memsetw(uint16 *dest, uint16 val, int bytecount);

void itoa(uint32 n, char str[]);
uint8 strlen(const char *str);
void reverse(char string[]);
void appendc(char s[], char n);
void appends(char a[], char b[]);
int strcomp(char stringa[], char stringb[]);
uint8 reverseByte(uint8 b);

#endif