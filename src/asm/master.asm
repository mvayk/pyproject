; mvayк
; mvayк
; mvayк

extern printf
global asm_main

section .data
    fmt db "pce", 10, 0 ; 10 is null terminator

section .text
asm_main:
    sub rsp, 40

    lea rcx, [rel fmt] ; rcx is * to string - printf
    call printf

    xor eax, eax ; return 0;
    add rsp, 40 ; realigns the stack
    ret
