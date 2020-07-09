#include <render/renderer.hpp>

void render::Renderer::render(render::Camera &camera, render::Buffer &buffer, float maxDistance, render::RenderFit fit) // fit = KeepRatio
{
    // Fit the uv range based on buffer size.
    float sx = 1.0f, sy = 1.0f;
    if (fit == render::RenderFit::KeepRatio)
    {
        float verticalScaleFactor = camera.aspect() / ((float)buffer.sizeX / buffer.sizeY);
        if (verticalScaleFactor > 1)
        {
            sx = 1.0f / verticalScaleFactor;
        }
        else
        {
            sy = verticalScaleFactor;
        }
    }

    for (int y = 0; y < buffer.sizeY; y++)
    {
        for (int x = 0; x < buffer.sizeX; x++)
        {
            // Fire from pixel center, uv range between -1 and 1
            float u = (2 * (x + 0.5f) / buffer.sizeX - 1.0f) * sx;
            float v = (2 * (y + 0.5f) / buffer.sizeY - 1.0f) * sy;
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
    // Render the normal (fit between0 and 1) for anything hit, or black otherwise
    return vec::vec4((d < threshold) ? sdf::calcNormal(ray.origin, dfunc) * 0.5f + 0.5f : 0.0f);
    // return vec::vec4(1.0f - totalDistance / maxDistance);
}
