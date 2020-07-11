#include <iostream>

#include <render/buffer.hpp>
#include <render/camera.hpp>
#include <render/renderer.hpp>
#include <sdf/op.hpp>
#include <sdf/shapes.hpp>
#include <vec/mat4.hpp>
#include <vec/vec3.hpp>

static const float deg2rad = M_PI / 180;

float rubix(const vec::vec3 &pos)
{
    static const vec::vec3 t(0.0f, 3.2f, 0.0f);
    static const vec::mat4 m = vec::mat4::transformed(t);
    static const vec::vec3 boxes(1.0f);
    return sdf::box(
        sdf::repeat(sdf::transform(pos, m), 2.2f, boxes),
        boxes);
}

float distance(const vec::vec3 &pos)
{
    static const float sphereR{3.0f};
    static const vec::vec3 sphereT(10.0f, sphereR, 0.0f);
    static const vec::mat4 sphereM = vec::mat4::transformed(sphereT);
    return std::min(
        std::min(
            sdf::plane(pos, vec::vec3::up(), 0.0f),
            rubix(pos)),
        sdf::sphere(sdf::transform(pos, sphereM), sphereR));
}

int main(int argc, char const *argv[])
{
    vec::mat4 camTransform = vec::mat4::targetted(
        vec::vec3(-15.0f, 13.0f, -30.0f),
        vec::vec3(0.0f, 3.0f, 0.0f),
        vec::vec3(0.0f, 1.0f, 0.0f));
    // 35mm sensor
    render::Camera camera(camTransform, 50.0f, 36.0f, 24.0f);
    render::Buffer buffer(354, 200);

    render::Renderer renderer(distance);
    renderer.render(camera, buffer, 100.0f);
    buffer.toPPM("sdf.ppm");

    return 0;
}
