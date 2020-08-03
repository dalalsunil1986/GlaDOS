C_SOURCES = $(wildcard kernel/*.c drivers/*.c cpu/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h cpu/*.h)

OBJ = ${C_SOURCES:.c=.o cpu/interrupt.o}

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -m32 -fno-pie

all: run

os-image.bin: boot/boot_sector.bin kernel.bin
	cat $^ > os-image.bin

kernel.bin: boot/kernel_entry.o ${OBJ}
	ld -o $@ -Ttext 0x1000 $^ -s -m elf_i386 --oformat binary

run: os-image.bin	
	qemu-system-x86_64 -m 1G -vga cirrus -cpu Nehalem-v2 -fda $<

# For all targets .o from all .c and all headers
%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@

clean:
	rm -rf *.bin *.dis *.o os-image.bin *.elf
	rm -rf kernel/*.o boot/*.bin drivers/*.o boot/*.o cpu/*.o

kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@