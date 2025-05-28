/* mvayк */
/* mvayк */
/* mvayк */

#include <stdio.h>
#include <windows.h>

#include "game/utils.h"
#include "include/GL/gl.h"
#include "include/GL/glu.h"
#include "include/GLFW/glfw3.h"
#include "include/glad/glad.h"

/* integrate master.asm */
int asm_main();

/* C main function - gets exported for ctypes */
__declspec(dllexport) int main(void) {
    int asm_r = asm_main();

    /* initialize glfw */
    glfwInit();

    /* create main window */
    GLFWwindow* g_window = glfwCreateWindow(800, 600, "game", NULL, NULL);
    if (!g_window) { LOG_FATAL("Failed to create g_window - exiting"); occur_fatal(); }

    glViewport(0, 0, 800, 600);

    /* create the window context */
    glfwMakeContextCurrent(g_window);

    /* load glad*/
    gladLoadGL();

    while (!glfwWindowShouldClose(g_window)) {
        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

    glfwDestroyWindow(g_window);
    glfwTerminate();

    return 0;
}