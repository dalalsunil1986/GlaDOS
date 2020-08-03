#include "mem.h"

#define BASE 0x100000

void* tracker = BASE;


// TODO:
// Implement a real malloc function right here
void* malloc(uint32 size){
    tracker+=size;
    return tracker;
}

