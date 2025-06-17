#pragma once

#include <iostream>
#include <windows.h>
#include <vector>

#include "../utils.h"
#include "../render/object.h"
#include "../render/camera.h"
#include "../render/render.h"
#include "../shader/shader.h"
#include "../shader/vert_frag.h"

#include "../../include/glad/glad.h"
#include "../../include/GLFW/glfw3.h"
#include "../../include/glm/glm.hpp"
#include "../../include/glm/gtc/matrix_transform.hpp"
#include "../../include/glm/gtc/type_ptr.hpp"

const float THICKNESS = 0.2f;

/* stuff that i dont understand */
bool collided(const glm::vec3& position, const Wall& wall) {
    glm::vec2 world_plane(position.x, position.z);

    glm::vec2 wall_vector = wall.end - wall.start;
    glm::vec2 player_vector = world_plane - wall.start;

    float wall_length = glm::dot(wall_vector, wall_vector);
    if (wall_length == 0.0f) {
        return glm::distance(world_plane, wall.start) < THICKNESS;
    }

    float something_questionmark = glm::dot(player_vector, wall_vector) / wall_length;
    something_questionmark = glm::clamp(something_questionmark, 0.0f, 1.0f);

    glm::vec2 closet_wall = wall.start + something_questionmark * wall_vector;
    float distance = glm::distance(world_plane, closet_wall);

    return distance < THICKNESS;
}
