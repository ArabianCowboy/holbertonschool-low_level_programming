section .data
    msg db "Hello, World", 10    ; the string + newline
    len equ $ - msg              ; length of the string

section .text
    global _start

_start:
    mov rax, 1        ; syscall number for write
    mov rdi, 1        ; file descriptor (stdout)
    mov rsi, msg      ; pointer to string
    mov rdx, len      ; length of string
    syscall

    mov rax, 60       ; syscall number for exit
    xor rdi, rdi      ; exit code 0
    syscall
