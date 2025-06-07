/* mvayк */
/* mvayк */
/* mvayк */

/* kkk */
#include <stdio.h>
#include <windows.h>

/* engine */
#include "engine/utils.h"
#include "engine/shader/shader.h"
#include "engine/render/object.h"
#include "engine/render/render.h"

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
__declspec(dllexport) int main() {
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

    /* shaders & stuff */
    Shader shader(shaders::vertex_shader, shaders::fragment_shader);

    /* glm math */
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.f/600.f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 4.0f, 6.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 model = glm::mat4(1.0f);

    mesh floor_mesh = create_mesh(objects::floor, 6);
    while (!glfwWindowShouldClose(g_window)) {
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        /* use shaders */
        shader.use() ;
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        shader.setMat4("model", model);

        draw_mesh(&floor_mesh);

        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

    free_mesh(&floor_mesh);
    glfwDestroyWindow(g_window);
    glfwTerminate();

    return 0;
}
