section .data
    msg db "Hello, World", 10    ; string with newline
    len equ $ - msg              ; length of string

section .text
    global _start

_start:
    mov rax, 1        ; syscall: write
    mov rdi, 1        ; fd = stdout
    mov rsi, msg      ; pointer to string
    mov rdx, len      ; length of string
    syscall

    mov rax, 60       ; syscall: exit
    xor rdi, rdi      ; exit code 0
    syscall
