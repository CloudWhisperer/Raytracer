#include "Raytracer.h"

Raytracer::Raytracer()
{
    _object.SetRadius(0.5f);
    _object.SetPosition(glm::vec3(0, 0, -2.0f));
}

glm::vec3 Raytracer::returncol(ray _ray)
{
    if (_object.IntersectTest(_ray).hit)
    {
        return _object.ShadePixel(_ray, _object.IntersectTest(_ray).intersectionPoint);
        //return glm::vec3(1, 0, 0);
    }

    return glm::vec3(0);
}
