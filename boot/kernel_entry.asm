[bits 32]
[extern _start]
call _start

jmp $ ; endless loop if we return from main c function (which should never happen if we have an endless loop in the main function)