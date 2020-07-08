#pragma once
#include <render/ray.hpp>
#include <vec/vec3.hpp>
#include <vec/mat4.hpp>

namespace render
{
    class Camera
    {
    public:
        vec::mat4 transform;
        float focal;
        float haperture;

        Camera(vec::mat4 &transform, float focal, float haperture) : focal(focal), haperture(haperture)
        {
            this->transform = transform;
        }

        render::Ray ray(float u, float v)
        {
            float ratio = focal / haperture;
            vec::vec3 offset = transform.forward() * ratio + transform.right() * u + transform.up() * v;
            return render::Ray(transform.position() + offset, normalize(offset));
        }
    };
} // namespace render
