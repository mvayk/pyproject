/* mvayк */
/* mvayк */
/* mvayк */

/* kkk */
#include <stdio.h>
#include <windows.h>

/* engine */
#include "engine/utils.h"

/* opengl glfw glad */
#define GLFW_INCLUDE_NONE
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"
#include "include/shader.h"

/* glm */
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

/* definitions */
#define GLM_FORCE_RADIANS

/* integrate master.asm */
extern "C" int asm_main();

/* C main function - gets exported for ctypes */
extern "C" __declspec(dllexport) int main(void) {
    int asm_r = asm_main();

    /* initialize glfw */
    glfwInit();

    /* create main window */
    GLFWwindow* g_window = glfwCreateWindow(800, 600, "game", NULL, NULL);
    if (!g_window) { LOG_FATAL("Failed to create g_window - exiting"); occur_fatal(); }

    /* create the window context */
    glfwMakeContextCurrent(g_window);

    /* load glad*/
    gladLoadGL();

    /* viewport */
    glViewport(0, 0, 800, 600);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(g_window)) {
        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

    glfwDestroyWindow(g_window);
    glfwTerminate();

    return 0;
}