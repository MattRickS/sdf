#include <iostream>

#include <buffer.hpp>
#include <scene/camera.hpp>
#include <scene/scene.hpp>
#include <vec/mat4.hpp>

int main(int argc, char const *argv[])
{
    vec::mat4 camTransform = vec::mat4::identity();
    scene::Camera camera(camTransform, 10.0f, 23.0f);
    Buffer buffer(100, 100);

    scene::Scene s;
    s.render(camera, buffer, 10.0f);
    buffer.toPPM("sdf.ppm");

    return 0;
}
