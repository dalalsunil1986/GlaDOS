all: run

kernel.bin: kernel_entry.o kernel.o
	ld -m elf_i386 -s -o $@ -Ttext 0x1000 $^ --oformat binary

kernel_entry.o: 
	nasm source/boot/kernel_entry.asm -f elf -o $@

irq_handlers.o:
	nasm source/boot/irq_handlers.asm -f elf -o $@

kernel.o : 
	gcc -Wall -Wextra -pedantic -fno-pie -m32 -ffreestanding -c source/kernel.c -o $@

kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@

bootsect.bin: 
	nasm source/boot/boot_sector.asm -f bin -o $@

os-image.bin: bootsect.bin kernel.bin
	cat $^ > $@

run: os-image.bin	
	qemu-system-i386 -fda $<

clean:
	rm *.bin *.o *.dis

