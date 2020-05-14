[bits 32]
[extern main]
call main

jmp $ ; endless loop if we return from main c function
