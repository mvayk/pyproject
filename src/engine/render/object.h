#pragma once
#define GLFW_INCLUDE_NONE

#include <stdio.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "render.h"

namespace objects {
    vertex floor[] = {
        {{-5.0f, 0.0f, -5.0f}, {0.3f, 0.7f, 0.3f}},
        {{ 5.0f, 0.0f, -5.0f}, {0.3f, 0.7f, 0.3f}},
        {{ 5.0f, 0.0f,  5.0f}, {0.3f, 0.7f, 0.3f}},
        {{ 5.0f, 0.0f,  5.0f}, {0.3f, 0.7f, 0.3f}},
        {{-5.0f, 0.0f,  5.0f}, {0.3f, 0.7f, 0.3f}},
        {{-5.0f, 0.0f, -5.0f}, {0.3f, 0.7f, 0.3f}},
    };
}