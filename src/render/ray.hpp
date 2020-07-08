#pragma once
#include <vec/float4.hpp>

namespace render
{
    class Ray
    {
    public:
        vec::float4 origin;
        vec::float4 direction;

        Ray(vec::float4 origin, vec::float4 direction)
        {
            this->origin = origin;
            this->direction = direction;
        }

        void advance(float distance)
        {
            origin += direction * distance;
        }
    };
} // namespace render
