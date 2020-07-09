#pragma once

#include <vec/vec4.hpp>

namespace vec
{
    class mat4
    {
    public:
        union
        {
            float arr[16];
            vec::vec4 rows[4];
        };

        mat4() {}

        inline float &operator[](int i)
        {
            return arr[i];
        }

        inline const float operator[](int i) const
        {
            return arr[i];
        }

        vec::vec3 position() const
        {
            return vec::vec3(arr[12], arr[13], arr[14]);
        }

        vec::vec3 forward() const
        {
            return vec::vec3(arr[8], arr[9], arr[10]);
        }

        vec::vec3 up() const
        {
            return vec::vec3(arr[4], arr[5], arr[6]);
        }

        vec::vec3 right() const
        {
            return vec::vec3(arr[0], arr[1], arr[2]);
        }

        void setPosition(vec::vec3 pos)
        {
            arr[12] = pos.x;
            arr[13] = pos.y;
            arr[14] = pos.z;
        }

        void setRotation(const vec::vec3 &eulerAngles)
        {
            const float sz = sinf(eulerAngles.z);
            const float cz = cosf(eulerAngles.z);
            const float sy = sinf(eulerAngles.y);
            const float cy = cosf(eulerAngles.y);
            const float sx = sinf(eulerAngles.x);
            const float cx = cosf(eulerAngles.x);

            rows[0] = vec::vec4(cz * cy, cz * sy * sx - sz * cx, cz * sy * cx + sz * sx, 0.0f);
            rows[1] = vec::vec4(sz * cy, sz * sy * sx + cz * cx, sz * sy * cx - cz * sx, 0.0f);
            rows[2] = vec::vec4(-sy, cy * sx, cy * cx, 0.0f);
        }

        static mat4 transformed(vec::vec3 xform)
        {
            mat4 m = mat4::identity();
            m.setPosition(xform);
            return m;
        }

        static mat4 transformed(vec::vec3 xform, vec::vec3 eulerAngles)
        {
            mat4 m = mat4::identity();
            m.setRotation(eulerAngles);
            m.setPosition(xform);
            return m;
        }

        static mat4 identity()
        {
            mat4 m;
            m.rows[0] = vec::vec4(1.0f, 0.0f, 0.0f, 0.0f);
            m.rows[1] = vec::vec4(0.0f, 1.0f, 0.0f, 0.0f);
            m.rows[2] = vec::vec4(0.0f, 0.0f, 1.0f, 0.0f);
            m.rows[3] = vec::vec4(0.0f, 0.0f, 0.0f, 1.0f);
            return m;
        }
    };
} // namespace vec

inline std::ostream &operator<<(std::ostream &_stream, vec::mat4 const &m)
{
    _stream << "( ";
    for (const float f : m.arr)
    {
        _stream << f << ' ';
    }
    _stream << ')';
}

inline vec::vec3 operator*(const vec::mat4 &m, const vec::vec3 v)
{
    vec::vec4 v4(v, 0.0f);
    return m.position() + vec::vec3(
                              dot(v4, m.rows[0]),
                              dot(v4, m.rows[1]),
                              dot(v4, m.rows[2]));
}

inline vec::mat4 invert(const vec::mat4 &m)
{
    vec::mat4 inv;
    float det;
    int i;

    inv[0] = m[5] * m[10] * m[15] -
             m[5] * m[11] * m[14] -
             m[9] * m[6] * m[15] +
             m[9] * m[7] * m[14] +
             m[13] * m[6] * m[11] -
             m[13] * m[7] * m[10];

    inv[4] = -m[4] * m[10] * m[15] +
             m[4] * m[11] * m[14] +
             m[8] * m[6] * m[15] -
             m[8] * m[7] * m[14] -
             m[12] * m[6] * m[11] +
             m[12] * m[7] * m[10];

    inv[8] = m[4] * m[9] * m[15] -
             m[4] * m[11] * m[13] -
             m[8] * m[5] * m[15] +
             m[8] * m[7] * m[13] +
             m[12] * m[5] * m[11] -
             m[12] * m[7] * m[9];

    inv[12] = -m[4] * m[9] * m[14] +
              m[4] * m[10] * m[13] +
              m[8] * m[5] * m[14] -
              m[8] * m[6] * m[13] -
              m[12] * m[5] * m[10] +
              m[12] * m[6] * m[9];

    inv[1] = -m[1] * m[10] * m[15] +
             m[1] * m[11] * m[14] +
             m[9] * m[2] * m[15] -
             m[9] * m[3] * m[14] -
             m[13] * m[2] * m[11] +
             m[13] * m[3] * m[10];

    inv[5] = m[0] * m[10] * m[15] -
             m[0] * m[11] * m[14] -
             m[8] * m[2] * m[15] +
             m[8] * m[3] * m[14] +
             m[12] * m[2] * m[11] -
             m[12] * m[3] * m[10];

    inv[9] = -m[0] * m[9] * m[15] +
             m[0] * m[11] * m[13] +
             m[8] * m[1] * m[15] -
             m[8] * m[3] * m[13] -
             m[12] * m[1] * m[11] +
             m[12] * m[3] * m[9];

    inv[13] = m[0] * m[9] * m[14] -
              m[0] * m[10] * m[13] -
              m[8] * m[1] * m[14] +
              m[8] * m[2] * m[13] +
              m[12] * m[1] * m[10] -
              m[12] * m[2] * m[9];

    inv[2] = m[1] * m[6] * m[15] -
             m[1] * m[7] * m[14] -
             m[5] * m[2] * m[15] +
             m[5] * m[3] * m[14] +
             m[13] * m[2] * m[7] -
             m[13] * m[3] * m[6];

    inv[6] = -m[0] * m[6] * m[15] +
             m[0] * m[7] * m[14] +
             m[4] * m[2] * m[15] -
             m[4] * m[3] * m[14] -
             m[12] * m[2] * m[7] +
             m[12] * m[3] * m[6];

    inv[10] = m[0] * m[5] * m[15] -
              m[0] * m[7] * m[13] -
              m[4] * m[1] * m[15] +
              m[4] * m[3] * m[13] +
              m[12] * m[1] * m[7] -
              m[12] * m[3] * m[5];

    inv[14] = -m[0] * m[5] * m[14] +
              m[0] * m[6] * m[13] +
              m[4] * m[1] * m[14] -
              m[4] * m[2] * m[13] -
              m[12] * m[1] * m[6] +
              m[12] * m[2] * m[5];

    inv[3] = -m[1] * m[6] * m[11] +
             m[1] * m[7] * m[10] +
             m[5] * m[2] * m[11] -
             m[5] * m[3] * m[10] -
             m[9] * m[2] * m[7] +
             m[9] * m[3] * m[6];

    inv[7] = m[0] * m[6] * m[11] -
             m[0] * m[7] * m[10] -
             m[4] * m[2] * m[11] +
             m[4] * m[3] * m[10] +
             m[8] * m[2] * m[7] -
             m[8] * m[3] * m[6];

    inv[11] = -m[0] * m[5] * m[11] +
              m[0] * m[7] * m[9] +
              m[4] * m[1] * m[11] -
              m[4] * m[3] * m[9] -
              m[8] * m[1] * m[7] +
              m[8] * m[3] * m[5];

    inv[15] = m[0] * m[5] * m[10] -
              m[0] * m[6] * m[9] -
              m[4] * m[1] * m[10] +
              m[4] * m[2] * m[9] +
              m[8] * m[1] * m[6] -
              m[8] * m[2] * m[5];

    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

    if (det == 0)
    {
        return m;
    }

    det = 1.0 / det;
    for (i = 0; i < 16; i++)
    {
        inv[i] = inv[i] * det;
    }

    return inv;
}