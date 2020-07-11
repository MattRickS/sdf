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

        inline float &operator[](int i);
        inline const float operator[](int i) const;
        vec::vec3 position() const;
        vec::vec3 forward() const;
        vec::vec3 up() const;
        vec::vec3 right() const;
        void setPosition(vec::vec3 pos);
        void setRotation(const vec::vec3 &eulerAngles);
        static vec::mat4 targetted(vec::vec3 pos, vec::vec3 lookAt, vec::vec3 up);
        static vec::mat4 rotated(vec::vec3 rot);
        static vec::mat4 transformed(vec::vec3 xform);
        static vec::mat4 transformed(vec::vec3 xform, vec::vec3 eulerAngles);
        static vec::mat4 identity();
    };
} // namespace vec

std::ostream &operator<<(std::ostream &_stream, vec::mat4 const &m);
vec::vec3 operator*(const vec::mat4 &m, const vec::vec3 v);
vec::mat4 invert(const vec::mat4 &m);
