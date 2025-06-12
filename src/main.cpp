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

__declspec(dllexport) int main() {
    /* call asm */
    if (asm_main() == 1) {
        printf("asm failed...");
        occur_fatal();
    }

    /* initialize glfw */
    glfwInit();
    GLFWwindow* g_window = glfwCreateWindow(800, 600, "game", NULL, NULL);
    if (!g_window) { LOG_FATAL("Failed to create g_window - exiting"); occur_fatal(); }

    glfwMakeContextCurrent(g_window);
    gladLoadGL();
    glViewport(0, 0, 800, 600);
    glEnable(GL_DEPTH_TEST);

    /* create floor */
    Object floor = create_floor();
    Shader floor_shader(shaders::vertex_shader, shaders::fragment_shader);

    /* camera */
    Camera camera;
    camera.position  = glm::vec3(0.0f, 4.0f, 6.0f);
    camera.front     = glm::vec3(0.0f, -0.5f, -1.0f);
    camera.up        = glm::vec3(0.0f, 1.0f, 0.0f);
    camera.model     = glm::mat4(1.0f);
    camera.projection = glm::perspective(glm::radians(45.0f), 800.f / 600.f, 0.1f, 100.0f);

    /* timing */
    float delta_time = 0.0f;
    float last_frame = 0.0f;
    const float base_speed = 5.0f;

    /* main loop */
    while (!glfwWindowShouldClose(g_window)) {
        /* delta time */
        float current_frame = glfwGetTime();
        delta_time = current_frame - last_frame;
        last_frame = current_frame;

        float speed = base_speed * delta_time;

        /* movement */
        if (glfwGetKey(g_window, GLFW_KEY_W) == GLFW_PRESS)
            camera.position += speed * camera.front;
        if (glfwGetKey(g_window, GLFW_KEY_S) == GLFW_PRESS)
            camera.position -= speed * camera.front;
        if (glfwGetKey(g_window, GLFW_KEY_A) == GLFW_PRESS)
            camera.position -= glm::normalize(glm::cross(camera.front, camera.up)) * speed;
        if (glfwGetKey(g_window, GLFW_KEY_D) == GLFW_PRESS)
            camera.position += glm::normalize(glm::cross(camera.front, camera.up)) * speed;

        /* update view */
        camera.view = glm::lookAt(camera.position, camera.position + camera.front, camera.up);

        /* render */
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        draw_object(floor, floor_shader, camera.projection, camera.view, camera.model);

        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

    destroy_object(floor);
    glfwDestroyWindow(g_window);
    glfwTerminate();

    return 0;
}
