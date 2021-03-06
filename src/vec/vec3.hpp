#pragma once
#include <algorithm>
#include <cmath>

namespace vec
{
    class vec3
    {
    public:
        union
        {
            struct
            {
                float x, y, z;
            };
            struct
            {
                float r, g, b;
            };
            float data[3];
        };
        vec3() {}
        vec3(float x) : x(x), y(x), z(x) {}
        vec3(float x, float y, float z) : x(x), y(y), z(z) {}

        static vec::vec3 up()
        {
            return vec::vec3(0.0f, 1.0f, 0.0f);
        }

        static vec::vec3 right()
        {
            return vec::vec3(1.0f, 0.0f, 0.0f);
        }

        static vec::vec3 forward()
        {
            return vec::vec3(0.0f, 0.0f, 1.0f);
        }

        inline float &operator[](int i)
        {
            return data[i];
        }

        inline void operator+=(const vec::vec3 &rhs)
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
        }

        inline void operator-=(const vec::vec3 &rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
        }

        inline void operator+=(float rhs)
        {
            x += rhs;
            y += rhs;
            z += rhs;
        }

        inline void operator-=(float rhs)
        {
            x -= rhs;
            y -= rhs;
            z -= rhs;
        }

        inline void operator*=(float rhs)
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;
        }

        inline void operator/=(float rhs)
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;
        }
    };
} // namespace vec

inline std::ostream &operator<<(std::ostream &_stream, vec::vec3 const &f)
{
    _stream << '(' << f.x << ", " << f.y << ", " << f.z << ')';
}

inline vec::vec3 operator+(const vec::vec3 &lhs, const vec::vec3 &rhs)
{
    return vec::vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

inline vec::vec3 operator+(const vec::vec3 &lhs, const float &rhs)
{
    return vec::vec3(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
}

inline vec::vec3 operator-(const vec::vec3 &lhs)
{
    return vec::vec3(-lhs.x, -lhs.y, -lhs.z);
}

inline vec::vec3 operator-(const vec::vec3 &lhs, const vec::vec3 &rhs)
{
    return vec::vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

inline vec::vec3 operator-(const vec::vec3 &lhs, const float &rhs)
{
    return vec::vec3(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
}

inline vec::vec3 operator*(const vec::vec3 &lhs, const float &rhs)
{
    return vec::vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

inline vec::vec3 operator/(const vec::vec3 &lhs, const float &rhs)
{
    return vec::vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

inline vec::vec3 abs(const vec::vec3 &lhs)
{
    return vec::vec3(std::abs(lhs.x), std::abs(lhs.y), std::abs(lhs.z));
}

inline vec::vec3 mod(const vec::vec3 &lhs, const float rhs)
{
    return vec::vec3(fmod(lhs.x, rhs), fmod(lhs.y, rhs), fmod(lhs.z, rhs));
}

inline vec::vec3 mod(const vec::vec3 &lhs, const vec::vec3 rhs)
{
    return vec::vec3(fmod(lhs.x, rhs.x), fmod(lhs.y, rhs.y), fmod(lhs.z, rhs.z));
}

inline vec::vec3 pow(const vec::vec3 &lhs, float rhs)
{
    return vec::vec3(powf(lhs.x, rhs), powf(lhs.y, rhs), powf(lhs.z, rhs));
}

inline float dot(const vec::vec3 &lhs)
{
    return lhs.x * lhs.x + lhs.y * lhs.y + lhs.z * lhs.z;
}

inline float dot(const vec::vec3 &lhs, const vec::vec3 &rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline vec::vec3 cross(const vec::vec3 &lhs, const vec::vec3 &rhs)
{
    return vec::vec3(
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x);
}

inline float length(const vec::vec3 &lhs)
{
    return std::sqrt(dot(lhs));
}

inline vec::vec3 normalize(const vec::vec3 &lhs)
{
    float l(length(lhs));
    return (l > 0) ? lhs / l : vec::vec3(0.0f);
}

inline vec::vec3 clamp(const vec::vec3 &lhs, const float min_, const float max_)
{
    return vec::vec3(
        std::min(std::max(lhs.x, min_), max_),
        std::min(std::max(lhs.y, min_), max_),
        std::min(std::max(lhs.z, min_), max_));
}

inline vec::vec3 clamp(const vec::vec3 &lhs, const vec::vec3 &min_, const vec::vec3 &max_)
{
    return vec::vec3(
        std::min(std::max(lhs.x, min_.x), max_.x),
        std::min(std::max(lhs.y, min_.y), max_.y),
        std::min(std::max(lhs.z, min_.z), max_.z));
}

inline vec::vec3 round(const vec::vec3 &lhs)
{
    return vec::vec3(std::round(lhs.x), std::round(lhs.y), std::round(lhs.z));
}

inline vec::vec3 max(const vec::vec3 &lhs, const float rhs)
{
    return vec::vec3(
        std::max(lhs.x, rhs),
        std::max(lhs.y, rhs),
        std::max(lhs.z, rhs));
}

inline vec::vec3 max(const vec::vec3 &lhs, const vec::vec3 &rhs)
{
    return vec::vec3(
        std::max(lhs.x, rhs.x),
        std::max(lhs.y, rhs.y),
        std::max(lhs.z, rhs.z));
}

inline vec::vec3 min(const vec::vec3 &lhs, const float rhs)
{
    return vec::vec3(
        std::min(lhs.x, rhs),
        std::min(lhs.y, rhs),
        std::min(lhs.z, rhs));
}

inline vec::vec3 min(const vec::vec3 &lhs, const vec::vec3 &rhs)
{
    return vec::vec3(
        std::min(lhs.x, rhs.x),
        std::min(lhs.y, rhs.y),
        std::min(lhs.z, rhs.z));
}
