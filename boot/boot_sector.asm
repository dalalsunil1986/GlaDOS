
	mov bp, 0x9000
	mov sp, bp
	
	mov bx, MSG_REAL_MODE
	call print


	call switch_to_pm  

	jmp $

%include "print_string.asm"
%include "gdt.asm"
%include "print_string_32.asm"
%include "switch_to_pm.asm"

[bits 32]
[extern main] ; External C function

BEGIN_PM:
	mov ebx, MSG_PROT_MODE
	call print_string_pm

	call main

	jmp $

MSG_REAL_MODE db "Started in 16 bit real mode", 0
MSG_PROT_MODE db "Succesfully landed in 32 bit protected mode", 0

times 510-($-$$) 	db 0
dw 0xaa55