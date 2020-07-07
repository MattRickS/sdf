#include <vec/float4.hpp>

namespace sdf
{
    float sphere(vec::float4 pos, float radius)
    {
        return length(pos) - radius;
    }
} // namespace sdf