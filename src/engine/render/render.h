#pragma once
#define GLFW_INCLUDE_NONE

#include <stdio.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

/* vertex struct */
struct vertex {
    float position[3];
    float color[3];
};

/* mesh struct */
struct mesh {
    GLuint vao;
    GLuint vbo;
    GLsizei vertex_count;
};

/* create mesh using mesh struct psuedo class */
mesh create_mesh(const vertex* vertices, size_t vertex_count) {
    mesh g_mesh;
    g_mesh.vertex_count = static_cast<GLsizei>(vertex_count);

    glGenVertexArrays(1, &g_mesh.vao);
    glGenVertexArrays(1, &g_mesh.vbo);

    glBindVertexArray(g_mesh.vao);
    glBindBuffer(GL_ARRAY_BUFFER, g_mesh.vbo);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(vertex), vertices, GL_STATIC_DRAW);

    /* positioning */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, position));
    glEnableVertexAttribArray(0);

    /* colors */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, color));
    glEnableVertexAttribArray(1);

    /* end */
    glBindVertexArray(0);

    return g_mesh;
}

void draw_mesh(const mesh* g_mesh) {
    glBindVertexArray(g_mesh->vao);
    glDrawArrays(GL_TRIANGLES, 0, g_mesh->vertex_count);
    glBindVertexArray(0);
}

void free_mesh(mesh* g_mesh) {
    glDeleteVertexArrays(1, &g_mesh->vao);
    glDeleteBuffers(1, &g_mesh->vbo);
}