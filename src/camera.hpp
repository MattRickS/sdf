#pragma once
#include "float4.hpp"
#include "matrix4.hpp"
#include "ray.hpp"

class Camera
{
public:
    matrix4 transform;
    float focal;
    float haperture;

    Camera(matrix4 &transform, float focal, float haperture) : focal(focal), haperture(haperture)
    {
        this->transform = transform;
    }

    Ray ray(float u, float v)
    {
        float ratio = focal / haperture;
        float4 origin = transform.position();
        float4 direction = normalize(
            transform.forward() * ratio + transform.right() * u + transform.up() * v);
        return Ray(origin, direction);
    }
};
