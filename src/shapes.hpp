#include "float4.hpp"

float sphere(float4 center, float radius)
{
    return length(center) - radius;
}