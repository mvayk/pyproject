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
#include "engine/game/map.h"
#include "engine/render/object.h"
#include "engine/render/render.h"
#include "engine/render/camera.h"
//#include "engine/shader/vert_frag.h"

/* opengl glfw glad */
#define GLFW_INCLUDE_NONE
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"

/* glm */
#include "include/glm/glm.hpp"
#include "include/glm/gtc/matrix_transform.hpp"
#include "include/glm/gtc/type_ptr.hpp"

/* definitions */
#define GLM_FORCE_RADIANS

/* integrate master.asm */
#include "asm/asm_globals.h"

/* global scope because */
Camera camera;

bool first_timer = true;
float last_x = 400.0f;
float last_y = 300.0f;

void callback(GLFWwindow* window, double xpos, double ypos) {
    if (first_timer == true) {
        last_x = xpos;
        last_y = ypos;
        first_timer = false;
    }

    float xoffset = xpos - last_x;
    float yoffset = last_y - ypos;

    last_x = xpos;
    last_y = ypos;

    xoffset *= camera.sensitivity;
    yoffset *= camera.sensitivity;

    camera.yaw += xoffset;
    camera.pitch += yoffset;

    if (camera.pitch > 89.0f) camera.pitch = 89.0f;
    if (camera.pitch < -89.0f) camera.pitch = -89.0f;

    glm::vec3 direction;
    direction.x = cos(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    direction.y = sin(glm::radians(camera.pitch));
    direction.z = sin(glm::radians(camera.yaw)) * cos(glm::radians(camera.pitch));
    camera.front = glm::normalize(direction);
}

__declspec(dllexport) int main() {
    /* call asm */
    if (asm_main() == 1) {
        printf("asm failed...");
        occur_fatal();
    }

    /* city of agartha */ 
    const int window_x = 800;
    const int window_y = 600;

    /* initialize glfw */
    glfwInit();
    GLFWwindow* g_window = glfwCreateWindow(window_x, window_y, "Damien's Doom", NULL, NULL);
    if (!g_window) { LOG_FATAL("Failed to create g_window - exiting"); occur_fatal(); }

    glfwMakeContextCurrent(g_window);
    gladLoadGL();
    glViewport(0, 0, window_x, window_y);
    glEnable(GL_DEPTH_TEST);

    /* create floor */
    Object floor = create_floor();
    Shader floor_shader(shaders::vertex_shader, shaders::fragment_shader);

    /* 我为什么换到了 Tab 缩进 --sxyazi */
    level::load(GODS_PLAN);

    /* mouse */
    glfwSetInputMode(g_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(g_window, callback);

    /* timing */
    float delta_time = 0.0f;
    float last_frame = 0.0f;

    /* entities */
    const float height_clamp = 1.6f;

    player.self.height_clamp = height_clamp;
    player.name = "ben";
    player.health = 100;
    player.skin_color = "pale";
    player.speed = 5.0f;
    set_fov(); player.fov = (float)player.fov;

    /* camera */
    camera.position   = glm::vec3(0.0f, 4.0f, 6.0f);
    camera.front      = glm::vec3(0.0f, -0.5f, -1.0f);
    camera.up         = glm::vec3(0.0f, 1.0f, 0.0f);
    camera.model      = glm::mat4(1.0f);
    camera.projection = glm::perspective(glm::radians(120.0f), 800.f / 600.f, 0.1f, 100.0f);

    /* huh */
    //rape_the_vad_exclamation_mark();

    /* main loop */
    while (!glfwWindowShouldClose(g_window)) {
        /* delta time */
        float current_frame = glfwGetTime();
        delta_time = current_frame - last_frame;
        last_frame = current_frame;

        float frame_speed = player.speed * delta_time;

        /* update view */
        camera.view = glm::lookAt(camera.position, camera.position + camera.front, camera.up);

        /* movement */
        if (glfwGetKey(g_window, GLFW_KEY_W) == GLFW_PRESS)
            camera.position += frame_speed * camera.front;
        if (glfwGetKey(g_window, GLFW_KEY_S) == GLFW_PRESS)
            camera.position -= frame_speed * camera.front;
        if (glfwGetKey(g_window, GLFW_KEY_A) == GLFW_PRESS)
            camera.position -= glm::normalize(glm::cross(camera.front, camera.up)) * frame_speed;
        if (glfwGetKey(g_window, GLFW_KEY_D) == GLFW_PRESS)
            camera.position += glm::normalize(glm::cross(camera.front, camera.up)) * frame_speed;

        camera.position.y = player.self.height_clamp;

        /* render */
        glClearColor(0.2f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        draw_object(floor, floor_shader, camera.projection, camera.view, camera.model);
        level::render_active(camera.projection, camera.view, camera.model);

        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

    level::wipetheslatecleandude();
    end_vad_abuse();
    destroy_object(floor);
    glfwDestroyWindow(g_window);
    glfwTerminate();

    return 0;
}
