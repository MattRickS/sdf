#pragma once
#include <render/ray.hpp>
#include <vec/vec3.hpp>
#include <vec/mat4.hpp>

namespace render
{
    class Camera
    {
    public:
        vec::mat4 transform;
        float focal;
        float sensorWidth;
        float sensorHeight;

        Camera(vec::mat4 &transform, float focal, float sensorWidth, float sensorHeight) : focal(focal), sensorWidth(sensorWidth), sensorHeight(sensorHeight)
        {
            this->transform = transform;
        }

        float aspect()
        {
            return sensorWidth / sensorHeight;
        }

        render::Ray ray(float u, float v)
        {
            vec::vec3 direction = normalize(
                vec::vec3(
                    transform.forward() * focal +
                    transform.right() * sensorWidth * 0.5f * u +
                    transform.up() * sensorHeight * 0.5f * v));
            return render::Ray(transform.position(), direction);
        }
    };
} // namespace render
