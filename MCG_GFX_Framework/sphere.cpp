#include "sphere.h"
#include <iostream>

sphere::sphere()
{
    radius = 0.f;
    sphereCenter = glm::vec3(0, 0, 0);
}

sphere::sphere(float _radius, glm::vec3 _sphereCenter, Material _mat)
{
    radius = _radius;
    sphereCenter = _sphereCenter;
    material = _mat;
}

Material::Material()
{
    //default material constructor
    diffuseColour = glm::vec3(0, 1, 1);
    specularStrength = 0.f;
}

Material::Material(glm::vec3 _diffuseColour, float _specularStrength)
{
    specularStrength = _specularStrength;
    diffuseColour = _diffuseColour;
}



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

    glm::vec3 x = _ray.origin + glm::dot((_3dquerypoint - _ray.origin), _ray.dir) * _ray.dir;

    return x;
}

sphereclass sphere::hitormiss(ray _ray, glm::vec3 _spherecentre, float _radius)
{
    sphereclass classthing;

    //p - x thing
    glm::vec3 delta = _spherecentre - closepoint(_ray, _spherecentre);


    //float deltadot = glm::dot(delta, _ray.dir);


    if (delta.x  <= radius && delta.y <= radius && delta.z <= radius)
    {
        sp_class.returnresult = true;
        //std::cout << "x " << delta.x << std::endl;
        //std::cout << "y " << delta.y << std::endl;
        //std::cout << "z " << delta.z << std::endl;

    }

    else
    {
        sp_class.returnresult = false;
        //std::cout << sp_class.returnresult << std::endl;

    }

    //if (deltadot < 0)
    //{
    //    sp_class.returnresult = false;
    //   //std::cout << sp_class.returnresult;
    //    return sp_class;
    //}
       
    glm::vec3 d = _spherecentre - _ray.origin - glm::dot((_spherecentre - _ray.origin), _ray.dir) * _ray.dir;
    glm::vec3 x = glm::sqrt((_radius * _radius) - (d * d));

    //closest intersection point
    glm::vec3 closestintersectionpoint = _ray.origin + (glm::dot((_spherecentre - _ray.origin), _ray.dir) - x) * _ray.dir;

    sp_class.vecresult = closestintersectionpoint;


    //std::cout << "x " << closestintersectionpoint.x << std::endl;
    //std::cout << "y " << closestintersectionpoint.y << std::endl;
    //std::cout << "z " << closestintersectionpoint.z << std::endl;



    //const float closestpoint = glm::length(delta - (deltadot * _ray.dir));

    //if (closestpoint > _radius)
    //{
    //    sp_class.returnresult = false;
    //    //std::cout << sp_class.returnresult;
    //}
    //  


    //const float x = glm::sqrt(_radius * _radius - closestpoint * closestpoint);
    //glm::vec3 hitposition = _ray.origin + (deltadot - x) * _ray.dir;

    //glm::vec3 hitnormal = glm::normalize(hitposition - _spherecentre);

    //sp_class.returnresult = true;
    //sp_class.vecresult = hitposition;
    //std::cout << sp_class.returnresult;


    return sp_class;
}
