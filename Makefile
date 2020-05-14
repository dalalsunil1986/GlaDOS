all: run

kernel.bin: kernel_entry.o kernel.o
	lf -o $@ -Ttext 0x1000 $^ --oformat binary

kernel_entry.o: kernel_entry.asm
	nasm $< -f elf -o $@

kernel.o : kernel.c
	gcc -m32 -ffreestandig -c $< -o $@

kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@

bootsect.bin: bootsect.asm
	nasm $< -f bin -o $@

os-image.bin: bootsect.bin kernel.bin
	cat $^ > $@

run: os-image.bin	
	qemu-system-i386 -fda $<

clean:
	rm *.bin *.o *.dis