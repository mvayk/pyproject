#pragma once

#include <stdio.h>

#define NL "\n"
#define LOG_ERROR(...) fprintf(stderr, "[-] " __VA_ARGS__); fprintf(stderr, NL)
#define LOG_FATAL(...) fprintf(stderr, "[!] " __VA_ARGS__); fprintf(stderr, NL)
#define LOG_PRINT(...) fprintf(stdout, "[+] " __VA_ARGS__); fprintf(stdout, NL)

int occur_fatal() {
    glfwTerminate();
    getc(stdin);
    return -1;
}