[bits 32]
[extern _start]
call _start

jmp $ ; endless loop if we return from main c function
