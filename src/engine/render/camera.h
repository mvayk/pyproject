#pragma once
#define GLFW_INCLUDE_NONE

#include <stdio.h>

#include "object.h"
#include "render.h"
#include "../shader/shader.h"

#include "../../include/glad/glad.h"
#include "../../include/GLFW/glfw3.h"
#include "../../include/glm/glm.hpp"

typedef struct {
    glm::mat4 projection;
    glm::mat4 view;
    glm::mat4 model;
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;

    float speed;
}Camera;
