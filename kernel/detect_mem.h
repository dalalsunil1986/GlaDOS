#ifndef __DETECT_MEM_H
#define __DETECT_MEM_H
#include "./inttypes.h"

typedef struct SMAP_entry {
 
	uint32 BaseL; // base address uint64_t
	uint32 BaseH;
	uint32 LengthL; // length uint64_t
	uint32 LengthH;
	uint32 Type; // entry Type
	uint32 ACPI; // extended
 
}__attribute__((packed)) SMAP_entry_t;


int __attribute__((noinline)) __attribute__((regparm(3))) detectMemory(SMAP_entry_t* buffer, int maxentries);

#endif