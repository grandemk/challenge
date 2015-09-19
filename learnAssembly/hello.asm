
section .data
    hello db "REVISE chloe"

section .text
    global _start

_start:
    mov edi, hello
    ; calculate the length of the string
    mov ecx, -1
    xor al, al
    cld
    repnz scasb
    not ecx
    sub ecx, 1
    ; print string
    mov edx, ecx
    mov ecx, hello
    mov ebx, 1
    mov eax, 4
    int 80h
    ; exit
    xor ebx, ebx
    push byte 1
    pop eax
    int 80h

