#pragma once
#include <algorithm>
#include <cmath>
#include <iostream>

namespace vec
{
    class float4
    {
    public:
        float x, y, z, w;

        float4() {}
        float4(float x) : x(x), y(x), z(x), w(x) {}
        float4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        float &operator[](int i)
        {
            switch (i)
            {
            case 0:
                return x;
            case 1:
                return y;
            case 2:
                return z;
            case 3:
                return w;
            default:
                throw "Invalid index";
            };
        }

        float4 operator+(const float rhs)
        {
            return float4(x + rhs, y + rhs, z + rhs, w + rhs);
        }

        float4 operator+(const float4 &rhs)
        {
            return float4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
        }

        void operator+=(const float rhs)
        {
            x += rhs;
            y += rhs;
            z += rhs;
            w += rhs;
        }

        void operator+=(const float4 &rhs)
        {
            x += rhs.x;
            y += rhs.y;
            z += rhs.z;
            w += rhs.w;
        }

        float4 operator-(const float rhs)
        {
            return float4(x - rhs, y - rhs, z - rhs, w - rhs);
        }

        float4 operator-(const float4 &rhs)
        {
            return float4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
        }

        void operator-=(const float rhs)
        {
            x -= rhs;
            y -= rhs;
            z -= rhs;
            w -= rhs;
        }

        void operator-=(const float4 &rhs)
        {
            x -= rhs.x;
            y -= rhs.y;
            z -= rhs.z;
            w -= rhs.w;
        }

        float4 operator*(const float rhs)
        {
            return float4(x * rhs, y * rhs, z * rhs, w * rhs);
        }

        float4 operator*(const float4 &rhs)
        {
            return float4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
        }

        void operator*=(const float rhs)
        {
            x *= rhs;
            y *= rhs;
            z *= rhs;
            w *= rhs;
        }

        void operator*=(const float4 &rhs)
        {
            x *= rhs.x;
            y *= rhs.y;
            z *= rhs.z;
            w *= rhs.w;
        }

        float4 operator/(const float rhs) const
        {
            return float4(x / rhs, y / rhs, z / rhs, w / rhs);
        }

        float4 operator/(const float4 &rhs)
        {
            return float4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
        }

        void operator/=(const float rhs)
        {
            x /= rhs;
            y /= rhs;
            z /= rhs;
            w /= rhs;
        }

        void operator/=(const float4 &rhs)
        {
            x /= rhs.x;
            y /= rhs.y;
            z /= rhs.z;
            w /= rhs.w;
        }
    };
} // namespace vec

inline vec::float4 clamp(const vec::float4 &lhs, float _min, float _max)
{
    return vec::float4(
        std::min(std::max(lhs.x, _min), _max),
        std::min(std::max(lhs.y, _min), _max),
        std::min(std::max(lhs.z, _min), _max),
        std::min(std::max(lhs.w, _min), _max));
}

inline vec::float4 pow(const vec::float4 &lhs, float rhs)
{
    return vec::float4(
        powf(lhs.x, rhs),
        powf(lhs.y, rhs),
        powf(lhs.z, rhs),
        powf(lhs.w, rhs));
}

inline float length(const vec::float4 &a)
{
    return sqrtf(
        a.x * a.x +
        a.y * a.y +
        a.z * a.z +
        a.w * a.w);
}

inline vec::float4 normalize(const vec::float4 &a)
{
    return a / length(a);
}

inline std::ostream &operator<<(std::ostream &_stream, vec::float4 const &f)
{
    _stream << "float4(" << f.x << ", " << f.y << ", " << f.z << ", " << f.w << ')';
}
