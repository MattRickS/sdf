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
            render::Hit hit = project(ray, maxDistance);
            vec::vec4 colour = shade(hit);
            buffer.setPixel(x, y, colour);
        }
    }
}

render::Hit render::Renderer::project(render::Ray &ray, float maxDistance)
{
    float d, totalDistance = 0.0;
    do
    {
        d = dfunc(ray.origin);
        totalDistance += d;
        ray.advance(d);
    } while (d > threshold && totalDistance < maxDistance);
    return render::Hit(ray, (d < threshold), totalDistance);
}

vec::vec4 render::Renderer::shade(render::Hit &hit)
{
    if (!hit.hit)
    {
        return vec::vec4(0.0f);
    }

    // Ambient occlusion
    vec::vec3 normal = gradient(hit.ray.origin) * 0.5f + 0.5f;
    float ao{0.0f};
    for (int i = 1; i <= aoSteps; i++)
    {
        ao += (i * aoDelta - dfunc(hit.ray.origin + normal * i * aoDelta)) / pow(2, i);
    }
    ao /= aoSteps;

    // return vec::vec4(1.0f - ao * aoStrength);
    return vec::vec4(normal * (1.0f - ao * aoStrength), 0.0f);
}

vec::vec3 render::Renderer::gradient(const vec::vec3 &pos, float offset) // offset = 0.00001
{
    static const vec::vec3 k0(1.0f, -1.0f, -1.0f);
    static const vec::vec3 k1(-1.0f, -1.0f, 1.0f);
    static const vec::vec3 k2(-1.0f, 1.0f, -1.0f);
    static const vec::vec3 k3(1.0f, 1.0f, 1.0f);
    return normalize(k0 * dfunc(pos + k0 * offset) +
                     k1 * dfunc(pos + k1 * offset) +
                     k2 * dfunc(pos + k2 * offset) +
                     k3 * dfunc(pos + k3 * offset));
}
