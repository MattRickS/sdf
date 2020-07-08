#include <vec/mat4.hpp>
#include <vec/vec3.hpp>

namespace sdf
{
    vec::vec3 transform(vec::vec3 pos, vec::mat4 xform)
    {
        return invert(xform) * pos;
    }

    vec::vec3 repeat(vec::vec3 pos, vec::vec3 offset)
    {
        return mod(pos + offset * 0.5f, offset) - offset * 0.5f;
    }
} // namespace sdf
