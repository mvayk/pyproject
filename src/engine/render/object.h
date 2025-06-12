#pragma once
#define GLFW_INCLUDE_NONE

#include <stdio.h>

#include "../../include/glad/glad.h"
#include "../../include/GLFW/glfw3.h"

typedef struct {
    unsigned int VAO, VBO;
}Object;

inline Object create_floor() {
    float floorVertices[] = {
    -5.0f, 0.0f, -5.0f, 0.3f, 0.7f, 0.3f,
     5.0f, 0.0f, -5.0f, 0.3f, 0.7f, 0.3f,
     5.0f, 0.0f,  5.0f, 0.3f, 0.7f, 0.3f,
     5.0f, 0.0f,  5.0f, 0.3f, 0.7f, 0.3f,
    -5.0f, 0.0f,  5.0f, 0.3f, 0.7f, 0.3f,
    -5.0f, 0.0f, -5.0f, 0.3f, 0.7f, 0.3f
    };

    Object floor;
    glGenVertexArrays(1, &floor.VAO);
    glGenBuffers(1, &floor.VBO);

    glBindVertexArray(floor.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, floor.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    return floor;
}
