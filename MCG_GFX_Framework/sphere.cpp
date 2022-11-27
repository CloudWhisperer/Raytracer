#include "sphere.h"

float sphere::intersection(ray _ray, glm::vec3 _vec3)
{
    _vec3.x / 255;
    _vec3.y / 255;
    _vec3.z / 255;

    //if (_ray.origin == )


    return  _vec3.x / 255;
}

glm::vec3 sphere::closepoint(ray _ray, glm::vec3 _3dquerypoint)
{
    glm::vec3 randompoint = _3dquerypoint - _ray.origin;

    float result = glm::dot((randompoint), _ray.origin);

    glm::vec3 x = _ray.origin + glm::dot((_3dquerypoint - _ray.origin), _ray.origin) * _ray.origin;

    return x;
}

bool sphere::hitormiss(ray _ray, glm::vec3 _spherecentre, float _radius)
{
    glm::vec3 x = _spherecentre - (closepoint(_ray, _spherecentre));

    if (glm::distance(_spherecentre , x) >= _radius)
    {
        return true;
    }

    else
    {
        return false;
    }
}
