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

sphereclass sphere::hitormiss(ray _ray, glm::vec3 _spherecentre, float _radius)
{
    sphereclass classthing;

    glm::vec3 delta = _spherecentre - _ray.origin;
    float deltadot = glm::dot(delta, _ray.dir);

    if (deltadot < 0)
        classthing.returnresult = false;
    return classthing;

    const float closestpoint = glm::length(delta - (deltadot * _ray.dir));

    if (closestpoint > _radius)
        classthing.returnresult = false;
    return classthing;


    const float x = glm::sqrt(_radius * _radius - closestpoint * closestpoint);
    glm::vec3 hitposition = _ray.origin + (deltadot - x) * _ray.dir;

    glm::vec3 hitnormal = glm::normalize(hitposition - _spherecentre);

    classthing.returnresult = true;
    classthing.vecresult = hitposition;

    return classthing;
}
