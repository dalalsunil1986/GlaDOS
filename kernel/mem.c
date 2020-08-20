#include "mem.h"

#define BASE 0x1000000

static void* tracker = BASE;


// TODO:
// Implement a real malloc function right here
void* malloc(uint32 size){
    tracker+=size;
    return tracker;
}

