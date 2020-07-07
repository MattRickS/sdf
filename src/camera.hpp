#pragma once
#include <scene/ray.hpp>
#include <vec/float4.hpp>
#include <vec/mat4.hpp>

namespace scene
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

        scene::Ray ray(float u, float v)
        {
            float ratio = focal / haperture;
            vec::float4 origin = transform.position();
            vec::float4 direction = normalize(
                transform.forward() * ratio + transform.right() * u + transform.up() * v);
            return scene::Ray(origin, direction);
        }
    };
} // namespace scene
