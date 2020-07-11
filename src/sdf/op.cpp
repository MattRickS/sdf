#include <sdf/op.hpp>

vec::vec3 sdf::transform(const vec::vec3 pos, vec::mat4 xform)
{
    return invert(xform) * pos;
}

vec::vec3 sdf::repeat(const vec::vec3 pos, vec::vec3 offset)
{
    return mod(pos + offset * 0.5f, offset) - offset * 0.5f;
}

vec::vec3 sdf::repeat(const vec::vec3 pos, float spacing, vec::vec3 limits)
{
    return pos - clamp(round(pos / spacing), -limits, limits) * spacing;
}