#include <iostream>

#include "buffer.hpp"
#include "camera.hpp"
#include "matrix4.hpp"
#include "scene.hpp"

int main(int argc, char const *argv[])
{
    Scene scene{};
    matrix4 camTransform = matrix4::identity();
    Camera camera(camTransform, 10.0f, 23.0f);
    Buffer buffer(100, 100);
    scene.render(camera, buffer, 10.0f);
    buffer.toPPM("sdf.ppm");
    return 0;
}
