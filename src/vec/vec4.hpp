#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vec/vec3.hpp>

namespace vec
{
    class vec4
    {
    public:
        union
        {
            struct
            {
                float x, y, z, w;
            };
            struct
            {
                float r, g, b, a;
            };
            float data[4];
        };
        vec4() {}
        vec4(vec::vec3 v) : x(v.x), y(v.y), z(v.z), w(1.0f) {}
        vec4(vec::vec3 v, float w) : x(v.x), y(v.y), z(v.z), w(w) {}
        vec4(float x) : x(x), y(x), z(x), w(x) {}
        vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        inline float &operator[](int i)
        {
            return data[i];
        }

        inline void operator+=(const vec::vec4 &rhs)
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;
        }

        inline void operator-=(const vec::vec4 &rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;
        }

        inline void operator+=(float rhs)
        {
            x += rhs;
            y += rhs;
            z += rhs;
            w += rhs;
        }

        inline void operator-=(float rhs)
        {
            x -= rhs;
            y -= rhs;
            z -= rhs;
            w -= rhs;
        }

        inline void operator*=(float rhs)
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            w *= rhs;
        }

        inline void operator/=(float rhs)
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            w /= rhs;
        }
    };
} // namespace vec

inline std::ostream &operator<<(std::ostream &_stream, vec::vec4 const &f)
{
    _stream << '(' << f.x << ", " << f.y << ", " << f.z << ", " << f.w << ')';
}

inline vec::vec4 operator+(const vec::vec4 &lhs, const vec::vec4 &rhs)
{
    return vec::vec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

inline vec::vec4 operator+(const vec::vec4 &lhs, const float &rhs)
{
    return vec::vec4(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
}

inline vec::vec4 operator-(const vec::vec4 &lhs, const vec::vec4 &rhs)
{
    return vec::vec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

inline vec::vec4 operator-(const vec::vec4 &lhs, const float &rhs)
{
    return vec::vec4(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
}

inline vec::vec4 operator*(const vec::vec4 &lhs, const float &rhs)
{
    return vec::vec4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

inline vec::vec4 operator/(const vec::vec4 &lhs, const float &rhs)
{
    return vec::vec4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

inline vec::vec4 abs(const vec::vec4 &lhs)
{
    return vec::vec4(std::abs(lhs.x), std::abs(lhs.y), std::abs(lhs.z), std::abs(lhs.w));
}

inline vec::vec4 mod(const vec::vec4 &lhs, const float rhs)
{
    return vec::vec4(
        fmod(lhs.x, rhs),
        fmod(lhs.y, rhs),
        fmod(lhs.z, rhs),
        fmod(lhs.w, rhs));
}

inline vec::vec4 mod(const vec::vec4 &lhs, const vec::vec4 rhs)
{
    return vec::vec4(
        fmod(lhs.x, rhs.x),
        fmod(lhs.y, rhs.y),
        fmod(lhs.z, rhs.z),
        fmod(lhs.w, rhs.w));
}

inline vec::vec4 pow(const vec::vec4 &lhs, float rhs)
{
    return vec::vec4(powf(lhs.x, rhs), powf(lhs.y, rhs), powf(lhs.z, rhs), powf(lhs.w, rhs));
}

inline float dot(const vec::vec4 &lhs, const vec::vec4 &rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

inline float dot(const vec::vec4 &lhs)
{
    return dot(lhs, lhs);
}

inline float length(const vec::vec4 &lhs)
{
    return std::sqrt(dot(lhs));
}

inline vec::vec4 normalize(const vec::vec4 &lhs)
{
    float l(length(lhs));
    return (l > 0) ? lhs / l : vec::vec4(0.0f);
}

inline vec::vec4 clamp(const vec::vec4 &lhs, const float min_, const float max_)
{
    return vec::vec4(
        std::min(std::max(lhs.x, min_), max_),
        std::min(std::max(lhs.y, min_), max_),
        std::min(std::max(lhs.z, min_), max_),
        std::min(std::max(lhs.w, min_), max_));
}

inline vec::vec4 max(const vec::vec4 &lhs, const float rhs)
{
    return vec::vec4(
        std::max(lhs.x, rhs),
        std::max(lhs.y, rhs),
        std::max(lhs.z, rhs),
        std::max(lhs.w, rhs));
}

inline vec::vec4 max(const vec::vec4 &lhs, const vec::vec4 &rhs)
{
    return vec::vec4(
        std::max(lhs.x, rhs.x),
        std::max(lhs.y, rhs.y),
        std::max(lhs.z, rhs.z),
        std::max(lhs.w, rhs.w));
}

inline vec::vec4 min(const vec::vec4 &lhs, const float rhs)
{
    return vec::vec4(
        std::min(lhs.x, rhs),
        std::min(lhs.y, rhs),
        std::min(lhs.z, rhs),
        std::min(lhs.w, rhs));
}

inline vec::vec4 min(const vec::vec4 &lhs, const vec::vec4 &rhs)
{
    return vec::vec4(
        std::min(lhs.x, rhs.x),
        std::min(lhs.y, rhs.y),
        std::min(lhs.z, rhs.z),
        std::min(lhs.w, rhs.w));
}
