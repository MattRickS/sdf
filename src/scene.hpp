#include "buffer.hpp"
#include "camera.hpp"
#include "float4.hpp"
#include "ray.hpp"

class Scene
{
public:
    float threshold{0.0001f};
    // TODO: A vector of SDF functions - must define an interface
    void render(Camera &camera, Buffer &buffer, float maxDistance);
    float4 process(Ray &ray, float maxDistance);
    float distance(float4 &pos);
};