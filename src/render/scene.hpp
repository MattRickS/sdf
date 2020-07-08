#include "buffer.hpp"
#pragma once
#include <render/camera.hpp>
#include <render/ray.hpp>
#include <vec/float4.hpp>

namespace render
{
    class Scene
    {
    public:
        float threshold{0.0001f};
        // TODO: A vector of SDF functions - must define an interface
        void render(render::Camera &camera, ::Buffer &buffer, float maxDistance);
        vec::float4 process(render::Ray &ray, float maxDistance);
        float distance(vec::float4 &pos);
    };
} // namespace render
