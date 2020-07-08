#include "buffer.hpp"
#pragma once
#include <scene/camera.hpp>
#include <scene/ray.hpp>
#include <vec/float4.hpp>

namespace scene
{
    class Scene
    {
    public:
        float threshold{0.0001f};
        // TODO: A vector of SDF functions - must define an interface
        void render(scene::Camera &camera, ::Buffer &buffer, float maxDistance);
        vec::float4 process(scene::Ray &ray, float maxDistance);
        float distance(vec::float4 &pos);
    };
} // namespace scene
