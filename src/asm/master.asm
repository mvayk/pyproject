; mvayк
; mvayк
; mvayк

; register order:
; rcx rdx r8 r9 -> stack
; rax is return value

; C functions
extern printf

; winapi functions
extern MessageBoxA
extern VirtualAlloc
extern VirtualFree
extern GetStdHandle
extern ExitProcess

; damien's doom
extern player

; globals
global asm_main
global set_fov
global rape_the_vad_exclamation_mark
global end_vad_abuse

section .bss
    nothingbuthate resq 1

section .data
    fmt db "%d", 10, 0
    success db "[!] Damien's Doom has loaded", 10, 0
    oh_balls db "[-] Failed to rape VAD", 10, 0
    crap_baskets db "[-] Failed to virginize VAD at cleanup", 10, 0
    memory_success db "[+] Successfully inseminated the VAD", 10, 0

    title db "Damien's Doom", 0
    msg db "Damien's Doom has loaded", 0

    ; vad raper 50% off
    size dq 5368709120 * 4
    alloc_flags dq 0x3000
    page_size dq 4096
    protect dq 0x40

section .text
set_fov:
    mov dword [rel player], 120
    ret

asm_main:
    sub rsp, 40

    lea rcx, [rel success] ; rcx is * to string - printf
    call printf

    mov rcx, 0              ; hwnd
    lea rdx, [rel msg]      ; text
    lea r8, [rel title]     ; title
    mov r9d, 0              ; type
    call MessageBoxA

    xor eax, eax ; return 0;

    add rsp, 40  ; realigns the stack
    ret

rape_the_vad_exclamation_mark:
    sub rsp, 40

    ; gather the bytes
    mov rcx, 0
    mov rdx, [rel size]
    mov r8, [rel alloc_flags]
    mov r9, [rel protect]

    call VirtualAlloc

    add rsp, 40
    test rax, rax
    jz .alloc_failed

    mov [rel nothingbuthate], rax
    
    xor rbx, rbx ; pass the bytes to the groper/s
.grope_loop:
    ; begin the groping
    mov rax, [rel nothingbuthate]
    add rax, rbx
    mov byte [rax], 0xCC
    add rbx, [rel page_size]
    cmp rbx, [rel size]
    jb .grope_loop

    jmp .done
.alloc_failed:
    sub rsp, 40
    lea rcx, [rel oh_balls] ; rcx is * to string - printf
    call printf
    add rsp, 40
    ret
.done:
    sub rsp, 40
    lea rcx, [rel memory_success] ; rcx is * to string - printf
    call printf
    add rsp, 40
    ret
end_vad_abuse:
    sub rsp, 40
    ; ICE gets called and illegal immigrants are deported
    mov rcx, [rel nothingbuthate]
    test rcx, rcx
    jz .skip_free

    mov rdx, 0
    mov r8, 0x8000

    call VirtualFree
.skip_free:
    sub rsp, 40
    lea rcx, [rel crap_baskets] ; rcx is * to string - printf
    call printf
    add rsp, 40
    ret
