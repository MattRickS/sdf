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
    vec::mat4 m = vec::mat4::rotated(vec::vec3(45.0f, 45.0f, 0.0f));
    // return sdf::box(sdf::transform(pos, m), vec::vec3(2.0f, 2.0f, 2.0f));
    return sdf::box(sdf::repeat(abs(sdf::transform(pos, m)), vec::vec3(3.0f, 3.0f, 3.0f)), vec::vec3(1.0f, 1.0f, 1.0f));
}

int main(int argc, char const *argv[])
{
    vec::mat4 camTransform = vec::mat4::transformed(vec::vec3(0.0f, 0.0f, -10.0f));
    render::Camera camera(camTransform, 50.0f, 23.0f);
    render::Buffer buffer(200, 200);

    render::Renderer renderer(distance);
    renderer.render(camera, buffer, 15.0f);
    buffer.toPPM("sdf.ppm");

    return 0;
}
