[bits 16]

switch_to_pm:
    cli

    lgdt [gdt_descriptor]

    mov eax, cr0 ; Set this control register to switch the cpu to 32bit
    or eax, 0x1 ; protected mode
    mov cr0, eax
    jmp CODE_SEG:init_pm

[bits 32]
; initialise registers and the stack in 32b PM 
init_pm:
    mov ax, DATA_SEG 
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000  ; Updating the stack position
    mov esp, ebp

    call BEGIN_PM