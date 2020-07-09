#include <iostream>

#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/renderer.hpp>
#include <sdf/op.hpp>
#include <sdf/shapes.hpp>
#include <vec/mat4.hpp>
#include <vec/vec3.hpp>

static const float deg2rad = M_PI / 180;

float distance(const vec::vec3 &pos)
{
    static const vec::mat4 m = vec::mat4::rotated(vec::vec3(45.0f, 45.0f, 0.0f) * deg2rad);
    // return sdf::box(sdf::transform(pos, m), vec::vec3(2.0f, 2.0f, 2.0f));
    return sdf::box(
        // Infinite repetition, abs() extends into negative, 3x3x3 spacing
        sdf::repeat(abs(sdf::transform(pos, m)), vec::vec3(5.0f, 5.0f, 5.0f)),
        // Box dimensions
        vec::vec3(1.0f, 1.0f, 1.0f));
}

int main(int argc, char const *argv[])
{
    vec::mat4 camTransform = vec::mat4::transformed(vec::vec3(0.0f, 0.0f, -7.0f));
    // 35mm sensor
    render::Camera camera(camTransform, 50.0f, 36.0f, 24.0f);
    render::Buffer buffer(150, 100);

    render::Renderer renderer(distance);
    renderer.render(camera, buffer, 30.0f);
    buffer.toPPM("sdf.ppm");

    return 0;
}
