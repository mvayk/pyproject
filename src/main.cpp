/* mvayк */
/* mvayк */
/* mvayк */

/* kkk */
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <cstdio>

/* engine */
#include "engine/utils.h"
#include "engine/shader/shader.h"
#include "engine/game/entity.h"
#include "engine/render/object.h"
#include "engine/render/render.h"
#include "engine/render/camera.h"

/* opengl glfw glad */
#define GLFW_INCLUDE_NONE
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"
#include "engine/shader/vert_frag.h"

/* glm */
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

/* definitions */
#define GLM_FORCE_RADIANS

/* integrate master.asm */
extern "C" int asm_main();

/* C main function - gets exported for ctypes */
__declspec(dllexport) int main() {
    int asm_r = asm_main();
    if (asm_r == 1) {
        printf("asm failed...");
        occur_fatal();
    }

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

    /* viewport */
    Object floor = create_floor();
    Shader floor_shader(shaders::vertex_shader, shaders::fragment_shader);

    /* initialize the camera */
    Camera camera;

    while (!glfwWindowShouldClose(g_window)) {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera.projection = glm::perspective(glm::radians(45.0f), 800.f / 600.f, 0.1f, 100.0f);
        camera.view = glm::lookAt(glm::vec3(0.0f, 4.0f, 6.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        camera.model = glm::mat4(1.0f);

        draw_object(floor, floor_shader, camera.projection, camera.view, camera.model);

        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

    destroy_object(floor);
    glfwDestroyWindow(g_window);
    glfwTerminate();

    return 0;
}
