#include "float4.hpp"

class Buffer
{
public:
    float4 *arr;
    int sizeX, sizeY;

    Buffer(int x, int y) : sizeX(x), sizeY(y)
    {
        arr = new float4[x * y];
    }

    ~Buffer()
    {
        delete[] arr;
    }

    float4 &pixel(int x, int y) { return arr[x + sizeX * y]; }

    void toPPM(const char *path, float gamma = 2.2f);
    static Buffer fromPPM(const char *path, float gamma = 2.2f);
};