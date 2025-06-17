#pragma once
#define GLFW_INCLUDE_NONE

#include <stdio.h>

#include "../../include/glad/glad.h"
#include "../../include/GLFW/glfw3.h"
#include "../../include/glm/glm.hpp"
#include "../../include/glm/gtc/matrix_transform.hpp"
#include "../../include/glm/gtc/type_ptr.hpp"

typedef struct {
    unsigned int VAO, VBO;
}Object;

const float GROUND_LEVEL = 0.0f;
const float WALL_HEIGHT = 3.0f;

struct Wall {
    glm::vec2 start;
    glm::vec2 end;
};

inline Object create_floor() {
    const float r = 0.2f;
    const float g = 0.2f;
    const float b = 0.2f;

    float floorVertices[] = {
    -25.0f, GROUND_LEVEL, -25.0f, r, g, b,
     25.0f, GROUND_LEVEL, -25.0f, r, g, b,
     25.0f, GROUND_LEVEL,  25.0f, r, g, b,
     25.0f, GROUND_LEVEL,  25.0f, r, g, b,
    -25.0f, GROUND_LEVEL,  25.0f, r, g, b,
    -25.0f, GROUND_LEVEL, -25.0f, r, g, b,
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

/*
 * came up with the idea to use points in 2d space-
 * and then adding to their y with a const
 */
inline Object create_wall(const Wall& wall) {
    float x1 = wall.start.x;
    float z1 = wall.start.y;
    float x2 = wall.end.x;
    float z2 = wall.end.y;

    /* succulent gray */
    const float R = 0.4f;
    const float G = 0.4f;
    const float B = 0.4f;

    /* triangles a + b = c < a halal */
    const float vertices[] = {
        x1, GROUND_LEVEL, z1, R, G, B,
        x2, GROUND_LEVEL, z2, R, G, B,
        x2, WALL_HEIGHT,  z2, R, G, B,

        x2, WALL_HEIGHT,  z2, R, G, B,
        x1, WALL_HEIGHT,  z1, R, G, B,
        x1, GROUND_LEVEL, z1, R, G, B,
    };

    /* create new object */
    Object wall_object;

    /* boiler plate propaganda */
    glGenVertexArrays(1, &wall_object.VAO);
    glGenBuffers(1, &wall_object.VBO);

    glBindVertexArray(wall_object.VAO);
    glBindBuffer(GL_ARRAY_BUFFER, wall_object.VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    return wall_object;
}
