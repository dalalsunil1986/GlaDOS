[org 0x7c00]

	mov bp, 0x9000
	mov sp, bp

	mov bx, START_MSG
	call print_string
	call print_nl

.typing_loop:
	call wait_for_key
	cmp al, 1Bh
	je .exit

	cmp al, 08h
	je .backspace

	cmp al, 0Dh
	je .return

	mov ah, 0x0e
	int 0x10

	jmp .typing_loop

.backspace:
	call print_remove
	jmp .typing_loop

.return:
	call print_nl
	jmp .typing_loop
	
.exit:
	call print_nl
	mov bx, EXIT_MSG
	call print_string

	jmp $

%include "print_string.asm"
%include "keyboard.asm"

EXIT_MSG: db 'Exited typing mode', 0
START_MSG: db 'Boot succeeded!', 0

times 510-($-$$) 	db 0
dw 0xaa55