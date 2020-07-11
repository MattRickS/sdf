#pragma once
#include <vec/vec3.hpp>

namespace render
{
    class Ray
    {
    public:
        vec::vec3 origin;
        vec::vec3 direction;

        Ray(vec::vec3 origin, vec::vec3 direction)
        {
            this->origin = origin;
            this->direction = direction;
        }

        void advance(float distance)
        {
            origin += direction * distance;
        }
    };

    struct Hit
    {
        Ray ray;
        bool hit;
        float distance;

        Hit(Ray ray, bool hit, float distance) : ray(ray), hit(hit), distance(distance) {}
    };
} // namespace render
