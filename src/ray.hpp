#pragma once
#include "float4.hpp"

class Ray
{
public:
    float4 origin;
    float4 direction;

    Ray(float4 origin, float4 direction)
    {
        this->origin = origin;
        this->direction = direction;
    }

    void advance(float distance)
    {
        origin += direction * distance;
    }
};