#pragma once
#include <vec/vec4.hpp>

namespace render
{
    class Buffer
    {
    public:
        vec::vec4 *arr;
        int sizeX, sizeY;

        Buffer(int x, int y) : sizeX(x), sizeY(y)
        {
            arr = new vec::vec4[x * y];
        }

        ~Buffer()
        {
            delete[] arr;
        }

        vec::vec4 &pixel(int x, int y) { return arr[x + sizeX * y]; }
        void setPixel(int x, int y, vec::vec4 &colour) { arr[x + sizeX * y] = colour; }

        void toPPM(const char *path, float gamma = 2.2f);
        static Buffer fromPPM(const char *path, float gamma = 2.2f);
    };
} // namespace render