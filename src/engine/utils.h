#pragma once
#define GLFW_INCLUDE_NONE

#include <stdio.h>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include <cstdio>

#define NL "\n"
#define LOG_ERROR(...) fprintf(stderr, "[-] " __VA_ARGS__); fprintf(stderr, NL)
#define LOG_FATAL(...) fprintf(stderr, "[!] " __VA_ARGS__); fprintf(stderr, NL)
#define LOG_PRINT(...) fprintf(stdout, "[+] " __VA_ARGS__); fprintf(stdout, NL)

int occur_fatal() {
    glfwTerminate();
    getc(stdin);
    return -1;
}
