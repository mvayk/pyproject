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

enum Level {
    GODS_PLAN
};

/* 我为什么换到了 Tab 缩进 --sxyazi */
namespace level {
    /* gotta solve the draw_object needing to be looped issue;;; */
    std::vector<std::pair<Object, Shader>> active_objects;

    bool load(int name) {
        if (name == GODS_PLAN) {
            Wall w1 = { { 0.0f, 0.0f, }, {5.0f, 0.0f} };
            Object w1_obj = create_wall(w1);
            Shader w1_shader(shaders::vertex_shader, shaders::fragment_shader);
            
            /* meant to be in a loop */
            //draw_object(w1_obj, w1_shader, projection, view, model);
            
            active_objects.push_back({w1_obj, w1_shader});
            return true;
        }
        return false;
    }

    void render_active(const glm::mat4& projection, const glm::mat4& view, const glm::mat4& model) {
        for (auto& [obj, shader] : active_objects) {
            draw_object(obj, shader,projection, view, model);
        }
    }

    void wipetheslatecleandude() {
        for (auto& [obj, _unusedbro] : active_objects) {
            destroy_object(obj);
        }

        active_objects.clear();
    }
}
