; mvayк
; mvayк
; mvayк

; register order:
; rcx rdx r8 r9 -> stack
; rax is return value

extern printf
extern MessageBoxA

global asm_main

section .data
    fmt db "%d", 10, 0
    success db "pce", 10, 0

    title db "o", 0
    msg db "msgbox", 0

section .text
asm_main:
    sub rsp, 40

    lea rcx, [rel success] ; rcx is * to string - printf
    call printf

    xor rcx, rcx            ; hwnd
    lea rdx, [rel msg]      ; text
    lea r8, [rel title]     ; title
    mov r9d, 0              ; type
    call MessageBoxA

    mov rcx, 10
    mov rdx, 100
    call add

    mov rcx, fmt
    mov rdx, rax
    call printf

    xor eax, 1 ; return 0;
    add rsp, 40 ; realigns the stack
    ret

add:
    mov rax, rcx
    add rax, rdx
    ret
