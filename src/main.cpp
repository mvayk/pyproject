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

    float floorVertices[] = {
    -5.0f, 0.0f, -5.0f,   0.3f, 0.7f, 0.3f,
     5.0f, 0.0f, -5.0f,   0.3f, 0.7f, 0.3f,
     5.0f, 0.0f,  5.0f,   0.3f, 0.7f, 0.3f,

     5.0f, 0.0f,  5.0f,   0.3f, 0.7f, 0.3f,
    -5.0f, 0.0f,  5.0f,   0.3f, 0.7f, 0.3f,
    -5.0f, 0.0f, -5.0f,   0.3f, 0.7f, 0.3f
    };


    /* refactor later */
    unsigned int floorVAO, floorVBO;
    glGenVertexArrays(1, &floorVAO);
    glGenBuffers(1, &floorVBO);

    glBindVertexArray(floorVAO);
    glBindBuffer(GL_ARRAY_BUFFER, floorVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    Shader floorShader(shaders::vertex_shader, shaders::fragment_shader);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.f/600.f, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 4.0f, 6.0f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 model = glm::mat4(1.0f);

    /* declare player struct */
    Player player;
    player.name = "ben";
    player.health = 100;
    player.skin_color = "white";

    printf("%d/n", player.self.id);

    Monster monster;
    monster.health = 100;

    while (!glfwWindowShouldClose(g_window)) {
        printf("5");
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        floorShader.use();
        floorShader.setMat4("projection", projection);
        floorShader.setMat4("view", view);
        floorShader.setMat4("model", model);

        glBindVertexArray(floorVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);


        glfwPollEvents();
        glfwSwapBuffers(g_window);
    }

    glfwDestroyWindow(g_window);
    glfwTerminate();

    return 0;
}
