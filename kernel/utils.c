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

unsigned short *memsetw(uint16 *dest, uint16 val, int count){
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

// Convert an integer to ascii chars
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

// Append a character n to the end of string s
void appendc(char s[], char n) {
    int len = strlen(s);
    s[len] = n;
    s[len+1] = '\0';
}

// Append string b to string a
void appends(char a[], char b[]){
    int lena = strlen(a);
    int i;
    for(i = 0; i < strlen(b); i++){
        a[lena+i] = b[i];
    }
    a[lena+i] = '\0';
}

// Compares two strings returns 0 if both strings are equal
// Returns -(ascii val of first not matching char) if stringb > stringa and (ascii val of first not matching char) if stringa > stringb
int strcomp(char stringa[], char stringb[]) {
    int i;
    // Compare for i=0 to the point where stringa doesnt match stringb anymore
    for(i=0; stringa[i] == stringb[i]; i++){
        // if we have reached the end of stringa and the strings are still equal
        // then we can return 0 because both strings are equal
        if(stringa[i] == '\0') return 0;
    }
    return stringa[i] - stringb[i];
}