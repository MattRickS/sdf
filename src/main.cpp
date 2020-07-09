#include <iostream>

#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/renderer.hpp>
#include <sdf/op.hpp>
#include <sdf/shapes.hpp>
#include <vec/mat4.hpp>
#include <vec/vec3.hpp>

float distance(const vec::vec3 &pos)
{
    vec::mat4 m = vec::mat4::transformed(vec::vec3(0.0f, 0.0f, 7.0f), vec::vec3(0.0f, 0.0f, 45.0f));
    return sdf::box(sdf::repeat(sdf::transform(pos, m), vec::vec3(7.0f, 7.0f, 100.0f)), vec::vec3(3.0f, 3.0f, 3.0f));
}

int main(int argc, char const *argv[])
{
    vec::mat4 camTransform = vec::mat4::identity();
    render::Camera camera(camTransform, 10.0f, 23.0f);
    render::Buffer buffer(200, 200);

    render::Renderer renderer(distance);
    renderer.render(camera, buffer, 15.0f);
    buffer.toPPM("sdf.ppm");

    return 0;
}
