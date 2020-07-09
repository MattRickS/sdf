#include <sdf/op.hpp>

vec::vec3 sdf::calcNormal(const vec::vec3 &pos, distanceFunc f, float offset) // offset = 0.0001
{
    static const vec::vec3 k0(1.0f, -1.0f, -1.0f);
    static const vec::vec3 k1(-1.0f, -1.0f, 1.0f);
    static const vec::vec3 k2(-1.0f, 1.0f, -1.0f);
    static const vec::vec3 k3(1.0f, 1.0f, 1.0f);
    return normalize(k0 * f(pos + k0 * offset) +
                     k1 * f(pos + k1 * offset) +
                     k2 * f(pos + k2 * offset) +
                     k3 * f(pos + k3 * offset));
}

vec::vec3 sdf::transform(const vec::vec3 pos, vec::mat4 xform)
{
    return invert(xform) * pos;
}

vec::vec3 sdf::repeat(const vec::vec3 pos, vec::vec3 offset)
{
    return mod(pos + offset * 0.5f, offset) - offset * 0.5f;
}