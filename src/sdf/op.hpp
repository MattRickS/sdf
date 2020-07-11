#pragma once
#include <vec/mat4.hpp>
#include <vec/vec3.hpp>

namespace sdf
{
    typedef float distanceFunc(const vec::vec3 &pos);

    vec::vec3 calcNormal(const vec::vec3 &pos, distanceFunc f, float offset = 0.0001);
    vec::vec3 transform(const vec::vec3 pos, vec::mat4 xform);
    vec::vec3 repeat(const vec::vec3 pos, vec::vec3 offset);
    vec::vec3 repeat(const vec::vec3 pos, float spacing, vec::vec3 limits);
} // namespace sdf
