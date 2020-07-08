#include <iostream>

#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/renderer.hpp>
#include <sdf/shapes.hpp>
#include <vec/mat4.hpp>
#include <vec/vec3.hpp>

float distance(vec::vec3 &pos)
{
    // return sdf::sphere(vec::vec3(0.0f, 0.0f, 8.0f) - pos, 5.0f);
    // TODO: Not rendering right, is it camera distortion or is the box algorithm wrong?
    return sdf::box(
        vec::vec3(0.0f, 0.0f, 5.0f) - pos,
        vec::vec3(3.0f, 3.0f, 3.0f));
}

int main(int argc, char const *argv[])
{
    vec::mat4 camTransform = vec::mat4::identity();
    render::Camera camera(camTransform, 10.0f, 23.0f);
    render::Buffer buffer(100, 100);

    render::Renderer renderer(distance);
    renderer.render(camera, buffer, 10.0f);
    buffer.toPPM("sdf.ppm");

    return 0;
}
