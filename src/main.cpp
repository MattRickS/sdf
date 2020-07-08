#include <iostream>

#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/scene.hpp>
#include <vec/mat4.hpp>

int main(int argc, char const *argv[])
{
    vec::mat4 camTransform = vec::mat4::identity();
    render::Camera camera(camTransform, 10.0f, 23.0f);
    render::Buffer buffer(100, 100);

    render::Scene s;
    s.render(camera, buffer, 10.0f);
    buffer.toPPM("sdf.ppm");

    return 0;
}
