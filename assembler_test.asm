%include "io.inc"
section .data
Hallo DB "Hallo"
A DD 12h
section .text
global CMAIN
CMAIN:
mov ebp, esp ; for correct debugging
;write your code here
xor eax, eax
MOV EAX, [A]
MOV EBX, 12
ADD EAX, EBX
PRINT_STRING Hallo
PRINT_DEC 4, EAX
xor eax, eax
ret
