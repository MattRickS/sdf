#include <render/renderer.hpp>

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
        d = dfunc(ray.origin);
        totalDistance += d;
        ray.advance(d);
    } while (d > threshold && totalDistance < maxDistance);
    return vec::vec4(1.0f - totalDistance / maxDistance);
}
