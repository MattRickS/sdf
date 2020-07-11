#pragma once
#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/ray.hpp>
#include <vec/vec3.hpp>
#include <vec/vec4.hpp>

namespace render
{
    typedef float distanceFunc(const vec::vec3 &pos);

    enum RenderFit
    {
        KeepRatio,
        Stretch,
    };

    class Renderer
    {
    public:
        distanceFunc *dfunc;
        float threshold;
        int aoSteps{5};
        float aoDelta{0.3f};
        float aoStrength{3.0f};

        Renderer(distanceFunc *func, float threshold = 0.0001f) : threshold(threshold)
        {
            this->dfunc = func;
        }

        // TODO: A vector of SDF functions - must define an interface
        void render(render::Camera &camera, render::Buffer &buffer, float maxDistance, RenderFit fit = RenderFit::KeepRatio);
        render::Hit project(render::Ray &ray, float maxDistance);
        vec::vec4 shade(render::Hit &hit);
        vec::vec3 gradient(const vec::vec3 &pos, float offset = 0.00001f);
    };
} // namespace render
