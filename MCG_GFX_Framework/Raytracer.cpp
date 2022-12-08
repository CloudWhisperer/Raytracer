#include "Raytracer.h"

Raytracer::Raytracer()
{
    _object.SetRadius(0.5f);
    _object.SetPosition(glm::vec3(0, 0, -1.0f));
}

glm::vec3 Raytracer::returncol(ray _ray)
{
    if (_object.IntersectTest(_ray).hit)
    {
        return glm::vec3(1, 0, 0);
    }

    return glm::vec3(0);
}
