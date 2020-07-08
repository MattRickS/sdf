#pragma once
#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/ray.hpp>
#include <vec/vec3.hpp>
#include <vec/vec4.hpp>

namespace render
{
    class Renderer
    {
    public:
        float threshold{0.0001f};
        // TODO: A vector of SDF functions - must define an interface
        void render(render::Camera &camera, render::Buffer &buffer, float maxDistance);
        vec::vec4 process(render::Ray &ray, float maxDistance);
        float distance(vec::vec3 &pos);
    };
} // namespace render
