#include <render/renderer.hpp>
#include <sdf/shapes.hpp>

void render::Renderer::render(render::Camera &camera, render::Buffer &buffer, float maxDistance)
{
    for (int y = 0; y < buffer.sizeY; y++)
    {
        for (int x = 0; x < buffer.sizeX; x++)
        {
            // Fire from pixel center, uv range between -0.5 and 0.5
            float u = 2 * (x + 0.5f) / buffer.sizeX - 1.0f;
            float v = 2 * (y + 0.5f) / buffer.sizeY - 1.0f;
            render::Ray ray = camera.ray(u, v);
            vec::vec4 colour = process(ray, maxDistance);
            buffer.setPixel(x, y, colour);
        }
    }
}

vec::vec4 render::Renderer::process(render::Ray &ray, float maxDistance)
{
    float d, totalDistance = 0.0;
    do
    {
        d = distance(ray.origin);
        totalDistance += d;
        ray.advance(d);
    } while (d > threshold && totalDistance < maxDistance);
    return vec::vec4(1.0f - totalDistance / maxDistance);
}

float render::Renderer::distance(vec::vec3 &pos)
{
    // return sdf::sphere(vec::vec3(0.0f, 0.0f, 8.0f) - pos, 5.0f);
    // TODO: Not rendering right, is it camera distortion or is the box algorithm wrong?
    return sdf::box(
        vec::vec3(0.0f, 0.0f, 5.0f) - pos,
        vec::vec3(3.0f, 3.0f, 3.0f));
}
