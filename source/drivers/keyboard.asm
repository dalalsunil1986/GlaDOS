wait_for_key:
	mov ah, 0x11
	int 0x16

	jnz .key_pressed

	hlt
	jmp wait_for_key

.key_pressed:
	mov ah, 0x10
	int 0x16
	ret

check_for_key:
	pusha

	mov ax, 0
	mov ah, 1
	int 16h

	jz .nokey

	mov ax, 0
	int 16h

	mov [.tmp_buf],ax

	popa
	mov ax, [.tmp_buf]

.nokey:
	popa
	mov ax, 0
	ret

	.tmp_buf dw 0