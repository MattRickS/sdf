#include "scene.hpp"
#include "shapes.hpp"

void Scene::render(Camera &camera, Buffer &buffer, float maxDistance)
{
    for (int y = 0; y < buffer.sizeY; y++)
    {
        for (int x = 0; x < buffer.sizeX; x++)
        {
            // Fire from pixel center, uv range between -0.5 and 0.5
            float u = (x + 0.5f) / buffer.sizeX - 0.5f;
            float v = (y + 0.5f) / buffer.sizeY - 0.5f;
            Ray ray = camera.ray(u, v);
            float4 colour = process(ray, maxDistance);
            buffer.setPixel(x, y, colour);
        }
    }
}

float4 Scene::process(Ray &ray, float maxDistance)
{
    float d, totalDistance = 0.0;
    do
    {
        d = distance(ray.origin);
        totalDistance += d;
        ray.advance(d);
    } while (d > threshold && totalDistance < maxDistance);
    return float4(1.0f - totalDistance / maxDistance);
}

float Scene::distance(float4 &pos)
{
    return sphere(float4(0.0f, 0.0f, 5.0f, 1.0f) - pos, 3.0f);
}