#pragma once
#include <vec/vec3.hpp>

namespace sdf
{
    float sphere(vec::vec3 pos, float radius)
    {
        return length(pos) - radius;
    }

    float box(vec::vec3 pos, vec::vec3 dimensions)
    {
        vec::vec3 distances = abs(pos) - dimensions;
        return std::max(std::max(distances.x, distances.y), distances.z);
    }

    float plane(vec::vec3 pos, vec::vec3 normal, float height)
    {
        return dot(pos, normal) + height;
    }
} // namespace sdf