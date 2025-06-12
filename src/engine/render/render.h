#pragma once
#define GLFW_INCLUDE_NONE

#include <stdio.h>

#include "object.h"
#include "../shader/shader.h"

#include "../../include/glad/glad.h"
#include "../../include/GLFW/glfw3.h"
#include "../../include/glm/glm.hpp"

inline void draw_object(const Object& object, Shader& shader, const glm::mat4& projection, const glm::mat4& view, const glm::mat4& model) {
    shader.use();
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);
    shader.setMat4("model", model);

    glBindVertexArray(object.VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

inline void destroy_object(Object& object) {
    glDeleteVertexArrays(1, &object.VAO);
    glDeleteBuffers(1, &object.VBO);
}
