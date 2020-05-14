	BITS 16

start:
	mov ax, 07C0h		
	add ax, 288		
	mov ss, ax
	mov sp, 4096

	mov ax, 07C0h		
	mov ds, ax


	mov si, boot_string	
	call print_string

	mov si ,newline 
	call print_string

	mov si, help_string	
	call print_string		
	jmp $	

%include "print_string.asm"		

	boot_string db 'GlaDOS Online!', 0
	help_string db 'I dont know what im doing anymore :(', 0
	newline db 0dh, 0ah, 0

	times 510-($-$$) db 0	
	dw 0xAA55		