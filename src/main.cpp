#include <iostream>

#include "buffer.hpp"

int main(int argc, char const *argv[])
{
    Buffer b(3, 3);
    b.arr[0] = float4(1.0f, 0.0f, 0.0f, 1.0f);
    b.arr[4] = float4(0.0f, 1.0f, 0.0f, 1.0f);
    b.arr[8] = float4(0.0f, 0.0f, 1.0f, 1.0f);
    b.arr[2] = float4(0.1f, 0.1f, 0.1f, 1.0f);
    b.arr[6] = float4(0.5f, 0.5f, 0.5f, 1.0f);
    b.toPPM("demo.ppm");

    Buffer b2 = Buffer::fromPPM("demo.ppm");
    b2.toPPM("demo2.ppm");

    return 0;
}
