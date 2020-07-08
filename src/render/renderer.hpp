#pragma once
#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/ray.hpp>
#include <vec/vec3.hpp>
#include <vec/vec4.hpp>

namespace render
{
    typedef float distanceFunc(vec::vec3 &pos);

    class Renderer
    {
    public:
        distanceFunc *dfunc;
        float threshold;

        Renderer(distanceFunc *func, float threshold = 0.0001f) : threshold(threshold)
        {
            this->dfunc = func;
        }

        // TODO: A vector of SDF functions - must define an interface
        void render(render::Camera &camera, render::Buffer &buffer, float maxDistance);
        vec::vec4 process(render::Ray &ray, float maxDistance);
    };
} // namespace render
